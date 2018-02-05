#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

string s1,s2;
string res;
int main(int argc, char const *argv[])
{
	cin>>s1>>s2;
	for (int i = 0; i <s2.size(); )
	{
		for (int j = 0; j <s1.size(); ++j)
		{
			if(s1[j]!=s2[i])
				res+=s1[j];
			else if(s1[j]==s2[i]){
				i++;
			}
		}
	}
	std::map<char, bool> m;
	string result;
	for (int i = 0; i <res.size(); ++i)
	{
		if(res[i]>='a'&&res[i]<='z')
			res[i]=res[i]-32;

		if(m[res[i]]==false){
			m[res[i]]=true;
			result+=res[i];
		}
	}
	cout<<result<<endl;
	system("pause");
	return 0;
}