#include<stdio.h>
#include<string.h>
int main()
{
	char s1[100];
	char s2[20];
	fgets(s1,100,stdin);
	fgets(s2,20,stdin);
	int len1=strlen(s1);
	int len2=strlen(s2);

	if(len1<len2)
	{
		printf("not possible ");
		return 0;
	}
	
	int i=0,j=0,k=0;
	int arr1[256]={0};
	for(;i<len2;i++)
	{
		arr1[s2[i]]++;
	}
	int check=0;
	int ptr1=0,ptr2=0;
	int min=1000;
	int k1,k2;
	len1--;
	len2--;
		for(i=0;i<len2;i++)
		{
			if(s1[0]==s2[i] )
			{
				
				arr1[s2[i]]--;
				check++;
				break;
			}		
		}
	while(ptr2<len1)
	{
		if(check==len2)
		{
			if(min>ptr2-ptr1)
			{
				k1=ptr1;
				k2=ptr2;
				min=ptr2-ptr1;
			}
			for(i=0;i<len2;i++)
			{
				if(s1[ptr1]==s2[i] )
				{	
					arr1[s2[i]]++;
					if(arr1[s2[i]]>0)
					check--;
					break;
				}
				
			}
			
			ptr1++;
			continue;
		}
		ptr2++;
		for(i=0;i<len2;i++)
		{
			if(s1[ptr2]==s2[i] )
			{
				
				arr1[s2[i]]--;
				if(arr1[s2[i]]>=0)
				{
					check++;
				}
				break;
				
			}		
		}
		

		
	}
	
	if(min==1000)
	{
		printf("no");
		return;
	}
	
	printf("\n %d \n %d  %d", min,k1,k2);
	return 0;

}