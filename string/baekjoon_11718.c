#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 3
#define MAXCHAR 20

char* str_in[MAXLINE];
char str_buff[MAXCHAR];
void input();
void output();

void main(){
input();
output();	
}

void input(){

	int i;
	for(i = 0;i < MAXLINE;i++){
	str_in[i] = (char*) malloc (MAXCHAR);
	fgets(str_in[i],MAXCHAR,stdin);
	}

}

void output(){
	int i;
	for(i = 0; i < MAXLINE; i++){
	fputs(str_in[i],stdout);
	free(str_in[i]);
	}
}
