/*
很好的排序题！-->一不小心就超时= =
1、排序不要整个Node排！先用id标识每个node,存储在origin数组中，排序的时候用id排，也就是
vector<int>!比较的时候（cmp)再通过origin比！
2、先按每个成绩段存储数据（v数组）~然后在每个成绩段中排序！这里有坑->总的输出<=100人所以大于100人时，用：
partial_sort，只排前100个！
3、再把排好的每个成绩段插入res数组（vector-->insert）,再对res排一次！
4、注意一定要在询问前都排好，不要询问一次排一次->超时！
5、每次询问从res中找符合该成绩段的！！res最大100*205
*/

#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int N, K;
struct Node
{
    char name[10];
    int age, worth, id;

};
std::vector<Node> cur;
std::vector<int> v[205];
std::vector<int> res;//放id
vector<Node>origin(100005, Node());
int num, lo, hi;
bool cmp(int aa, int bb){
    Node a = origin[aa];
    Node b = origin[bb];
    if (a.worth != b.worth)return a.worth>b.worth;
    else{
        if (a.age != b.age)
            return a.age<b.age;
        else
            return strcmp(a.name, b.name)<0;
    }
}
void query(int num, int lo, int hi){

    int cnt = 0;

    for (int i = 0; cnt < num&&i <res.size(); ++i){
        if (origin[res[i]].age >= lo&&origin[res[i]].age <= hi){
            printf("%s %d %d\n", origin[res[i]].name, origin[res[i]].age, origin[res[i]].worth);
            cnt++;
        }

    }
    if (cnt == 0)
        printf("None\n");
}
int main(int argc, char const *argv[])
{
    cin >> N >> K;
    char na[10];
    int a, w;
    int id = 0;

    for (int i = 0; i <N; ++i)
    {

        scanf("%s%d%d", origin[i].name, &origin[i].age, &origin[i].worth);
        origin[i].id = i;
        v[origin[i].age].push_back(i);//v用于记录每个成绩段的node的id

    }
    for (int i = 0; i < 205; ++i)
    {

        if (v[i].size()>0){
            if (v[i].size() <= 100){
                sort(v[i].begin(), v[i].end(), cmp);
                res.insert(res.end(), v[i].begin(), v[i].end());
            }
            else
            {
                partial_sort(v[i].begin(), v[i].begin() + 100, v[i].end(), cmp);
                res.insert(res.end(), v[i].begin(), v[i].begin() + 100);
            }
        }

    }
    sort(res.begin(), res.end(), cmp);

    for (int i = 0; i < K; ++i)
    {
        scanf("%d%d%d", &num, &lo, &hi);
        printf("Case #%d:\n", i + 1);
        query(num, lo, hi);
    }

    system("pause");
    return 0;
}

 
