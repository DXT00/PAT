#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int N,x;
struct Node
{
	Node *left,*right;
	int data;
	Node(int data):data(data),left(NULL),right(NULL){}
};
int Height(Node *root){
	if(root==NULL)
		return 0;
	return 1+max(Height(root->left),Height(root->right));
}
Node *LL(Node *root){
	Node *tmp=root->left;
	root->left=tmp->right;
	tmp->right=root;
	return tmp;
}
Node *RR(Node *root){
	Node *tmp=root->right;
	root->right=tmp->left;
	tmp->left=root;
	return tmp;
}
Node *LR(Node *root){
	root->left=RR(root->left);
	return LL(root);
}
Node *RL(Node *root){
	root->right=LL(root->right);
	return RR(root);
}
Node *insert(Node *root,int x){
	if(root==NULL)
		root=new Node(x);
	else{
		if(x<root->data){
			root->left=insert(root->left,x);
			if(Height(root->left)-Height(root->right)>1)
				root=(x<root->left->data)?LL(root):LR(root);
		}
		else {
			root->right=insert(root->right,x);
				if(Height(root->right)-Height(root->left)>1)
					root=(x>root->right->data)?RR(root):RL(root);
		}
	}

	return root;

}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	Node *root=NULL;
	for (int i = 0; i <N; ++i){
		scanf("%d",&x);
		
		root=insert(root,x);
	}
	// cout<<root->right->right->data<<endl;
	// cout<<Height(root)<<endl;
	cout<<root->data<<endl;
	system("pause");
	return 0;
}