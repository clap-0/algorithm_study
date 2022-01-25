#include <iostream>
using namespace std;

const int MAX = 100000;
int arr[MAX];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, S;
  cin >> N >> S;
  for(int i=0; i<N; i++) cin >> arr[i];

  // 투포인터 알고리즘
  int from=0, to=0, ans=MAX;
  int sum = arr[0];
  while(from<=to && to <= N) {
    if(sum == S) {
      ans = min(ans, to-from+1);
      sum += arr[++to];
    }
    else if(sum < S) sum += arr[++to];
    else {
      ans = min(ans, to-from+1);
      sum -= arr[from++];
    }
  }
  cout << (ans!=MAX ? ans : 0) << '\n';
}
