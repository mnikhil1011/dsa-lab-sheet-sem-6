#include<stdio.h>

int isprime(int num)
{
	int i;
	for( i=2;i<num;i++)
	{
		if(num%i ==0)
			return 0;
	}
	return 1;
}

int main()
{
	int a,b,i,j;
	scanf("%d %d",&a,&b);
	int val[10];
	for( i=1;i<=9;i++)
		val[i]=0;	
	for( i=a;i<=b;i++)
	{
		if(isprime(i))
		{
			j=i;
			while(j)
			{
				int a=j%10;
				val[a]++;
				j /=10;
			}
		}
	}
	
	int max=1;
	for( i=2;i<=9;i++)
	{
		if(val[i]>val[max])
			max=i;	
	}
	
	printf("\n %d	%d",max,val[max]);
	
}