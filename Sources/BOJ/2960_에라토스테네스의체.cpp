#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int n, k, ret, cnt=0;
  vector<bool> remaining(1001, true);
  cin >> n >> k;
  remaining[0] = remaining[1] = false;
  for(int i=2; i<=n; i++)
    if(remaining[i])
      for(int j=i; j<=n; j+=i)
        if(remaining[j]){
          remaining[j]=false;
          if(++cnt==k) ret=j;
        }
  cout << ret << endl;
  return 0;
}
