#include <cstdio>
#include <queue>
using namespace std;
int main()
{
  int c;
  scanf("%d", &c);
  while(c--){
    int n;
    priority_queue<int, vector<int>, greater<int> > q;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
      int len;
      scanf("%d", &len);
      q.push(len);
    }
    //길이가 짧은 문자열들끼리 먼저 합친다
    int cost=0;
    while(q.size()>1){
      int merge=0;
      merge += q.top(); q.pop();
      merge += q.top(); q.pop();
      cost += merge;
      q.push(merge);
    }
    printf("%d\n", cost);
  }
}
