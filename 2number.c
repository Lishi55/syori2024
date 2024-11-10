#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char moji[10000];
char bun[10000];
typedef struct{
char alpha[2];
short count;
} ans;
int nara(const void * n1, const void * n2)
{
	if (((ans *)n1)->count > ((ans *)n2)->count)
	{
		return -1;
	}
	else if (((ans *)n1)->count < ((ans *)n2)->count)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void){
	FILE*fp;

	int m = 0;
	ans aaa[730];
	for(int i=0; i <26; i++){
	   for(int j = 0; j < 27; j++){
		aaa[m].alpha[0] ='a' + i;
	      if(j < 26){
		aaa[m].alpha[1] ='a' + j;
	      }
	      if(j == 26){
	        aaa[m].alpha[1] = ' ';
	      }
	      aaa[m].count = 0;
	      m++;
	   }
	}
	printf("%c%c\n",aaa[0].alpha[0],aaa[0].alpha[1]);
	for(int i = 0; i < 26;i++){
	   aaa[m].alpha[0] = ' ';
	   aaa[m].alpha[1] = 'a' + i;
	   aaa[m].count = 0;
	   m++;
	}
        int j = 0;

	size_t aaaSize = sizeof(aaa) / sizeof(aaa[0]);

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

        for(int i = 0;moji[i] != EOF; i++){
           if(isalpha(moji[i])){
             	   bun[j] = moji[i];
	   j++;
	   }else if(moji[i] == ' '){
		    bun[j] = moji[i];
	   j++;
	   }
	}

	for (i=0 ; i < strlen(bun) ; i++){
	bun[i] = tolower(bun[i]);
	}
	
        printf("%s\n",bun);
	for(int i = 0; i < strlen(bun); i++){
		for(int j = 0; j < (m + 1); j++)
                  if(bun[i] == aaa[j].alpha[0]){
			  if(bun[i + 1] == aaa[j].alpha[1]){
			  aaa[j].count++;
			  }
	}
	}
	qsort(aaa, aaaSize, sizeof(ans), nara);
        for(int j = 0; j < 30;j++){
           printf("%c%c,%d\n",aaa[j].alpha[0],aaa[j].alpha[1],aaa[j].count);
        }
        printf("\n");
        return 0;
    }
