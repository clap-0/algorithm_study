#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int num[8], arr[8];
bool used[8];
void backtrack(int curr){
  if(curr==m){
    for(int i=0; i<m; i++) cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  for(int i=0; i<n; i++){
    if(!used[i]){
      used[i]=true;
      arr[curr]=num[i];
      backtrack(curr+1);
      used[i]=false;
    }
    
  }
}
int main()
{
  cin >> n >> m;
  for(int i=0; i<n; i++) cin >> num[i];
  sort(num, num+n);
  backtrack(0);
}
