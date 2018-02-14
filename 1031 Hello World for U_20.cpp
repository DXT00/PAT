#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s,str;
int main(int argc, char const *argv[])
{
	cin>>s;
	int N=s.size(),n2;
	for(int i=3;i<N;i++){
		if((N-i)%2==0&&(N-i)/2+1<=i){
			n2=i;
			break;
		}
	}
	int n1=(N-n2)/2,k=0;
	str=string(n2-2,' ');
	while(k<n1){
		cout<<s[k]<<str<<s[N-k-1]<<endl;
		k++;
	}
	cout<<s.substr(n1,n2);
	system("pause");
	return 0;
}