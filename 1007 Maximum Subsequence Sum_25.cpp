#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;
int N;
int main(int argc, char const *argv[])
{	
	scanf("%d",&N);
	vector<int> v(N,0);
	for (int i = 0; i <N; ++i)
		scanf("%d",&v[i]);
	int sum=0,start=0,endd=N-1,MAX=-1,res_start;
	for (int i = 0; i <N; ++i){
		sum+=v[i];
		if(sum<0){
			sum=0;
			start=i+1;
		}
		else{//当所有数都小于0时，sum<0,所以MAX一直=-1用此判断是否所有数都小于0，不必设flag
			if(sum>MAX){
				MAX=sum;
				endd=i;
				res_start=start;
			}
		}		
	}
	if(MAX==-1)
			cout<<0<<" "<<v[0]<<" "<<v[N-1]<<endl;
	else
	cout<<MAX<<" "<<v[res_start]<<" "<<v[endd]<<endl;
	system("pause");
	return 0;
}