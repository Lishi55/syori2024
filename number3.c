#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char moji[50];

typedef struct{
char alpha[1];
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
	ans aaa[25];
	for(int i=0; i <26; i++){	
	        aaa[i].alpha[0] ='a' + i;
		aaa[i].count = 0;
	}
	size_t aaaSize = sizeof(aaa) / sizeof(aaa[0]);
        scanf("%s",moji);
        for(int i = 0; i < 51;i++){
                if(isalpha(moji[i])){
                for(int j=0; j <26; j++){
                  if(moji[i] == aaa[j].alpha[0]){
                  aaa[j].count++;
                  }
                }
                }
        }
	qsort(aaa, aaaSize, sizeof(ans), nara);
        for(int j = 0; j <26;j++){
           printf("%c,%d\n",aaa[j].alpha[0],aaa[j].count);
        }
        printf("\n");
        return 0;
    }
