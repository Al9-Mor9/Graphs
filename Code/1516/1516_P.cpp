#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 501

int N, preBuilt, t;
int indegree[MAX], neededTime[MAX], inMax[MAX];
int ans[MAX];
vector<vector<int>> adj;
queue<int> q;

int main(){
	scanf("%d", &N);
	adj.resize(N + 1);

	for (int i = 1; i <= N; i++){
		scanf("%d", &t);
		neededTime[i] = t;
		while (true){
			scanf("%d", &preBuilt);
			if (preBuilt == -1) break;
			adj[preBuilt].push_back(i);
			indegree[i]++;
		}
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()){
		int front = q.front();
		q.pop();
		for (int next : adj[front]){
			indegree[next]--;
			inMax[next] = max(inMax[next], neededTime[front]);
			if (indegree[next] == 0){
				neededTime[next] += inMax[next];
				q.push(next);
			}
		}	
	}

	for (int i = 1; i <= N; i++){
		printf("%d\n", neededTime[i]);
	}
}
