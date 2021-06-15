#include <iostream>
using namespace std;
int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << min(x, min(y, min(w-x, h-y))) << endl;
}
