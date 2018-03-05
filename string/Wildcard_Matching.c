/*
Problem : Implement wildcard pattern matching with support for '?' and '*'.
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence)
The matching should cover the entire input string (not partial).

*/
#include <stdio.h>
typedef enum {false, true} bool;
bool isMatch(char* TestData, char* UserData);
void result(bool test);
void main()
{
bool test;

test = isMatch("aa","a");
result(test);
test = isMatch("aa","aa");
result(test);
test = isMatch("aaa","aa");
result(test);
test = isMatch("aa","*");
result(test);
test = isMatch("aa","a*");
result(test);
test = isMatch("ab","?*");
result(test);
test = isMatch("aab", "c*a*b");
result(test);
}

bool isMatch(char* TestData, char* UserData){
	int i = 0;
	

	while( !((TestData[i] == '\n') || (UserData[i] == '\n')) ){
	if(TestData[i] != UserData[i]) {
	if(UserData[i] == '*'){return true;}
	else if(UserData[i] == '?'){;}
	else {return false;}
	}
	i++;
	}

	if ( ((TestData[i] == '\n') ^ (UserData[i] == '\n')) ){return false;} else {return true;} 

	
}

void result(bool test){
	if(test){printf("true\n");}
	else {printf("false\n");}
}
