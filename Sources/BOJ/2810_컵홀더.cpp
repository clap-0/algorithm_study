#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, couples=0;
  string seat;
  cin >> N >> seat;
  for(int i=0; i<N; i++){
    if(seat[i]=='L') ++couples;
  }
  int cupHolders = N - couples/2 + 1;
  cout << min(cupHolders, N) << '\n';
}
