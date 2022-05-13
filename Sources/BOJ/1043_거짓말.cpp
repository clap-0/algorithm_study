#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int uf[50];
int partyMember[50];  // partyMember[i] = i번째 파티에 참가한 사람 중 하나의 번호

// 유니온파인드 알고리즘
int find(int n) {
  if(uf[n] < 0) return n;
  return uf[n] = find(uf[n]);
}

void merge(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return;
  uf[u] += uf[v];
  uf[v] = u;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M, truth, person;
  cin >> N >> M >> truth;

  memset(uf, -1, sizeof(uf));

  // 진실을 아는 사람들끼리 유니온파인드로 묶는다
  // 진실을 아는 사람 중 한 명을 prevTruthPerson에 저장해놓는다
  int prevTruthPerson = -1;
  for(int i = 0; i < truth; i++) {
    cin >> person; person--;
    if(prevTruthPerson != -1) merge(prevTruthPerson, person);
    prevTruthPerson = person;
  }

  // i번째 파티의 참가자들끼리 유니온파인드로 묶는다
  // 파티에 참가한 사람들 중 한 명을 partyMember[i]에 저장해놓는다
  for(int i = 0; i < M; i++) {
    int personCount; partyMember[i] = -1;
    cin >> personCount;
    while(personCount--) {
      cin >> person; person--;
      if(partyMember[i] != -1) merge(partyMember[i], person);
      partyMember[i] = person;
    }
  }

  // i번째 파티에 참가한 사람과 진실을 아는 사람이
  // 유니온파인드로 연결되어있다면 i번째 파티에서는 거짓말을 할 수 없다
  int ans = M;
  if(prevTruthPerson != -1)
    for(int i = 0; i < M; i++)
      if(find(partyMember[i]) == find(prevTruthPerson)) --ans;

  cout << ans << '\n';
}
