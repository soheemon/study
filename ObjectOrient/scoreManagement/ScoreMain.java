package scoreManagement;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import kosta.bank.Customer;
import kosta.bank.MyBank;

public class ScoreMain {
	Class classGurum; // 한 반 생성
	
	public ScoreMain() {
		classGurum = new Class(30);
		showMenu();
	}
	
	public void showMenu() { // show method 만들기
		String name = null;
		int math = 0,
			korean = 0,
			english = 0;
		
		String menu = null;
		Score score = null;
		Student result = null;
		do {

			System.out.println("****메뉴를 입력하세요****");
			System.out.println("1. 학생추가");
			System.out.println("2. 학생정보보기(이름으로 검색)");
			System.out.println("3. 학생전체보기");
			System.out.println("4. 평균으로 등수 나열하기");
			System.out.println("q.***끝내기***");
			System.out.println("***************");
			System.out.print(">>");

			menu = readFromKeyboard();

			if (menu.equals("1")) { // 학생추가

				System.out.print("학생 이름을 입력하세요: ");
				name =  readFromKeyboard();

				System.out.print("국어점수를 입력하세요: ");
				korean = Integer.parseInt(readFromKeyboard()); 

				System.out.print("수학점수를 입력하세요: ");
				math = Integer.parseInt(readFromKeyboard()); 
				
				
				System.out.print("영어점수를 입력하세요: ");
				english = Integer.parseInt(readFromKeyboard()); 
				
				score = new Score(korean, math, english);

				classGurum.studentmember[classGurum.getIndexOfStudent()] = classGurum.addStudent(name, score); //구름반_n번째학생의객체_
			} else if (menu.equals("2")) { // 학생 한명 보기
				System.out.print("학생 이름을 입력하세요: ");
				name = readFromKeyboard();
				result  = classGurum.showStudent(name); // 이름으로 학생 검색해서 Student return.
				if(result != null) {
					System.out.println("이름 영어 수학 국어");
					System.out.println(result.name + result.getScore().english + result.getScore().math + result.getScore().korean);
				}else {
					System.out.println("등록된 학생이 없습니다!");
				}
			} else if (menu.equals("3")) { // 학생 전체보기

				Student[] allStudent = classGurum.getAllStudents(); // 배열 개수찾기.
				System.out.println("이름 영어 수학 국어");
				for (int i = 0; allStudent[i] != null; i++) {
					System.out.println(allStudent[i].getName() + ": " + allStudent[i].getScore().english + " :"
							+ allStudent[i].getScore().korean + ":" + allStudent[i].getScore().math);
				}

			} else if (menu.equals("4")) { // 평균으로 등수 나열하기

				Student[] listOfStudent = classGurum.sortStudent();
				if(listOfStudent != null) {
					for (int i = 0;  listOfStudent[i] != null; i++) {
						System.out.println((i) + "등 :" + listOfStudent[i].getName() + "점수:" +  listOfStudent[i].getScore().average + "점");
					}
				}else {
					System.out.println("등록된 학생이 없습니다!");
				}
			}
		} while (!menu.equals("q")); // 종료
	}

	public String readFromKeyboard() {
		String input = null;
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			input = br.readLine();
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
		return input;
	}
	
	public static void main(String[] args) {
		ScoreMain appStart = new ScoreMain();
	}
}
