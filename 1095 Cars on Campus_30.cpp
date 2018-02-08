/*
一定要在询问之前把所有的数据都算好了~不要一边一边询问一遍查！（最大询问次数：80000-->会超时！）
还有更简洁的方法：参考柳婼~https://www.liuchuo.net/archives/2951
下次再改！

*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;
int N, K;
struct Node
{
	string name;
	int hour, min, second, time, in;
	Node() :time(-1){}
};
std::vector<Node> v;

bool cmp(Node a, Node b){
	if (a.name != b.name)return a.name<b.name;
	else
		return a.time<b.time;
}
bool cmp2(Node a, Node b){
	return a.time<b.time;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &K);
	v.assign(N, Node());
	int ho, mi, se, ti;

	for (int i = 0; i <N; ++i)
	{
		char na[7], status[3];
		string sta;
		cin >> v[i].name;
		scanf("%d:%d:%d", &ho, &mi, &se);
		cin >> sta;
		ti = 3600 * ho + 60 * mi + se;
		v[i].hour = ho;
		v[i].min = mi;
		v[i].second = se;
		v[i].in = (sta == "in") ? 1 : 0;
		v[i].time = ti;
	}

	sort(v.begin(), v.end(), cmp);
	int total = 0, Max = -1;
	std::vector<string> res;
	std::vector<Node> Qres;
	int i;
	for (i = 1; i <N; ++i)
	{
		if (v[i].name == v[i - 1].name){//in和out匹配
			if (v[i - 1].in == 1 && v[i].in == 0){
				total += (v[i].time - v[i - 1].time);
				Qres.push_back(v[i - 1]);
				Qres.push_back(v[i]);
			}
		}
		else{
			if (total>Max){			//找出最长时间
				Max = total;
				res.clear();
				res.push_back(v[i - 1].name);
			}
			else if (total == Max){
				res.push_back(v[i - 1].name);
			}
			total = 0;
		}
	}
	if (total>Max){
		Max = total;
		res.clear();
		res.push_back(v[i - 1].name);
	}
	else if (total == Max){
		res.push_back(v[i - 1].name);
	}
	sort(Qres.begin(), Qres.end(), cmp2);
	int k = 0;
	int timee[86405];
	int pre = 0, num = 0;
	int size = Qres.size();
	for (int i = 0; k<size && i <86400; ++i)	//统计每一时刻的车辆数~Qres是按时间排序的
	{

		while (k<size&&i == Qres[k].time){//如果某一时间等于有车辆进入或出去的时间~根据in或out~统计该时间段停车场的车辆数
										//这里注意：有可能同一时刻有多辆车进入或出去~所以用while不用if
			if (Qres[k].in == 1)num++;
			else
				num--;

			timee[i] = num;
			pre = num;
			k++;
		}
			timee[i] = pre;
	}
	int query;
	for (int i = 0; i <K; ++i)
	{
		scanf("%d:%d:%d", &ho, &mi, &se);
		query = 3600 * ho + 60 * mi + se;
		printf("%d\n",timee[query]);
	}
	for (int i = 0; i <res.size(); ++i)
		printf("%s ", res[i].c_str());
	printf("%02d:%02d:%02d\n", Max / 3600, Max % 3600 / 60, Max % 3600 % 60);
	system("pause");
	return 0;

}

/*



ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in

ZA3Q625 11:42:01 out

ZA3Q625 06:30:50 in

ZA3Q625 23:55:00 in

ZA133CH 17:11:22 out

DB8888A 06:30:50 in
*/
// //JH007BD 05:09:59 in 18599
// JH007BD 05:10:33 in 18633
// JH007BD 12:23:42 out 44622

// //JH007BD 12:24:23 out
// JH007BD 18:00:01 in
// JH007BD 18:07:01 out 420