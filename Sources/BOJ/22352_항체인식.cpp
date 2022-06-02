#include <iostream>
using namespace std;

const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

int N, M;
int before[30][30], after[30][30];
bool visited[30][30];

void dfs(int y, int x, int data) {
  visited[y][x] = true;
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
    if(!visited[ny][nx] && before[ny][nx] == before[y][x]) dfs(ny, nx, data);
  }
  before[y][x] = data;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++) cin >> before[i][j];

  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++) cin >> after[i][j];

  // 백신 주사 후 달라진 조직이 있다면 해당 조직에 백신을 주사했을 때 달라진 조직으로 변한다고 가정한다
  bool injected = false;
  for(int i = 0; i < N && !injected; i++)
    for(int j = 0; j < M; j++)
      if(before[i][j] != after[i][j]) {
        injected = true;
        dfs(i, j, after[i][j]);
        break;
      }

  // 백신을 주사한 이후에도 달라진 조직이 있다면 주사된 백신은 CPCU-1202가 아니다
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      if(before[i][j] != after[i][j]) {
        cout << "NO" << '\n';
        return 0;
      }
  cout << "YES" << '\n';
}
