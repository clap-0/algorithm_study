#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> clothesMap;
    // 각 의상종류마다 몇 개의 의상이 있는지 구한다
    for(auto& c : clothes)
        clothesMap[c[1]]++;
    // 각 의상종류마다 해당 의상종류의 개수와 입지 않는 경우를 합해 곱연산을 한다
    for(auto iter : clothesMap)
        answer *= iter.second+1;
    return answer-1;
}
