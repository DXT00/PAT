#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

string s;
string v1[10] = { "", "", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi" };
string v2[10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
bool neg=false;
std::vector<string> res;
bool flag_lianxu0=false;//后四位（个位-千位）连续0标记
bool flag_lianxu0Hi=false;//前多位的连续0标记
int main(int argc, char const *argv[])
{
	cin>>s;
	if(s=="0"){
		cout<<"ling"<<endl;
		system("pause");
	return 0;
	}
	if(s[0]=='-'){
		neg=true;
		res.push_back("Fu");
		s=s.substr(1);
	}
	int size=s.size();
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i]!='0'){
			res.push_back(v2[s[i]-'0']);
			if(v1[size-i]!="")
			res.push_back(v1[size-i]);
			if(size-i<=4)
				flag_lianxu0=false;
			else if(size-i>=5)
				flag_lianxu0Hi=false;
		}
		else{
			if(size-i<=4){//后4位（个位-千位）
				if(s.substr(i)==string(size-i,'0'));//如果这一位到个位都是0，则什么都不输出
				else{
					if(flag_lianxu0==false){
						res.push_back("ling");//否则输出0
						flag_lianxu0=true;//0只输出一次，所以后面的连续的0标记起来，不输出
					}
					
				}
			}
			else{//万以上包括万位的高位
				
				 if(size-i>=5){
					if(s.substr(i,size-5-i+1)==string(size-5-i+1,'0'));//如果这一位到wan位都是0，则什么都不输出
					else{
						if(flag_lianxu0Hi==false){
							res.push_back("ling");//否则输出0
							flag_lianxu0Hi=true;//0只输出一次，所以后面的连续的0标记起来，不输出

						}
					}
				}
				if(size-i==5&&size<9)//如果这个数有亿为，万位为0时不用输出wan，否则要输出wan
					res.push_back("Wan");
			}
		}
	}

	for (int i =0; i<res.size();i++)
	{
		if(i!=0)cout<<" ";
		cout<<res[i];
	}
	system("pause");
	return 0;
}