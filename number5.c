#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


int main(void){

	srand((unsigned int)time(NULL));

        FILE*fp;
	char moji[10000];
	char bun[10000];

	fp = fopen("test.txt","r");
        if(fp == NULL){
		printf("%s file not open!\n","test.txt");
		return -1;
	}
        int i;
	while((moji[i] = fgetc(fp)) != EOF){
	i++;
	}
	fclose(fp);
        
	printf("文の文字数は\n");
        int M = strlen(moji);
	printf("%d\n",M);
        
        int j;
	for(int i = 0;moji[i] != EOF; i++){
           if(isalpha(moji[i])){
             	   bun[j] = moji[i];
	   j++;
	   }else if(moji[i] == 20){
		    bun[j] = moji[i];
	   j++;
	   }else if(moji[i] == 10){
		    bun[j] = moji[i];
           j++;
	   }
	}
	printf("アルファベットのみの文の文字数は\n");
	M = strlen(bun);
	printf("%d\n",M);

        int k; 
        printf("文を生成\n");

        for(int i = 0; i < 101; i++){
           k = rand()%M;
           putchar(bun[k]);
	}

        printf("\n");
		return 0;
}
