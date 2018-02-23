#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int M,N,L,T,x,res=0;//M=1286x ,N=128y,L=60z
struct Node{
    int x,y,z,data;
};
Node v[65][1300][130];
int visited[65][1300][130];
queue<Node>q;
int main(int argc, char const *argv[])
{
	scanf("%d%d%d%d",&M,&N,&L,&T);
	for (int k = 0; k <L ; ++k){
		for (int i = 0; i <M; ++i){
			for (int j = 0; j < N; ++j){
					scanf("%d",&x);
					v[k][i][j].z=k;
					v[k][i][j].x=i;
					v[k][i][j].y=j;
					v[k][i][j].data=x;
			}
		}
	}
	for (int k = 0; k <L ; ++k){
		for (int i = 0; i <M; ++i){
			for (int j = 0; j < N; ++j){
					if(visited[k][i][j]==0&&v[k][i][j].data==1){
						visited[k][i][j]=1;
						q.push(v[k][i][j]);
						int cur=0;
						while(!q.empty()){
							Node w=q.front();
							q.pop();
							cur++;
							int x=w.x,y=w.y,z=w.z;
							if(z+1<L&&v[z+1][x][y].data==1&&visited[z+1][x][y]==0){
								q.push(v[z+1][x][y]);
								visited[z+1][x][y]=1;
							}

							if(z-1>=0&&v[z-1][x][y].data==1&&visited[z-1][x][y]==0){
								q.push(v[z-1][x][y]);
								visited[z-1][x][y]=1;
							}

							if(x+1<M&&v[z][x+1][y].data==1&&visited[z][x+1][y]==0){
								q.push(v[z][x+1][y]);
								visited[z][x+1][y]=1;
							}

							if(x-1>=0&&v[z][x-1][y].data==1&&visited[z][x-1][y]==0){
								q.push(v[z][x-1][y]);
								visited[z][x-1][y]=1;
							}

							if(y+1<N&&v[z][x][y+1].data==1&&visited[z][x][y+1]==0){
								q.push(v[z][x][y+1]);
								visited[z][x][y+1]=1;
							}

							if(y-1>=0&&v[z][x][y-1].data==1&&visited[z][x][y-1]==0){
								q.push(v[z][x][y-1]);
								visited[z][x][y-1]=1;
							}
							
						}
						if(cur>=T)res+=cur;
					}
			}
		}
	}
	cout<<res<<endl;
	system("pause");
	return 0;
}
