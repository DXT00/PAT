/*
大模拟~~ = =！
小白做法：按照时间遍历~~好像也不超时->->
维持两个队列：
s:包括vip和普通用户
vipInque：vip用户

判断每一时刻：
1、是否有桌子释放了
2、是否有人到达-->插入s队列，若是vip还要插入vipInque队列
3、vipInque队列是否有vip客户-->有的话分配vip桌子，（当然用个数组记录哪些是vip桌子~），并从两个队列删除。
	没有分配到vip桌子的vip用户任然在s队列中，所以直接下一步：
4、s队列中是否有用户（包括普通用户和哪些没分配到vip桌子的用户）-->有的话分配普通桌子~若是普通用户则从s删除，若是vip则还要在vipInque队列中删除！
5、最后记得在遍历时用个res数组记下拿到桌子的节点就好啦！^-^~~

*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;
int N, K, M, Tvip, x;
struct Node
{
	int id, hour, min, second, time, playtime, vip, waittime, servetime;
	Node() :time(-1){}
};
struct TNode//桌子节点
{
	int cnt;
	bool full, vip;
	int start, end;//end为这张桌子上的用户结束时间
	TNode() :cnt(0), full(false), vip(false){}
};
std::vector<Node> v(75605);
std::vector<TNode> table;//记录所有桌子
std::vector<int> vipTable;//记录vip桌子编号
std::vector<Node> res;

bool cmp1(Node a, Node b){
	return a.servetime < b.servetime;
}
int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	int h, m, se, p, vi, ti;
	for (int i = 0; i <N; ++i){
		scanf("%d:%d:%d%d%d", &h, &m, &se, &p, &vi);
		ti = h * 3600 + m * 60 + se;
		if (p>120)p = 120;//此处有坑！大于2小时的要按2小时算！！
		v[ti].hour = h; v[ti].min = m, v[ti].second = se; v[ti].playtime = p; v[ti].vip = vi; v[ti].time = ti;
	}
	scanf("%d%d", &K, &M);
	table.assign(K + 1, TNode());
	for (int i = 0; i <M; ++i)
	{
		scanf("%d", &x);
		table[x].vip = true;
		vipTable.push_back(x);
	}
	sort(vipTable.begin(), vipTable.end());

	set<int> s;//又有vip又有普通
	set<int> vipInque;//vip队列
	for (int i = 0; i <28800; ++i)//有坑！！有人会8：00前就到了= =！
	{
		if (v[i].time != -1){//这一时刻有人到来
			s.insert(i);//插入队伍中
			if (v[i].vip == true)
				vipInque.insert(i);
			//cout<<"ren "<<i<<endl;
		}
	}
	for (int i = 28800; i <75600; ++i)//有坑！只计算21：00前到达的
	{

		//看看有没有桌子在此刻释放
		for (int t = 1; t <table.size(); ++t)
		{
			if (table[t].full == true && table[t].end == i){
				table[t].full = false;
			}
		}

		if (v[i].time != -1){//这一时刻有人到来
			s.insert(i);//插入队伍中
			if (v[i].vip == true)//是vip的话还要插入vip队伍
				vipInque.insert(i);
		}

		while (!vipInque.empty()){//先看vip桌子，队伍中有vip
			set<int>::iterator it = vipInque.begin();
			bool flag1 = false;
			for (int j = 0; j<vipTable.size(); j++){
				if (table[vipTable[j]].full == false){//有vip桌子，先分配了
					flag1 = true;
					table[vipTable[j]].full = true;
					table[vipTable[j]].cnt++;
					table[vipTable[j]].start = *it;
					table[vipTable[j]].end = i + v[*it].playtime * 60;
					v[*it].servetime = i;
					v[*it].waittime = i - *it;
					res.push_back(v[*it]);
					int index = *it;
					set<int>::iterator itf = s.find(index);
					if (itf != s.end())
						s.erase(itf);
					vipInque.erase(it);
					break;
				}
			}
			if (flag1 == false)//没桌子可分
				break;
		}
		while (!s.empty()){	//没有vip,或有vip没有vip桌子

			set<int>::iterator its = s.begin();//队头元素
			bool flag2 = false;
			for (int k = 1; k<table.size(); ++k)
			{
				if (table[k].full == false){//有桌子
					flag2 = true;
					table[k].full = true;
					table[k].cnt++;
					table[k].start = *its;
					table[k].end = i + v[*its].playtime * 60;
					v[*its].servetime = i;
					v[*its].waittime = i - *its;
					if (v[*its].vip == true){
						int index2 = *its;
						set<int>::iterator itf2 = vipInque.find(index2);
						if (itf2 != vipInque.end())
							vipInque.erase(itf2);	//有坑！！这里不止有普通客户，还有可能是那些vip没有vip桌子的，所以，分配到普通桌子后，也要在vip队列中删掉这些人的编号！！-->卡了老半天==
					}
					res.push_back(v[*its]);
					s.erase(its);
					break;
				}
			}
			if (flag2 == false)break;//没有桌子->等待
		}

	}
	sort(res.begin(), res.end(), cmp1);
	for (int i = 0; i <res.size() && res[i].servetime<75600; ++i)
	{
		int severh = res[i].servetime / 3600;
		int severm = res[i].servetime % 3600 / 60;
		int servers = res[i].servetime % 3600 % 60;
		int wait = round((double)res[i].waittime / 60);
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", res[i].hour, res[i].min, res[i].second, severh, severm, servers, wait);
	}
	for (int i = 1; i < table.size(); i++){
		if (i != 1)printf(" ");
		printf("%d", table[i].cnt);
	}
	system("pause");
	return 0;
}
/*
一些测试用例：
//vip桌子分配例子，有vip桌子时，优先把vip分到编号小的vip桌子，没有的话当作普通用户！！
4
06:00:00 30 1
08:00:00 30 1
10:00:00 30 1
12:00:00 30 1
5 1
3
答案为：
06:00:00 08:00:00 120
08:00:00 08:00:00 0
10:00:00 10:00:00 0
12:00:00 12:00:00 0
1 0 3 0 0

//超过两小时的例子
2
18:00:00 180 1
20:00:00 60 1
1 1
1
答案为：
18:00:00 18:00:00 0
20:00:00 20:00:00 0
2

//关于四舍五入为1分钟的例子，大约等于30秒才+1分钟，小于30则不+
3
07:59:31 60 1
07:59:29 60 1
08:00:30 100 1
2 1
1
答案为：
1
07:59:29 08:00:00 1
07:59:31 08:00:00 0
08:00:30 09:00:00 60
2 1
*/
