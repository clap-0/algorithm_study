#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

int population[50][50];
// isUnited = 연합국에 속해있으면 true, 아니면 false
bool isUnited[50][50];

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, L, R;
  cin >> N >> L >> R;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      cin >> population[i][j];
  
  int days = 0;
  while(true) 
  {
    // hasMove = 인구 이동 발생 여부
    bool hasMoved = false;
    // 매일마다 연합을 초기화한다.
    memset(isUnited, false, sizeof(isUnited));
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
        if(!isUnited[i][j])
        {
          queue<pair<int,int> > Q;
          Q.push({i, j});
          isUnited[i][j] = true;
          // alliance = 현재 나라와 연합을 이루고 있는 나라들
          vector<pair<int,int> > alliance;
          alliance.push_back({i, j});
          int alliancePopulation = population[i][j];

          // 넓이 우선 탐색 알고리즘을 통해 연결된 연합국을 찾는다.
          while(!Q.empty())
          {
            int y = Q.front().first, x = Q.front().second;
            Q.pop();
            for(int d = 0; d < 4; d++)
            {
              int ny = y + dy[d], nx = x + dx[d];
              if(ny < 0 || nx < 0 || ny >= N || nx >= N || isUnited[ny][nx]) continue;
              // 인접국과의 인구 차이가 L이상 R이하면 연합국에 넣는다.
              int diff = abs(population[y][x] - population[ny][nx]);
              if(L <= diff && diff <= R)
              {
                isUnited[ny][nx] = true;
                Q.push({ny, nx});
                alliance.push_back({ny, nx});
                alliancePopulation += population[ny][nx];
              }
            }
          }

          // 연합국들끼리 인구 이동을 한다.
          alliancePopulation /= alliance.size();
          for(auto &ally : alliance)
            population[ally.first][ally.second] = alliancePopulation;

          if(alliance.size() > 1)
            hasMoved = true;
        }
    if(!hasMoved) break;
    ++days;
  }

  cout << days << '\n';
}
