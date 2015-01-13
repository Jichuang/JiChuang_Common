package com.ccu.BookManage_Model;

import java.awt.List;

public class Book {

	private String BookName;
	private String AuthorName;
	private String Price;
	
	public Book(String BookName, String AuthorName, String Price) {
		this.BookName = BookName;
		this.AuthorName = AuthorName;
		this.Price = Price;
	}
	
	public String getBookName() {
		return BookName;
	}

	public String getAuthorName() {
		return AuthorName;
	}

	public String getPrice() {
		return Price;
	}
}