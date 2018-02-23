#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
string origin,s;
std::vector<char> v;
std::map<char, bool> m;
int main(int argc, char const *argv[])
{
	cin>>origin>>s;
	int i=0,j=0;
	while(i<origin.size()){
		if(origin[i]!=s[j]){
			char cur=isalpha(origin[i])?toupper(origin[i]):origin[i];
			if(m[cur]==false){
				v.push_back(cur);
				m[cur]=true;
			}	
		}
		else{
			j++;
		}
		i++;
	}
	for (int i = 0; i <v.size(); ++i)
		cout<<v[i];
	
	system("pause");
	return 0;
}
