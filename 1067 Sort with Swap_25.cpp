#include <algorithm>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int N, origin, x, already = 0, cnt = 0, c = 0;
std::vector<int> pos, v;
int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	v.assign(N, 0);
	pos.assign(N, 0);
	for (int i = 0; i <N; ++i)
	{
		scanf("%d", &x);
		pos[x] = i;
		if (x == i)already++;
	}
	while (already<N){
		if (pos[0] != 0){
			swap(pos[0], pos[pos[0]]);
			cnt++;
			already++;
		}
		else{
			if (already == N - 1)break;		

			while (pos[c] == c)c++;
			swap(pos[0], pos[c]);
			cnt++;
		

		}
	}
	cout << cnt << endl;
	system("pause");
	return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <stdio.h>
// #include <set>
// using namespace std;
// int N, done = 0;
// std::vector<int> v;
// std::vector<int> pos;
// set<int>s;//用set存储那些位置不对的数
// set<int>::iterator it;

// int main(int argc, char const *argv[])
// {
// 	scanf_s("%d", &N);
// 	v.assign(N, 0);
// 	pos.assign(N, 0);
// 	for (int i = 0; i <N; ++i)
// 	{
// 		scanf_s("%d", &v[i]);
// 		if (i!=0&&v[i] == i)done++;
// 		else{
// 			if (i!=0)
// 			s.insert(i);
// 		}
// 		pos[v[i]] = i;
// 	}
// 	int cnt = 0, w;
// 	while (true){

// 		if (pos[0] != 0){
// 			set<int>::iterator its;
// 			its = s.find(pos[0]);
// 			s.erase(its);

// 			swap(pos[0], pos[pos[0]]);

// 			done++;
// 			cnt++;
// 		}
// 		else{
// 			if (s.size() == 0)break;
// 			it = s.begin();
// 			swap(pos[0], pos[*it]);
// 			cnt++;


// 		}

// 	}
// 	cout << cnt << endl;
// 	system("pause");
// 	return 0;
// }

// #include <iostream>
// #include <vector>
// #include <stdio.h>
// #include <algorithm>
// #include <queue>
// #include <math.h>
// using namespace std;
// int N,x,cnt=0,cnt1=0;
// int already=0;
// int judge(vector<int> &pos){
// 	int k=0,t;
// 	while(true){
// 		if(pos[0]!=0){
// 				t=pos[0];
// 				pos[0]=pos[t];
// 				pos[t]=t;
// 				cnt++;
// 				cnt1++;
// 		}
// 		else{
// 			//k=0;  //这里一定要注意！不要每次都重头开始找，会超时
// 					//每次交换后位置都是固定的，所以只要从上次的k开始向后找第一个pos[k]!=k的数即可！！
// 			if(cnt1+1+already==N)return cnt;
// 			while(pos[k]==k){
// 				k++;
// 			}
// 			if(k==N)return cnt;
// 			pos[0]=pos[k];
// 			pos[k]=0;
// 			cnt++;
// 		}	
// 	}
// 	return cnt;
// }
// int main(int argc, char const *argv[])
// {
// 	scanf("%d",&N);
// 	std::vector<int> pos(N);
// 	for (int i = 0; i <N; ++i)
// 	{
// 		scanf("%d",&x);
// 		pos[x]=i;
// 		if(i==x)already++;
// 	}
// 	if (already==N)
// 	{
// 		printf("0\n");
// 	}
// 	else
// 		printf("%d\n",judge(pos) );
	
// 	getchar();
// 	system("pause"); 
// 	return 0;
// }
