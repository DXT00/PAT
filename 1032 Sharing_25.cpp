/*
方法一：两个链表先对齐再查找
方法二：再开辟一个flag数组，遍历第一条链表时，把遍历过的节点置true,遍历第二条链表时若有节点是true,立即返回
我采用了方法一。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int S1,S2,N,x,y,cur1,cur2;
char c[2];
int v[100002];
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&S1,&S2,&N);
	for (int i = 0; i <N; ++i){
		scanf("%d%s%d",&x,&c,&y);
		v[x]=y;
	}
	int len1=0,len2=0,cur=S1;
	while(cur!=-1){
		len1++;
		cur=v[cur];
	}
	cur=S2;
	while(cur!=-1){
		len2++;
		cur=v[cur];
	}
	if(len1>len2){
		cur1=S1;cur2=S2;
	}
	else {
		cur1=S2;cur2=S1;
	}
	int k=0;
	while(k<abs(len1-len2)){
		cur1=v[cur1];
		k++;
	}
	while(cur1!=cur2){
		cur1=v[cur1];
		cur2=v[cur2];
	}
	if(cur1==-1)cout<<-1<<endl;
	else
		printf("%05d\n",cur1 );
	system("pause");
	return 0;
}