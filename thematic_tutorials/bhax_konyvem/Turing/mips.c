#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("Adj meg egy számot: ");
    int a;
    int count=0;
    scanf("%d",&a);
    while (a!=0)
    {
        a<<=1;
        count++;
    }
    printf("%d\n",count);
}
