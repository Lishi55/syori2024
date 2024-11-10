#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char moji[13000];
char bun[13000];
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
	ans aaa[680];
	for(int i=0; i <26; i++){
	   for(int j = 0; j < 26; j++){
		aaa[m].alpha[0] ='a' + i;
	      if(j < 26){
		aaa[m].alpha[1] ='a' + j;
	      }
	      aaa[m].count = 0;
	      m++;
	   }
	}
	printf("%c%c\n",aaa[0].alpha[0],aaa[0].alpha[1]);
        int j = 0;

	size_t aaaSize = sizeof(aaa) / sizeof(aaa[0]);

        fp = fopen("test.txt","r");
        if(fp == NULL){
		printf("%s file not open!\n","test.txt");
		return -1;
	}
        int i = 0;
	int c;
	while ((c = fgetc(fp)) != EOF){
	moji[i++] = c;
	}
	fclose(fp);
	printf("%s\n",moji);
	for (i=0 ; i < strlen(moji) ; i++){
	moji[i] = tolower(moji[i]);
	}
	printf("\n\n\n");
        printf("%s\n",moji);
	for(int i = 0; i < strlen(moji); i++){
		for(int j = 0; j < (m + 1); j++)
                  if(moji[i] == aaa[j].alpha[0]){
			  if(moji[i + 1] == aaa[j].alpha[1]){
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
