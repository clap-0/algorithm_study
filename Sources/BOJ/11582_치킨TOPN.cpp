#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numbers[1<<20];

// numbers[low..mid), numbers[mid, high)가 정렬되어있다고 가정하고,
// numbers[low..high)를 병합정렬을 이용해 정렬한다.
void mergesort(int low, int high)
{
  int mid = (low + high) / 2;
  int tmp[high - low];  // 정렬된 결과를 담는 임시 배열

  int left = low, right = mid, idx = 0;
  while (left < mid && right < high) 
    if (numbers[left] < numbers[right])
      tmp[idx++] = numbers[left++];
    else
      tmp[idx++] = numbers[right++];
  for (int i = left; i < mid; i++)
    tmp[idx++] = numbers[i];
  for (int i = right; i < high; i++)
    tmp[idx++] = numbers[i];
  
  for (int i = low; i < high; i++)
    numbers[i] = tmp[i - low];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N, k;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> numbers[i];
  cin >> k;

  for (int i = 2; i * k <= N; i *= 2)
    for (int j = 0; j < N; j += i)
      mergesort(j, j + i);

  for (int i = 0; i < N; i++)
    cout << numbers[i] << ' ';
}
