#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;
int N;
struct Node
{
	int data;
	Node *left,*right;
	Node(int data):left(NULL),right(NULL),data(data){}
};

std::vector<int> v;
Node* dfs1(vector<int> v,int lo,int hi){
	if(lo>hi)return NULL;
	
	int cur=lo+1;
	while(cur<=hi&&v[cur]<v[lo]){
		cur++;
	}
	for (int i = cur; i <=hi; ++i)
	{
		if(v[i]<v[lo]){
			return NULL;
		}
	}
	Node *root=new Node(v[lo]);
	root->left=dfs1(v,lo+1,cur-1);
	root->right=dfs1(v,cur,hi);

	return root;

}
Node* dfs2(vector<int> v,int lo,int hi){
	if(lo>hi)return NULL;
	
	int cur=lo+1;
	while(cur<=hi&&v[cur]>=v[lo]){
		cur++;
	}
	for (int i = cur; i <=hi; ++i)
	{
		if(v[i]>=v[lo]){
			return NULL;
		}
	}
	Node *root=new Node(v[lo]);
	root->left=dfs2(v,lo+1,cur-1);
	root->right=dfs2(v,cur,hi);

	return root;

}
int cnt=0,c=0;
std::vector<int> res;
void postOrder(Node *root){
	if(root==NULL)return;
	postOrder(root->left);
	postOrder(root->right);
	res.push_back(root->data);
}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	v.assign(N,0);
	Node *root;
	for (int i = 0; i <N; ++i)
	{
		scanf("%d",&v[i]);
	}
	if(v.size()==1)
		printf("YES\n%d",v[0]);
	else{
		if(v[1]<v[0])
			root=dfs1(v,0,N-1);
		else
			root=dfs2(v,0,N-1);

	
		postOrder(root);
		if(res.size()<N)
			printf("NO\n");
		else{
			printf("YES\n");
			for (int i = 0; i <res.size(); ++i)
			{
				if(i!=0)printf(" ");
				printf("%d",res[i]);
			}
		}

	}
	//cout<<root->left->left->data<<endl;
	system("pause");
	return 0;
}