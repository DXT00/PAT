#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int N, m, n, MIN = 1000000;
bool cmp(int a, int b){ return a>b; }
int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	std::vector<int> v(N, 0);
	for (int i = 0; i <N; ++i)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end(), cmp);
	for (int i = 1; i <=N; ++i)
	{
		if(N%i==0){
			m=i;
			n=N/i;
			if(m>=n)break;
		}
	}//m行n列
	std::vector<int> cur(n, 0);
	std::vector<vector<int> > res(m, cur);
	int k = 1, j = 0;
	int i = 0;
	int status = 0;//0向右；1向下；2向左；3向上
	res[0][0] = v[0];
	while (k<N){		
		if (status == 0){
			if (j + 1<n&&res[i][j + 1] == 0)
				j++;
			else{
				status = 1;
				continue;
			}		
		}
		else if (status == 1){
			if (i + 1<m&&res[i + 1][j] == 0)
				i++;
			else{
				status = 2;
				continue;
			}	
		}
		else if (status == 2){
			if (j - 1 >= 0 && res[i][j - 1] == 0)
				j--;
			else{
				status = 3;
				continue;
			}				
		}
		else if (status == 3){
			if (i - 1 >= 0 && res[i - 1][j] == 0)
				i--;
			else{
				status = 0;
				continue;
			}				
		}
		
		res[i][j] = v[k];
		k++;
		
	}
	for (int i = 0; i <m; ++i){
		for (int j = 0; j < n; ++j){
			if(j!=0)printf(" ");
			printf("%d", res[i][j]);
		}
		printf("\n");
	}
	getchar();
	system("pause");
	return 0;
}
