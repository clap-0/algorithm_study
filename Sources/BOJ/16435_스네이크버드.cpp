#include <iostream>
#include <algorithm>
using namespace std;

int h[1000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N, L;
  cin >> N >> L;
  for(int i=0; i<N; i++) cin >> h[i];
  sort(h, h+N);
  for(int i=0; i<N; i++){
    if(L < h[i]) break;
    L++;
  }
  cout << L << '\n';
}
