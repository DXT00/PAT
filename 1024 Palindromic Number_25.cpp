#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;
string s;
int N;
bool isPalindromic(string a){
	int i = 0, size=a.size();//j = a.size() - 1;
	while (i <= size-i-1){
		if (a[i] != a[size-i-1])
			return false;
		i++;
	}
	return true;
}
string add(string a, string b){//a和b是等长的！
	int i = a.size() - 1,j = b.size() - 1,forward=0;
	string res;
	while (i >= 0 && j >= 0){
		int cur = a[i] + b[j] - '0' - '0'+forward;
		res = to_string(cur % 10) + res;
		forward = cur / 10;
		i--;
		j--;
	}
	if (forward!=0)
	res = "1"+ res;
		
	return res;
}
int main(int argc, char const *argv[])
{	
	cin >> s >> N;
	bool flag = false;
	string res,origin = s; 
	int i,index;
	for ( i= 0; i <=N; i++){
		if (isPalindromic(origin)){
			flag = true;
			index = i;
			res = origin;
			break;
		}
		res = origin;
		s = origin;
		reverse(s.begin(), s.end());
		origin=add(origin, s);
	}
	if (!flag)
		index = N;

	cout << res << endl;
	cout << index << endl;
	
	system("pause");
	return 0;
}