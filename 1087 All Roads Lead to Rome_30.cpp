/*
//不要漏了记录pathCnt[]-->到达每个节点的最短路径条数！！！
不是单纯的加1！！
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#define inf 99999999
using namespace std;
int N, M, D, S, k, le;
string str,str1,str2;
vector<int> v[20000];
int happy[20000];
int weight[20000][20000];
int change(string s){
	int res = 0, ten = 1;
	for (int i = 2; i >= 0; i--){
		res += ten*(s[i] - 'A');
		ten *= 26;
	}
	return res;
}
void Djistra(){
	bool visited[20000];
	int dist[20000], cnt[20000],hap[20000],path[20000],pathCnt[20000];
	int min = S;
	fill(visited, visited + 20000, false);
	fill(path, path + 20000, -1);
	fill(dist, dist + 20000, inf);
	dist[min] = 0;
	pathCnt[min]=1;
	hap[min] = 0;
	cnt[min] = 0;
	visited[min] = true;
	while (true){

		for (int i = 0; i <v[min].size(); ++i){
			int j = v[min][i];
			if (visited[j] == false){
				if (dist[min] + weight[min][j]<dist[j]){
					dist[j] = dist[min] + weight[min][j];
					hap[j] = happy[j] + hap[min];
					cnt[j] = cnt[min] + 1;
					pathCnt[j]=pathCnt[min];//不要漏了记录pathCnt[]-->到达每个节点的最短路径条数！！！
					path[j] = min;
				}
				else if (dist[min] + weight[min][j] == dist[j]){
					pathCnt[j]=pathCnt[j]+pathCnt[min];
					if (hap[min] + happy[j]>hap[j]){
						hap[j] = hap[min] + happy[j];
						cnt[j] = cnt[min] + 1;
						path[j] = min;
					}
					else if (hap[min] + happy[j] == hap[j]){
						if ((hap[min] + happy[j])/(cnt[min] + 1)>hap[j]/cnt[j]){
							cnt[j] = cnt[min] + 1;
							path[j] = min;
						}
					}
				}
			}
		}
		int MIN = inf, MIN_i;
		for (int i = 0; i <20000; ++i){
			if (visited[i] == false){
				if (dist[i]<MIN){
					MIN = dist[i];
					MIN_i = i;
				}
			}
		}
		min = MIN_i;
		visited[min] = true;
		if (min == D)break;

	}
	int cur = D;
	std::vector<int> res;
	while (cur != -1){
		res.push_back(cur);
		cur = path[cur];
	}
	cout << pathCnt[D] << " " << dist[D] << " " << hap[D] << " " << hap[D] / cnt[D] << endl;
	for (int i = res.size() - 1; i >= 0; i--){
		if (i != res.size() - 1)printf("->");
		printf("%c%c%c", res[i] / 26 / 26 + 'A', res[i] / 26 % 26 + 'A', res[i] % 26 + 'A');

	}
}
int main(int argc, char const *argv[])
{
	
	D = change("ROM");
	scanf("%d%d", &N, &M);
	cin>>str;
	S = change(str);
	happy[S] = 0;

	for (int i = 0; i <N - 1; ++i){
		cin>>str;
		scanf("%d",&k);
		happy[change(str)] = k;
	}
	for (int i = 0; i < M; ++i){
		cin>>str1>>str2;
		scanf("%d",  &le);
		int x = change(str1);
		int y = change(str2);
		v[x].push_back(y);
		v[y].push_back(x);
		weight[x][y] = weight[y][x] = le;
	}
	Djistra();
	system("pause");
	return 0;
}
/*
//用map映射就不用遍历0~20000了
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

#define inf 99999999

using namespace std;

int N, M, k = 0, x, le,D,num=1;
string start, str, s1, s2;
std::map<string, int> m;
std::map<int, string> m2;
std::vector<int> v[202];
std::vector<int> happy;
int length[202][202];
void Dijstra(){
	std::vector<int> dist(N,inf);
	std::vector<bool> visited(N,false);
	std::vector<int> happyi(N,0);
	std::vector<int> pathCnt(N,0);
	std::vector<int> cnt(N,0);
	std::vector<int> path(N,-1);
	int min=0;
	visited[min]=true;
	happyi[min]=0;
	cnt[min]=0;
	dist[min]=0;
	pathCnt[min]=1;
	while(true){

		for (int i = 0; i <v[min].size(); ++i)
		{
			int j=v[min][i];
			if(visited[j]==false){
				if(dist[min]+length[min][j]<dist[j]){
					dist[j]=dist[min]+length[min][j];
					happyi[j]=happyi[min]+happy[j];
					cnt[j]=cnt[min]+1;
					pathCnt[j]=pathCnt[min];
					path[j]=min;
				}
				else if(dist[min]+length[min][j]==dist[j]){
					//num++;
					pathCnt[j]=pathCnt[j]+pathCnt[min];
					if(happyi[min]+happy[j]>happyi[j]){
						happyi[j]=happyi[min]+happy[j];
						cnt[j]=cnt[min]+1;
						path[j]=min;
					}
					else if(happyi[min]+happy[j]==happyi[j]){
						if(cnt[min]+1<cnt[j]){
							cnt[j]=cnt[min]+1;
							path[j]=min;
						}
					}

				}
			}
		}
		int MIN=inf,MIN_i;
		for (int i = 0; i <N; ++i)
		{
			if(visited[i]==false&&dist[i]<MIN){
				MIN=dist[i];
				MIN_i=i;
			}
		}
		min=MIN_i;
		if(min==D)break;
		visited[min]=true;

	}
	std::vector<int> res;
	int cur=D;
	while(cur!=-1){
		res.push_back(cur);
		cur=path[cur];
	}
	cout<<pathCnt[D]<<" "<<dist[D]<<" "<<happyi[D]<<" "<<happyi[D]/cnt[D]<<endl;
	for (int i = res.size()-1; i>=0;i--)
	{
		if(i!=res.size()-1)printf("->");
		printf("%s",m2[res[i]].c_str());
	}

}
int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &M);
	cin >> start;
	getchar();
	m2[k] = start;
	m[start] = k++;
	happy.assign(N + 1, 0);
	for (int i = 0; i <N-1; ++i)
	{
		cin >> str >> x;
		m2[k] = str;
		m[str] = k;
		happy[k] = x;
		if(str=="ROM")D=k;
		k++;
	}

	for (int i = 0; i <M; ++i)
	{
		cin >> s1 >> s2 >> le;
		length[m[s1]][m[s2]] = length[m[s2]][m[s1]] = le;
		v[m[s1]].push_back(m[s2]);
		v[m[s2]].push_back(m[s1]);
	}	
	
	Dijstra();
	system("pause");
	return 0;
}
*/
