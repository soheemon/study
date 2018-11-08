package scoreManagement;

public class Score {

	int korean,
		math,
		english,
		average;
	
	public Score(int korean, int math, int english) {
		this.korean = korean;
		this.math = math;
		this.english = english;

		average = (korean + math + english)/3;
	}
	
	public int getKorean() {
		return korean;
	}

	public void setKorean(int korean) {
		this.korean = korean;
	}

	public int getMath() {
		return math;
	}

	public void setMath(int math) {
		this.math = math;
	}

	public int getEnglish() {
		return english;
	}

	public void setEnglish(int english) {
		this.english = english;
	}

	public int getAverage() {
		return english;
	}
	

}
