package org.hope6537.service;

import java.util.List;

public interface BaseService<T> {

	int saveEntry(T t);

	int updateEntry(T t);

	int deleteEntry(T t);

	T getEntryByPrimaryKey(int id);

	List<T> getEntryBySQL(String sql, List<Object> params);


}
