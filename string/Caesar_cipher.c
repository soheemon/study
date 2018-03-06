#include<stdio.h>

#define MAXTEXT 50
#define KEY 19
int key; //encryption key
char plaintext[MAXTEXT];
char encryptext[MAXTEXT];

void InputKey();
void Inputtext();
void Encrypt();

void main()
{
	InputKey();
	Inputtext();
	Encrypt();	
}

void InputKey(){
key = KEY;
}
void Inputtext(){
	fputs("Enter Plaintext:",stdout);
	fgets(plaintext,MAXTEXT,stdin);
	fputs(plaintext,stdout);
}
void Encrypt(){

	char* ptr_p = plaintext;
	char* ptr_e = encryptext;

	while(*ptr_p!='\n')
	{
	num_y = ( ((*ptr_p - 'A') + key) % 26); // A~Z = 0~25

	*ptr_e = num_y + 'A';
	ptr_p++;
	ptr_e++;

	}
	fputs(encryptext,stdout);
}
