#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, k;
vector<bool> discovered(100001); //각 점에 방문했는지 저장
vector<int> shortest(100001); //수빈이가 각 점에 가는데 걸리는 최단시간 저장
//수빈이가 how방법으로 움직일 때 이동한 위치 반환
int move(int pos, int how){
  switch(how){
    case 0 : return pos-1;
    case 1 : return pos+1;
    default : return pos*2;
  }
}
//BFS를 이용해 동생찾기
int findBro(int n){
  discovered[n]=true;
  shortest[n]=0;
  queue<int> q;
  q.push(n);
  while(!q.empty()){
    int pos = q.front();
    q.pop();
    if(pos==k) return shortest[pos]; //동생 찾으면 k까지 가는데 걸린시간 반환
    for(int i=0; i<3; i++){
      int nextPos=move(pos, i);
      if(nextPos<0||nextPos>100001) continue;
      if(!discovered[nextPos]){
        q.push(nextPos);
        discovered[nextPos]=true;
        shortest[nextPos] = shortest[pos]+1; //nextPos까지 걸린시간 = 현위치까지 오는데 걸린시간+1
      }
    }
  }
  return -1;
}
int main()
{
  cin >> n >> k;
  cout << findBro(n) << endl;
  return 0;
}
