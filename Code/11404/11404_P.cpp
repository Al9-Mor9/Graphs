#include <stdio.h>
#include <vector>
using namespace std;
#define INF 10000000

int n, m, a, b, c, bus[101][101], st[101][101]{ 0, };

int min(int a, int b) { return a < b ? a : b; }
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n + 1; i++)for (int j = 0; j < n + 1; j++) {
		bus[i][j] = INF; bus[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (bus[a][b] > c) bus[a][b] = c;
	}

	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				bus[i][j] = min(bus[i][j], bus[i][k] + bus[k][j]);
			}
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int l = 1; l < n + 1; l++) {
			if (bus[i][l] != INF) printf("%d ", bus[i][l]); else printf("0 ");
		}
		printf("\n");
	}
}
