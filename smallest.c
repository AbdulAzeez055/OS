#include<stdio.h>
int main()
{
    int n,a[10];
    printf("Enter number of elements \n");
    scanf("%d",&n);
    printf("Enter elements  \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int min=a[0],pos=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
            pos=i;
        }

    }
    printf("Min element is %d at position=%d",min,pos);
    return 0;

}
