#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int N, K;
struct Node
{
	Node *left, *right;
	int data, red;
	Node(int data, int red) :data(data), red(red), left(NULL), right(NULL){}
};
Node* dfs(vector<int> origin, int lo, int hi){
	if (lo>hi)return NULL;
	int red = (origin[lo]<0) ? 1 : 0;
	Node*root = new Node(abs(origin[lo]), red);

	int cur = lo + 1;
	while (cur <= hi&&abs(origin[cur])<abs(origin[lo]))cur++;
	root->left = dfs(origin, lo + 1, cur - 1);
	root->right = dfs(origin, cur, hi);
	return root;
}


int c , pre;
bool find(Node *root, int BlackCnt){
	if (root == NULL){
		if (c == 0){
			pre = BlackCnt;
			c++;
			return true;
		}		
		else{
			if (BlackCnt != pre)return false;
			else
				return true;
		}
	}
	if (root->red == 1){
		if (root->left&&root->left->red == 1)return false;
		if (root->right&&root->right->red == 1)return false;
	}
	else
		BlackCnt++;
	return find(root->left, BlackCnt) && find(root->right, BlackCnt);
}
bool judge(vector<int> origin, int K){
	Node*root = dfs(origin, 0, K - 1);
	c = 0;
	if (root->red == 1)return false;
	return find(root, 0);
}
int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	for (int i = 0; i <N; ++i){
		scanf("%d", &K);
		vector<int> origin(K, 0);
		for (int j = 0; j <K; ++j)
			scanf("%d", &origin[j]);
	
		if(judge(origin, K))
			cout << "Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	system("pause");
	return 0;
}