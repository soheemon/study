package baseballgame;

import java.util.Scanner;

public class UserInput {
	Scanner userinput;
	String result[] ;
	
	public UserInput() {
		userinput = new Scanner(System.in);
		result = new String[3];
	}
	public String[] UserInputString() {
		for(int index = 0; index < 3; index++) {
			result[index] = userinput.next();
		}
		return result;
	}
}
