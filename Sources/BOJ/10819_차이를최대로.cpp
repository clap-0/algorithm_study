#include <iostream>
using namespace std;
int N;
int arr[8], order[8];
bool isPicked[8];
int abs(int n) {return n>0 ? n : -n;}
//백트래킹으로 n!개의 순열을 만들어 답을 구함
int solve(int curr){
  int ret=0;
  if(curr==N){
    for(int i=0; i+1<N; i++) ret+=abs(arr[order[i]]-arr[order[i+1]]);
    return ret;
  }
  for(int i=0; i<N; i++)
    if(!isPicked[i]){
      order[curr]=i;
      isPicked[i]=true;
      ret = max(ret,solve(curr+1));
      isPicked[i]=false;
    }
  return ret;
}
int main()
{
  cin >> N;
  for(int i=0; i<N; i++) cin >> arr[i];
  cout << solve(0) << '\n';
}
