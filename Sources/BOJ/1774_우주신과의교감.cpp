#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int uf[1000]; // 유니온 파인드

pair<int,int> pos[1000];
vector<pair<double,pair<int,int> > > adj;

// 좌표 A와 B가 매개변수로 주어질 때 A와 B 사이의 유클리드 거리를 반환하는 함수
double dist(pair<int,int>& A, pair<int,int>& B) {
  double dx = A.first - B.first, dy = A.second - B.second;
  return sqrt(dx * dx + dy * dy);
}

// n이 속한 트리의 루트 번호를 반환하는 함수
int find(int n) {
  if(uf[n] < 0) return n;
  return uf[n] = find(uf[n]);
}

// u가 속한 트리에 v가 속한 트리를 합치는 함수
bool merge(int u, int v) {
  u = find(u), v = find(v);
  if(u == v) return false;  // 이미 두 트리가 같은 트리인 경우 false 반환
  uf[v] = u;
  return true;  // 성공적으로 합쳐진 경우 true 반환
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  memset(uf, -1, sizeof(uf));
  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> pos[i].first >> pos[i].second;

  int cnt = 0;  // cnt : 정점들끼리 최소한으로 연결할 때 연결된 간선의 개수
  
  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    if(merge(u - 1, v - 1)) ++cnt;
  }

  // 좌표들간의 유클리드 거리를 구하여 adj에 저장한다
  for(int i = 0; i < N; i++)
    for(int j = i + 1; j < N; j++)  // 중복을 제거하기 위해 (i + 1)부터 계산한다
      adj.push_back({dist(pos[i], pos[j]), {i, j}});

  
  // 크루스칼의 MST 알고리즘
  double ans = 0.0;
  
  sort(adj.begin(), adj.end()); // 거리에 대하여 오름차순 정렬
  
  // 거리가 짧은 간선부터 두 끝점이 직,간접적으로 연결되지 않았다면 연결한다
  for(auto& p : adj) {
    double w = p.first;
    int u = p.second.first, v = p.second.second;
    if(merge(u, v)) {
      ans += w;
      if(++cnt == N - 1) break; // 간선의 개수가 N - 1인 경우 더 연결할 필요가 없다
    }
  }

  cout.precision(2);
  cout << fixed;
  cout << ans << '\n';
}
