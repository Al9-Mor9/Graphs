#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, a, b, indeg[32001]{ 0, };
queue<int> ffind;
queue<int> result;
vector<vector<int>> adj;

int main(){
	scanf("%d%d", &N, &M);
	adj.resize(N + 1);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		indeg[b]++;
	}

	for (int i = 1; i <= N; i++) {
		if (!indeg[i]) ffind.push(i);
	}

	while (!ffind.empty()) {
		int front = ffind.front();
		ffind.pop();
		for (int to : adj[front]) {
			indeg[to] --;
			if (!indeg[to]) ffind.push(to);
		}
		result.push(front);
	}

	while (!result.empty()) {
		printf("%d ", result.front());
		result.pop();
	}


}
