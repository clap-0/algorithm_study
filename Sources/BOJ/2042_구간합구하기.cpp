// 펜윅트리를 이용해 구간 합 구하기
#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<long long> tree;

// pos위치의 값에 value만큼 더하며
// 해당 위치를 포함하는 모든 구간의 구간 합들도 value만큼 더한다
void add(int pos, long long value) {
  while(pos <= N) {
    tree[pos] += value;
    pos += pos & -pos;
  }
}

// pos까지의 부분합을 구한다
long long partialSum(int pos) {
  long long ret = 0LL;
  while(pos > 0) {
    ret += tree[pos];
    pos &= (pos - 1);
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M >> K;
  tree = vector<long long>(N + 1, 0);

  long long num;
  for(int i = 1; i <= N; i++) {
    cin >> num;
    add(i, num);
  }

  for(int i = 0, cnt = M + K; i < cnt; i++) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    if(a == 1) {
      // 기존의 값에서 c로 값을 바꿀 때의 변화량을 구해서 해당 값만큼 더한다
      long long variance = c - (partialSum(b) - partialSum(b - 1));
      add(b, variance);
    }
    else {
      // 부분합을 이용하여 구간 [b, c]의 구간합을 구한다
      cout << partialSum(c) - partialSum(b - 1) << '\n';
    }
  }
}
