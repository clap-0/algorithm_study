#include <cstdio>
#include <queue>
using namespace std;

const char MEALS[3] = {'B','L','D'};
char pills[1500];
bool visited[1500][1500];

int main()
{
  int N;
  scanf("%d %s", &N, pills);
  
  int cnt = 0;
  queue<pair<int,int> > Q;
  if (pills[0] == 'B') {
    Q.push({1, 3*N-1});
    visited[1][3*N-1] = true;
  }
  if (pills[3*N-1] == 'B') {
    Q.push({0, 3*N-2});
    visited[0][3*N-2] = true; 
  }

  while (!Q.empty()) {
    int qsize = Q.size();
    while (qsize--) {
      int left = Q.front().first, right = Q.front().second;
      Q.pop();

      if (left > right)
        continue;

      if (pills[left] == MEALS[(cnt+1)%3] && !visited[left + 1][right]) {
        Q.push({left + 1, right});
        visited[left + 1][right] = true;
      }
      if (pills[right] == MEALS[(cnt+1)%3] && !visited[left][right - 1]) {
        Q.push({left, right - 1});
        visited[left][right - 1] = true;
      }
    }
    ++cnt;
  }
  printf("%d\n", cnt);
}
