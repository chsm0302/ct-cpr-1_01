#include<stdio.h>

void fib(char copy[],int number)
{
	int len,i,j;
	
	for(len=0;;len++)
	{
		if(copy[len]=='\0')
			break;
	}
		
	for(i=0;copy[i]!='\0';i++)
	{
		if(copy[i]=='(')
		{
			for(j=len;j>i;j--)
			{
				copy[j+1]=copy[j];
			}
			len++;
			for(j=len;j>i;j--)
			{
				copy[j+1]=copy[j];
			}
			len++;
			copy[i+1]=number;
			if(i+2<len);
				copy[i+2]=',';
		}		
	}	
}

void reset(char copy[])
{
	int len;
	
	for(len=0;;len++)
	{
		if(copy[len]=='\0')
			break;
		copy[len]='\0';
	}
}

void steps(unsigned int n) 
{
	static char arr[10][5000]={"(1)","(1,1), (2)","(1,1,1), (1,2), (2,1), (3)"};
	static char copy[5000];
	int i,j;
	int len=0,check=0;
	
	if(n>2)
		arr[n][0]='1';
	
	
	if(n>2)
	{	// ********************************
		steps(n-1);
		fib(copy,49);
		for(i=0;copy[i]!='\0';i++)
		{
			arr[n][i]=copy[i];
			len++; 
		}
		reset(copy);
		j=len;
		// ***********************************
		steps(n-2);
		fib(copy,50);
		arr[n][j]=',';
		arr[n][j+1]=' ';
		j+=2;
		len+=2;
		for(i=0;copy[i]!='\0';i++)
		{
			arr[n][j]=copy[i];
			len++; 
			j++;
		}
		reset(copy);
		j=len;
		//***************************************
		steps(n-3);
		fib(copy,51);
		arr[n][j]=',';
		arr[n][j+1]=' ';
		j+=2;
		len+=2;
		for(i=0;copy[i]!='\0';i++)
		{
			arr[n][j]=copy[i];
			len++; 
			j++;
		}
	}
	
	for(i=0;;i++)
	{
		if(arr[n][i]=='\0')
			break;
		copy[i]=arr[n][i];
	}
	
	for(i=0;i<=10;i++)
	{
		if(arr[i][0]=='\0' && i-1==n)
		{
			for(i=0;;i++)
			{
				if(arr[n][i]=='(' && arr[n][i+1]=='2' && check==0)
				{
					arr[n][i-1]='\n';
					arr[n][i-2]=' ';
					check=1;
				}
				if(arr[n][i]=='(' && arr[n][i+1]=='3')
				{
					arr[n][i-1]='\n';
					arr[n][i-2]=' ';
					break;
				}
			}	
			printf("%s\n",arr[n]);
		}
	}	
	
		
	
}

int main(void)
{
	int input,i;
	
	printf("Enter step number: ");
	scanf("%d",&input);
	
	steps(input-1); 	
}
