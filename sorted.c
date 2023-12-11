#include<stdio.h>
int main()
{
int a[50],b[50],c[100],x,y;
printf("Enter the number of elements of the first array : ");
scanf("%d",&x);
printf("Enter the number of elements of the second array : ");
scanf("%d",&y);
printf("Enter the elements of the first array : ");
for(int i=0;i<x;i++)
{
scanf("%d",&a[i]);
}
printf("Enter the elements of the second array : ");
for(int j=0;j<y;j++)
{
scanf("%d",&b[j]);
}
int z=x+y;
int i=0;
int j=0;
int k=0;
while(i<x && j<y)
{
if(a[i]<b[j])
{
c[k]=a[i];
i++;
}
else if(a[i]>b[j])
{
c[k]=b[j];
j++;
}
k++;
}
while(i<x)
{
c[k]=a[i];
i++;
k++;
}
while(j<y)
{
c[k]=b[j];
j++;
k++;
}
printf("Merged array is : ");
for(int k=0;k<z;k++)
{
printf("%d ",c[k]);
}
return 0;
}


