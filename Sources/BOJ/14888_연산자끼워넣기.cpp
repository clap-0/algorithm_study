#include <iostream>
using namespace std;

int N, maxAns, minAns;
int A[11], oper[4];

// 백트래킹을 이용해 value와 curr번째 수를 연산해 나올 수 있는 경우의 수를 모두 구한다
void bruteforce(int curr, int value) {
  // 연산자를 모두 사용한 경우 최댓값과 최솟값을 최신화시킨다
  if(curr == N) {
    maxAns = max(value, maxAns);
    minAns = min(value, minAns);
    return;
  }
  
  for(int i=0; i<4; i++) 
    if(oper[i] > 0) {
      --oper[i];
      int tmp = value;
      switch(i) {
        case 0: tmp += A[curr]; break;
        case 1: tmp -= A[curr]; break;
        case 2: tmp *= A[curr]; break;
        case 3: tmp /= A[curr]; break;
        default:;
      }
      bruteforce(curr + 1, tmp);
      ++oper[i];
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i=0; i<N; i++) cin >> A[i];
  for(int i=0; i<4; i++) cin >> oper[i];

  maxAns = -2e9, minAns = 2e9;
  bruteforce(1, A[0]);
  cout << maxAns << '\n' << minAns << '\n';
}
