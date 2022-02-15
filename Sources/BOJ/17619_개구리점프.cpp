#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int,int> > triple;

// woods : { k, { k번째 통나무의 왼쪽끝, k번째 통나무의 오른쪽끝 } }을 왼쪽끝을 기준으로 오름차순 정렬하여 저장한다
triple woods[100000];

int uf[100000];

bool compare(triple& a, triple& b) {
  if(a.second.first != b.second.first) return a.second.first < b.second.first;
  return a.second.second < b.second.second;
}

// 유니온파인드 알고리즘
int find(int n) {
  if(uf[n] < 0) return n;
  return uf[n] = find(uf[n]);
}

void merge(int u, int v) {
  u = find(u), v = find(v);
  if(u == v) return;
  uf[v] = u;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, Q;
  cin >> N >> Q;
  for(int i = 0; i < N; i++) {
    int x1, x2, y;
    cin >> x1 >> x2 >> y;
    woods[i] = {i, {x1, x2}};
    uf[i] = -1;
  }
  
  sort(woods, woods+N, compare);
  
  // end : 지금까지 발견한 가장 오른쪽에 있는 통나무의 오른쪽끝 좌표
  int prev = woods[0].first, end = woods[0].second.second;
  for(int i = 1; i < N; i++) {
    int curr = woods[i].first;
    // 이번 통나무로 이동이 가능한 경우 prev를 루트로 하는 그룹에 합친다
    if(woods[i].second.first <= end) merge(prev, curr);
    // 이동이 불가능한 경우 curr를 루트로 하는 그룹을 만든다
    else prev = curr;
    end = max(end, woods[i].second.second);
  }
  
  while(Q--) {
    int A, B;
    cin >> A >> B;
    cout << (find(A-1) == find(B-1)) << '\n';
  }
}
