package com.ccu.BookManage_view;

import java.util.ArrayList;
import java.util.List;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.TabFolder;
import org.eclipse.swt.widgets.TabItem;
import org.eclipse.swt.widgets.Table;
import org.eclipse.swt.widgets.TableColumn;
import org.eclipse.swt.widgets.TableItem;
import org.eclipse.swt.widgets.Text;
import org.eclipse.wb.swt.SWTResourceManager;

import com.ccu.BookManage_Model.Book;

public class BookManage_View {

	protected Shell shell;
	private Text BookNameText;
	private Text AuthorNameText;
	private Text PriceText;
	List<Book> book = new ArrayList<Book>();
	private Table table;
	private Text BookNameDeltext;
	private Text BookNameSearchtext;
	private Text BookNameChangetext;
	private Text AuthorNameChangetext;
	private Text PriceChangetext;
	private int b = 0;

	public static void main(String[] args) {
		try {
			BookManage_View window = new BookManage_View();
			window.open();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * Open the window.
	 */
	public void open() {
		Display display = Display.getDefault();
		createContents();
		shell.open();
		shell.layout();
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch()) {
				display.sleep();
			}
		}
	}

	public void box(Boolean judge) {
		MessageBox box = new MessageBox(shell);
		box.setText("温馨提示");
		if (judge) {
			box.setMessage("添加成功！");
		} else {
			box.setMessage("请填写完整信息！");
		}
		box.open();
	}

	public void boxdel(Boolean judge) {
		MessageBox box = new MessageBox(shell);
		box.setText("温馨提示");
		if (judge) {
			box.setMessage("删除成功！");
		} else {
			box.setMessage("未找到该图书！");
		}
		box.open();
	}

	public void boxchange(int judge) {
		MessageBox box = new MessageBox(shell);
		box.setText("温馨提示");
		switch (judge) {
		case 1:
			box.setMessage("修改成功！");
			break;
		case 2:
			box.setMessage("请填写完整信息！");
			break;
		case 3:
			box.setMessage("书名与其他书相同！");
			break;
		}
		box.open();
	}

