#include<stdio.h>

int main()
{
	int m,n,p,q;
	scanf("%d %d",&m,&n);
	int i,j;
	int a[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
		
	}
	scanf("%d %d",&p,&q);
	int b[p][q];
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
			scanf("%d",&b[i][j]);
		
	}
	int rowcheck=0;
	for(i=0;i<=m;i++)
	{	
		for(j=0;j<=n-q;j++)
		{
			int k=0,l=0;
			for(;k<p;k++)
			{
				if(a[i][j]==b[k][0])
				{
					int see=0;
					for(l=0;l<q;l++)
					{
						if(a[i][j+l]!=b[k][l])
						{
							see=1;break;
						}	
							
						
					}
					if(see==0)
						rowcheck++;
				}
			}
			
		}
	}
	
	int colcheck=0;
	for(i=0;i<=m-p;i++)
	{	
		for(j=0;j<=n;j++)
		{
			int k=0,l=0;
			for(;k<q;k++)
			{
				if(a[i][j]==b[0][k])
				{
					int see=0;
					for(l=0;l<p;l++)
					{
						if(a[i+l][j]!=b[l][k])
						{
							see=1;break;
						}	
							
						
					}
					if(see==0)
						colcheck++;
				}
			}
			
		}
	}
	
	if(rowcheck==0&& colcheck==0)
		printf("NO");
	else if( rowcheck=p && colcheck==q)
		printf("yes");
	else
		printf("partial");
	
	
	
}