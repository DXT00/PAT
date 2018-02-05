/*
一定要注意溢出判断！
A>0,B>0-->A+B<=0溢出!
A<0,B<0-->A+B>=0溢出!
*/

#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int N;
long long A, B, C;
bool add(long long A, long long B, long long C){
	long long D = A + B;
	//cout << A;
	//cout << B;
	if (A < 0 && B < 0 && D>=0)return false;//不要漏了D=0的情况->也是溢出
	if (A > 0 && B > 0 && D <= 0)return true;//不要漏了D=0的情况->也是溢出

	if (D>C)
		return true;
	else
		return false;
}
int main(int argc, char const *argv[])
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> A;
		
		cin >> B;
		cin>> C;
		printf("Case #%d: ", i + 1);
		if (add(A, B, C))
			printf("true\n");
		else
			printf("false\n");
	}
	system("pause");
	return 0;
}
/*
9223372036854775808 -9223372036854775807 0
9223372036854775807 -9223372036854775807 0
-9223372036854775808 -9223372036854775808 0
9223372036854775808 9223372036854775808 3
*/