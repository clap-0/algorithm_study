#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, row, column;
bool check;
int d[4][2]={{1,1},{1,2},{2,1},{2,2}};

int Z(int y, int x, int size)
{
  if(size==1) return 0; //기저사례:크기가 1*1이면 종료
  int i=0, ret=0;
  int half=size/2;
  while(!((row<y+half*d[i][0])&&(column<x+half*d[i][1]))){ //구하려는 좌표가 각 4분면에 있는지 확인
    i++;
    ret+=half*half; //없으면 그 4분면 크기만큼 방문횟수 증가
  }
  ret+=Z(y+half*(d[i][0]-1), x+half*(d[i][1]-1), half); //있으면 그 4분면에서 재귀호출로 찾기
  return ret;
}
int main()
{
  cin >> n >> row >> column;
  cout << Z(0,0,pow(2,n)) << endl;
  return 0;
}
