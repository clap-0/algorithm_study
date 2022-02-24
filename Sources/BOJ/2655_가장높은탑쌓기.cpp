#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// 직육면체 벽돌의 넓이, 높이, 무게, 벽돌번호를 담은 구조체
struct Brick {
  int area, height, weight, num;
  Brick() : Brick(10001, 10001, 10001, 101) {}
  Brick(int _a, int _h, int _w, int _n) : area(_a), height(_h), weight(_w), num(_n) {}
};

vector<Brick> bricks;
int N;
int cache[100];
// under[i] = 가장 높게 탑을 쌓았을 때 i번 벽돌 밑에 있는 벽돌의 번호
int under[100];

// DP를 사용해서 LIS를 구하는 방법을 응용하여
// 넓이에 대하여 오름차순 정렬되어 있는 벽돌들을
// 무게에 대하여 오름차순이고, 높이가 가장 높게 되도록 하는 탑의 높이를 반환하는 함수
int solve(int curr) {
	// 메모이제이션
  int& ret = cache[curr];
  if(ret != 0) return ret;
	// curr보다 무게가 무거운 벽돌에 대하여 해당 벽돌이 맨 위에 있는 탑을 쌓았을 때의 최대 높이가
	// 현재까지 구한 최대 높이보다 높은 경우, curr 벽돌 밑에 해당 벽돌이 있게 한다
  for(int next = curr + 1; next < N; next++)
    if(bricks[curr].weight < bricks[next].weight) {
      int nextHeight = solve(next);
      if(ret < nextHeight) {
        ret = nextHeight;
        under[bricks[curr].num] = bricks[next].num;
      }
    }
  return ret += bricks[curr].height;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  bricks.resize(N);
  for(int i = 0; i < N; i++) {
    int a, h, w;
    cin >> a >> h >> w;
    bricks[i] = Brick(a, h, w, i);
  }

  sort(bricks.begin(), bricks.end(), [](Brick& a, Brick& b) {
    return a.area < b.area;
  });

  memset(under, -1, sizeof(under));
	// high = 가장 높은 탑의 높이
	// top = 높이가 가장 높을 때 맨 위에 있는 벽돌의 번호
  int top = 0, high = 0;
  for(int i = 0; i < N; i++) {
    int h = solve(i);
    if(high < h) {
      high = h;
      top = bricks[i].num;
    }
  }

  vector<int> layer;
  layer.push_back(top);
  while(under[top] != -1) {
    layer.push_back(under[top]);
    top = under[top];
  }

  cout << layer.size() << '\n';
  for(int l : layer) cout << l + 1 << '\n';
}
