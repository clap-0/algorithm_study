#include <iostream>
#include <queue>
#include <cstring>
#include <functional>
using namespace std;

const int MAX=1000001;

int f, s, g, u, d;

function<int(int)> button[2]={
  [](int n){return n+u;}, //n층에서 u층위의 층
  [](int n){return n-d;}  //n층에서 d층아래 층
};

//너비우선탐색을 통해 s에서 g로 가기위해 눌러야 할 최소 버튼수 반환
//엘리베이터로 이동 불가능한 경우 -1반환
int bfs(){
  if(s==g) return 0; //현재 층이 목표층인 경우 눌러야 할 버튼수는 0개
  int press[MAX]; //s에서부터 각 층에 가기위해 누른 버튼 수
  queue<int> q;
  memset(press, -1, sizeof(press));
  q.push(s);
  press[s]=0;
  while(!q.empty()){
    int here = q.front(); q.pop();
    for(int i=0; i<2; i++){
      int next = button[i](here);
      if(next<1||next>f) continue; //해당층이 없는 경우 패스
      if(press[next]!=-1) continue; //이미 왔던 층은 패스
      q.push(next);
      press[next]=press[here]+1;
      if(next==g) return press[next]; //목표층에 도달한 경우 값 반환
    }
  }
  return -1;
}
int main()
{
  cin >> f >> s >> g >> u >> d;
  int ans=bfs();
  if(ans!=-1) cout << ans << '\n';
  else cout << "use the stairs\n";
}
