#include <stdio.h>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> vt;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int V, E, K, u, v, w;

int main() {
	scanf("%d%d%d", &V, &E, &K);
	vt.resize(V + 1);
	int *dist = new int[V + 1];

	for (int i = 0; i < E; i++) {
		scanf("%d%d%d", &u, &v, &w);
		vt[u].push_back({ v,w });
	}

	for (int i = 1; i < V + 1; i++) dist[i] = -1;
	pq.push({ 0,K });

	while (!pq.empty()) {
		int w = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		if (dist[x] > -1) continue;
		dist[x] = w;
		
		for (auto nxt : vt[x]) {
			int next = nxt.first;
			int ncost = nxt.second + w;
			if (dist[next] > -1) continue;
			pq.push({ ncost,next });

		}

	}
	
	for (int i = 1; i < V + 1; i++) {
		if (dist[i] <0) printf("INF\n");
		else printf("%d\n", dist[i]);
	}



}
