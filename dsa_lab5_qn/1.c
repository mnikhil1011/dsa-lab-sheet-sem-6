//add number on top
//can make more efficient if i add condn if(score<-1 && score>(n)/2) or something

#include<stdio.h>
void backtrack(char * a, int layer,int n, int score)
{
	if(layer==n )
	{
		if(score != 0)
			return ;
			
		int i;
		for(i=0;i<=n;i++)
		{
			printf("%c",a[i]);
		}
		printf("\n");
		
		return;
	}
	if(score<-1 )
	{
		return;
	}
	
	a[layer]='(';
	backtrack(a,layer+1,n,score+1);
	
	a[layer]=')';
	backtrack(a,layer+1,n,score-1);

}
 
int main()
{
	int n;
	scanf("%d",&n);
	char a[n];
	int i=0;
	
	
	a[0]='(';
	a[n-1]=')';
	n --;
	backtrack(a,1,n,0);
}


