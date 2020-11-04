#include <stdio.h>
#include <stdlib.h>

int x=10;

int main(){
	int y=6;
	int static c=9;

	int* a=(int*)malloc(7*sizeof(int));



printf("the global %d ,local %d , static %d ,malloc nu %d \n",x,y,c,a[1]);
	getchar();

}
