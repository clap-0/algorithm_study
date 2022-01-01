#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

// 공항을 key값, 임의로 지정된 번호를 value로 하는 unordered_map
unordered_map<string,int> airportToNum;
// adjAirport[i] = i번 공항에서 출발하는 티켓의 도착지와 티켓번호. 사전순으로 하기 위해 set사용
set<pair<string,int> > adjAirport[10000];
// 공항의 개수
int airportSize;

// 인접리스트. 각 티켓을 정점으로 하고, 도착지와 출발지가 같은 티켓 사이에 간선을 둔다
vector<vector<int> > adj;
vector<bool> visited;

// 깊이우선탐색 알고리즘
// 티켓 here에서 출발하여 갈 수 있는 가장 긴 경로를 반환한다
vector<int> dfs(int here) {
    vector<int> ret;
    for(int there : adj[here]) {
        if(!visited[there]) {
            visited[there] = true;
            vector<int> tmp = dfs(there);
            // 경로가 긴 것으로 최신화시킨다
            if(ret.size() < tmp.size()) ret = tmp;
            visited[there] = false;
        }
    }
    ret.insert(ret.begin(), here);
    return ret;
}

vector<string> solution(vector<vector<string>> tickets) {
    int ticketsCnt = tickets.size();
    
    // i번째 티켓의 출발지와 도착지를 간선으로 연결해 adjAirport를 만든다
    for(int i = 0; i < ticketsCnt; i++) {
        string from = tickets[i][0], to = tickets[i][1];
        if(!airportToNum.count(from)) {
            airportToNum[from] = airportSize++;
        }
        if(!airportToNum.count(to)) {
            airportToNum[to] = airportSize++;
        }
        adjAirport[airportToNum[from]].insert({to, i});
    }
    
    // i번 티켓의 도착지와 출발지가 같은 티켓들을 i번 티켓과 간선으로 연결해 adj를 만든다
    adj.resize(ticketsCnt + 1);
    visited.resize(ticketsCnt + 1, false);
    for(int i = 0; i < ticketsCnt; i++) {
        int destNum = airportToNum[tickets[i][1]];
        for(auto next : adjAirport[destNum]) {
            adj[i].push_back(next.second);
        }
    }
    
    // 출발지가 "ICN"인 티켓들을 임의의 ticketsCnt번 티켓과 간선으로 연결한다
    int depNum = airportToNum["ICN"];
    for(auto next : adjAirport[depNum]) {
        adj[ticketsCnt].push_back(next.second);
    }
    
    vector<int> path = dfs(ticketsCnt);
    vector<string> answer;
    answer.push_back("ICN");
    for(int i = 1; i < path.size(); i++) {
        answer.push_back(tickets[path[i]][1]);
    }
    
    return answer;
}
