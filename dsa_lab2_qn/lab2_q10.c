#include<stdio.h>

struct countrymedal
{
	int tally[3];
	char name[10];
	
};
typedef struct countrymedal info;

int greater(int a[], int b[])
{
	if(b[0]>a[0] ||(b[0]==a[0] && b[1]>a[1]) || (b[0]==a[0] && b[1]==a[1] && b[2]>a[2]))
		return 1;
		
	return 0;		
}

int main()
{
	int n;
	scanf("%d",&n);
	info info1[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%s",&info1[i].name);
		int j;
		for(j=0;j<3;j++)
			scanf("%d",&info1[i].tally[j]);
	}
	
	for(i=0;i<n;i++)
	{
		int j;
		for(j=0;j<n-1;j++)
		{
			if(greater(info1[j].tally,info1[j+1].tally))
			{
				info temp =info1[j];
				info1[j]= info1[j+1];
				info1[j+1]= temp;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf(" %s \n" ,info1[i].name);
	}

	
	
	
}