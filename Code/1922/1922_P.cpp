#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001

int N, M, a, b, c;
int parent[MAX];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
int totalCost, connCount;

int find(int a){
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

bool uni(pair<int, int> edge){
	int a = find(edge.first);
	int b = find(edge.second);
	if (a == b) return false;
	parent[b] = a;
	return true;
}

void kruskal(){
	while (connCount < N - 1){
		pair<int, pair<int, int>> minEdge = pq.top();
		pq.pop();
		if (uni(minEdge.second)) {
			totalCost += minEdge.first;
			connCount++;
		}
	}
}

int main(){
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 0; i < M; i++){
		scanf("%d%d%d", &a, &b, &c);
		if (a == b) continue;
		pq.push({c, {a, b}});
	}

	kruskal();
	printf("%d", totalCost);
}
