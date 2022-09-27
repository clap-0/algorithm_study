#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N;
  cin >> N;
  int maxNum = 0, minNum = 1000000;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    maxNum = max(maxNum, num);
    minNum = min(minNum, num);
  }
  cout << maxNum * minNum << '\n';
}
