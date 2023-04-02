#include <iostream>
#include <cmath>
using namespace std;

long long velocity[300000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) 
    cin >> velocity[i];

  for (int i = N - 1; i >= 1; i--) {
    if (velocity[i - 1] < velocity[i]) {
      velocity[i - 1] *= ceil(1.0 * velocity[i] / velocity[i - 1]);
    }
  }

  cout << velocity[0] << '\n';
}
