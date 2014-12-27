package org.hope6537.view;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
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
import org.eclipse.swt.widgets.Text;
import org.hope6537.model.Userinfo;
import org.hope6537.service.UserinfoService;
import org.hope6537.service.impl.UserinfoServiceImpl;
import org.hope6537.utils.AESLocker;
import org.hope6537.utils.NameValuePair;

import com.alibaba.fastjson.JSONObject;

import org.eclipse.swt.widgets.Table;
import org.eclipse.swt.widgets.TableColumn;
import org.eclipse.swt.widgets.TableItem;
import org.eclipse.swt.widgets.Menu;
import org.eclipse.swt.widgets.MenuItem;

public class MainView {

	protected Shell shell;
	private Text key1;
	private Text key2;
	private Text key3;
	private Text key4;
	private Label dataShowLabel;
	private Text usernameText;
	private Text passwordText;
	private Text _usernameText;
	private Text _passwordText;
	private Table table;

	private UserinfoService userinfoService;
	private Label lblConnectionStatus;
	private Label lblStatementStatus;
	private Label lblPreper;
	private Label lblResultsetStatus;
	private Button updateButton;
	private Button registerButton;
	private Button queryButton;
	private Button createDataBaseButton;
	private MenuItem checkdeleteButton;
	private MenuItem checkupdateButton;
	private Label userIdLabel;

