#include <iostream>
#include <algorithm>
using namespace std;

string serial[50];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> serial[i];

  sort(serial, serial + N, [](string& a, string& b){
    // 1. A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
    if(a.length() != b.length()) return a.length() < b.length();
    
    // 2. 만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
    int len = a.length(), aCount = 0, bCount = 0;
    for(int i = 0; i < len; i++) {
      if('0' <= a[i] && a[i] <= '9') aCount += a[i] - '0';
      if('0' <= b[i] && b[i] <= '9') bCount += b[i] - '0';
    }
    if(aCount != bCount) return aCount < bCount;
    
    // 3. 만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
    return a < b;
  });

  for(int i = 0; i < N; i++) cout << serial[i] << '\n';
}
