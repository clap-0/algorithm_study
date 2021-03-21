#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
  int n, largest=0;
  vector<int> nums;
  vector<bool> isPrime(1001, true);
  cin >> n;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    nums.push_back(a);
    largest = max(largest, a);
  }
  //에라토스테네스의 체
  isPrime[0] = isPrime[1] = false;
  int sqrtL=int(sqrt(largest));
  for(int i=2; i<=sqrtL; i++)
    if(isPrime[i])
      for(int j=i*i; j<=largest; j+=i)
        isPrime[j]=false;
  int ret=0;
  for(auto &num : nums)
    ret+=isPrime[num];
  cout << ret << endl;
  return 0;
}
