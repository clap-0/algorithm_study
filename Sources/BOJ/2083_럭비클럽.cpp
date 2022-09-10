#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string name;
  int age, weight;
  while (true) {
    cin >> name >> age >> weight;
    if (name == "#") break;
    cout << name << (age > 17 || weight >= 80 ? " Senior\n" : " Junior\n");
  }
}
