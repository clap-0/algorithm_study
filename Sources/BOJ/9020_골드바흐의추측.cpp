#include <iostream>
#include <cstring>
using namespace std;

bool isPrime[10000];

void eratosthenes()
{
  memset(isPrime, 1, sizeof(isPrime));
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= 100; i++)
    if (isPrime[i])
      for (int j = i * i; j < 10000; j += i)
        isPrime[j] = false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  eratosthenes();
  while (T--) {
    int n;
    cin >> n;
    int a, b;
    if (n == 4)
      a = b = 2;
    else {
      for (int i = 3; i <= n/2 ; i += 2)
        if (isPrime[i] && isPrime[n - i]) {
          a = i;
          b = n - i;
        }
    }
    cout << a << ' ' << b << '\n';
  }
}
