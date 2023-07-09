#include<stdio.h>
#include<stdlib.h>

int main()
{
    int m,n;
    int ri,rh,ci,ch;
    scanf("%d %d",&n,&m);
    int **p=(int**) malloc(n*sizeof(int*));
 	int i;int sum=0;

    for( i=0;i<n;i++)
    {
        p[i] = (int*)malloc (m*sizeof(int*));
        int j;
        for( j=0;j<m;j++)
        {
            int num;
            scanf("%d",&num);
            sum += num;
           	p[i][j]=sum;
        }

        
    }

    scanf("%d %d %d %d",&ri,&ci,&rh,&ch);

    if((ri+rh)>n || (ci+ch)>m)
    {
        printf("no");
        return 0;
    }

int ans=0; 
    for( i=ri;i<(rh+ri);i++)
    {
        printf("\n");
       int j;
        for(j=ci;j<(ch+ci);j++)
        {
            ans=ans+p[i][j];

        }
    }

	for( i=0;i<n;i++)
    {
        printf("\n");
       int j;
        for(j=0;j<m;j++)
        {
            printf("%d	" ,p[i][j]);
        }
    }        
	            printf("%d	" ,ans);

}