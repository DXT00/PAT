#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;

struct Node
{
	int time, process, wait;
	Node(int time,int process):time(time),process(process){}
};
int N, M,hour,minn,second,ti,pro;
int res=0;
std::vector<Node> v;
std::vector<int> windows;
bool cmp(Node a, Node b){
	return a.time<b.time;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &M);
	windows.assign(M, 28800);

	for (int i = 0; i <N; ++i){
		scanf("%d:%d:%d%d", &hour, &minn, &second, &pro);
		ti = 3600 * hour + 60 * minn + second;
		if(ti>61200)continue;
		if(pro>60)pro=60;
		v.push_back(Node(ti,pro));
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i <v.size(); ++i){
		int MIN=99999999,MIN_j;
		for (int j = 0; j <M; ++j){
			if(windows[j]<MIN){
				MIN=windows[j];
				MIN_j=j;
			}
		}

		if(v[i].time<windows[MIN_j]){
			v[i].wait=windows[MIN_j]-v[i].time;
			res+=v[i].wait;
			windows[MIN_j]+=v[i].process*60;
		}
		else{
			v[i].wait=0;
			windows[MIN_j]=v[i].time+v[i].process*60;
		}
	}

	if(v.size()==0)printf("0.0\n");
	else
	printf("%.1lf\n",(double)res/(v.size()*60.0));

	system("pause");
	return 0;
}












// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <stdio.h>
// #include <queue>
// using namespace std;
// struct NodeW
// {
// 	int num, endTime;
// 	NodeW() :num(0){}
// };
// struct Node
// {
// 	int hour, min, second, time, process, wait;
// };
// int N, M;
// std::vector<Node> v;
// std::vector<NodeW> windows;
// bool cmp(Node a, Node b){
// 	return a.time<b.time;
// }
// int main(int argc, char const *argv[])
// {
// 	scanf("%d%d", &N, &M);
// 	v.assign(N, Node());
// 	windows.assign(M, NodeW());
// 	for (int i = 0; i <N; ++i){
// 		scanf("%d:%d:%d%d", &v[i].hour, &v[i].min, &v[i].second, &v[i].process);
// 		v[i].time = 3600 * v[i].hour + 60 * v[i].min + v[i].second;
// 		if (v[i].process>60)v[i].process = 60;
// 	}
// 	sort(v.begin(), v.end(), cmp);
// 	queue<int> q;
// 	int k = 0;
// 	int res_cnt=0,res=0;
	
// 	for (int i = 21600; i <=61200 ; ++i){
// 		if (k<N&&i == v[k].time){
// 			q.push(k);
// 			k++;
// 		}
// 		for (int w = 0; w <M; ++w)
// 		{
// 			if (windows[w].endTime == i){
// 				windows[w].num = 0;
// 			}
// 		}

// 		if (i >= 28800){

// 			while (!q.empty()){
// 				int qf = q.front();

// 				bool exist = false;
// 				for (int j = 0; j <M; ++j)
// 				{
// 					if (windows[j].num == 0){
// 						exist = true;
// 						windows[j].num++;
// 						windows[j].endTime = i + v[qf].process * 60;
// 						v[qf].wait = i - v[qf].time;
// 						res += v[qf].wait;
// 						res_cnt++;
// 						q.pop();
// 						break;
// 					}
// 				}
// 				if (exist == false)break;
// 			}


// 		}

// 	}

// 	printf("%.1lf\n", (double)res /60/res_cnt);
// 	system("pause");
// 	return 0;
// }
