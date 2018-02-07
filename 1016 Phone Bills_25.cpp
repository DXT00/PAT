/*
大模拟~~

这种时间的题：无论是求一段时间还是钱，都要从0开始算：(否则会麻烦死！)
如求on~~off时间-->变为：
1、求0~~on
2、求0~~off
3、on~~off = 0~~off - 0~o~n

用map记录每个用户

注意on与off匹配方法！！！
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
struct Node
{
	string name;
	int on, day, hour, min, time;

};


int Cost[24];
int N, month, day_Cost = 0;
std::vector<Node> v;
bool cmp(Node a, Node b){
	if (a.name != b.name)
		return (a.name<b.name);
	else
		return a.time<b.time;
}
double ZeroToNow(Node a){
	int money = 0;
	money += day_Cost*a.day;//a.day天的钱
	money += Cost[a.hour] * a.min;//多出来的几分钟
	for (int i = 0; i <a.hour; ++i)//从0小时开始算
		money += Cost[i] * 60;

	return money;
}
int main(int argc, char const *argv[])
{
	for (int i = 0; i <24; ++i){
		scanf_s("%d", &Cost[i]);
		day_Cost += Cost[i] * 60;
	}
	scanf_s("%d", &N);
	v.assign(N, Node());
	for (int i = 0; i <N; ++i)
	{
		string online;
		cin >> v[i].name;
		scanf_s("%d:%d:%d:%d", &month, &v[i].day, &v[i].hour, &v[i].min);
		cin >> online;

		v[i].on = (online=="on-line") ? 1 : 0;
		v[i].time = 24 * 60 * v[i].day + 60 * v[i].hour + v[i].min;
	}
	sort(v.begin(), v.end(), cmp);



	std::map<string, vector<Node> >m;
	for (int i = 1; i <v.size(); ++i)//注意这个方法！on-off匹配！！
	{
		if (v[i].name == v[i - 1].name){
			if (v[i - 1].on == 1 && v[i].on == 0){
				m[v[i - 1].name].push_back(v[i - 1]);
				m[v[i].name].push_back(v[i]);
			}
		}
	}
	/*
	0__________________|__________|
					   on        off

	money_off-money_on就是这段时间的话费！！

	千万不要从on开始算啊啊啊！
	*/
	double total;
	std::map<string, vector<Node> >::iterator it;//用map存储每个用户！！
	for (it = m.begin(); it != m.end(); it++)
	{
		vector<Node> temp = it->second;
		total = 0;
		printf("%s %02d\n", it->first.c_str(), month);
		for (int i = 1; i <temp.size(); i = i + 2)
		{
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].min, temp[i].day, temp[i].hour, temp[i].min, temp[i].time - temp[i - 1].time, (double)(ZeroToNow(temp[i]) - ZeroToNow(temp[i - 1])) / 100.0);
			total += (ZeroToNow(temp[i]) - ZeroToNow(temp[i - 1]));
		}
		printf("Total amount: $%.2lf\n", (double)total / 100.0);
	}


	system("pause");
	return 0;
}














