#include<ctype.h>
#include<stdio.h>

char moji[1000];
int main(void){
	FILE * fp = NULL;

	fp = fopen("test.txt", "r");

	for(int i = 0; i <1001;i++){
	moji[i] = fgetc(fp);
	}

        for(int i = 0; i < 1001;i++){
	 if(isalpha(moji[i]))
		printf("%c",moji[i]);
	else if(moji[i] == 10)
	        printf("%c",moji[i]);
	else if(moji[i] == 17)
		printf("%c",moji[i]);
	}
	printf("\n");
	return 0;

	}
