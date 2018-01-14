//!!想复杂了！
// #include <iostream>
// #include <vector>
// #include <stdio.h>
// #include <algorithm>
// #include <string>

// using namespace std;

// int main(int argc, char const *argv[])
// {
// 	string s;
// 	int res = 0;
// 	cin >> s;
// 	int N = s.size();
// 	std::vector<int> p;
// 	std::vector<int> a;
// 	std::vector<int> t;
// 	std::vector<int> pc(N);
// 	std::vector<int> ac(N);
// 	std::vector<int> tc(N);
// 	for (int i = s.size() - 1; i >= 0; i--)
// 	{
// 		if (s[i] == 'P'){
// 			p.push_back(i);
// 			pc[i] = a.size();
// 		}
// 		else if (s[i] == 'A'){
// 			a.push_back(i);
// 			ac[i] = t.size();
// 		}
// 		else
// 			t.push_back(i);
// 	}

// 	for (int i = 0; i <p.size(); ++i)
// 	{
// 		for (int j = 0; j<pc[p[i]]; j++){//p[i]后头有pc[p[i]]个A
// 			res += ac[a[j]];
// 		}
// 	}
// 	cout << res << endl;
// 	getchar();
// 	system("pause");
// 	return 0;
// }
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	long long int p=0,pa=0,pat=0;
	for (int i = 0; i <s.size(); ++i)
	{
		if(s[i]=='P'){
			p++;
		}
		else if(s[i]=='A'){
			pa+=p;
		}
		else if(s[i]=='T'){
			pat+=pa;
		}
	}
	cout<<pat%1000000007<<endl;
	getchar();
	system("pause");
	return 0;
}