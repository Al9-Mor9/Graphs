#include <iostream>
#include <vector>
using namespace std;

int N, a, b, c, dp[100001][19], mindp[100001][19], maxdp[100001][19], depth[100001], K;
vector<vector<pair<int, int>>> adj;
vector<pair<int, int>> ans;

void maketree(int cur, int par) {
	for (auto child : adj[cur]) {
		if (child.first != par) {
			dp[child.first][0] = cur;
			mindp[child.first][0] = maxdp[child.first][0] = child.second;
			depth[child.first] = depth[cur] + 1;
			maketree(child.first, cur);
		}
	}
}
int min(int a, int b) {	return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

void solve(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int diff = depth[a] - depth[b], minn = 1000001, maxx = 0;
	if (a == b) minn = maxx = 0;

	while (diff) {
		int d = 0;
		for (int i = 1; i <= diff; i *= 2) d++;
		minn = min(minn, mindp[a][d - 1]), maxx = max(maxx, maxdp[a][d - 1]);
		a = dp[a][d - 1], diff = depth[a] - depth[b];
	}
	if (a != b) {
		for (int i = 18; i >= 0; i--) {
			if (dp[a][i] && dp[a][i] != dp[b][i]) {
				minn = min(minn, mindp[a][i]), minn = min(minn, mindp[b][i]);
				maxx = max(maxx, maxdp[a][i]), maxx = max(maxx, maxdp[b][i]);
				a = dp[a][i], b = dp[b][i];
			}

		}
		minn = min(minn, mindp[a][0]), minn = min(minn, mindp[b][0]);
		maxx = max(maxx, maxdp[a][0]), maxx = max(maxx, maxdp[b][0]);
		a = dp[a][0];
	}
	ans.push_back({ minn, maxx });
}

int main() {
	scanf("%d", &N);
	adj.resize(N + 1);
	for (int i = 1; i <= N; i++) depth[i] = 1;
	for (int i = 1; i < N; i++) {
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	maketree(1, 0);
	for (int j = 1; j < 19; j++) {
		for (int i = 1; i <= N; i++) {
			if (!dp[i][j - 1]) continue;
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
			mindp[i][j] = min(mindp[dp[i][j - 1]][j - 1], mindp[i][j - 1]);
			maxdp[i][j] = max(maxdp[dp[i][j - 1]][j - 1], maxdp[i][j - 1]);
		}
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d%d", &a, &b);
		solve(a, b);
	}

	for (int i = 0; i < K; i++) printf("%d %d\n", ans[i].first, ans[i].second);






}