	/**
	 * Create contents of the window.
	 */
	protected void createContents() {
		shell = new Shell();
		shell.setSize(700, 500);
		shell.setText("图书管理系统");

		TabFolder tabFolder = new TabFolder(shell, SWT.NONE);
		tabFolder.setBounds(0, 64, 684, 397);

		TabItem AddtabItem = new TabItem(tabFolder, SWT.NONE);
		AddtabItem.setText("图书添加");

		Group Addgroup = new Group(tabFolder, SWT.NONE);
		AddtabItem.setControl(Addgroup);

		Label BookName = new Label(Addgroup, SWT.NONE);
		BookName.setBounds(141, 60, 61, 17);
		BookName.setText("书名");

		Label AuthorName = new Label(Addgroup, SWT.NONE);
		AuthorName.setBounds(141, 105, 61, 17);
		AuthorName.setText("作者");

		Label Price = new Label(Addgroup, SWT.NONE);
		Price.setBounds(141, 150, 61, 17);
		Price.setText("价格");

		BookNameText = new Text(Addgroup, SWT.BORDER);
		BookNameText.setBounds(210, 60, 73, 23);

		AuthorNameText = new Text(Addgroup, SWT.BORDER);
		AuthorNameText.setBounds(210, 105, 73, 23);

		PriceText = new Text(Addgroup, SWT.BORDER);
		PriceText.setBounds(208, 150, 73, 23);

		Button Add = new Button(Addgroup, SWT.NONE);
		Add.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				if (BookNameText.getText() != ""
						&& AuthorNameText.getText() != ""
						&& PriceText.getText() != "") {
					book.add(new Book(BookNameText.getText(), AuthorNameText
							.getText(), PriceText.getText()));
					BookNameText.setText("");
					AuthorNameText.setText("");
					PriceText.setText("");
					box(true);
				} else {
					box(false);
				}
			}
		});
		Add.setBounds(320, 150, 80, 27);
		Add.setText("添加");

		TabItem SearchtabItem = new TabItem(tabFolder, SWT.NONE);
		SearchtabItem.setText("查询列表");

		Group Searchgroup = new Group(tabFolder, SWT.NONE);
		SearchtabItem.setControl(Searchgroup);

		table = new Table(Searchgroup, SWT.BORDER | SWT.FULL_SELECTION);
		table.setBounds(10, 57, 656, 300);
		table.setHeaderVisible(true);
		table.setLinesVisible(true);

		TableColumn BookNameColumn = new TableColumn(table, SWT.NONE);
		BookNameColumn.setWidth(218);
		BookNameColumn.setText("书名");

		TableColumn AuthorNameColumn = new TableColumn(table, SWT.NONE);
		AuthorNameColumn.setWidth(218);
		AuthorNameColumn.setText("作者");

		TableColumn PriceColumn = new TableColumn(table, SWT.NONE);
		PriceColumn.setWidth(218);
		PriceColumn.setText("价格");

		Button button = new Button(Searchgroup, SWT.NONE);
		button.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				table.removeAll();
				for (Book book : book) {
					TableItem tableItem = new TableItem(table, SWT.NONE);
					tableItem.setText(new String[] { book.getBookName(),
							book.getAuthorName(), book.getPrice() });
				}
			}
		});
		button.setBounds(586, 24, 80, 27);
		button.setText("刷新");

		TabItem ChangetabItem = new TabItem(tabFolder, SWT.NONE);
		ChangetabItem.setText("更改信息");

		Group Changegroup = new Group(tabFolder, SWT.NONE);
		ChangetabItem.setControl(Changegroup);

		Label BookNameChange = new Label(Changegroup, SWT.NONE);
		BookNameChange.setBounds(10, 23, 61, 17);
		BookNameChange.setText("输入书名");

		BookNameSearchtext = new Text(Changegroup, SWT.BORDER);
		BookNameSearchtext.setBounds(85, 20, 73, 23);

		Button SearchButton = new Button(Changegroup, SWT.NONE);
		SearchButton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				// b用于判断 链表中与输入的书名相同的元素在链表中的位置
				b = 0;
				for (Book book : book) {
					if (book.getBookName().equals(BookNameSearchtext.getText())) {
						BookNameChangetext.setText(book.getBookName());
						AuthorNameChangetext.setText(book.getAuthorName());
						PriceChangetext.setText(book.getPrice());
						b++;
						break;
					} else {
						b++;
					}
				}
			}
		});
		SearchButton.setBounds(191, 18, 80, 27);
		SearchButton.setText("搜索");

		Label BookNameSearch = new Label(Changegroup, SWT.NONE);
		BookNameSearch.setBounds(149, 86, 61, 17);
		BookNameSearch.setText("书名");

		Label AuthorNameSearch = new Label(Changegroup, SWT.NONE);
		AuthorNameSearch.setBounds(149, 128, 61, 17);
		AuthorNameSearch.setText("作者");

		Label BookPriceSearch = new Label(Changegroup, SWT.NONE);
		BookPriceSearch.setBounds(149, 170, 61, 17);
		BookPriceSearch.setText("价格");

		BookNameChangetext = new Text(Changegroup, SWT.BORDER);
		BookNameChangetext.setBounds(224, 83, 73, 23);

		AuthorNameChangetext = new Text(Changegroup, SWT.BORDER);
		AuthorNameChangetext.setBounds(224, 125, 73, 23);

		PriceChangetext = new Text(Changegroup, SWT.BORDER);
		PriceChangetext.setBounds(224, 167, 73, 23);

		Button ChangeButton = new Button(Changegroup, SWT.NONE);
		ChangeButton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				// a用于判断 链表中与输入的书名相同的个数
				int a = 0;
				for (Book book : book) {
					if (BookNameChangetext.getText().equals(book.getBookName())) {
						a++;
					}
				}
				if (a == 1) {
					boxchange(3);
				} else if (!(BookNameChangetext.getText().equals("")
						|| AuthorNameChangetext.getText().equals("") || PriceChangetext
						.getText().equals(""))) {
					book.set(b - 1,
							new Book(BookNameChangetext.getText(),
									AuthorNameChangetext.getText(),
									PriceChangetext.getText()));
					BookNameSearchtext.setText("");
					BookNameChangetext.setText("");
					AuthorNameChangetext.setText("");
					PriceChangetext.setText("");
					boxchange(1);
				} else {
					boxchange(2);
				}
			}
		});
		ChangeButton.setBounds(308, 209, 80, 27);
		ChangeButton.setText("确定修改");

		TabItem DeletetabItem = new TabItem(tabFolder, SWT.NONE);
		DeletetabItem.setText("删除图书");

		Group Deletegroup = new Group(tabFolder, SWT.NONE);
		DeletetabItem.setControl(Deletegroup);

		BookNameDeltext = new Text(Deletegroup, SWT.BORDER);
		BookNameDeltext.setBounds(222, 145, 90, 23);

		Label BookNameDel = new Label(Deletegroup, SWT.NONE);
		BookNameDel.setBounds(161, 148, 61, 17);
		BookNameDel.setText("输入书名");

		Button Delete = new Button(Deletegroup, SWT.NONE);
		Delete.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				// a用于判断 链表中与输入的书名相同的元素在链表中的位置
				// c用于判断是否有相同的书名
				int a = 0, c = 0;
				for (Book book : book) {
					if (book.getBookName().equals(BookNameDeltext.getText())) {
						c = 1;
						break;
					} else {
						a++;
					}
				}
				if (c != 0) {
					book.remove(a);
					boxdel(true);
				} else {
					boxdel(false);
				}
			}
		});
		Delete.setBounds(338, 143, 80, 27);
		Delete.setText("删除");

		Label lblNewLabel = new Label(shell, SWT.SHADOW_IN | SWT.CENTER);
		lblNewLabel.setFont(SWTResourceManager.getFont("楷体", 24, SWT.BOLD));
		lblNewLabel.setForeground(SWTResourceManager
				.getColor(SWT.COLOR_DARK_GREEN));
		lblNewLabel.setBounds(136, 10, 377, 48);
		lblNewLabel.setText("欢迎使用图书管理系统");
	}
}