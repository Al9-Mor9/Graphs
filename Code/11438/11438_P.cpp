#include <iostream>
#include <vector>
#define MAX 100001
#define MAX_DEPTH 18
using namespace std;

int N, M, depth[MAX], parent[MAX][MAX_DEPTH], a, b;
vector<vector<int>> adj;
vector<int> ans;

void maketree(int cur, int par) {
	
	for (int child : adj[cur]) {
		if (child != par) {
			depth[child] = depth[cur] + 1;
			parent[child][0] = cur;
			maketree(child, cur);
		}
	}
}

int main() {
	scanf("%d", &N);
	adj.resize(N + 1);
	for (int i = 1; i <= N; i++) depth[i] = 1;

	for (int i = 1; i < N; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	maketree(1, 0);

	for (int j = 1; j < MAX_DEPTH; j++) {
		for (int i = 1; i <= N; i++) 
			if (parent[i][j-1]) parent[i][j] = parent[parent[i][j - 1]][j - 1];
	}
    scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		
		if (depth[a] < depth[b]) swap(a, b);
		int diff = depth[a] - depth[b];

		for (int i = 0; i < MAX_DEPTH; i++){
			if (diff & (1 << i)) a = parent[a][i];
		}

		if (a != b) {
			for (int j = MAX_DEPTH - 1; j >= 0; j--) {
				if (parent[a][j] && parent[a][j] != parent[b][j]) {
					a = parent[a][j]; 
                    b = parent[b][j];
				}
			}
			a = parent[a][0];
		}
		ans.push_back(a);
    }
	for (int i = 0; i < M; i++) printf("%d\n", ans[i]);
}
