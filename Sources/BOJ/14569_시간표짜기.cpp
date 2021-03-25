#include <iostream>
using namespace std;
const int MAX_N=1000;
long long classHour[MAX_N]; //classHour[i] = i번 과목의 수업시간 비트마스크 표현
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, k, t;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> k;
    for(int j=0; j<k; j++){
      cin >> t;
      classHour[i] |= (1ll<<(t-1)); //오버플로우 조심해서 1LL로 
    }
  }
  int m, p, q;
  cin >> m;
  for(int i=0; i<m; i++){
    cin >> p;
    int cnt=0;
    long long spareTime=0; //비어있는 교시 비트마스크 표현
    for(int j=0; j<p; j++){
      cin >> q;
      spareTime |= (1ll<<(q-1));
    }
    for(int subject=0; subject<n; subject++)
      if((classHour[subject] & spareTime)==classHour[subject])
        cnt++;
    cout << cnt << '\n';
  }
  return 0;
}
