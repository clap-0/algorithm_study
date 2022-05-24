#include <iostream>
using namespace std;

int N;
int weight[1 << 21];

// 포화이진트리에서 현재 노드에서 부모노드로 가는 에지의 번호 parentEdge가 주어졌을 때
// 해당 노드를 루트로 하는 서브트리에서 루트에서 리프까지의 거리가 같게 하면서 
// 에지 가중치의 총합이 최소가 되도록 에지들의 가중치를 증가시킨다.
// 또한 모든 리프까지의 거리의 최댓값을 반환한다
int getMaxDist(int parentEdge) {
  int leftEdge = parentEdge * 2 + 1;  // leftEdge: 왼쪽 노드로 가는 에지의 번호
  
  // 현재 노드가 리프노드인 경우 부모노드로 가는 에지의 가중치 반환
  if(leftEdge >= N) return weight[parentEdge];

  int rightEdge = parentEdge * 2 + 2; // rightEdge: 오른쪽 노드로 가는 에지의 번호
  int leftDist = getMaxDist(leftEdge);  // leftDist: 왼쪽 에지에서의 거리의 최댓값
  int rightDist = getMaxDist(rightEdge);  // rightDist: 오른쪽 에지에서의 거리의 최댓값

  // 왼쪽 에지의 거리와 오른쪽 에지의 거리의 차이만큼
  // 거리가 더 짧은 에지의 가중치에 더한다
  if(leftDist > rightDist) swap(leftEdge, rightEdge);
  weight[leftEdge] += abs(rightDist - leftDist);

  // (부모노드로 가는 에지의 가중치 + 두 에지의 거리 중 더 큰 값) 반환
  return weight[parentEdge] + max(leftDist, rightDist);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int k;
  cin >> k;
  N = (1 << k + 1) - 1;
  for(int i = 1; i < N; i++) cin >> weight[i];
  
  getMaxDist(0);
  int ans = 0;
  for(int i = 1; i < N; i++) ans += weight[i];
  cout << ans << '\n';
}
