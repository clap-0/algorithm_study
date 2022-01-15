#include <iostream>
#include <algorithm>
using namespace std;

int w[5000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, C;
  cin >> N >> C;
  for(int i=0; i<N; i++) {
    cin >> w[i];
    // 물건 하나로 C에 맞추는 경우
    if(w[i] == C) {
      cout << 1 << '\n';
      return 0;
    }
  }
  
  sort(w, w+N);
  for(int i=0; w[i]<C && i<N; i++) 
    for(int j=i+1; w[i]+w[j]<=C && j<N; j++) {
      // 물건 두개로 C에 맞추는 경우
      if(w[i] + w[j] == C) {
        cout << 1 << '\n';
        return 0;
      }
      // 물건 세개로 C에 맞추는 경우
      if(*lower_bound(w+j+1, w+N, C-w[i]-w[j]) == C-w[i]-w[j]) {
        cout << 1 << '\n';
        return 0;
      }
    }
  cout << 0 << '\n';
}
