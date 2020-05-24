#include <stdio.h>

int main(){

int a= 9;
int b= 13;

printf("Eredeti a: %d \n",a);
printf("Eredeti b: %d \n",b);

a= a^b;
b= b^a;
a= a^b;

printf("Új a: %d \n",a);
printf("Új b: %d \n",b);

return 0;
}
