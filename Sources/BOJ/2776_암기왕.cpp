#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numbers;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N;
    numbers = vector<int>(N);
    for (int i = 0; i < N; i++)
      cin >> numbers[i];
    
    sort(numbers.begin(), numbers.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
      int num;
      cin >> num;
      cout << binary_search(numbers.begin(), numbers.end(), num) << '\n';
    }
  }
}
