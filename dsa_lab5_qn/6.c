//i didnt do this

#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int A[n];
for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
}
int m;
scanf("%d",&m);
int B[m];
for(int j=0;j<m;j++)
{
    scanf("%d",&B[j]);
}
int C[n*m];
for(int i=0;i<n*m;i++){
    C[i]=A[i/m]^B[i%m];
}
int xr=C[0];
for(int i=1;i<n*m;i++){
    xr=xr^C[i];
}
printf("%d",xr);
}