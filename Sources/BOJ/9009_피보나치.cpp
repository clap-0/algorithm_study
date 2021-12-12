#include <iostream>
#include <vector>
using namespace std;

int fibo[45];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;

  // 1,000,000,000이하의 피보나치수를 미리 모두 계산한다
  fibo[0] = 0, fibo[1] = 1;
  for(int i=2; i<45; i++) fibo[i] = fibo[i-1] + fibo[i-2];

  while(T--){
    int n;
    cin >> n;
    
    // n보다 작거나 같은 가장 큰 피보나치 수를 구하고 n에서 빼는 걸 반복한다
    vector<int> ans;
    for(int i=44; i>0; i--){
      if(n >= fibo[i]){
        ans.push_back(fibo[i]);
        if((n -= fibo[i]) == 0) break;
      }
    }
    
    while(!ans.empty()){
      cout << ans.back() << ' ';
      ans.pop_back();
    }
    cout << "\n";
  }
}
