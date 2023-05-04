#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<int> weirdPrimes;

// n이 소수인지 판별하는 함수이다.
bool isPrime(int n)
{
  int sqrtn = sqrt(n);
  for (int i = 2; i <= sqrtn; i++)
    if (n % i == 0)
      return false;
  return true;
}

// 숫자 prime으로 시작하는 N자리의 신기한 소수를 찾는 함수이다.
void findWeirdPrimes(int prime)
{
  // prime이 N자리인 경우, weirdPrimes 벡터에 넣는다.
  if (to_string(prime).size() == N) {
    weirdPrimes.push_back(prime);
    return;
  }
  
  // prime 뒤에 i를 붙인 숫자 nextNum이 소수이면 
  // nextNum으로 시작하는 N자리의 신기한 소수를 찾는다.
  for (int i = 1; i < 10; i += 2) {
    int nextNum = prime * 10 + i;
    if (isPrime(nextNum)) {
      findWeirdPrimes(nextNum);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;

  // 자릿수가 1인 소수에서 확장해나간다.
  findWeirdPrimes(2);
  findWeirdPrimes(3);
  findWeirdPrimes(5);
  findWeirdPrimes(7);
  
  for (int weirdPrime : weirdPrimes)
    cout << weirdPrime << '\n';
}
