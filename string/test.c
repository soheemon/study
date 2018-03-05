#include<stdio.h>
#define MAXLINE 3
void input();
void output();
char* str_in[MAXLINE];
void main(){
input();
output();	
}

void input(){

	int i;
	for(i = 0;i < MAXLINE;i++){
	str_in[i] = (char*) malloc
	fgets(str_buff,sizeof(str_buff),stdin);
	}

}

void output(){
	int i;
	for(i = 0; i < MAXLINE; i++){
	fputs(str_in[i],stdout);
	}
}
