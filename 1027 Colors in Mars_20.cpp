#include <algorithm>
#include <stdio.h>
using namespace std;
char c[14]={"0123456789ABC"};
int color;
int main(int argc, char const *argv[])
{
	printf("#");
	for (int i = 0; i <3; ++i){
		scanf("%d", &color);
		printf("%c%c",c[color/13],c[color%13] );
	}
	system("pause");
	return 0;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <stdio.h>
// #include <string>
// using namespace std;
// int color;
// string s,res = "#";
// int main(int argc, char const *argv[])
// {
// 	for (int i = 0; i < 3; i++){
// 		s = "";
// 		scanf("%d", &color);
// 		int cur = color;
// 		while (cur != 0){
// 			char c = (cur % 13) > 9 ? (cur % 13 + 55) : (cur % 13 + '0');
// 			s = c + s;
// 			cur /= 13;	
// 		}
// 		s = string(2 - s.size(), '0') + s;
// 		res += s;
// 	}
// 	cout << res << endl;
// 	system("pause");
// 	return 0;
// }