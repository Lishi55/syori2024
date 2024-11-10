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
	   }else if(moji[i] == ' '){
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
        

        int k,A,B,C,kd,h; 
        printf("文を生成\n");

           k = rand()%M;
           putchar(bun[k]);
	   putchar(bun[k+1]);
	   putchar(bun[k+2]);
           A = bun[k+1];
           h = 1;
	   while(h == 1){
              kd = rand()%M;
	   for(int j = kd;j < (M+1);j++){
	   if(bun[j] == A){
		   putchar(bun[j+1]);
	           B = bun[j+1];
		   h = 10;
	   }
	   if(h == 10){
	   j = M+1;
	   }
	   }
	   }
           for(int i = 0; i < 30;i++){
		   h = 5;
	   while(h == 5){
	      kd = rand()%M;
	    for(int g = kd;g < (M+1);g++){
	     if(bun[g] == A){
	       if(bun[g + 1] == B){
		   if(isalpha(bun[g + 2])){
		     putchar(bun[g + 2]);
	             h = 2;
	             A = bun[g+1];
                     B = bun[g+2];
		   }else if(bun[g + 2] == ' '){
		     putchar(bun[g + 2]);
                     h = 2;
                     A = bun[g+1];
                     B = bun[g+2];
		   }
	        }
	     }
	      if(h == 2){
                g = M+1;
              }//aa
            }
	   }
	   }
	   
           
        printf("\n");
		return 0;
}
