#include <iostream>
using namespace std;

int N, M, parent[1000001], order,a, b;

int find(int x) {
	if (parent[x] == x) return x;
	else return parent[x]  = find(parent[x]);
}

void uunion(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) parent[b] = a;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
  
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &order, &a, &b);
		if (order == 0) uunion(a, b);
		else if (order == 1) {
			if (find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
	}
}
