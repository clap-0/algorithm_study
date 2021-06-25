#include <iostream>
#include <vector>
using namespace std;
const int MAX=50;
int N, M;
//집의 위치와 치킨집의 위치
vector<int> house, chicken;
//n의 절댓값 반환
int abs(int n) {return n>0 ? n : -n;}
//모든 집의 남은 M개의 치킨집에 대한 치킨거리의 합 구하기
int chickenDist(vector<int>& picked){
  int ret=0;
  for(int h : house){
    int hy=h/MAX, hx=h%MAX, dist=987654321;
    for(int p : picked)
      dist=min(dist, abs(hy-chicken[p]/MAX)+abs(hx-chicken[p]%MAX));
    ret+=dist;
  }
  return ret;
}
//폐업 안 시킬 M개의 치킨집을 완전탐색을 통해 고르고
//고른 치킨집에 대한 도시의 치킨거리의 최솟값 반환
int shutDown(int curr, vector<int>& picked){
  if(picked.size()==M) return chickenDist(picked);
  int ret=987654321;
  for(int next=curr+1; next<chicken.size(); next++){
    picked.push_back(next);
    ret=min(ret, shutDown(next, picked));
    picked.pop_back();
  }
  return ret;
}
int main()
{
  cin >> N >> M;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++){
      int a;
      cin >> a;
      if(a==1) house.push_back(i*MAX+j);
      else if(a==2) chicken.push_back(i*MAX+j);
    }
  //폐업 안 시킬 치킨집의 번호
  vector<int> picked;
  cout << shutDown(-1, picked) << '\n';
}
