#include <stdio.h>
#include <queue>
using namespace std;

int N, M, a, b, c, cnt;
long long INF = 2147483647;

bool cycle = true;
long long dist[501];
vector<vector<pair<int, int>>> vt;
queue<int> input, output;

void bellman(int cnt) {
	if (cnt == 1) cycle = false;
	while (cnt--) {
		while (!input.empty()) {
			int here = input.front();
			for (auto it : vt[here]) {
				int next = it.first;
				int cost = it.second;
				if (dist[here] + it.second < dist[next]) {
					cycle = true;
					dist[next] = dist[here] + it.second;
					output.push(next);
				}
			}
			input.pop();
		}
		while (!output.empty()) {
			int here = output.front();
			for (auto it : vt[here]) {
				int next = it.first;
				int cost = it.second;
				if (dist[here] + it.second < dist[next]) {
					dist[next] = dist[here] + it.second;
					cycle = true;
					input.push(next);
				}
			}
			output.pop();
		}
	}
}



int main() {
	scanf("%d%d", &N, &M);
	vt.resize(N + 1);
	for (int i = 0; i < N + 1; i++) dist[i] = INF;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b, &c);
		vt[a].push_back({ b,c });
	}
	dist[1] = 0;
	input.push(1);
	bellman(N);
	bellman(1);
	if (cycle) printf("-1");
	else {
		for (int i = 2; i < N + 1; i++) {
			if (dist[i] < INF) printf("%lld", dist[i]);
			else printf("-1");
			if (i < N) printf("\n");

		}
	}


}
