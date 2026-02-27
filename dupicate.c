#include<stdio.h>
int main()
{
    int n;
    int a[10];
    printf("Enter number of elements\n");
    scanf("%d",&n);
    int d=0;
    printf("Enter elements \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                d=1;

            }


        }

    }
    if(d==0)
    {
        printf("No duplicates found \n");

    }
    else if(d==1)
    {
        printf("Dupicates are found ");
    }
    return 0;




}
