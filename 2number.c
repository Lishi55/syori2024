#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char moji[50];
char bun[50];
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
	int m = 0;
	ans aaa[500];
	for(int i=0; i <26; i++){
	   for(int j; j < 27; j++){
		aaa[m].alpha[0] ='a' + i;
	      if(j < 26){
		aaa[m].alpha[1] ='a' + j;
	      }else if(j == 26){
	        aaa[m].alpha[1] = 20;
	      }
	      aaa[m].count = 0;
	      m++;
	   }
	}
	printf("%c%c\n",aaa[0].alpha[0],aaa[0].alpha[1]);
	for(int i = 0; i < 26;i++){
	   aaa[m].alpha[0] = 20;
	   aaa[m].alpha[1] = 'a' + i;
	   aaa[m].count = 0;
	   m++;
	}
        int j = 0;

	size_t aaaSize = sizeof(aaa) / sizeof(aaa[0]);

        scanf("%s",moji);

        for(int i = 0;i < 51; i++){
           if(isalpha(moji[i])){
             	   bun[j] = moji[i];
	   j++;
	   }else if(moji[i] == 20){
		    bun[j] = moji[i];
	   j++;
	   }
	}
        printf("%s\n",bun);
	for(int i = 0; i < 51; i++){
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
