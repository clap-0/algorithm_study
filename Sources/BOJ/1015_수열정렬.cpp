#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> arr[50];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }

  sort(arr, arr + N);
  for (int i = 0; i < N; i++)
    arr[i].first = i;
  sort(arr, arr + N, [](pair<int,int>& a, pair<int,int>& b) {
    return a.second < b.second;
  });

  for(int i = 0; i < N; i++)
    cout << arr[i].first << ' ';
}
