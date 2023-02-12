#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  
  int complex[3] = {0};
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    complex[A % 3]++;
  }

  int p = complex[1] - complex[2];
  int q = complex[0] - complex[2];
  cout << p << ' ' << q << '\n';
}