	/**
	 * Launch the application.
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			MainView window = new MainView();
			window.open();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void showMessage(String message) {
		MessageBox messageBox = new MessageBox(shell);
		messageBox.setMessage(message);
		messageBox.setText("System Alert");
		messageBox.open();
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

	/**
	 * Create contents of the window.
	 */
	protected void createContents() {
		shell = new Shell(SWT.CLOSE | SWT.MIN);
		shell.setSize(800, 709);
		shell.setText("I/O Application");

		TabFolder tabFolder = new TabFolder(shell, SWT.NONE);
		tabFolder.setBounds(10, 10, 764, 651);

		TabItem tbtmBrower = new TabItem(tabFolder, SWT.NONE);
		tbtmBrower.setText("Brower");

		Group grpIo = new Group(tabFolder, SWT.NONE);
		grpIo.setText("Data Access Object");
		tbtmBrower.setControl(grpIo);

		Group grpIo_1 = new Group(grpIo, SWT.NONE);
		grpIo_1.setText("I/O");
		grpIo_1.setBounds(10, 36, 736, 188);

		Label lblPutData = new Label(grpIo_1, SWT.NONE);
		lblPutData.setBounds(10, 22, 61, 17);
		lblPutData.setText("Put Data");

		key1 = new Text(grpIo_1, SWT.BORDER);
		key1.setBounds(10, 57, 73, 23);

		key2 = new Text(grpIo_1, SWT.BORDER);
		key2.setBounds(10, 87, 73, 23);

		key3 = new Text(grpIo_1, SWT.BORDER);
		key3.setBounds(10, 116, 73, 23);

		key4 = new Text(grpIo_1, SWT.BORDER);
		key4.setBounds(10, 145, 73, 23);

		Button btnInput = new Button(grpIo_1, SWT.NONE);
		btnInput.addSelectionListener(new OutputAdapter());
		btnInput.setBounds(102, 17, 80, 27);
		btnInput.setText("Write");

		Button btnRead = new Button(grpIo_1, SWT.NONE);
		btnRead.addSelectionListener(new InputAdapter());
		btnRead.setBounds(241, 17, 80, 27);
		btnRead.setText("Read");

		dataShowLabel = new Label(grpIo_1, SWT.NONE);
		dataShowLabel.setBounds(359, 22, 367, 146);
		dataShowLabel.setText("Data Will Show");

		Group grpJson = new Group(grpIo_1, SWT.NONE);
		grpJson.setBounds(102, 66, 228, 102);
		grpJson.setText("JSON");

		Button btnJsonwrite = new Button(grpJson, SWT.NONE);
		btnJsonwrite.addSelectionListener(new JsonOutputAdapter());
		btnJsonwrite.setBounds(10, 27, 80, 27);
		btnJsonwrite.setText("JsonWrite");

		Button btnJsonread = new Button(grpJson, SWT.NONE);
		btnJsonread.addSelectionListener(new JsonInputAdapter());
		btnJsonread.setBounds(138, 27, 80, 27);
		btnJsonread.setText("JsonRead");

		Group grpSql = new Group(grpIo, SWT.NONE);
		grpSql.setText("SQL");
		grpSql.setBounds(10, 230, 736, 381);

		Button btnInitDatabaseconnection = new Button(grpSql, SWT.NONE);
		btnInitDatabaseconnection
				.addSelectionListener(new InitDataBaseConnectionAdapter());
		btnInitDatabaseconnection.setBounds(10, 26, 166, 27);
		btnInitDatabaseconnection.setText("Init DataBaseConnection");

		lblConnectionStatus = new Label(grpSql, SWT.NONE);
		lblConnectionStatus.setBounds(10, 69, 205, 17);
		lblConnectionStatus.setText("Connection Status\uFF1A");

		lblStatementStatus = new Label(grpSql, SWT.NONE);
		lblStatementStatus.setBounds(10, 92, 205, 17);
		lblStatementStatus.setText("StateMent Status\uFF1A");

		lblPreper = new Label(grpSql, SWT.NONE);
		lblPreper.setBounds(10, 115, 205, 17);
		lblPreper.setText("PreperStatement Status:");

		lblResultsetStatus = new Label(grpSql, SWT.NONE);
		lblResultsetStatus.setBounds(10, 138, 205, 17);
		lblResultsetStatus.setText("ResultSet Status:");

		Group grpData = new Group(grpSql, SWT.NONE);
		grpData.setText("Data Insert");
		grpData.setBounds(221, 26, 205, 140);

		Label lblUsername = new Label(grpData, SWT.NONE);
		lblUsername.setBounds(10, 27, 61, 17);
		lblUsername.setText("Username");

		Label lblPassword = new Label(grpData, SWT.NONE);
		lblPassword.setBounds(10, 78, 61, 17);
		lblPassword.setText("Password");

		usernameText = new Text(grpData, SWT.BORDER);
		usernameText.setBounds(10, 49, 73, 23);

		passwordText = new Text(grpData, SWT.BORDER | SWT.PASSWORD);
		passwordText.setBounds(10, 107, 73, 23);

		registerButton = new Button(grpData, SWT.NONE);
		registerButton.setEnabled(false);
		registerButton.addSelectionListener(new RegisterUserinfoAdapter());
		registerButton.setBounds(107, 47, 80, 27);
		registerButton.setText("Register");

		Group grpDataUpdate = new Group(grpSql, SWT.NONE);
		grpDataUpdate.setText("Data Update");
		grpDataUpdate.setBounds(432, 26, 294, 140);

		Label label = new Label(grpDataUpdate, SWT.NONE);
		label.setText("Username");
		label.setBounds(10, 27, 61, 17);

		_usernameText = new Text(grpDataUpdate, SWT.BORDER);
		_usernameText.setBounds(10, 49, 73, 23);

		Label label_1 = new Label(grpDataUpdate, SWT.NONE);
		label_1.setText("Password");
		label_1.setBounds(10, 78, 61, 17);

		_passwordText = new Text(grpDataUpdate, SWT.BORDER);
		_passwordText.setBounds(10, 107, 73, 23);

		updateButton = new Button(grpDataUpdate, SWT.NONE);
		updateButton.addSelectionListener(new UpdateUserinfoAdapter());
		updateButton.setEnabled(false);
		updateButton.setBounds(117, 105, 80, 27);
		updateButton.setText("Update");

		userIdLabel = new Label(grpDataUpdate, SWT.NONE);
		userIdLabel.setBounds(117, 27, 167, 17);
		userIdLabel.setText("UserId is");

		Group grpDataCheck = new Group(grpSql, SWT.NONE);
		grpDataCheck.setText("Data Check");
		grpDataCheck.setBounds(10, 211, 716, 160);

		table = new Table(grpDataCheck, SWT.BORDER | SWT.FULL_SELECTION);
		table.setBounds(10, 25, 521, 125);
		table.setHeaderVisible(true);
		table.setLinesVisible(true);

		TableColumn tblclmnUserid = new TableColumn(table, SWT.NONE);
		tblclmnUserid.setWidth(100);
		tblclmnUserid.setText("userId");

		TableColumn tblclmnUsername = new TableColumn(table, SWT.NONE);
		tblclmnUsername.setWidth(202);
		tblclmnUsername.setText("username");

		TableColumn tblclmnPassword = new TableColumn(table, SWT.NONE);
		tblclmnPassword.setWidth(198);
		tblclmnPassword.setText("password");

		Menu menu = new Menu(table);
		table.setMenu(menu);

		checkupdateButton = new MenuItem(menu, SWT.NONE);
		checkupdateButton.addSelectionListener(new ShowUpdateUserinfoAdapter());
		checkupdateButton.setEnabled(false);
		checkupdateButton.setText("checkUpdate");

		checkdeleteButton = new MenuItem(menu, SWT.NONE);
		checkdeleteButton.setEnabled(false);
		checkdeleteButton.setText("checkDelete");
		checkdeleteButton.addSelectionListener(new DeleteUserinfoAdapter());

		queryButton = new Button(grpSql, SWT.NONE);
		queryButton.setEnabled(false);
		queryButton.addSelectionListener(new ShowUserinfoAdapter());
		queryButton.setBounds(363, 173, 363, 27);
		queryButton.setText("Query Data Now");

		createDataBaseButton = new Button(grpSql, SWT.NONE);
		createDataBaseButton.setEnabled(false);
		createDataBaseButton.setBounds(10, 173, 347, 27);
		createDataBaseButton.setText("Danger! Create New DataBase");
		createDataBaseButton.addSelectionListener(new CreateDatabaseAdapter());

	}

