#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;
int N,index=0;
bool judge(vector<int> &origin,vector<int> &v){
	int i=1;	
	while(i<N&&v[i]>=v[i-1]){
		i++;
	}
	index=i;	
	
	while(i<N){
		if(v[i]!=origin[i])
			return false;
		i++;
	}
	return true;
}
void Merge(vector<int> &v,vector<int> &origin){
	int k=1,i=0,j;
	bool flag=true;
	while(flag){
		flag=false;
		for (j = 0; j < N; ++j)
			if(v[j]!=origin[j]){
				flag=true;break;
			}
		for(i=0;i<N/k;i++){
			sort(origin.begin()+i*k,origin.begin()+(i+1)*k);
		}
		sort(origin.begin()+(N/k)*k,origin.end());
		k=k*2;
	}
	
}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	std::vector<int> origin(N);
	std::vector<int> v(N);
	for (int i = 0; i <N; ++i)
		scanf("%d",&origin[i]);
	for (int i = 0; i <N; ++i)
		scanf("%d",&v[i]);
	if(judge(origin,v)){
		printf("Insertion Sort\n");
		
		sort(origin.begin(),origin.begin()+index+1);
		// for (int i = 0; i < v.size(); ++i)
		// {
		// 	if(i==v.size()-1)
		// 		printf("%d\n",v[i]);
		// 	else
		// 	printf("%d ",v[i]);
		// }
	}
	else{
		printf("Merge Sort\n");
		Merge(v,origin);
		
	}
	for (int i = 0; i < origin.size(); ++i)
		{
			if(i==origin.size()-1)
				printf("%d\n",origin[i]);
			else
			printf("%d ",origin[i]);
		}
	getchar();
	system("pause");
	return 0;
}