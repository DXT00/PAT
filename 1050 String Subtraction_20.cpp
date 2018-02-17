#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
string S1,S2;
string res;
std::map<char, int> m;
int main(int argc, char const *argv[])
{
	getline(cin,S1);
	getline(cin,S2);
	for (int i = 0; i <S2.size(); ++i)
		m[S2[i]]=1;
	
	for (int i = 0; i < S1.size(); ++i){
		if(m[S1[i]]!=1)
			res+=S1[i];
	}
	cout<<res<<endl;
	system("pause");
	return 0;
}