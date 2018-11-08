package scoreManagement;

public class Class {
	Student[] studentmember;
	private int numberOfPersons;
	private int indexOfStudent;
	
	Class() {};
	
	public Class(int numberOfPersons) { // ScoreMain에서 생성 필요
		this.numberOfPersons = numberOfPersons;
		studentmember = new Student[this.numberOfPersons];
	}
	
	public Student addStudent(String name, Score score) { //호출시 학생 추가
		Student student = new Student(name, score);
		indexOfStudent++;
		return student;
	}
	public Student showStudent(String name) {
		Student result = null;
		
		for(int index = 0; studentmember[index] != null; index++) {
			if(name.equals(studentmember[index].name)) {
				result = studentmember[index];
			}
		}
		return result;
	}
	public Student[] sortStudent() {
		if(indexOfStudent != 0) {
			Student tmp = null;
			Student[] newArr = new Student[numberOfPersons];
			
			for(int index = 0; studentmember[index] != null; index++) {
				newArr[index] = studentmember[index];//null전까지 전부 복사한다.
			}
			
			for(int key = 0; newArr[key] != null; key++) {
				for(int index = key; newArr[index] != null; index++) {
					if(newArr[key].getScore().average < newArr[index].getScore().average) { // 평균만 바꿀게 아니라 배열전체를 바꿔야행..
						tmp = newArr[key];
						newArr[key] = newArr[index];
						newArr[index] = tmp;
					}
				}
			}
			return newArr; // 정렬된 상태의 새 배열을 return
		}else {
			return null;
		}
	}
	public Student[] getAllStudents() {
		Student[] newArr = new Student[numberOfPersons];
		for(int index = 0; studentmember[index] != null; index++) {
			newArr[index] = studentmember[index];//null전까지 전부 복사한다.
		}
		return newArr;
		
		
	}

	public Student[] getStudentmember() {
		return studentmember;
	}

	public void setStudentmember(Student[] studentmember) {
		this.studentmember = studentmember;
	}

	public int getNumberOfPersons() {
		return numberOfPersons;
	}

	public void setNumberOfPersons(int numberOfPersons) {
		this.numberOfPersons = numberOfPersons;
	}

	public int getIndexOfStudent() {
		return indexOfStudent;
	}

	public void setIndexOfStudent(int indexOfStudent) {
		this.indexOfStudent = indexOfStudent;
	}
}
