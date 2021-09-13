#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
pair<int,int> jewel[300000];
int C[300000];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, K;
  priority_queue<int> pq;
  cin >> N >> K;
  for(int i=0; i<N; i++) cin >> jewel[i].first >> jewel[i].second;
  for(int i=0; i<K; i++) cin >> C[i];
  //보석정보와 가방을 무게에 대하여 오름차순으로 정렬한다
  sort(jewel, jewel+N);
  sort(C, C+K);
  int idx=0;
  long long ans=0;
  for(int i=0; i<K; i++){
    //i번가방의 최대무게보다 무게가 작거나 같은 모든 보석을 pq에 넣는다.
    //C[i]보다 무게가 작거나 같은 보석은 C[i+1]보다도 작거나 같으므로 pq를 clear하지 않아도 된다
    while(idx<N && jewel[idx].first<=C[i]) pq.push(jewel[idx++].second);
    //pq는 우선순위큐이므로 가격이 가장 비싼 보석 하나를 뺀다
    if(!pq.empty()){
      ans+=pq.top();
      pq.pop();
    }
  }
  cout << ans << '\n';
}
