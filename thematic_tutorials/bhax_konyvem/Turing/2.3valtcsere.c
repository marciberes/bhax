#include <stdio.h>

//valt.csere seged valt. nelkul
int main(){

int a= 11;
int b= 7;

printf("Eredeti a: %d \n",a);
printf("Eredeti b: %d \n",b);


b=b-a;
a=a+b;
b=a-b;

printf("Új a: %d \n",a);
printf("Új b: %d \n",b);

return 0;
}

