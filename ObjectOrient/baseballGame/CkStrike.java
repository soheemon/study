package baseballgame;

public class CkStrike {
	enum gamestatus {
		GAME_EXIT, GAME_CONTINUE
	}
	public CkStrike() {
	}// 배열을 입력받아서 1. 각 자리마다 비교 2. 동일한 수가 몇개있는지 비교 하자.
	public gamestatus ckgame(String[] randomInput, String[] userInput) {
		int[] strikeIndex = new int[3]; // 매번 초기화 해야 하므로 필드가 아니라 지역변수로 선언.
		int strike = 0,
				ball = 0;
		gamestatus result = null;

		for(int index = 0; index < 3; index++) {
			if(randomInput[index].equals(userInput[index])) {
				strike++;
				strikeIndex[index] = 1; // 현재 index가 strike로 체크한다. strike와 ball이 중복되지 않게하기 위함.
				//같은 자리수끼리 비교한다.
			}
		}
		if(strike == 3) {
			result = CkStrike.gamestatus.GAME_EXIT;
			return result;
		}
		
		for(int key = 0; key < 3; key++) { //3개의 숫자를 9회 비교한다
			if(strikeIndex[key] == 1) {//현재 인덱스가 스트라이크라면. ball로 집계하지않기위해 countinue.
				continue;
			}
			for(int index = 0; index < 3; index++) {
				if(randomInput[key].equals(userInput[index])) {
					ball++;
				}
			}
		}
		System.out.println("게임 스코어는 " + strike+ "스트라이크" + ball + "볼" + "입니다.");
		result = CkStrike.gamestatus.GAME_CONTINUE;
		return result;
	}
}
