#include <iostream>
using namespace std;

int N, S;
int arr[40];
// 부분수열의 합의 범위가 -4,000,000 ~ 4,000,000 이므로
// 크기가 8,000,000인 배열을 만든다
int subseqSum[8000000];

// [0, N/2)범위의 모든 부분수열의 합을 구한다
void leftSum(int pos, int n, int sum) {
  if(pos == n) {
    // sum이 음수일 수도 있으니 4000000을 더한다
    subseqSum[sum + 4000000]++;
    return;
  }
  leftSum(pos + 1, n, sum);
  leftSum(pos + 1, n, sum + arr[pos]);
}

// [N/2, N)범위의 모든 부분수열의 합에 대하여
// 기존에 구한 왼쪽 범위의 부분수열의 합과 더했을 때 S가 되는 부분수열의 개수를 구한다
long long rightSum(int pos, int n, int sum) {
  if(pos == n) 
    return subseqSum[S - sum + 4000000];
  return rightSum(pos + 1, n, sum) + rightSum(pos + 1, n, sum + arr[pos]);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> S;
  for(int i = 0; i < N; i++) cin >> arr[i];

  leftSum(0, N / 2, 0);
  
  long long ans = rightSum(N / 2, N, 0);
  // S가 0인 경우 공집합(왼쪽과 오른쪽 범위에서 아무 원소도 더하지 않은 경우)을 배제하기 위해 1을 뺀다
  if(S == 0) --ans;
  cout << ans << '\n';
}
