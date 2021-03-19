#include <iostream>
#include <queue>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m;
  unsigned long long num, least, less, sum=0ull;
  priority_queue< unsigned long long, vector<unsigned long long>, greater<unsigned long long> > cards;
  cin >> n >> m;
  for(int i=0; i<n; i++){
    cin >> num;
    cards.push(num);
  }
  //가장 작은 카드와 그 다음 작은 카드를 합체시켜 가장 작은 점수 계산
  for(int cnt=1; cnt<=m; cnt++){
    least = cards.top(); cards.pop();
    less = cards.top(); cards.pop();
    least += less;
    cards.push(least); cards.push(least);
  }
  while(!(cards.empty())){
    sum += cards.top();
    cards.pop();
  }
  cout << sum << endl;
  return 0;
}
