#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

long long int str_to_int(string s){
	stringstream ss;
	ss<<s;
	long long int res;
	ss>>res;
	return res;
}
string int_to_str(long long int t){
	stringstream ss;
	ss<<t;
	string res;
	ss>>res;
	return res;
}
bool isPalindromic(string s){
	int i=0,j=s.size()-1;
	while(i<=j){
		if (s[i]!=s[j]) return false;
		i++;
		j--;		
	}
	return true;
}
string add(string a,string b){
	string res="";
	int sum=0,forward=0;
	string str_sum,str_forward;
	for (int i = 0; i <a.size(); ++i)
	{
	
		sum=a[i]-'0'+b[i]-'0'+forward;
		str_sum=sum%10+'0';
		forward=sum/10;
		res=str_sum+res;

	}
	if(forward!=0){
		str_forward=forward+'0';
		res=str_forward+res;
	}
	
	return res;
}
int main(int argc, char const *argv[])
{
	string orgin,re,result;
	cin>>orgin;
	result=orgin;
	int i;
	//cout<<add("9","5")<<endl;
	for ( i= 0; i <10; ++i)
	{
		if(isPalindromic(result)){
			cout<<result<<" is a palindromic number."<<endl;
			break;
		}
		re=orgin;
		reverse(re.begin(),re.end());
		result=add(re,orgin);
		cout<<orgin<<" + "<<re<<" = "<<result<<endl;
		orgin=result;
		
		
		
	}
	if(i==10)
		cout<<"Not found in 10 iterations."<<endl;
	
	

	getchar();
	system("pause");
	return 0;
}