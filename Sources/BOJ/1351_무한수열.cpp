#include <iostream>
#include <unordered_map>
using namespace std;

long long n, p, q;
unordered_map<long long, long long> cache;

long long getSequence(long long n) {
  if(cache.count(n)) return cache[n];
  return cache[n] = getSequence(n / p) + getSequence(n / q);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> p >> q;
  cache[0] = 1;
  cout << getSequence(n) << '\n';
}
