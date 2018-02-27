#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct Node
{
	Node *left, *right;
	int data;
	Node(int data) :data(data), left(NULL), right(NULL){}
};
int N;
std::vector<int> preorder;
std::vector<int> postoder;
bool flag = true;
Node* dfs(int pre_lo, int pre_hi, int post_lo, int post_hi){
	if (pre_lo > pre_hi)return NULL;
	//if (pre_lo == pre_hi)return new Node(preorder[pre_lo]);;
	Node *root = new Node(preorder[pre_lo]);
	int cur = post_lo;
	for (int i = post_lo; i <post_hi; ++i)
	{
		if (postoder[i] == preorder[pre_lo + 1]){
			cur = i;
			break;
		}
			
	}
	if (cur + 1 == post_hi)flag = false;
	root->left = dfs(pre_lo + 1, pre_lo + cur - post_lo + 1, post_lo, cur);
	root->right = dfs(pre_lo + cur - post_lo + 2, pre_hi, cur + 1, post_hi-1);
	return root;

}
int c = 0;
void inOrder(Node *root){
	if (root == NULL)return;
	inOrder(root->left);
	if (c != 0)printf(" ");
	printf("%d", root->data);
	c++;
	inOrder(root->right);
}
int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	preorder.assign(N, 0);
	postoder.assign(N, 0);
	for (int i = 0; i <N; ++i)
		scanf("%d", &preorder[i]);
	for (int i = 0; i <N; ++i)
		scanf("%d", &postoder[i]);

	Node *root;
	root = dfs(0, N - 1, 0, N - 1);
	if (flag)printf("Yes\n");
	else
		printf("No\n");

	inOrder(root);
	printf("\n");
	system("pause");
	return 0;
}