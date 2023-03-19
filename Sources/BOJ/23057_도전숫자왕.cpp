#include <iostream>
#include <unordered_set>
using namespace std;

int numbers[20];
unordered_set<int> sumSet;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

  int n;
  cin >> n;

  int totalSum = 0;
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
    totalSum += numbers[i];
  }

  // 비트마스킹을 이용해 n개의 수에 대한 모든 조합의 합을 구한다.
  for (int indexes = 1; indexes != (1 << n); indexes++) {
    int sum = 0;
    for (int tmp = indexes; tmp; tmp &= (tmp - 1)) {
      int index = __builtin_ctz(tmp);   // index: tmp에서 가장 작은 켜져있는 비트의 인덱스
      sum += numbers[index];
    }
    sumSet.insert(sum);
  }
  
  cout << totalSum - sumSet.size() << '\n';
}
