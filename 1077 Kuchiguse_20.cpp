#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
int N;
int main(int argc, char const *argv[])
{
	cin>>N;
	getchar();
	string str;
	int MINlen = 100000;
	std::vector<string> s;
	for (int i = 0; i <N; ++i){
		getline(cin, str);
		reverse(str.begin(), str.end());
		s.push_back(str);
		int len = str.length();
		if(len<MINlen)
			MINlen =len;
	}
	string res="";
	bool flag=false;
	for (int i = 0; i <MINlen; ++i){
		for (int j = 1; j <N; ++j){
			if (s[j][i] != s[0][i]){
				flag=true;
				break;
			}
		}
		if(flag)break;
		res += s[0][i];
	}
	if(res.length()==0)
		cout<<"nai"<<endl;
	else{
		reverse(res.begin(), res.end());
		cout<<res<<endl;
	}
	
	system("pause");
	return 0;
}
