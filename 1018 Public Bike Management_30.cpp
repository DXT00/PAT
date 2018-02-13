/*
方法一：Dfs(剪枝就不会超时-->把路径长度len超过最小路径长度MIN的剪了！)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int Cmax,N,Sp,M,x,y,ti,minremain=99999999,minsend=999999999,MIN=99999999,remain,send;
int bike[502];//minremain与minsend为res路径所对应的remain和send
int timee[502][502];
vector<int> res;
vector<int> v[502];
void dfs(int x,vector<bool> visited,int len,vector<int> path){
	if(len>MIN)return;//剪枝了
	if(x==Sp){
			if(len<MIN){//时间最小的路径。则直接res=path,minremain=remain,minsend=send;
				MIN=len;
				res=path;
				remain=0,send=0;
				for (int i = 1; i <path.size(); ++i){  //计算remain,send
					if(remain+bike[path[i]]>Cmax){
						remain=remain+bike[path[i]]-Cmax;
					}
					else{
						send+=(Cmax-(remain+bike[path[i]]));
						remain=0;
					}
				}
				minremain=remain;
				minsend=send;
			}
			else if(len==MIN){//时间相同,比较remain和send
				remain=0,send=0;
				for (int i = 1; i <path.size(); ++i){  //计算remain,send
					if(remain+bike[path[i]]>Cmax){
						remain=remain+bike[path[i]]-Cmax;
					}
					else{
						send+=(Cmax-(remain+bike[path[i]]));
						remain=0;
					}
				}

				if(send<minsend){
					minsend=send;
					minremain=remain;
					res=path;
				}
				else if(send==minsend){
					if(remain<minremain){
						minremain=remain;
						res=path;
					}
				}
			}
		return;
	}
	for (int i = 0; i <v[x].size(); ++i){
		if(visited[v[x][i]]==false){
			path.push_back(v[x][i]);
			visited[v[x][i]]=true;
			dfs(v[x][i],visited,len+timee[x][v[x][i]],path);
			visited[v[x][i]]=false;
			path.pop_back();
		}	
	}
	
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d%d",&Cmax,&N,&Sp,&M);
	Cmax/=2;
	for (int i = 1; i <=N; ++i)
		scanf("%d",&bike[i]);
	for (int i = 0; i <M; ++i){
		scanf("%d%d%d",&x,&y,&ti);
		v[x].push_back(y);
		v[y].push_back(x);
		timee[x][y]=timee[y][x]=ti;
	}
	vector<bool> visited(N+1,false);
	vector<int> path;
	visited[0]=true;
	path.push_back(0);
	dfs(0,visited,0,path);
	path.pop_back();
	visited[0]=false;

	cout<<minsend<<" ";
	for (int j = 0; j <res.size() ; ++j){
	 	if(j!=0)printf("->");
	 	printf("%d",res[j]);
	}
	cout<<" "<<minremain<<endl;
	
	system("pause");
	return 0;
}

/*
想想啊：
用djistra的话，路径要解析出来，麻烦！
试一下dfs

*/
/*
方法二：Dijastra与Dfs
能够用数组的尽量用数组！！vector会超时！特别是vector<vector<int> >
vector<vector<int> > a--->用vector<int> a[500]代替！
用数组记得初始化！！(for)

多用#define 别老是写9999999！！

*/

#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;

#define inf 99999999

int Cmax, N, Sp, M, x, y, z;//M->road
int Cars[502];
int res_index, res_need = inf, res_remain = inf;

int Time[502][502];
std::vector<int> path[502];
bool visited[502];
std::vector<int> res_s;
void dfs(int root, vector<int> s){
	if (root == 0){

		int remain = 0;
		int need = 0;
		for (int j = s.size() - 2; j >= 0; j--)
		{
			remain = Cars[s[j]] + remain;
			if (remain >= Cmax){
				remain = remain - Cmax;
			}
			else{
				need += Cmax - remain;
				remain = 0;
			}
		}
		if (need<res_need){

			res_need = need;
			res_remain = remain;
			res_s = s;
		}
		else if (need == res_need){
			if (remain<res_remain){

				res_need = need;
				res_remain = remain;
				res_s = s;
			}
		}
		return;
	}
	for (int i = 0; i <path[root].size(); ++i)
	{
		s.push_back(path[root][i]);
		dfs(path[root][i], s);
		s.pop_back();
	}
}
void Djistra(){
	std::vector<int> time(N + 1, inf);
	int min = 0;
	time[0] = 0;
	visited[0] = true;

	while (true){
		for (int j = 0; j <= N; ++j)
		{
			if (Time[min][j]<inf && visited[j] == false){
				if (time[min] + Time[min][j]<time[j]){
					time[j] = time[min] + Time[min][j];
					path[j].clear();
					path[j].push_back(min);
				}
				else if (time[min] + Time[min][j] == time[j]){
					path[j].push_back(min);
				}
			}
		}
		int MIN = inf, MIN_i;
		for (int i = 0; i <= N; ++i)
		{
			if (visited[i] == false){
				if (time[i]<MIN){
					MIN = time[i];
					MIN_i = i;
				}
			}
		}
		min = MIN_i;
		if (min == Sp)break;
		visited[min] = true;
	}
	vector<int> s;
	s.push_back(Sp);
	dfs(Sp, s);

}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d%d", &Cmax, &N, &Sp, &M);
	Cmax = Cmax / 2;
	for (int i = 0; i <= N; ++i)
		for (int j = 0; j <= N; ++j)
			Time[i][j] = inf;	
	for (int i = 0; i <= N; i++)
		visited[i] = false;

	for (int i = 1; i <= N; ++i)
		scanf("%d", &Cars[i]);

	for (int i = 0; i <M; ++i)
	{
		scanf("%d%d%d", &x, &y, &z);
		Time[x][y] = z;
		Time[y][x] = z;
	}
	Djistra();

	printf("%d ", res_need);
	for (int i = res_s.size() - 1; i >= 0; i--){
		if (i != res_s.size() - 1)
			printf("->");
		printf("%d", res_s[i]);
	}
	printf(" %d\n", res_remain);

	system("pause");
	return 0;
}
