#include <iostream>
#include <queue>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  int n, ans=0;
  priority_queue<int, vector<int>, greater<int> > decks;
  cin >> n;
  for(int i=0; i<n; i++){
    int deckSize;
    cin >> deckSize;
    decks.push(deckSize);
  }
  while(decks.size()!=1){
    int least = decks.top();
    decks.pop();
    least += decks.top(); decks.pop();
    decks.push(least);
    ans+=least;
  }
  cout << ans << endl;
  return 0;
}
