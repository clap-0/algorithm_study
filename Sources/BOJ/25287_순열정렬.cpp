#include <iostream>
using namespace std;

bool isMonotone(int N) {
  int num, altNum, prev;
  bool ret = true;
  cin >> num;
  prev = min(num, N - num + 1);
  for(int i = 1; i < N; i++) {
    cin >> num;
    altNum = N - num + 1;
    if(prev > max(num, altNum)) ret = false;
    else {
      if(prev <= min(num, altNum)) prev = min(num, altNum);
      else prev = max(num, altNum);
    }
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    cout << (isMonotone(N) ? "YES" : "NO") << '\n';
  }
}
