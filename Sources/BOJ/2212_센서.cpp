#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sensors[10000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N, K;
  cin >> N >> K;
  for(int i=0; i<N; i++) cin >> sensors[i];

  // 집중국의 개수가 센서의 수 이상인 경우 각 센서에 최소 한 개씩 집중국을 세우면 된다
  if(N<=K){
    cout << 0 << '\n';
    return 0;
  }

  sort(sensors, sensors+N);

  // 인접한 센서사이의 거리를 구해 내림차순 정렬한다
  vector<int> dist;
  for(int i=1; i<N; i++) dist.push_back(sensors[i]-sensors[i-1]);
  sort(dist.begin(), dist.end(), greater<int>());

  // 양 끝의 센서사이의 거리를 구하고, 인접한 거리가 큰 것부터 뺀다
  int sum = sensors[N-1] - sensors[0];
  for(int i=0; i<K-1; i++) sum -= dist[i];

  cout << sum << '\n';
}
