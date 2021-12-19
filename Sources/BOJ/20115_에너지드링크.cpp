#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, largest=0;
  double sum = 0;
  cin >> N;
  for(int i=0; i<N; i++){
    int x;
    cin >> x;
    largest = max(x, largest);
    sum += x;
  }
  sum = (sum + largest)/2.0;
  cout << fixed;
  cout.precision(5);
  cout << sum << '\n';
}
