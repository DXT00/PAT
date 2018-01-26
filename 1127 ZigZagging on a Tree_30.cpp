#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int N;
std::vector<int> in;
std::vector<int> post;
struct Node
{
	int data, level;
	Node *left, *right;
	Node(int data) :left(NULL), right(NULL),data(data){}
};
Node *dfs(int in_lo, int in_hi, int post_lo, int post_hi){
	if (in_lo > in_hi)return NULL;

	Node *root = new Node(post[post_hi]);
	int i;
	for (i = in_lo; i <= in_hi; ++i)
	{
		if (in[i] == post[post_hi]){
			break;
		}		
	}
	
	root->left=dfs(in_lo, i - 1, post_lo, post_lo + i - 1 - in_lo);
	root->right=dfs(i + 1, in_hi, post_lo + i - in_lo, post_hi - 1);

	return root;
}

std::vector<vector<int> > v(100);//用于记录每层都有哪些节点！

void bfs(Node *root){	//统计每个节点的层数
	queue<Node*> q;	
	root->level = 0;
	q.push(root);
	while (!q.empty()){
		Node *w = q.front();
		q.pop();

		v[w->level].push_back(w->data);
		if (w->left != NULL){
			w->left->level = w->level + 1;
			q.push(w->left);
		}
		if (w->right != NULL){
			w->right->level = w->level + 1;
			q.push(w->right);
		}

	}

}
int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	post.assign(N, 0);
	in.assign(N, 0);	
	for (int i = 0; i <N; ++i)
		scanf("%d", &in[i]);
	for (int i = 0; i < N; ++i)
		scanf("%d", &post[i]);

	Node *res_root;
	res_root=dfs(0, N - 1, 0, N - 1);
	bfs(res_root);
	int cnt=0;
	for (int i = 0; i <v.size(); ++i)//循环输出v
	{
		if(v[i].size()==0)break;
		if(i%2==0){
			for(int j=v[i].size()-1;j>=0;j--){
				if(cnt==0){
					printf("%d", v[i][j]);cnt++;
				}
				else
					printf(" %d",v[i][j] );
			}
		}
		else{
			for (int j = 0; j <v[i].size(); ++j)
			{
				printf(" %d",v[i][j] );
			}
		}			
	}
	printf("\n");
	getchar();
	system("pause");
	return 0;
}