#include <iostream>
#include <vector>
using namespace std;
int deck[1000][5];
//a번 사람의 카드뭉치 중 3개를 합했을 때 최대의 1의 자리 수 반환
int maxUnitDigit(int a, int curr, vector<int>& card){
  if(card.size()==3) return (card[0]+card[1]+card[2])%10;
  int res=0;
  for(int next=curr+1; next<5; next++){
    card.push_back(deck[a][next]);
    res = max(res, maxUnitDigit(a, next, card));
    card.pop_back();
  }
  return res;
}
int main()
{
  int N;
  pair<int,int> ans(-1,0);
  vector<int> card;
  cin >> N;
  for(int i=0; i<N; i++)
    for(int j=0; j<5; j++) cin >> deck[i][j];
  for(int a=0; a<N; a++){
    int d = maxUnitDigit(a, -1, card);
    if(ans.second<=d) ans = {a+1,d};
  }
  cout << ans.first << '\n';
}
