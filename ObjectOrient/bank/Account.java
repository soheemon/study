package kosta.bank;

public class Account {
	private String id;
	private long balance;
	
	Account(){};
	
	Account(String id, long balance) {
		this.id = id;
		this.balance = balance;
	}
	void deposit(long amt) {
		this.balance += amt;
	}
	boolean withdraw(long amt) { // 출금시 잔액 비교하여 가능하다면 true 불가능하다면 false를 return.
		if(balance < amt) { //출금할 금액이 잔액보다 크다면.
			return false;
		}else {
			balance -= amt;
			return true;
		}
	}
	String getId() {
		return id;
	}
	long getBalance() {
		return balance;
	}
}
