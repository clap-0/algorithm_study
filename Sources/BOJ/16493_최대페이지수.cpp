#include <iostream>
#include <algorithm>
using namespace std;

int W, N;
pair<int,int> items[20];
int maxprofit;

// 각 노드의 유망 여부
bool promising(int index, int profit, int weight)
{
  if (weight >= W)
    return false;
  else {
    int k = index + 1;
    int totweight = weight;
    double bound = profit;
    while (k < N && totweight + items[k].first <= W) {
      totweight += items[k].first;
      bound += items[k].second;
      ++k;
    }
    if (k < N)
      bound += (W - totweight) * items[k].second / items[k].first;
    return bound > maxprofit;
  }
}

// 분기한정법
void branchAndBound(int index, int profit, int weight)
{
  if (weight <= W && profit > maxprofit)
    maxprofit = profit;
  if (promising(index, profit, weight)) {
    branchAndBound(index + 1, profit + items[index + 1].second, weight + items[index + 1].first);
    branchAndBound(index + 1, profit, weight);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> W >> N;
  for (int i = 0; i < N; i++)
    cin >> items[i].first >> items[i].second;
  
  // p/w에 대해 내림차순 정렬
  sort(items, items + N, [](pair<int,int> &a, pair<int,int> &b) {
    return 1.0 * a.second / a.first > 1.0 * b.second / b.first;
  });
  branchAndBound(-1, 0, 0);

  cout << maxprofit << '\n';
}
