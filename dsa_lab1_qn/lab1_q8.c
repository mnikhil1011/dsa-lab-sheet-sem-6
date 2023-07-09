#include<stdio.h>
#include<string.h>

int main()
{
	char str[100];
	int i,j;
	gets(str);
	char word[20][20];
	int wlen[20];
	int k=0;
	for(i=0;str[k] != 0;i++)
	{
		j=0;
		while(str[k]!=' '&&str[k]!=0)
		{
			word[i][j]=str[k];
			k++;
			j++;

		}
		wlen[i]=j;
		k++;
	}
	
	int len=i;
	for(i=0;i<len;i++)
	{
		word[i][wlen[i]]=0;
		--wlen[i];
		for(j=0;j<(wlen[i]/2)+1;j++)
		{
			char temp=word[i][j];
			word[i][j]=word[i][wlen[i]-j];
			word[i][wlen[i]-j]=temp;
		}
		
		printf("%s ",word[i]);
	}
	printf("\n");
	k=0;
	for(i=0;str[k] != 0;i++)
	{
		j=0;
		int check=0;
		while(str[k]!=' '&&str[k]!=0)
		{
			if(word[i][j] != str[k])
				check++;
			++j;
			++k;	
		}
		++k;
		if(check==0)
			printf("%s ",word[i]);
		
	}
	
}