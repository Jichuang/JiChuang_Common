package org.hope6537.service.impl;

import java.lang.reflect.ParameterizedType;
import java.util.List;

import org.hope6537.dao.BaseDaoUtil;
import org.hope6537.service.BaseService;

public class BaseServiceImpl<T> implements BaseService<T> {

	protected BaseDaoUtil<T> dao;

	public BaseServiceImpl(BaseDaoUtil<T> dao) {
		this.dao = dao;
	}

	public BaseServiceImpl() {

	}

	public int saveEntry(T t) {
		return this.dao.saveByPrepared(t);
	}

	public int updateEntry(T t) {
		return this.dao.updateByPrepared(t);
	}

	public int deleteEntry(T t) {
		return this.dao.deleteByPrepared(t);
	}

	public T getEntryByPrimaryKey(int id) {
		return this.dao.getEntryByPrimaryKey(id);
	}

	public List<T> getEntryBySQL(String sql, List<Object> params) {
		ParameterizedType type = (ParameterizedType) this.getClass()
				.getGenericSuperclass();
		@SuppressWarnings("unchecked")
		Class<T> clz = (Class<T>) type.getActualTypeArguments()[0];
		return this.dao.findRef(sql, params, clz);
	}

}
