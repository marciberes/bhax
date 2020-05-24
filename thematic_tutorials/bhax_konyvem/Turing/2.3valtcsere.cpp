#include <iostream>
using namespace std;

//valt.csere seged valt. nelkul
int main(){

int a= 11;
int b= 7;

cout<<"Eredeti a: "<<a<<endl;
cout<<"Eredeti b: "<<b<<endl;


b=b-a;
a=a+b;
b=a-b;

cout<<"Új a: "<<a<<endl;
cout<<"Új b: "<<b<<endl;

return 0;
}

