#include <algorithm>
#include <iostream>

int requiredMileages[100];
int othersMileages[100];

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int P, L;
		cin >> P >> L;
		for (int p = 0; p < P; p++) {
			cin >> othersMileages[p];
		}

		if (P < L) {
			requiredMileages[i] = 1;
		} else {
			sort(othersMileages, othersMileages + P, greater<int>());
			requiredMileages[i] = othersMileages[L - 1];
		}
	}

	int ans = 0;
	sort(requiredMileages, requiredMileages + n);
	for (int sum = requiredMileages[0]; sum <= m && ans < n; sum += requiredMileages[++ans]) ;

	cout << ans << '\n';
}
