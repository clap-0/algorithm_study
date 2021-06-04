#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX=50001, INF=987654321;

vector<pair<int,int> > adj[MAX];
vector<int> minFeeds(MAX,INF); //minFeeds[i] = 헛간 1에서 i까지 가는데 필요한 최소여물 수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
  //다익스트라 알고리즘
	priority_queue<pair<int,int> > pq;
	pq.push({0,1});
	minFeeds[1]=0;
	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if(minFeeds[here]<cost) continue;
		if(here==n) break;
		for(auto &p : adj[here]){
			int there = p.first, nextCost = minFeeds[here]+p.second;
			if(minFeeds[there]>nextCost){
				minFeeds[there]=nextCost;
				pq.push({-nextCost,there});
			}
		}
	}
	cout << minFeeds[n] << '\n';
}
