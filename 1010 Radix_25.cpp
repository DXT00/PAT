/*
有坑！
注意：最大进制数不是36！
而是N1或N2对应的十进制数！
顺序查找会超时，所以采用二分查找！

如果N1或N2只有一位，则可能有多种进制-->用顺序查找找出最小radix快!
如果有多位，答案肯定是唯一的-->用二分查找！

*/


#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string N1, N2;
long long tag, radix;
long long convert_dec(string s, long long radix){

	long long res = 0;
	long long size = s.size();
	for (long long i = 0; i < size; i++)
	{
		long long xishu = (s[i] >= '0'&&s[i] <= '9') ? (s[i] - '0') : (s[i] - 87);
		if (xishu >= radix)//说明radix过小
			return -1;
		else{
			res += xishu*pow(radix, size - i - 1);
			if (res < 0)return -2;//res小于零说明radix过大溢出了！
		}		
	}
	return res;

}

long long judge(string s, long long y, long long rMax){

	long long res = 0;
	long long size = s.size();
	if (size == 1){
		for (long long r = 1; r <= rMax; r++){
			res = convert_dec(s, r);
			if (res == y)return r;
		}
	}
	else if (size>1){
		long long cur,lor = 1, hir = rMax ;
		while (lor <= hir){
			cur = (lor + hir) / 2;
			if (convert_dec(s, cur) == -1 || convert_dec(s, cur)>=0&& convert_dec(s, cur)<y)
				lor = cur + 1;
			else if (convert_dec(s, cur) == -2 ||convert_dec(s, cur)>y)
				hir = cur - 1;
			else if (convert_dec(s, cur) == y)
				return cur;
		}
	}

	return -1;
}
int main(int argc, char const *argv[])
{
	cin >> N1 >> N2 >> tag >> radix;

	long long ON1, ON2, result;
	if (tag == 1){
		ON1 = convert_dec(N1, radix);
		result = judge(N2, ON1, ON1+1 );
		if (result == -1)
			cout << "Impossible" << endl;
		else
			cout << result << endl;
	}
	else{
		ON2 = convert_dec(N2, radix);
		result = judge(N1, ON2, ON2+1);
		if (result == -1)
			cout << "Impossible" << endl;
		else
			cout << result << endl;
	}
	system("pause");
	return 0;
}