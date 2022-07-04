#include<stdio.h>

int main(void)
{
	int input_x,input_y;
	int x,y;
	
	scanf("%d %d",&input_x,&input_y);
	
	for(y=0 ; y<input_y ; y++)
	{
		for(x=0 ; x<input_x ; x++)
			printf("*");
		printf("\n");
	}
}
