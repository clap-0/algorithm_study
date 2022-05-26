#include <iostream>
using namespace std;

// isOccupied[i]: i번 땅의 점유 여부
bool isOccupied[1 << 20];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, Q;
  cin >> N >> Q;
  for(int i = 0; i < Q; i++) {
    int site;
    cin >> site;
    
    // site부터 루트 땅까지 올라가며 이미 점유된 땅이 있다면 ans값을 바꾼다
    int temp = site, ans = 0;
    while(temp != 1) {
      if(isOccupied[temp]) ans = temp;
      temp /= 2;
    }
    if(ans == 0) isOccupied[site] = true;
    cout << ans << '\n';
  }
}
