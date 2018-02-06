/*
学会两个用法：
isalpha(a[i])-->判断是否是字母，大小写都行
isdigit(a[i])-->判断是否是数字（‘0’-‘9’）
*/

#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string Week[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
int main(int argc, char const *argv[])
{
	std::vector<string> v(4);
	for (int i = 0; i <4; ++i)
		cin >> v[i];

	string Day = "";
	int Min = -1, Second = -1,Day_i;
	for (int i = 0; i <min(v[0].length(), v[1].length()); ++i){	
		if (Day.length()==0&&v[0][i] >= 'A'&&v[0][i] <= 'G'&&v[0][i] == v[1][i]){
			Day = Week[v[0][i] - 65];
			Day_i = i;
		}
		if (Day.length() != 0&&i != Day_i&&Min == -1 && ((v[0][i] >= 'A'&&v[0][i] <= 'N') || isdigit(v[0][i])) && v[0][i] == v[1][i]){
			Min = isdigit(v[0][i]) ? (v[0][i] - '0'):( v[0][i] - 55);
			break;
		}
	}
	for (int i = 0; i <min(v[2].length(), v[3].length()); ++i)
		if ((isalpha(v[2][i]))&&v[2][i] == v[3][i]){
			Second = i;
			break;
		}

	cout << Day << " ";
	printf("%02d:%02d\n", Min, Second);
	system("pause");
	return 0;
}