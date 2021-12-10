#include <cstdio>
#include <algorithm>
using namespace std;

char table[20000];
bool isBurger[20000];

int main()
{
  int N, K;
  scanf("%d %d", &N, &K);
  for(int i=0; i<N; i++){
    scanf(" %c", table+i);
    if(table[i]=='H') isBurger[i]=true;
  }

  int ans=0;
  for(int i=0; i<N; i++)
    if(table[i]=='P')
      for(int j=max(0, i-K); j<=min(N-1, i+K); j++)
        if(isBurger[j]){
          isBurger[j]=false;
          ++ans;
          break;
        }
  printf("%d\n", ans);
}
