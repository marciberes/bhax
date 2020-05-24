#include <iostream>
using namespace std;

int main(){

int a= 9;
int b= 13;

cout<<"Eredeti a: "<<a<<endl;
cout<<"Eredeti b: "<<b<<endl;

a= a^b;
b= b^a;
a= a^b;

cout<<"Új a: "<<a<<endl;
cout<<"Új b: "<<b<<endl;

return 0;
}
