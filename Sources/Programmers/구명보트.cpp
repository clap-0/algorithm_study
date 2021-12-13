#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    // 몸무게에 대하여 내림차순으로 정렬
    sort(people.begin(), people.end(), greater<int>());
  
    // 보트에 최대 두 명씩밖에 타지 못하므로
    // 가장 무거운 사람과 가장 가벼운 사람을 같이 태운다
    // 만약 위의 두 사람을 같이 태우지 못하면 무거운 사람만 태운다
    for(int heavy = 0, light = people.size()-1; heavy <= light; heavy++){
        if(people[heavy] + people[light] <= limit){
            light--;
        }
        ++answer;
    }
    return answer;
}
