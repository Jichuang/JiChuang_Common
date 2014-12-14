package org.jichuang.hope6537;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/** 
 * <p>Describe: Format DataTables' DataLines</p>
 * <p>Using: Controller or Service</p>
 * <p>DevelopedTime: Nov 30, 2014 2:17:10 PM</p>
 * <p>Company: ChangChun Unviersity JiChuang Team</p>
 * @author Hope6537
 * @version 1.0
 * @see
 */
public class InfoUtils {

	public static Map<String, List<String>> getInfoMap(String info) {
		Map<String, List<String>> infos = new HashMap<String, List<String>>();
		info = info.substring(1, info.length());
		String[] infoArray = info.split(",");
		for (String str : infoArray) {
			String key = str.split("=")[0].trim();
			String value = str.split("=")[1].trim();
			List<String> values = infos.get(key);
			if (values == null) {
				values = new ArrayList<String>();
			}
			values.add(value);
			infos.put(key, values);
		}
		return infos;
	}

}
