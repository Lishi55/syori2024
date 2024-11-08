#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char moji[10000];

int main(void){
	FILE * fp = NULL;
	fp = fopen("test.txt", "r");
	int i;
	while ((moji[i] = fgetc(fp)) != EOF){
	i += 1;
	}
        int M = strlen(moji);
	printf("%d\n",M);
		return 0;
}
