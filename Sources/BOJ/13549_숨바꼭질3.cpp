#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int MAX=100001;
int main()
{
  int n, k;
  int shortest[MAX];
  queue<int> Q;
  cin >> n >> k;
  memset(shortest, -1, sizeof(shortest));
  Q.push(n);
  shortest[n]=0;
  while(!Q.empty()){
    int pos = Q.front(); Q.pop();
    if(pos==k) break;
    if(pos*2<MAX && shortest[pos*2]==-1){
      Q.push(pos*2);
      shortest[pos*2]=shortest[pos];
    }
    if(pos-1>=0 && shortest[pos-1]==-1){
      Q.push(pos-1);
      shortest[pos-1]=shortest[pos]+1;
    }
    if(pos+1<MAX && shortest[pos+1]==-1){
      Q.push(pos+1);
      shortest[pos+1]=shortest[pos]+1;
    }
  }
  cout << shortest[k] << '\n';
}
