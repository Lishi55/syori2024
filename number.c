#include<ctype.h>
#include<stdio.h>

char moji[50];
int main(void){
        scanf("%s",moji);

        for(int i = 0; i < 50;i++){
		if(isalpha(moji[i]))
		printf("%c",moji[i]);
	}
	printf("\n");
	return 0;

	}
