package org.dcache.srm.handler;

import org.dcache.srm.v2_2.TReturnStatus;
import org.dcache.srm.v2_2.TStatusCode;
import org.dcache.srm.v2_2.SrmStatusOfLsRequestResponse;
import org.dcache.srm.v2_2.SrmStatusOfLsRequestRequest;
import org.dcache.srm.SRMUser;
import org.dcache.srm.request.RequestCredential;
import org.dcache.srm.AbstractStorageElement;
import org.dcache.srm.SRMException;
import org.dcache.srm.scheduler.Scheduler;
import org.dcache.srm.request.ContainerRequest;
import org.dcache.srm.util.Configuration;
import org.dcache.srm.SRMException;
import org.dcache.srm.SRMInternalErrorException;
import org.dcache.srm.SRMTooManyResultsException;
import org.dcache.srm.request.LsRequest;
import org.dcache.srm.request.LsFileRequest;
import org.dcache.srm.request.FileRequest;
import org.dcache.srm.request.sql.LsFileRequestStorage;
import org.dcache.srm.request.sql.LsRequestStorage;
import org.dcache.srm.SRM;
import org.apache.log4j.Logger;
import org.apache.axis.types.URI.MalformedURIException;
import java.sql.SQLException;



public class SrmStatusOfLsRequest {
        private static Logger logger = 
            Logger.getLogger(SrmStatusOfLsRequest.class);
        private final static String SFN_STRING="?SFN=";
        AbstractStorageElement storage;
        SrmStatusOfLsRequestRequest request;
        SrmStatusOfLsRequestResponse response;
        SRMUser user;
        RequestCredential credential;
        LsRequestStorage requestStorage;
        LsFileRequestStorage fileRequestStorage;
        Configuration configuration;
        private int results_num;
        private int max_results_num;
        int numOfLevels =0;

        public SrmStatusOfLsRequest(SRMUser user,
                                    RequestCredential credential,
                                    SrmStatusOfLsRequestRequest request,
                                    AbstractStorageElement storage,
                                    SRM srm,
                                    String client_host) {
                this.request = request;
                this.user = user;
                this.credential = credential;
                this.storage = storage;
                this.configuration = srm.getConfiguration();
        }

        boolean longFormat =false;
        String servicePathAndSFNPart = "";
        int port;
        String host;
        public SrmStatusOfLsRequestResponse getResponse() {
                if(response != null ) return response;
                try {
                        response = srmStatusOfLsRequest();
                } catch(MalformedURIException mue) {
                    logger.debug(" malformed uri : "+mue.getMessage());
                    response = getFailedResponse(" malformed uri : "+mue.getMessage(),
                            TStatusCode.SRM_INVALID_REQUEST);
                } catch(SQLException sqle) {
                    logger.error(sqle);
                    response = getFailedResponse("sql error "+sqle.getMessage(),
                            TStatusCode.SRM_INTERNAL_ERROR);
                } catch(SRMException srme) {
                    logger.error(srme);
                    response = getFailedResponse(srme.toString());
                }        
                return response;
        }

        public static final SrmStatusOfLsRequestResponse getFailedResponse(String error) {
                return getFailedResponse(error,null);
        }

        public static final SrmStatusOfLsRequestResponse getFailedResponse(String error,TStatusCode statusCode) {
                if(statusCode == null) {
                        statusCode =TStatusCode.SRM_FAILURE;
                }
                TReturnStatus status = new TReturnStatus();
                status.setStatusCode(statusCode);
                status.setExplanation(error);
                SrmStatusOfLsRequestResponse srmStatusOfLsRequestResponse = new SrmStatusOfLsRequestResponse();
                srmStatusOfLsRequestResponse.setReturnStatus(status);
                return srmStatusOfLsRequestResponse;
        }

        public SrmStatusOfLsRequestResponse srmStatusOfLsRequest()
                throws SRMException,MalformedURIException,
                SQLException {
                String requestToken = request.getRequestToken();
                if( requestToken == null ) {
                        return getFailedResponse("request contains no request token");
                }
                Long requestId;
                try {
                        requestId = new Long( requestToken);
                }
                catch (NumberFormatException nfe){
                        return getFailedResponse(" requestToken \""+
                                                 requestToken+"\"is not valid",
                                                 TStatusCode.SRM_FAILURE);
                }
                ContainerRequest containerRequest =(ContainerRequest) ContainerRequest.getRequest(requestId);
                if(request == null) {
                        return getFailedResponse("request for requestToken \""+
                                                 requestToken+"\"is not found",
                                                 TStatusCode.SRM_FAILURE);

                }
                if ( !(containerRequest instanceof LsRequest) ){
                        return getFailedResponse("request for requestToken \""+
                                                 requestToken+"\"is not srmLs request",
                                                 TStatusCode.SRM_FAILURE);

                }
                return ((LsRequest)containerRequest).getSrmStatusOfLsRequestResponse();
        }
}
