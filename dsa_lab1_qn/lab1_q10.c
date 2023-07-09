#include<stdio.h>
#include<string.h>

int main()
{
	char a[20],b[20];
	
	fgets(b,20,stdin);
	fgets(a,20,stdin);

	int i,j;
	
	int n=strlen(a);
	int	m=strlen(b);
	if(m !=n)
		return 0;
	
	int seq[n];
	
	for(i=0;i<n-1;i++)
	{
		seq[i]=i;
	}

	
	int check =0;
	for(i=0;i<n-1;i++)
	{
		for(j=i;j<n-1;j++)
		{
			if(a[i]== b[j])
			{
 				check++;
				if(i!=j)
				{
 					
					char temp=b[i];
					b[i]=b[j];
					b[j]=temp;
					
					int t=seq[i];
					seq[i]=seq[j];
					seq[j]=t;
					
					break;

				}
			}
		}
	}
	
	
	if(check != (n-1))
	{
		printf("no");
		return 0;
	}
	
	
	for(j=0;j<n-1;j++)
	{
		
		printf("%d " ,seq[j]+1);
			
	}
}