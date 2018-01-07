#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <stdio.h>
using namespace std;

/*----------------------------------------------------
设1出现的次数为res,

则res=个位1出现的次数+十位1出现的次数+百位1出现的次数+千位1出现的次数+......

设现在所在的位的数字为now,now左边的数为left,右边的数为right,基数为base,分三种情况：
//如1234 now=3时，left=12 right=4,base=10
		 now=2时，left=1  right=34,base=100
		 ......

1.now>1 res+=(left+1)*base
2.now=1 res+=left*base+right+1
3.now=0 res+=left*base

------------------------------------------------------*/


int main(int argc, char const *argv[])
{
	long long int x;
	cin>>x;
	long long int now=x%10,left=x/10,right=0,base=1,res=0;
	while(x/base){
		//cout<<now<<" "<<left<<" "<<right<<endl;
		if(now>1)res+=(left+1)*base;
		else if(now==1)res+=left*base+right+1;
		else if(now==0)res+=left*base;
		base=base*10;
		left=x/base/10;
		now=x/base%10;
		right=x%base;
	}
	cout<<res<<endl;

	getchar();
	system("pause");
	return 0;
}