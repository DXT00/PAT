#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <map>
using namespace std;
int N;
std::map<string, int> m1, m2;
string msl[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string msh[13] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
void judge(string s){
	if (isdigit(s[0])){
		int hi = stoi(s) / 13;
		int lo = stoi(s) % 13;
		if (stoi(s) == 0) { cout << msl[0] << endl; return; }				//这里一定要注意格式啊，卡了好一会！！！
		//if (hi != 0)
			cout << msh[hi];
			if (hi != 0 && lo != 0)cout << " " << msl[lo] << endl;
			else if (lo != 0)
				cout << msl[lo] << endl;
			else if (lo == 0)
				cout << endl;
	}
	else{
		int res = 0;
		string a[2];
		int i = 0,k=0;
		while (s[i] != ' '&&s[i] != '\0'){
			a[k] += s[i];
			i++;
		}
		if (s[i] == ' '){
			k++;
			i++;
			while (s[i] != '\0'){
				a[k] += s[i];
				i++;
			}
		}
		int size = k+1;
		for (int i = 0; i <size; ++i)
		{
			if (m1[a[i]] != 0){
				res += m1[a[i]];
			}
			if (m2[a[i]] != 0){
				res += m2[a[i]] * 13;
			}
		}
		cout << res << endl;
	}

}
int main(int argc, char const *argv[])
{

	for (int i = 1; i <= 12; ++i)
	{
		m1[msl[i]] = i;
		m2[msh[i]] = i;
	}
	cin >> N;
	getchar();
	string s;
	for (int i = 0; i < N; i++){
		getline(cin,s);
		judge(s);
	}
	
	system("pause");
	return 0;
}