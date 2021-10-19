#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> umset;
    // multiset에 participant의 원소들을 넣고, completion의 원소들을 지워 마지막까지 남아있는 원소를 찾는다
    for(string p : participant) umset.insert(p);
    for(string c : completion) umset.erase(umset.find(c));
    answer = *umset.begin();
    return answer;
}
