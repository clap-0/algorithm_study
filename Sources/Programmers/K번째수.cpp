#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto& c : commands){
        // temp를 array의 i번째수부터 j번째수로 자른다
        vector<int> temp(array.begin()+c[0]-1, array.begin()+c[1]);
        // 해당 벡터를 정렬한다
        sort(temp.begin(), temp.end());
        // k번째 수를 찾는다
        answer.push_back(temp[c[2]-1]);
    }
    return answer;
}
