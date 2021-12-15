#include <iostream>
#include <algorithm>
using namespace std;

int crains[50], boxes[10000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N;
  for(int i=0; i<N; i++) cin >> crains[i];
  cin >> M;
  for(int i=0; i<M; i++) cin >> boxes[i];

  sort(crains, crains+N, greater<int>());
  sort(boxes, boxes+M, greater<int>());

  if(crains[0] < boxes[0]){
    cout << -1 << '\n';
    return 0;
  }

  int ans=0, moved=0;
  while(moved < M){
    int crainIter=0;
    for(int i=0; i<M; i++){
      if(boxes[i] == 0 || boxes[i] > crains[crainIter]) continue;
      boxes[i] = 0;
      ++moved;
      if(++crainIter == N) break;
    }
    ++ans;
  }
  cout << ans << '\n';
}
