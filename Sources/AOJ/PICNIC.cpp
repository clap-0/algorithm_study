#include <iostream>
#include <vector>
using namespace std;
//각 학생들의 친구 목록
vector<int> friends[10];
//각 학생들의 짝을 이루었는지 여부
bool isPaired[10];
//브루트포스를 이용해 친구끼리 짝을 이루는 방법의 수 구함
int countPairings(int n){
  //남은 짝이 없는 학생들 중 번호가 가장 빠른 학생 찾기
  int toPair=-1;
  for(int i=0; i<n; i++)
    if(!isPaired[i]){
      toPair = i;
      break;
    }
  //기저사례 : 모든 학생들이 짝을 이룬 경우
  if(toPair==-1) return 1;
  //이 학생의 친구들 중 짝을 이룰 학생 찾기
  int res=0;
  for(int f : friends[toPair])
    if(!isPaired[f]){
      isPaired[toPair] = isPaired[f] = true;
      res += countPairings(n);
      isPaired[toPair] = isPaired[f] = false;
    }
  return res;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int C;
  cin >> C;
  while(C--){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) friends[i].clear();
    for(int i=0; i<m; i++){
      int a, b;
      cin >> a >> b;
      friends[a].push_back(b);
      friends[b].push_back(a);
    }
    cout << countPairings(n) << endl;
  }
}
