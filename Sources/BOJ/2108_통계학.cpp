#include <iostream>
#include <algorithm>
using namespace std;

int numbers[500000];
int frequency[8001]; // frequency[i] = (i - 4000)의 빈도수

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
    sum += numbers[i];
    ++frequency[numbers[i] + 4000];
  }

  // 산술평균 계산
  int mean = (int)((sum / n) + (sum < 0 ? -0.5 : 0.5));
  
  // 최빈수 계산
  int mode;
  int mostFrequency = 0;
  bool isFirstMode = false; // 현재 mode가 여러 최빈값 중 첫번째 최빈값인지 여부
  for (int i = 0; i <= 8000; i++)
    if (frequency[i] > mostFrequency) {
      mode = i - 4000;
      mostFrequency = frequency[i];
      isFirstMode = true;
    }
    else if (frequency[i] == mostFrequency && isFirstMode) {
      mode = i - 4000;
      isFirstMode = false;
    }

  // 주어진 수들 오름차순 정렬
  sort(numbers, numbers + n);
  
  // 중앙값 계산
  int median = numbers[n / 2];
  // 범위 계산
  int range = numbers[n - 1] - numbers[0];

  cout << mean << '\n' << median << '\n' << mode << '\n' << range << '\n';
}
