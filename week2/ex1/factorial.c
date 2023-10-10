#include <stdio.h>
int main()
{
    int i,n;
    double sum=1;
    printf("Enter a number: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
          sum=sum*i;
        }
    printf("%d!=%lf\n", n,sum);
    return 0;
}