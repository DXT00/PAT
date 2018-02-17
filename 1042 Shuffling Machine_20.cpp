#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std; 
int N;
string order1[54]={"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13","H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13","C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13","D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13","J1","J2"};
vector<string>order(order1,order1+54);
vector<int>pos(54);
vector<string> cur(54);
int main(int argc, char const *argv[])
{
	cin>>N;
	for (int i = 0; i <54; ++i)
		scanf("%d",&pos[i]);
	for (int k = 0; k <N; ++k) {
		for (int i = 0; i <54; ++i){
			cur[pos[i]-1]=order[i];
		}
		order=cur;
	}
	for (int i = 0; i <54; ++i){
		if(i!=0)printf(" ");
		printf("%s",order[i].c_str());
	}
	system("pause");
	return 0;
}