	class RegisterUserinfoAdapter extends SelectionAdapter {
		@Override
		public void widgetSelected(SelectionEvent e) {
			String username = usernameText.getText();
			String password = passwordText.getText();
			if (username.isEmpty() || password.isEmpty()) {
				showMessage("Input Data!");
			} else {
				Userinfo userinfo = new Userinfo(username, password);
				int res = userinfoService.saveEntry(userinfo);
				showMessage(res > 0 ? "Success" : "Failed");
				new ShowUserinfoAdapter().widgetSelected(e);
			}

		}
	}

	class DeleteUserinfoAdapter extends SelectionAdapter {
		@Override
		public void widgetSelected(SelectionEvent e) {
			
			MessageBox messageBox = new MessageBox(shell, SWT.ICON_QUESTION
					| SWT.YES | SWT.NO);
			messageBox.setText("System Alert");
			messageBox.setMessage("Confrim Delete?");
			int message = messageBox.open();
			e.doit = message == SWT.YES;
			if (message == 64) {
				int index = table.getSelectionIndex();
				TableItem item = table.getItem(index);
				String userId = item.getText(0);
				Userinfo userinfo = new Userinfo();
				userinfo.setU_id(Integer.parseInt(userId));
				int res = userinfoService.deleteEntry(userinfo);
				showMessage(res > 0 ? "Success" : "Failed");
				new ShowUserinfoAdapter().widgetSelected(e);
			} else {
				new ShowUserinfoAdapter().widgetSelected(e);
			}
		}
	}

	class ShowUpdateUserinfoAdapter extends SelectionAdapter {

		@Override
		public void widgetSelected(SelectionEvent e) {
			int index = table.getSelectionIndex();
			TableItem item = table.getItem(index);
			String userId = item.getText(0);
			_usernameText.setText(item.getText(1));
			_passwordText.setText(item.getText(2));
			userIdLabel.setText("UserId is " + userId);
			createDataBaseButton.setEnabled(false);
			checkdeleteButton.setEnabled(false);
			checkupdateButton.setEnabled(false);
			queryButton.setEnabled(false);
			registerButton.setEnabled(false);
			updateButton.setEnabled(true);
		}

	}

	class UpdateUserinfoAdapter extends SelectionAdapter {

		@Override
		public void widgetSelected(SelectionEvent e) {
			String userId = userIdLabel.getText().split("is")[1].trim();
			String username = _usernameText.getText();
			String password = _passwordText.getText();
			if (username.isEmpty() || password.isEmpty()) {
				showMessage("Input Data!");
			} else {
				Userinfo userinfo = new Userinfo(username, password);
				userinfo.setU_id(Integer.parseInt(userId));
				int res = userinfoService.updateEntry(userinfo);
				showMessage(res > 0 ? "Success" : "Failed");
				updateButton.setEnabled(false);
				createDataBaseButton.setEnabled(true);
				checkdeleteButton.setEnabled(true);
				checkupdateButton.setEnabled(true);
				queryButton.setEnabled(true);
				registerButton.setEnabled(true);
				new ShowUserinfoAdapter().widgetSelected(e);
				;
			}
		}

	}

	class CreateDatabaseAdapter extends SelectionAdapter {

		@Override
		public void widgetSelected(SelectionEvent e) {
			showMessage("Danger Operate! Not Open Now");
		}
	}

	class ShowUserinfoAdapter extends SelectionAdapter {

		@Override
		public void widgetSelected(SelectionEvent e) {
			table.removeAll();
			List<Userinfo> userinfos = userinfoService.queryAll();
			for (Userinfo userinfo : userinfos) {
				TableItem tableItem = new TableItem(table, SWT.NONE);
				tableItem.setText(new String[] { userinfo.getU_id() + "",
						userinfo.getU_username(), userinfo.getU_password() });
			}
		}
	}

