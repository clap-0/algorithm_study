#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string name;
    int grade;
    cin >> name >> grade;
    cout << name << ' ';
    if (grade >= 97) cout << "A+\n";
    else if (grade >= 90) cout << "A\n";
    else if (grade >= 87) cout << "B+\n";
    else if (grade >= 80) cout << "B\n";
    else if (grade >= 77) cout << "C+\n";
    else if (grade >= 70) cout << "C\n";
    else if (grade >= 67) cout << "D+\n";
    else if (grade >= 60) cout << "D\n";
    else cout << "F\n";
  }
}
