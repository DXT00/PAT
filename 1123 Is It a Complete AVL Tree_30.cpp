#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
using namespace std;
int N;
struct Node
{
	Node *left,*right;
	int data;
	Node(int data):data(data),left(NULL),right(NULL){}
};
std::vector<int> v;
int Height(Node *root){
	if(root==NULL)return 0;
	return 1+max(Height(root->left),Height(root->right));
}
Node* LL(Node *root){
	Node *temp=root->left;
	root->left=temp->right;
	temp->right=root;
	return temp;
}
Node* RR(Node *root){
	Node *temp=root->right;
	root->right=temp->left;
	temp->left=root;
	return temp;
}
Node* LR(Node *root){
	root->left=RR(root->left);
	return LL(root);
}
Node* RL(Node *root){
	root->right=LL(root->right);
	return RR(root);
}
Node *insert(Node *root,int x){
	if(root==NULL)
		return new Node(x);
	if(x<root->data){
		root->left=insert(root->left,x);
		if(Height(root->left)-Height(root->right)>1){
			root=(x<root->left->data)?LL(root):LR(root);
		}
	}
	else{
		root->right=insert(root->right,x);
		if(Height(root->right)-Height(root->left)>1){
			root=(x>root->right->data)?RR(root):RL(root);
		}
	}
	return root;
}
int c=0;
bool level(Node *root){
	int cnt=0;
	std::vector<int> res;
	bool flag=true;
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){

		Node *w=q.front();
		q.pop();
		cnt++;
		if(w==NULL){
			if(cnt<N+1){
				flag=false;
			}
		}
		else{
			res.push_back(w->data);
			
			q.push(w->left);
			q.push(w->right);
		}

	}
	for (int i = 0; i <res.size(); ++i)
	{
		if(i!=0)printf(" ");
		printf("%d",res[i]);
	}
	printf("\n");
	if(flag)printf("YES\n");
	else
		printf("NO\n");

}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	v.assign(N,0);
	for (int i = 0; i <N; ++i)
		scanf("%d",&v[i]);
	Node *root=NULL;
	for (int i = 0; i <N; ++i)
	{
		root=insert(root,v[i]);
	}
	level(root);
	system("pause");
	return 0;
}