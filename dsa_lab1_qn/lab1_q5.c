
#include<stdio.h>
int mid, n;
int i;int j;
int a[50][50];
char b[50][50];
void generate(int layer,int p,int q,int num)
{

	if(layer%2==1)
	{
	
		for(i=0;i<layer;i++)
		{
			a[p][q]=2*num;
			
			num++;
			b[2*p][2*q+1]='-';
			q++;

		}
		
		for(i=0;i<layer;i++)
		{
			a[p][q]=2*num;
			
			num++;
			b[2*p-1][2*q]='|';
						p--;

		}
	
	}
	
	else
	{
	
		for(i=0;i<layer;i++)
		{
			a[p][q]=2*num;
			
			num++;
			b[2*p][2*q-1]='-';
						q--;

		}
		
		for(i=0;i<layer;i++)
		{
			a[p][q]=2*num;
			num++;
			
			b[2*p+1][2*q]='|';
						p++;

		}
	
	}
	
	if(layer==n)
	{
	}
	else
		generate( layer+1,p ,q,num);
	
}

int main()
{
	
	scanf("%d", &n);
	
	for( i=0;i<2*n;i++)
	{
		for(j=0;j<2*n;j++)
		{
			b[i][j]=' ';
		}
	}
	
	if(n%2==0)
	{
		printf("    ");

		mid=n/2-1;
		
		a[mid+1][mid]=2;

	generate( 1,mid+1 ,mid,1);
	}
	else
	{
//		printf("    	");

		mid=n/2;
		
		a[mid][mid]=2;

	generate( 1,mid ,mid,1);

	}
	


	for(i=0;i<2*n;i++)
	{
		for(j=0;j<2*n;j++)
		{
			if(i%2==0&&j%2==0)
			printf("%d	",a[i/2][j/2]);
			else
			printf("%c	",b[i][j]);
			
		}
		printf(" \n");
	}
	
	
	
	
	
	
	
}
