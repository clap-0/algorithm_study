#include <iostream>
using namespace std;

int P[50002];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 1; i <= N; i++)
    cin >> P[i];
  
  for(int i = 1; i <= N; i++)
    if(P[i - 1] <= P[i] && P[i + 1] <= P[i])
      cout << i << '\n';
}
