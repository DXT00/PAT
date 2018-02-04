#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int N;
struct Node
{
  string xishu;
  int zhishu;
  Node() :xishu(""), zhishu(0){}
};
string A, B;
Node change(string s){
  Node res = Node();
  int i = 0;
  string point_before = "", point_after = "";
  while (s[i] != '.'&&s[i] != '\0'){
    point_before += s[i];
    i++;
  }
  if (s[i] == '.'){
    string ss = s.substr(i + 1);
    point_after = ss;
  }
  if (stod(point_before)!=0){//如123.456
    int i = 0;
    while (point_before[i] == '0')i++;//除去多余的0-->会有坑：如：00123.456
    point_before = point_before.substr(i);
    res.xishu = "0." + point_before + point_after;
    res.zhishu = point_before.size();
  }
  else{//小数的情况如：0.00145
    int cnt_0 = 0;
    int j = 0;
    while (point_after[j] == '0'){
      j++;
      cnt_0++;//统计after中0的个数！
    }
    if (cnt_0 == point_after.size())//全为0的情况如：0.0000-->change-->0.0000*10^0
      res.zhishu = 0;
    else
      res.zhishu = -cnt_0;//如0.0145-->0.145*10^-1

    if (cnt_0 == point_after.size())//全为0的情况
      res.xishu = s;
    else
      res.xishu = "0." + point_after.substr(j);
  }
  return res;
}
int main(int argc, char const *argv[])
{
  cin >> N;
  cin >> A >> B;
  Node SA, SB;
  SA = change(A);
  SB = change(B);
  int cnt = 0;

  for (int i = 2; i <SA.xishu.size() && i<SB.xishu.size(); ++i)
  {
    if (SA.xishu[i] == SB.xishu[i]){
      cnt++;
    }
    else
      break;
  }
  if (cnt >= N&&SA.zhishu == SB.zhishu)
    cout << "YES " << SA.xishu.substr(0, N + 2) << "*10^" << SA.zhishu << endl;
    
  else{
    if (stod(SA.xishu) ==0&& stod(SB.xishu) == 0){//全为0的情况
      string s0(N, '0');
      cout << "YES 0." << s0 << "*10^0"<< endl;//指数必为0！ 如：0.0000-->change-->0.0000*10^0
    }
    else
    cout << "NO " << SA.xishu << "*10^" << SA.zhishu << " " << SB.xishu << "*10^" << SB.zhishu << endl;
    
  }
  system("pause");
  return 0;
}