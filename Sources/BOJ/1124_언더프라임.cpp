#include <iostream>
#include <vector>
using namespace std;

vector<int> isPrime;
int primeFactors[100001];

// 에라토스테네스의 체를 이용해서
// n이하의 수들에 대해서 각각의 수의 소수인 소인수들의 개수를 구한다.
void calcPrimeFactors(int n)
{
  isPrime = vector<int>(n + 1, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= n; i++)
    if (isPrime[i])
      for (int j = i * 2; j <= n; j += i) {
        isPrime[j] = false;
        int tmp = j;
        while (tmp % i == 0) {
          tmp /= i;
          primeFactors[j]++;
        }
      }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int A, B;
  cin >> A >> B;
  calcPrimeFactors(B);
  int ans = 0;
  for (int i = A; i <= B; i++)
    if (isPrime[primeFactors[i]])
      ++ans;
  cout << ans << '\n';
}
