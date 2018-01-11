#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
string convert_2_str(int a){
	stringstream ss;
	ss<<a;
	string res;
	ss>>res;
	while(res.size()<4){
		res='0'+res;
	}
	return res;
}
int convert_2_int(string a){
	stringstream ss;
	ss<<a;
	int res;
	ss>>res;
	return res;
}
int main(int argc, char const *argv[])
{
	string s,s_r;
	cin>>s;
	// while(s.size()<4){
	// 	s='0'+s;
	// }
	s.insert(0,4-s.size(),'0');//从下标为0开始插入4-s.size()个‘0’
	int pre_result=0,result=0;
	while(true){	
		sort(s.begin(), s.end());
		s_r=s;
		reverse(s_r.begin(), s_r.end());
		

		if(s_r==s){
			printf("%s %s %s %s %04d\n",s_r.c_str(),"-",s.c_str(),"=",0);		
			break;
		}
		
		result=convert_2_int(s_r)-convert_2_int(s);	
		printf("%s %s %s %s %04d\n",s_r.c_str(),"-",s.c_str(),"=",result);
		
		if(result==6174||result==0) break;
	
		s=convert_2_str(result);

	}
	getchar();
	system("pause");
	return 0;
}

/*----------------c++11代码：---------

string转int用：stoi()
int转string用：to_string()

------------------------------------*/
/*

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string s, s_r;
	cin >> s;
	// while(s.size()<4){
	// 	s='0'+s;
	// }
	s.insert(0, 4 - s.size(), '0');
	int pre_result = 0, result = 0;
	while (true){
		sort(s.begin(), s.end());
		s_r = s;
		reverse(s_r.begin(), s_r.end());


		if (s_r == s){
			printf("%s %s %s %s %04d\n", s_r.c_str(), "-", s.c_str(), "=", 0);
			break;
		}

		result = stoi(s_r) - stoi(s);
		printf("%s %s %s %s %04d\n", s_r.c_str(), "-", s.c_str(), "=", result);

		if (result == 6174 || result == 0) break;

		s = to_string(result);
		s.insert(0, 4 - s.size(), '0');

	}
	getchar();
	system("pause");
	return 0;
}













*/
