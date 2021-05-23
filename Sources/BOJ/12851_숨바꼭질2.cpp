#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX=100001, INF=987654321;

int main()
{
  int n, k, cnt=0;
  queue<int> Q;
  vector<int> shortest(MAX, INF);
  
  cin >> n >> k;
  
  //BFS를 이용한 최단거리 찾기
  Q.push(n);
  shortest[n]=0;
  while(!Q.empty()){
    int pos=Q.front(); Q.pop();
    
    //k에 도달한 이후, k에 도달하는데 걸린 최단시간보다 느린 곳을 탐색하면 탐색중단
    if(shortest[pos] > shortest[k]) break;
    if(pos==k) cnt++; //최단시간으로 찾는 방법의 수 구하기
    
    //수빈이가 현 위치에서 이동할 곳을 구한다
    //이때 한번도 가지 않았던 곳이나, 이미 이동할 목록에 넣었던 곳이라도
    //현위치에서 이동했을 때 걸리는 시간이 최단시간과 같으면 목록에 추가한다
    if(pos*2<MAX && shortest[pos*2]>shortest[pos]){
      Q.push(pos*2);
      shortest[pos*2]=shortest[pos]+1;
    }
    if(pos-1>=0 && shortest[pos-1]>shortest[pos]){
      Q.push(pos-1);
      shortest[pos-1]=shortest[pos]+1;
    }
    if(pos+1<MAX && shortest[pos+1]>shortest[pos]){
      Q.push(pos+1);
      shortest[pos+1]=shortest[pos]+1;
    }
  }
  cout << shortest[k] << '\n' << cnt << '\n';
}
