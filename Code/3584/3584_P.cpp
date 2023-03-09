#include <iostream>
#include <vector>
using namespace std;
#define MAX 10001

int parent[MAX];
int depth[MAX];
vector<vector<int>> childs;

int findLSA(int u, int v){
	if (depth[u] < depth[v]) swap(u, v);

	while (depth[u] != depth[v]) {
		u = parent[u]; 
	}
	while (u != v){
		u = parent[u];
		v = parent[v];
	}
	return u;
}

void setParents(int cur, int par){
	for (int child : childs[cur]){
		depth[child] = depth[cur] + 1;
		setParents(child, cur);
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++){
		int N, par, child;
		scanf("%d", &N);
		childs.clear();
		childs.resize(N + 1);
		for (int i = 0; i <= N; i++) parent[i] = 0;
		for (int i = 0; i <= N; i++) depth[i] = 0;

		for (int i = 0; i < N-1; i++) {
			scanf("%d%d", &par, &child);
			parent[child] = par;	
			childs[par].push_back(child);
		}
		int start;
		for (int i = 1; i <= N; i++) if (!parent[i]) start = i;
		setParents(start, 0);
		
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", findLSA(u ,v));
	
	}
}
