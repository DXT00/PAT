#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <sstream>
#include <algorithm>
using namespace std;
int N;
double res;
bool judge(string s){
	int cnt_point = 0,dot=-1;
	int i = (s[0] == '-') ? 1 : 0;
	for (; i < s.size(); i++){		
		if (!(s[i] <= '9'&&s[i] >= '0') && s[i] != '.')return false;
		else if (s[i] == '.'){			
			cnt_point++;
			if (cnt_point>1)return false;
			if (s.size() - i>3)return false;	
		}
	}
	res = stod(s);//c++11
	if (res <=1000 && res >=-1000)return true;
	return false;
}
int main(int argc, char const *argv[])
{
	string s;
	double sum = 0.0;
	int sum_cnt = 0;
	cin >> N;
	for (int i = 0; i <N; ++i)
	{
		cin >> s;
		if (judge(s)){
			sum += res;
			sum_cnt++;
		}
		else
			cout << "ERROR: " << s << " is not a legal number" << endl;
	}
	if (sum_cnt == 0)
		printf("The average of 0 numbers is Undefined\n");
	else if (sum_cnt == 1)
		printf("The average of 1 number is %.2lf\n", sum );		
	else
	printf("The average of %d numbers is %.2lf\n", sum_cnt, sum / sum_cnt);
	getchar();
	system("pause");
	return 0;
}