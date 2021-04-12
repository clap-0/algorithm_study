#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
  int n, k;
  vector<int> psum;
  map<int, long long> prev;
  cin >> n >> k;
  psum.push_back(0); //편의를 위해 부분합의 맨 앞에 0 삽입
  for(int i=1; i<=n; i++){
    int num;
    cin >> num;
    psum.push_back(num+psum[i-1]);
  }
  //psum[index1] - psum[index2] == k이면
  //psum[index1] - k == psum[index2]이므로
  //위 공식을 만족하는 psum[index2]의 수를 모두 구하면 됨
  long long ans=0;
  for(int i=0; i<=n; i++){
    ans += prev[psum[i]-k]; //이전에 발견된 psum[i]-k의 수를 답에 더함
    prev[psum[i]]++; //발견된 목록에 psum[i] 하나 추가
  }
  cout << ans << endl;
  return 0;
}
