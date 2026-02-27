#include<stdio.h>

int main()
{

    int n;
    int a[10];
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter elements \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    int ele;
    int pos=-1;
    printf("Enter element to search");
    scanf("%d",&ele);
    for(int i=0;i<n;i++)
    {
        if(ele==a[i])
        {


            pos=i;
            printf("Element found at pos",pos);
            break;
        }

    }
    if(pos==-1)
    {
        printf("Entered element not present \n");

    }
    return 0;

}
