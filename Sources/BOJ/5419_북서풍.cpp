#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

int n;
int tree[75001];
pii island[75000];
int newY[75000];

// 펜윅트리
void add(int idx) {
  ++idx;
  while(idx <= n) {
    ++tree[idx];
    idx += (idx & -idx);
  }
}

int partialSum(int idx) {
  ++idx;
  int ret = 0;
  while(idx > 0) {
    ret += tree[idx];
    idx &= (idx - 1);
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> island[i].first >> island[i].second;

    // 섬의 y좌표에 대하여 내림차순 정렬
    sort(island, island + n, [](pii& a, pii& b){
      return a.second > b.second;
    });

    // 섬의 y좌표를 해당 섬이 모든 섬들 중 몇 번째로 북쪽에 가까운지 순위로 바꾼다
    // 가장 북쪽에 있는 섬의 y좌표는 0이 된다
    int range = 0;
    for(int i = 0; i < n; i++) {
      // y좌표가 같은 섬은 같은 range를 가진다
      if(i > 0 && island[i - 1].second != island[i].second) range++;
      newY[i] = range;
    }
    for(int i = 0; i < n; i++) island[i].second = newY[i];

    // x좌표에 대하여 오름차순으로 정렬한다
    // x좌표가 같은 경우 북쪽에 더 가까운 섬이 앞에 온다
    sort(island, island + n);

    long long ans = 0;
    memset(tree, 0, sizeof(tree));
    for(int i = 0; i < n; i++) {
      // i번째로 확인한 섬보다 북서쪽에 있는 섬의 개수를 더한다
      ans += partialSum(island[i].second);
      add(island[i].second);
    }

    cout << ans << '\n';
  }
}
