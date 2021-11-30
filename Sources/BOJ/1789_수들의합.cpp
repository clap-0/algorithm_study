#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  long long S;
  cin >> S;

  // N이 최대한 커야 하므로
  // 작은 값부터 S에서 빼준다
  int N=1;
  while(S>=N){
    S -= N++;
  }

  cout << N-1 << '\n';
}
