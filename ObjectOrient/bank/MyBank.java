package kosta.bank;

public class MyBank {
	private Customer[] customers;
	private static int customersNum;
	
	MyBank(){
		customers = new Customer[20];
		customersNum = 0;
	};
	
	void addCustomer(String id, String  name, long balance) {
		Account account = new Account(id, balance);
		customers[customersNum] = new Customer(id, name, account);
		customersNum++;
	}
	
	static int getCustomersNum() {
		return customersNum;
	}
	Customer getCustomer(String id) {
		int index = 0;
		Customer customerTmp = null;
		while(customersNum != 0) {
			if(id.equals(customers[index].getId())) {
				customerTmp = customers[index];
				break;
			}
			index++;
		}
		return customerTmp;
	}
	
	Customer[] getAllCustomers() {
		return customers;
	}
}
