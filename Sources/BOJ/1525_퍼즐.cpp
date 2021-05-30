#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

typedef long long state;
const int d[4]={-3,3,-1,1}, dx[4]={0,0,-1,1};

//비트마스킹을 이용해 주어진 표의 index번째 수를 val로 바꾼 값을 리턴
state change(state curr, int index, state val) { return (curr & ~(15LL<<(index*4))) | (val<<(index*4)); }

//비트마스킹을 이용해 주어진 표의 index번째 수를 리턴
int get(state curr, int index) { return (curr>>(index*4)) & 15; }

//주어진 표에서 빈칸을 인접한 칸으로 이동시킨 상태들 목록 리턴
vector<state> getAdjacent(state curr){
  vector<state> adj; //인접상태 목록 저장
  int blankSpace; //빈칸의 인덱스번호
  for(int i=0; i<9; i++)
    if(get(curr, i)==0) blankSpace=i;
  //상하좌우에서 인접한 상태들을 adj에 저장한다
  for(int i=0; i<4; i++){
    int index=blankSpace+d[i];
    //빈칸의 인접한 상,하,좌,우 중 표 바깥인 것은 패스
    if(index<0||index>=9 || blankSpace%3+dx[i]<0||blankSpace%3+dx[i]>=3) continue;
    //빈칸과 인접한 수 swap하기
    state tmp = curr;
    int value=get(curr, index);
    tmp=change(tmp, blankSpace, value);
    tmp=change(tmp, index, 0);
    adj.push_back(tmp);
  }
  return adj;
}

//너비우선탐색을 통해 begin상태에서
//end상태까지 최소 이동 수 리턴
int bfs(state begin, state end){
  if(begin==end) return 0; //초기상태와 목표상태가 같으면 이동시킬 필요없음
  queue<state> q; //앞으로 방문할 상태들 목록
  set<state> c; //방문했던 상태들 목록
  q.push(begin);
  c.insert(begin);
  int res=1;
  while(!q.empty()){
    int qsize=q.size();
    for(int i=0; i<qsize; i++){
      state curr = q.front(); q.pop();
      //현상태의 인접상태들중 방문 안 한 것들 확인
      vector<state> adj=getAdjacent(curr);
      for(state next : adj)
        if(c.find(next)==c.end()){
          q.push(next);
          c.insert(next);
          if(next==end) return res; //목표상태를 찾으면 이동횟수 반환
      }
    }
    res++;
  }
  return -1; //이동이 불가능한 경우 -1 반환
}

int main()
{
  state initial=0LL, goal=0LL;
  for(int i=0; i<9; i++){
    int num;
    cin >> num;
    initial=change(initial, i, num);
  }
  for(int i=0; i<8; i++) goal=change(goal, i, i+1); //목표상태를 미리 계산해둔다
  cout << bfs(initial, goal) << '\n';
}
