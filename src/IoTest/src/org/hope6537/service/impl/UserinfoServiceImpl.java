package org.hope6537.service.impl;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import org.hope6537.dao.impl.UserinfoDaoImpl;
import org.hope6537.model.Userinfo;
import org.hope6537.service.UserinfoService;
import org.hope6537.service.impl.BaseServiceImpl;

public class UserinfoServiceImpl extends BaseServiceImpl<Userinfo> implements
		UserinfoService {

	public UserinfoServiceImpl() {
		super(new UserinfoDaoImpl());
	}

	public void createDataBase() {
		String dropSql = "DROP TABLE IF EXISTS `userinfo`";
		String createSql = "CREATE TABLE `userinfo` (`u_id` int(11) NOT NULL,`u_username` varchar(255) default NULL,`u_password` varchar(255) default NULL, PRIMARY KEY  (`u_id`))";
		this.dao.update(dropSql);
		this.dao.update(createSql);
	}

	public ArrayList<Map<String, String>> query(String sql) {
		return this.dao.query(sql);
	}

	public ArrayList<Userinfo> queryAll() {
		ArrayList<Map<String, String>> list = this.dao
				.query("select * from Userinfo");
		ArrayList<Userinfo> userinfos = new ArrayList<>();
		for (Map<String, String> map : list) {
			Userinfo userinfo = new Userinfo(map.get("u_username"),
					map.get("u_password"));
			userinfo.setU_id(Integer.parseInt(map.get("u_id")));
			userinfos.add(userinfo);
		}
		return userinfos;
	}

	public int getEntryCounts() {
		List<Map<String, String>> list = this.dao
				.query("select count(*) as ci from Userinfo");
		return Integer.parseInt(list.get(0).get("ci"));
	}
}
