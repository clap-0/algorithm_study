#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int TC;
  cin >> TC;
  while(TC--){
    int n;
    unordered_map<string, int> clothMap;
    cin >> n;
    // 의상종류마다 몇개가 있는지 구한다 (의상이름은 몰라도 된다)
    for(int i=0; i<n; i++){
      string clothName, clothType;
      cin >> clothName >> clothType;
      clothMap[clothType]++;
    }
    int ans=1;
    unordered_map<string, int>::iterator iter;
    // 각 종류의 의상의 개수마다 안 입는 경우를 고려해 1을 더한 다음 경우의 수를 구하기 위해 곱한다
    for(iter=clothMap.begin(); iter!=clothMap.end(); iter++) ans *= iter->second+1;
    // 모든 종류의 의상을 안 입는 경우를 제외하기 위해 1을 뺀다
    cout << ans-1 << '\n';
  }
}
