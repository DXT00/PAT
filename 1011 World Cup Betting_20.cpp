#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
char Bet[3]={'W','T','L'};
int MAX_i;
int main(int argc, char const *argv[])
{
	double res=1.0,x;
	for (int i = 0; i <3; ++i){
		double MAX=-1;
		for (int j = 0; j <3; ++j){
			scanf("%lf",&x);
			if(x>MAX){
				MAX=x;
				MAX_i=j;
			}
		}
		cout<<Bet[MAX_i]<<" ";
		res*=MAX;
	}
	printf("%.2lf\n",(res*0.65-1)*2.0);
	system("pause");
	return 0;
}