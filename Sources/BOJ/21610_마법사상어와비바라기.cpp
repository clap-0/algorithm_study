#include <iostream>
#include <vector>
using namespace std;

const int dr[8] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dc[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int A[50][50];
vector<pair<int,int> > clouds;
bool isRained[50][50];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> A[i][j];
  
  // 초기 비구름의 위치
  clouds = {{N-1, 0}, {N-1, 1}, {N-2, 0}, {N-2, 1}};
  
  int d, s;
  for (int m = 0; m < M; m++) {
    cin >> d >> s;
    for (auto& cloud : clouds) {
      // 모든 구름이 di 방향으로 si칸 이동한다.
      cloud.first = (cloud.first + s * (dr[d - 1] + N)) % N;
      cloud.second = (cloud.second + s * (dc[d - 1] + N)) % N;

      // 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
      ++A[cloud.first][cloud.second];
      isRained[cloud.first][cloud.second] = true;
    }

    // 물이 증가한 칸에 물복사버그 마법을 시전한다.
    for (auto& cloud : clouds) {
      for (int i = 1; i < 8; i += 2) {
        int nr = cloud.first + dr[i];
        int nc = cloud.second + dc[i];
        if (nr < 0 || nc < 0 || nr >= N || nc >= N || A[nr][nc] == 0) {
          continue;
        }
        ++A[cloud.first][cloud.second];
      }
    }

    // 구름이 모두 사라진다.
    clouds.clear();

    // 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다.
    // 이때 구름이 생기는 칸은 구름이 사라진 칸이 아니어야 한다.
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (!isRained[i][j]) {
          if (A[i][j] >= 2) {
            clouds.push_back({i, j});
            A[i][j] -= 2;
          }
        }
        else {
          isRained[i][j] = false;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      ans += A[i][j];
  cout << ans << '\n';
}
