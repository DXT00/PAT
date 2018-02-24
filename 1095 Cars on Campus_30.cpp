/*
一定要在询问之前把所有的数据都算好了~不要一边一边询问一遍查！（最大询问次数：80000-->会超时！）
*/
#include <vector>
#include <iostream>
#include<algorithm>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;
int N,K,ho,mi,se;

struct Node
{
	string id;
	int hour,min,second,time,in;
};
vector<Node> v,longest,res;
bool cmp(Node a,Node b){
	return a.time<b.time;
}
bool cmp1(Node a,Node b){
	if(a.id!=b.id)return a.id<b.id;
	else
		return a.time<b.time;
}
int main(int argc, char const *argv[])
{
	char idd[10],sta[5];
	scanf("%d%d\n",&N,&K);
	v.assign(N,Node());
	for (int i = 0; i <N; ++i){
		scanf("%s %d:%d:%d %s\n",idd,&ho,&mi,&se,sta);//scanf()要把格式写好了，特别是带有%s时！不要漏了\n
		v[i].id=string(idd);
		v[i].hour=ho;
		v[i].min=mi;
		v[i].second=se;
		v[i].time=3600*v[i].hour+60*v[i].min+v[i].second;
		v[i].in=(sta[0]=='i')?1:0;
	}
	sort(v.begin(), v.end(),cmp1);
	int total=0,MAX=-1;
	for (int i = 1; i <v.size(); ++i){
		if(v[i].id==v[i-1].id){
			if(v[i-1].in==1&&v[i].in==0){
				total+=v[i].time-v[i-1].time;
				res.push_back(v[i-1]);
				res.push_back(v[i]);
			}
			
		}
		if(v[i].id!=v[i-1].id||i==v.size()-1){//注意不要漏了最后一个也要与MAX比较!
			if(total>MAX){
				MAX=total;
				longest.clear();
				longest.push_back(v[i-1]);
			}
			else if(total==MAX){
				longest.push_back(v[i-1]);
			}
			total=0;
		}
	}
	sort(res.begin(),res.end(),cmp);
	for(int i = 0; i <K; ++i){
		scanf("%d:%d:%d",&ho,&mi,&se);
		int w=3600*ho+60*mi+se;
		int num=0;

		for (int i = 0; i <res.size()&&res[i].time<=w; ++i){
			if(res[i].in==1)num++;
			else num--;
		}
		printf("%d\n",num);
	}
	for (int i = 0; i <longest.size(); ++i)
		printf("%s ",longest[i].id.c_str() );
	
	printf("%02d:%02d:%02d\n",MAX/3600,MAX%3600/60,MAX%3600%60);
	
	system("pause");
	return 0;
}
// #include <iostream>
// #include <vector>
// #include <stdio.h>
// #include <algorithm>
// #include <string>
// #include <set>
// #include <map>
// using namespace std;
// int N, K;
// struct Node
// {
// 	string name;
// 	int hour, min, second, time, in;
// 	Node() :time(-1){}
// };
// std::vector<Node> v;

// bool cmp(Node a, Node b){
// 	if (a.name != b.name)return a.name<b.name;
// 	else
// 		return a.time<b.time;
// }
// bool cmp2(Node a, Node b){
// 	return a.time<b.time;
// }
// int main(int argc, char const *argv[])
// {
// 	scanf("%d%d", &N, &K);
// 	v.assign(N, Node());
// 	int ho, mi, se, ti;

// 	for (int i = 0; i <N; ++i)
// 	{
// 		char na[7], status[3];
// 		string sta;
// 		cin >> v[i].name;
// 		scanf("%d:%d:%d", &ho, &mi, &se);
// 		cin >> sta;
// 		ti = 3600 * ho + 60 * mi + se;
// 		v[i].hour = ho;
// 		v[i].min = mi;
// 		v[i].second = se;
// 		v[i].in = (sta == "in") ? 1 : 0;
// 		v[i].time = ti;
// 	}

// 	sort(v.begin(), v.end(), cmp);
// 	int total = 0, Max = -1;
// 	std::vector<string> res;
// 	std::vector<Node> Qres;
// 	int i;
// 	for (i = 1; i <N; ++i)
// 	{
// 		if (v[i].name == v[i - 1].name){//in和out匹配
// 			if (v[i - 1].in == 1 && v[i].in == 0){
// 				total += (v[i].time - v[i - 1].time);
// 				Qres.push_back(v[i - 1]);
// 				Qres.push_back(v[i]);
// 			}
// 		}
// 		else{
// 			if (total>Max){			//找出最长时间
// 				Max = total;
// 				res.clear();
// 				res.push_back(v[i - 1].name);
// 			}
// 			else if (total == Max){
// 				res.push_back(v[i - 1].name);
// 			}
// 			total = 0;
// 		}
// 	}
// 	if (total>Max){
// 		Max = total;
// 		res.clear();
// 		res.push_back(v[i - 1].name);
// 	}
// 	else if (total == Max){
// 		res.push_back(v[i - 1].name);
// 	}
// 	sort(Qres.begin(), Qres.end(), cmp2);
// 	int k = 0;
// 	int timee[86405];
// 	int pre = 0, num = 0;
// 	int size = Qres.size();
// 	for (int i = 0; k<size && i <86400; ++i)	//统计每一时刻的车辆数~Qres是按时间排序的
// 	{

// 		while (k<size&&i == Qres[k].time){//如果某一时间等于有车辆进入或出去的时间~根据in或out~统计该时间段停车场的车辆数
// 										//这里注意：有可能同一时刻有多辆车进入或出去~所以用while不用if
// 			if (Qres[k].in == 1)num++;
// 			else
// 				num--;

// 			timee[i] = num;
// 			pre = num;
// 			k++;
// 		}
// 			timee[i] = pre;
// 	}
// 	int query;
// 	for (int i = 0; i <K; ++i)
// 	{
// 		scanf("%d:%d:%d", &ho, &mi, &se);
// 		query = 3600 * ho + 60 * mi + se;
// 		printf("%d\n",timee[query]);
// 	}
// 	for (int i = 0; i <res.size(); ++i)
// 		printf("%s ", res[i].c_str());
// 	printf("%02d:%02d:%02d\n", Max / 3600, Max % 3600 / 60, Max % 3600 % 60);
// 	system("pause");
// 	return 0;

// }

// /*



