#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

int n, m, k, a, b, c;
priority_queue<int> dist[MAX];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
vector<vector<pair<int, int>>> adj;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	adj.resize(n + 1);
	for (int i = 0; i < m; i++){
		scanf("%d%d%d", &a, &b, &c);
		adj[a].emplace_back(b, c);
	}

	pq.push({0, 1});	
	dist[1].push(0);

	while (!pq.empty()){
		pair<int, int> top = pq.top();
		pq.pop();

		for (pair<int, int> next : adj[top.second]){
			if (dist[next.first].size() < k) {
				pq.push({top.first + next.second, next.first});
				dist[next.first].push(top.first + next.second);
			}
			else if (dist[next.first].top() > top.first + next.second){
				dist[next.first].pop();
				dist[next.first].push(top.first + next.second);
				pq.push({top.first + next.second, next.first});
			}
		}
	}
	
	for (int i = 1; i <= n; i++){
		if (dist[i].size() < k) printf("-1");
		else printf("%d", dist[i].top());
		
		printf("\n");
	}	
}
