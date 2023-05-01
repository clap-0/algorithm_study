#include <iostream>
using namespace std;

int dp[15][15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int i = 1; i <= 14; i++)
		dp[0][i] = i;

	for (int i = 1; i <= 14; i++)
		for (int j = 1; j <= 14; j++)
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
	
	while (T--) {
		int k, n;
		cin >> k >> n;
		cout << dp[k][n] << '\n';
	}
	
	return 0;
}
