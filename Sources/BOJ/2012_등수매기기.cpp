#include <iostream>
#include <algorithm>
using namespace std;

// 예상 등수
int prospect[500000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i=0; i<N; i++) cin >> prospect[i];

  sort(prospect, prospect+N);

  // 불만도
  long long complaint=0;
  for(int i=0; i<N; i++){
    complaint += (long long)abs(i+1-prospect[i]);
  }
  
  cout << complaint << '\n';
}
