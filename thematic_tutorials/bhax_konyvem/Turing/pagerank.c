#include <stdio.h>
#include <math.h>

void printResult(double array[], int n);

double distance(double PR[], double PRv[], int n);

int main(){
double L[4][4] = {
{0.0, 0.0, 1.0/3.0, 0.0},
{1.0, 1.0/2.0, 1.0/3.0, 1.0},
{0.0, 1.0/2.0, 0.0, 0.0},
{0.0, 0.0, 1.0/3.0, 0.0}
};

double PR[4] = {0.0, 0.0, 0.0, 0.0};
double PRv[4] = {1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0};

for(;;)
{
	for(int i = 0; i < 4; i++)
		PR[i] = PRv[i];
	for(int i = 0; i < 4; i++)
	{
		PRv[i] = 0.0;
	for(int j = 0; j < 4; j++){
		PRv[i] += L[i][j]*PR[j];
		}
	}
	if(distance(PR, PRv, 4) < 0.000001)
	break;
}
printResult(PR, 4);

return 0;
}

void printResult(double array[], int n){
	for(int i = 0; i < n; ++i){
		printf("%f\n", array[i]);
	}
}
double distance(double PR[], double PRv[], int n){
	double sum = 0.0;
	for(int i = 0; i < n; ++i){
		sum += (PR[i] - PRv[i])*(PR[i]-PRv[i]);
	}
return sqrt(sum);
}
