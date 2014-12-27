package org.hope6537.model;

import java.io.Serializable;

/** 
 *<pre>
 *Example 注意建表的时候字段一定要对应上
 *</pre>
 * <p>Describe: </p>
 * <p>Using: </p>
 * <p>DevelopedTime: 2014年10月21日下午7:41:22</p>
 * <p>Company: ChangChun Unviersity JiChuang Team</p>
 * @author Hope6537
 * @version 1.0
 * @see
 */
public class Userinfo implements Serializable {

	/**
	 * <p>Describe: </p>
	 * <p>Using: </p>
	 */

	public Userinfo() {

	}

	@Override
	public String toString() {
		return "Userinfo [u_id=" + u_id + ", u_username=" + u_username
				+ ", u_password=" + u_password + "]";
	}

	private static final long serialVersionUID = -3559649936996399684L;

	private Integer u_id;

	private String u_username;

	private String u_password;

	public Integer getU_id() {
		return u_id;
	}

	public void setU_id(Integer u_id) {
		this.u_id = u_id;
	}

	public String getU_username() {
		return u_username;
	}

	public void setU_username(String u_username) {
		this.u_username = u_username;
	}

	public String getU_password() {
		return u_password;
	}

	public void setU_password(String u_password) {
		this.u_password = u_password;
	}

	public Userinfo(String u_username, String u_password) {
		super();
		this.u_username = u_username;
		this.u_password = u_password;
	}

}
