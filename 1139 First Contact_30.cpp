#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int N, M, K, C, D;
struct Node
{
	int C, D;
	Node(int C, int D) :C(C), D(D){}
};
std::vector<int> cur;
std::vector<vector<int> > v(10001, cur);
std::vector<int> gender(10001, 1);//0girl,1boy
bool cmp(Node a, Node b){
	if (a.C != b.C)return a.C<b.C;
	else return a.D<b.D;
}
void find(int x, int y){
	int gender_x = gender[x];
	int gender_y = gender[y];

	int cnt = 0;
	std::vector<Node> res;
	for (int i = 0; i<v[x].size(); i++){
		C = v[x][i];
		//cout<<"C "<<C<<endl;
		if (gender[C] == gender_x&& C != y){
			for (int j = 0; j <v[C].size(); ++j)
			{
				D = v[C][j];
				if (gender[D] == gender_y&&D != x && D != y){
					
					for (int k = 0; k <v[D].size(); ++k)
					{
						if (v[D][k] == y){
							cnt++;
							res.push_back(Node(C, D));
						}
					}
				}
			}
		}
	}
	sort(res.begin(), res.end(), cmp);
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); ++i)
		printf("%04d %04d\n", res[i].C, res[i].D);

}
int main(int argc, char const *argv[])
{
	int xx, yy;
	string sx, sy;
	scanf_s("%d%d", &N, &M);
	for (int i = 0; i<M; i++){
		cin >> sx >> sy;
		if (sx.size() == 5){
			xx = stoi(sx.substr(1));
			gender[xx] = 0;
		}
		else {
			xx = stoi(sx);
		}
		if (sy.size() == 5){
			yy = stoi(sy.substr(1));
			gender[yy] = 0;
		}
		else {
			yy = stoi(sy);
		}
		v[xx].push_back(yy);
		v[yy].push_back(xx);
		
	}
	scanf_s("%d", &K);
	for (int i = 0; i <K; ++i)
	{
		cin >> sx >> sy;
		if (sx.size() == 5){
			xx = stoi(sx.substr(1));
			gender[xx] = 0;
		}
		else {
			xx = stoi(sx);
		}
		if (sy.size() == 5){
			yy = stoi(sy.substr(1));
			gender[yy] = 0;
		}
		else {
			yy = stoi(sy);
		}
		find(xx, yy);
	}
	getchar();
	system("pause");
	return 0;
}