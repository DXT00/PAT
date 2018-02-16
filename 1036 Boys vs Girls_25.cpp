#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
struct Node
{
	string name,id;
	int grade;
	Node(string name,string id,int grade):name(name),id(id),grade(grade){}
};
int N,gra;
vector<Node> male;
vector<Node> female;
bool flag1=false,flag2=false;
bool cmp1(Node a,Node b){return a.grade>b.grade;}
bool cmp2(Node a,Node b){return a.grade<b.grade;}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for (int i = 0; i <N; ++i){
		char c;//一定要把char c]放这！！,不然会缓存上一次输入的值
		char na[15],id[15];
		scanf("%s %c %s %d",na,&c,id,&gra);
		if(c=='M')
			male.push_back(Node(string(na),string(id),gra));
		else
			female.push_back(Node(string(na),string(id),gra));
	}
	if(female.size()==0){
		flag1=true;
		printf("Absent\n");
	}
	else{
		sort(female.begin(), female.end(),cmp1);
		printf("%s %s\n",female[0].name.c_str(),female[0].id.c_str());
	}
	if(male.size()==0){
		flag2=true;
		printf("Absent\n");
	}
	else{
		sort(male.begin(), male.end(),cmp2);
		printf("%s %s\n",male[0].name.c_str(),male[0].id.c_str());
	}
	
	if(flag1==true||flag2==true)
		printf("NA\n");
	else
		printf("%d\n",female[0].grade-male[0].grade);
	
	system("pause");
	return 0;
}