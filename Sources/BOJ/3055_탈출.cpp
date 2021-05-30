#include <iostream>
#include <queue>
using namespace std;

const int MAX=50;
const int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};

char adj[MAX][MAX];
bool discovered[MAX][MAX]; //각 칸을 발견했는지 여부 저장

int main()
{
  int r, c, dochi;
  queue<int> q; //물과 고슴도치의 방문예정목록을 한 큐에 같이 넣는다
  cin >> r >> c;
  for(int i=0; i<r; i++)
    for(int j=0; j<c; j++){
      cin >> adj[i][j];
      //고슴도치는 물이 찰 예정인 칸으로 이동이 불가하므로
      //큐에 물이 차있는 지역부터 넣어 먼저 인접 빈칸을 발견하게 한다
      if(adj[i][j]=='*'){
        q.push(1*(MAX*MAX)+i*MAX+j);
        discovered[i][j]=true;
      }
      else if(adj[i][j]=='S') dochi=i*MAX+j;
    }
  q.push(dochi);
  discovered[dochi/MAX][dochi%MAX]=true;
  int time=0;
  while(!q.empty()){
    int qsize=q.size();
    for(int i=0; i<qsize; i++){
      bool isWater = q.front()/(MAX*MAX); //참이면 물, 거짓이면 고슴도치의 위치
      int y=q.front()%(MAX*MAX)/MAX;
      int x=q.front()%(MAX*MAX)%MAX; 
      q.pop();
      for(int i=0; i<4; i++){
        int ny=y+dy[i], nx=x+dx[i];
        if(ny<0||nx<0||ny>=r||nx>=c) continue; //범위밖이면 패스
        if(discovered[ny][nx] || adj[ny][nx]=='X') continue; //이미 발견했거나 돌인 경우 패스
        if(adj[ny][nx]=='D'){ //비버소굴에 도달한 경우
          if(isWater) continue; //물은 비버소굴로 이동불가
          cout << time+1 << '\n';
          return 0;
        }
        q.push(isWater*(MAX*MAX)+ny*MAX+nx);
        discovered[ny][nx]=true;
      }
    }
    time++;
  }
  cout << "KAKTUS\n";
}
