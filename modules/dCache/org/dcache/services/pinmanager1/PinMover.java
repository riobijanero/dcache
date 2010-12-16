package org.dcache.services.pinmanager1;

import diskCacheV111.util.PnfsId;
import diskCacheV111.vehicles.*;

import dmg.cells.nucleus.CellPath;
import org.dcache.cells.CellStub;
import org.dcache.cells.MessageReply;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * Background task used to perform the actual pinning operation. To do
 * this, it will talk to the PNFS manager, pool manager and pools.
 *
 * It is spawned by a Pin instance, and will do a callback to that pin
 * when done.
 */
class PinMover extends SMCTask
{
    private static final Logger _logger =
        LoggerFactory.getLogger(PinMover.class);

    private final PinManager _manager;
    private final Pin _srcPoolPin;
    private final Pin _dstPoolPin;
    private final PnfsId _pnfsId;
    private final PinMoverContext _fsm;
    private final CellStub _pool;
    private String _dstPoolName;
    private long _expiration;
    private PinManagerMovePinMessage _movePin;
    protected final MessageReply _reply ;
    // We record this now in Pinner, since upon success
    // we need to change the original pin expiration time
    // which will be calcuated only after the file was
    // succesfully staged or otherwise made available and
    // the read pool is given to us
    private long _orginalPinRequestId;

    public PinMover(PinManager manager,
                    PnfsId pnfsId,
                    Pin srcPoolPin,
                    Pin dstPoolPin,
                    String dstPoolName,
                    long expiration,
                    PinManagerMovePinMessage movePin,
                    MessageReply reply,
                    CellStub pool)
    {
        super(manager.getCellEndpoint());

        _manager = manager;
        _pool = pool;
        _pnfsId = pnfsId;
        _dstPoolName = dstPoolName;
        _srcPoolPin = srcPoolPin;
        _dstPoolPin = dstPoolPin;
        _expiration = expiration;
        _movePin = movePin;
        _reply = reply;
        _fsm = new PinMoverContext(this);
        setContext(_fsm);
        synchronized (this) {
            _fsm.go();
        }
        _logger.info("PinMover constructor done");
    }

    /** Returns the current state of the pinner. */
    public String toString()
    {
        return _fsm.getState().toString();
    }


    void markSticky()
    {
        _logger.info("markSticky");
        long stickyBitExpiration = _expiration;
        if(stickyBitExpiration > 0) {
            stickyBitExpiration += PinManager.POOL_LIFETIME_MARGIN;
        }
        PoolSetStickyMessage setStickyRequest =
            new PoolSetStickyMessage(_dstPoolName,
            _pnfsId,
            true,
            //Use a pin specific name, so multiple pins of the same file
            // by the pin manager would be possible
            // needed if the unpinning is started and new pin request
            // has arrived
            getCellName()+_dstPoolPin.getId(),
            stickyBitExpiration);
        send(_pool, setStickyRequest, _dstPoolName);
    }

    void unsetStickyFlags()
    {
        String stickyBitName = getCellName()+
                Long.toString(_srcPoolPin.getId());
        String oldStickyBitName = getCellName();
        String srcPoolName = _srcPoolPin.getPool();
        _logger.info("unsetStickyFlags in "+srcPoolName+" for "+
            _pnfsId+" stickyBitNameName:"+stickyBitName);

        PoolSetStickyMessage setStickyRequest =
            new PoolSetStickyMessage(srcPoolName,
            _pnfsId, false,stickyBitName,-1);
            send(_pool, setStickyRequest, srcPoolName);
    }
    boolean pinMoveSucceed()
    {
        _logger.debug("pinMoveSucceed");
        try {
            return _manager.pinMoveToNewPoolPinSucceeded(
                _srcPoolPin,
                _dstPoolPin,
                _dstPoolName,
                _expiration,
                _movePin,
                _reply);
        } catch (PinException pe) {
           _logger.error(pe.toString());
            return false;
        }
        //_pin.pinSucceeded();
    }


    void succeed()
    {
        _logger.info("succeed");
        try {
            _manager.pinMoveSucceeded(
                _srcPoolPin,
                _dstPoolPin,
                _dstPoolName,
                _expiration,
                _movePin,
                _reply);
        } catch (PinException pe) {
           _logger.error(pe.toString());
        }
        //_pin.pinSucceeded();
    }

    void fail(Object reason)
    {
       _logger.error("failed: "+reason);
        try {
            _manager.pinMoveFailed(_srcPoolPin,
                _dstPoolPin,
                _dstPoolName,
                _expiration,
                _movePin,
                _reply,
                reason);

        } catch (PinException pe) {
          _logger.error(pe.toString());
        }
       // _pin.pinFailed(reason);
    }
}
