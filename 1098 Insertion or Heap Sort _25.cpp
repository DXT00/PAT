#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;
int N,index,index1,tmp;
bool flag=true;
void swap(int &a,int &b){
	tmp=a;
	a=b;
	b=tmp;
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
	for (int i = 0; i+1 <v.size(); ++i)
	{
		if(v[i]>v[i+1]){
			index=i+1;
			break;
		}
	}

	for (int i = index; i <N ; ++i)
	{
		if(origin[i]!=v[i]){
			flag=false;
			break;
		}
	}
	if(flag){//insertion
		printf("Insertion Sort\n");
		sort(v.begin(), v.begin()+index+1);
	}
	else{
		int k=N-1;
		int root=v[0];
		printf("Heap Sort\n");
		while(k>=0&&v[k]>root)k--;
		int index1=k;
		swap(v[0],v[index1]);
		int i=0;
		while(2*i+1<index1){
			if(2*i+2>=index1){
				if(v[2*i+1]>v[i]){
					swap(v[2*i+1],v[i]);
					i=2*i+1;
				}
			}
			else{
				if(v[2*i+1]>=v[2*i+2]){
					if(v[2*i+1]>v[i]){
						swap(v[2*i+1],v[i]);
						i=2*i+1;
					}
				}
				else{
					if(v[2*i+2]>v[i]){
						swap(v[2*i+2],v[i]);
						i=2*i+2;
					}
				}
			}
		}
	}
	for (int i = 0; i <v.size(); ++i)
	{
		if(i!=0)printf(" ");
		printf("%d",v[i]);
	}printf("\n");
	getchar();
	system("pause");
	return 0;
}