package diskCacheV111.util;

import java.net.URI;
import java.util.Map;

public interface HsmLocation {

	/**
	 * 
	 * @return URI representation of location information
	 */
	public URI location();
	
	/**
	 * 
	 * @return pnfs level based representation of location information
	 */
	public Map<Integer, String> toLevels();
}
