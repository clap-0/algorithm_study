#include <iostream>
using namespace std;

int cache[1000001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  
  cache[1] = 1;
  for(int i = 2; i <= N; i++) {
    cache[i] = cache[i - 1];
    if(!(i % 2)) cache[i] = (cache[i] + cache[i / 2]) % 1000000000;
  }
  
  cout << cache[N] << '\n';
}
