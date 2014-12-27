package org.hope6537.service;

import java.util.ArrayList;
import java.util.Map;

import org.hope6537.model.Userinfo;

public interface UserinfoService extends BaseService<Userinfo> {

	void createDataBase();

	ArrayList<Map<String, String>> query(String sql);

	ArrayList<Userinfo> queryAll();

	public int getEntryCounts();
}
