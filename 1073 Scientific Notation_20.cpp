/*
一定要用string处理，否则指数为9999时，若用double会溢出！！

*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

string s, e_after, point_before, point_after, result;
double d_sub;
int d_expp;
int main(int argc, char const *argv[])
{
	cin >> s;
	bool neg = false;
	if (s[0] == '-')neg = true;
	int i = 1, k = 0;
	bool behind = false;
	while (s[i] != '.'){
		point_before += s[i];
		i++;
	}
	i++;
	while (s[i] != 'E'){
		k++;
		point_after += s[i];
		i++;
	}	
	i++;
	while (s[i] != '\0'){
		e_after += s[i];
		i++;
	}
	d_expp = stoi(e_after);//最大9999

	if (d_expp < 0){

		string s(-d_expp - 1, '0');//string 初始化
		result = "0." + s + point_before + point_after;
	}
	else if (d_expp > 0){
		if (k <= d_expp){
			
			string s(d_expp - k, '0');
			result = point_before + point_after + s;
		}
		else{
			result = point_before + point_after.substr(0, d_expp) + '.' + point_after.substr(d_expp);
		}
	}

	if (neg == true){
		cout << '-';
		cout << result << endl;
	}
	else
		cout << result << endl;
	
	system("pause");
	return 0;
}