	class InitDataBaseConnectionAdapter extends SelectionAdapter {

		@Override
		public void widgetSelected(SelectionEvent e) {
			System.out.println("Collection Init");
			if (userinfoService == null) {
				userinfoService = new UserinfoServiceImpl();
				lblConnectionStatus.setText(lblConnectionStatus.getText()
						+ " Online");
				lblPreper.setText(lblPreper.getText() + " Online");
				lblResultsetStatus.setText(lblResultsetStatus.getText()
						+ " Online");
				lblStatementStatus.setText(lblStatementStatus.getText()
						+ " Online");

				checkdeleteButton.setEnabled(true);
				checkupdateButton.setEnabled(true);
				createDataBaseButton.setEnabled(true);
				queryButton.setEnabled(true);
				registerButton.setEnabled(true);
			} else {
				showMessage("already init");
			}

		}
	}

	
	//{"name":"value","name2":"value2"}
	
	class JsonOutputAdapter extends SelectionAdapter {

		private OutputStream out;

		@Override
		public void widgetSelected(SelectionEvent e) {
			try {
				out = new FileOutputStream(new File("D:\\2.txt"));
				String value1 = key1.getText();
				String value2 = key2.getText();
				String value3 = key3.getText();
				String value4 = key4.getText();
				JSONObject json = new JSONObject();
				json.put("key1", value1);
				json.put("key2", value2);
				json.put("key3", value3);
				json.put("key4", value4);
				byte[] data = AESLocker.Encrypt(json.toJSONString()).getBytes(
						"UTF-8");
				out.write(data);
			} catch (Exception e1) {
				e1.printStackTrace();
			}
		}
	}

	class JsonInputAdapter extends SelectionAdapter {

		private BufferedReader in;

		@Override
		public void widgetSelected(SelectionEvent e) {
			try {
				in = new BufferedReader(new FileReader(new File("D:\\2.txt")));
				StringBuffer stringBuffer = new StringBuffer();
				String s;
				while ((s = in.readLine()) != null) {
					stringBuffer.append(s);
				}
				String data = AESLocker.Decrypt(stringBuffer.toString());
				//
				JSONObject jsonObject = JSONObject.parseObject(data);
				StringBuffer buffer = new StringBuffer().append("key1")
						.append(":").append(jsonObject.get("key1"))
						.append("\r\n").append("key2").append(":")
						.append(jsonObject.get("key2")).append("\r\n")
						.append("key3").append(":")
						.append(jsonObject.get("key3")).append("\r\n")
						.append("key4").append(":")
						.append(jsonObject.get("key4")).append("\r\n");
				dataShowLabel.setText(buffer.toString());
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
	}

	
	class InputAdapter extends SelectionAdapter {

		private ObjectInputStream in;

		@Override
		public void widgetSelected(SelectionEvent e) {
			try {
				in = new ObjectInputStream(new FileInputStream(new File("D:\\1.txt")));
				@SuppressWarnings("unchecked")
				List<NameValuePair> pairList = (List<NameValuePair>) in.readObject();
				//
				StringBuffer stringBuffer = new StringBuffer();
				for (NameValuePair nameValuePair : pairList) {
					stringBuffer.append(nameValuePair.getName()).append(":")
							.append(nameValuePair.getValue()).append("\r\n");
				}
				dataShowLabel.setText(stringBuffer.toString());
			} catch (Exception e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}
	}

	/**
	 * 1、声明对象输出流对象 找出文件位置
	 * 2、获取Text的值
	 * 3、通过Key和Value的组合生成NameValuePair对象
	 * 4、把这些对象装入List中区
	 * 5、通过out对象的WriteObject方法写入
	 * @author Zhaopeng-Rabook
	 *
	 */
	class OutputAdapter extends SelectionAdapter {

		private ObjectOutputStream out;

		@Override
		public void widgetSelected(SelectionEvent e) {
			try {
				out = new ObjectOutputStream(new FileOutputStream(new File("D:\\1.txt")));
			} catch (FileNotFoundException e1) {
				e1.printStackTrace();
			} catch (IOException e1) {
				e1.printStackTrace();
			}
			String value1 = key1.getText();
			String value2 = key2.getText();
			String value3 = key3.getText();
			String value4 = key4.getText();
			List<NameValuePair> pairList = new ArrayList<>();
			pairList.add(new NameValuePair("key1", value1));
			pairList.add(new NameValuePair("key2", value2));
			pairList.add(new NameValuePair("key3", value3));
			pairList.add(new NameValuePair("key4", value4));
			try {
				out.writeObject(pairList);
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}

		}
	}
}
