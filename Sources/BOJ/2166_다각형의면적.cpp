#include <iostream>
using namespace std;

pair<int,int> P[10000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;

  double S = 0;
  pair<long long,long long> u, v;
  // 벡터 u를 벡터 P₀P₁로 초기화한다
  u = {P[1].first - P[0].first, P[1].second - P[0].second};
  // 다각형의 면적을 점 P₀, Pᵢ₋₁, Pᵢ로 이루어진 삼각형들의 면적의 합을 통해 구한다. (2 <= i < N)
  for(int i = 2; i < N; i++) {
    v = {P[i].first - P[0].first, P[i].second - P[0].second};
    // 벡터 u와 v의 외적을 이용하여 u와 v로 이루어진 삼각형의 넓이를 구한다
    S += (u.first * v.second - u.second * v.first) / 2.0;
    u = v;
  }
  
  cout << fixed;
  cout.precision(1);
  cout << abs(S) << '\n';
}
