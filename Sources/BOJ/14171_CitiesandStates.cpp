#include <iostream>

using namespace std;

const int ALPHABET = 26;

// {도시 코드, 주 코드} 쌍의 개수
int cnt[ALPHABET*ALPHABET][ALPHABET*ALPHABET];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  int ans = 0;
  for (int i = 0; i < N; i++) {
    string city, state;
    cin >> city >> state;

    int cityCode = ALPHABET*(city[0]-'A') + (city[1]-'A');
    int stateCode = ALPHABET*(state[0]-'A') + (state[1]-'A');

    if (cityCode == stateCode) {
      continue;
    }

    ++cnt[cityCode][stateCode];       // {도시 코드, 주 코드} 쌍의 개수를 늘린다.
    ans += cnt[stateCode][cityCode];  // {주 코드, 도시 코드} 쌍이 있으면 더한다.
  }

  cout << ans << '\n';
}
