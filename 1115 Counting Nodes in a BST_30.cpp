#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <set>
using namespace std;
int N,MAXLevel=-1;
struct Node
{
	Node *left,*right;
	int data;
	Node(int data):data(data),left(NULL),right(NULL){}
};
std::vector<int> v;
std::vector<int> resLevel(1002);
Node *insert(Node *root,int x,int level){
	if(root==NULL){
		root=new Node(x);
		MAXLevel=max(MAXLevel,level);
		resLevel[level]++;
	}
	else{
		if(x<=root->data)
			root->left=insert(root->left,x,level+1);
		else
			root->right=insert(root->right,x,level+1);
	}
	return root;
	
}

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	v.assign(N,0);
	Node *root=NULL;
	for (int i = 0; i <N; ++i)
		scanf("%d",&v[i]);
	for (int i = 0; i <N; ++i){
		root=insert(root,v[i],1);
	}
	cout<<resLevel[MAXLevel]<<" + "<<resLevel[MAXLevel-1]<<" = "<<resLevel[MAXLevel]+resLevel[MAXLevel-1];

	system("pause");
	return 0;
}