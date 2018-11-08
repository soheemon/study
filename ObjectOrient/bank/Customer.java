package kosta.bank;

public class Customer {
	private String id,
			name;
	private Account account;
	
	Customer() {
		// TODO Auto-generated constructor stub
	};
	
	Customer(String id, String name, Account account) {
		this.id = id;
		this.name = name;
		this.account = account;
	}
	void setAccount(Account account) {
		this.account = account;
	}
		
	Account getAccount() {
		return this.account;
	}
	String getId() {
		return id;
	}
	void setName(String name) {
		this.name = name;
	}
	String getName() {
		return name;
	}
}
