package org.hope6537.test;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import org.hope6537.model.Userinfo;
import org.hope6537.service.UserinfoService;
import org.hope6537.service.impl.UserinfoServiceImpl;
import org.junit.Test;

public class UserinfoController {

	private UserinfoService userinfoService = new UserinfoServiceImpl();

	@Test
	public void testString() {
		String str = "test";
		str += '1';
	}

	@Test
	public void testCreate() {
		userinfoService.createDataBase();
	}

	@Test
	public void testSave() {
		for (int i = 1; i <= 5; i++) {
			Userinfo userinfo = new Userinfo("username" + i, "password" + i);
			userinfoService.saveEntry(userinfo);
		}
	}

	@Test
	public void testUpdate() {
		Userinfo userinfo = userinfoService.getEntryByPrimaryKey(2);
		userinfo.setU_password("newPassword");
		userinfoService.updateEntry(userinfo);
	}

	@Test
	public void testQuery() {
		Userinfo userinfo = userinfoService.getEntryByPrimaryKey(2);
		System.out.println("[SimpleUserinfo] " + userinfo.toString());
		List<Userinfo> list = userinfoService.getEntryBySQL(
				"select * from Userinfo", null);
		for (Userinfo u : list) {
			System.out.println("[ListQuery] " + u.toString());
		}
	}

	@Test
	public void testClassicQuery() {
		String sql = "select * from userinfo where u_username like '%2%'";
		ArrayList<Map<String, String>> list = this.userinfoService.query(sql);
		for (int i = 0; i < list.size(); i++) {
			String id = list.get(i).get("u_id");
			String username = list.get(i).get("u_username");
			String password = list.get(i).get("u_password");
			System.out.println("[ClassicQuery] " + id + " " + username + " "
					+ password);
		}
	}

	@Test
	public void testQueryCount() {
		int count = userinfoService.getEntryCounts();
		System.out.println("[count] " + count);
	}

}
