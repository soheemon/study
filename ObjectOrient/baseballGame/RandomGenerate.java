package baseballgame;

public class RandomGenerate { // 호출시마다 랜덤한 수 3개를 String배열로 넘겨준다.

	public String[] oneToNine() {
		String[] ret = new String[3];
		int[] tmp = new int[3];
		boolean samenumber; 

		do {
			samenumber = true; // 이 값을 계속 유지한다면 바뀌지 않았다는거니까! (같은 숫자가 안나왔다는 거니까.)
			for(int index = 0; index < 3; index ++) {
				tmp[index] = (int)(Math.random() * 9) + 1; // 숫자 3개를 구한다. 
			}
			
			for(int key = 0; key < 3; key++) {
			for(int index = key+1; index < 3; index++) { // 숫자 3개를 비교한다.

				if(tmp[key] == tmp[index]) {
					samenumber = false;// 다시 반복해야 한다. 즉 false일때 무한반복!
				}
				}
			}
		}while(samenumber != true); // false면 무한반복. true면 끝난다.

		for(int index = 0; index < 3; index ++) { // 같은 숫자가 없을경우 String으로 전환한다.
				ret[index] = Integer.toString(tmp[index]);
			}	
		return ret;
	}
}
