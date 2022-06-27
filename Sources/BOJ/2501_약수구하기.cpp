#include <iostream>
using namespace std;

int solve(int n, int k) {
  for(int i = 1; i <= n; i++) 
    if(n % i == 0 && --k == 0) return i;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;

  cout << solve(n, k);
}
