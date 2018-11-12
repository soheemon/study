package baseballgame;

public class GameStart {
	
	RandomGenerate value;
	UserInput user;
	CkStrike ckStrike;
	RandomGenerate random;
	
	public GameStart() {
		ckStrike = new CkStrike();
		user = new UserInput();
		random = new RandomGenerate();
		playGame();
	}

	public void playGame() {
		CkStrike.gamestatus res = null;
		do {
			String[] ran = random.oneToNine();
			System.out.println("랜덤 숫자가 생성되었습니다.");
			System.out.println("숫자 세개를 입력해 주세요.");
			String[] userInput = user.UserInputString();
			
			res = ckStrike.ckgame(ran, userInput);

			switch (res) {
			case GAME_CONTINUE:
				System.out.println("랜덤숫자: "+ ran[0] + ran[1] + ran[2]);
				System.out.println("사용자숫자: "+ userInput[0] + userInput[1] + userInput[2]);
				System.out.println("게임을 계속합니다..");
				break;
			case GAME_EXIT:
				System.out.println("랜덤숫자: "+ ran[0] + ran[1] + ran[2]);
				System.out.println("사용자숫자: "+ userInput[0] + userInput[1] + userInput[2]);
				System.out.println("게임을 종료합니다!");
				break;
			}
		}while(res != CkStrike.gamestatus.GAME_EXIT);
	}
}
