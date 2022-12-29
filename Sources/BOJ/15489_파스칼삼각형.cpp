#include <iostream>
using namespace std;

int dp[31][31];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int R, C, W;
	cin >> R >> C >> W;
	dp[1][1] = 1;
	for (int i = 2; i < R + W; i++)
		for (int j = 1; j <= i; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

	int ans = 0;
	for (int i = 0; i < W; i++)
		for (int j = 0; j <= i; j++)
			ans += dp[R + i][C + j];
	cout << ans << '\n';
}
