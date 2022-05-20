#include <iostream>
#include <vector>
using namespace std;

int order[1 << 10];
vector<int> buildings[10];

// 중위순위결과를 바탕으로 완전이진트리를 구한다
void solve(int from, int to, int level) {
  int mid = (from + to) / 2;
  buildings[level].push_back(order[mid]);
  if(from != to) {  // 리프노드가 아닌 경우
    solve(from, mid - 1, level + 1);
    solve(mid + 1, to, level + 1);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int K, nodes;
  cin >> K;
  nodes = (1 << K) - 1;
  for(int i = 0; i < nodes; i++) cin >> order[i];

  solve(0, nodes - 1, 0);

  for(int i = 0; i < K; i++) {
    for(int building : buildings[i]) cout << building << ' ';
    cout << '\n';
  }
}
