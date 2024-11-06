#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char moji[1000];

typedef struct{
char alpha[5];
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
	ans aaa[] = {{"a", 0}, {"b", 0}, {"c", 0},{"d", 0},{"e", 0},{"f", 0},{"g", 0},{"h", 0},{"i", 0},{"j", 0},{"k", 0},
	{"l", 0},{"m", 0},{"n", 0},{"o", 0},{"p", 0},{"q", 0},{"r", 0},{"s", 0},{"t", 0},{"u", 0},
	{"v", 0},{"w", 0},{"x", 0},{"y", 0},{"z", 0},};
	size_t aaaSize = sizeof(aaa) / sizeof(aaa[0]);
        
        FILE * fp = NULL;

	fp = fopen("test.txt", "r");

	for(int i = 0; i <1001;i++){
	moji[i] = fgetc(fp);
	}

        for(int i = 0; i < 1001;i++){
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
           printf("%s,%d\n",aaa[j].alpha,aaa[j].count);
        }
        printf("\n");
        return 0;
    }
