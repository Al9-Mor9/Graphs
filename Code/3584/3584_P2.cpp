#include <stdio.h>
#include <queue>
using namespace std;

int T, N, parent[10001],a, b, qa, qb, ans;
queue<int> ancx;
queue<int> ancy;

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < 10001; i++) {
			parent[i] = 0;
		}
		while (!ancx.empty()) ancx.pop();
		while (!ancy.empty()) ancy.pop();

		for (int i = 1; i < N; i++) {
			scanf("%d%d", &a, &b);
			parent[b] = a;
		}

		scanf("%d%d", &qa, &qb);

		while (qa) {
			ancx.push(qa);
			qa = parent[qa];
		}
		while (qb) {
			ancy.push(qb);
			qb = parent[qb];
		}

		while (1) {
			if (ancx.front() == ancy.front()) {
				ans = ancx.front(); break;
			}

			if (ancx.size() > ancy.size()) {
				ancx.pop();
			}
			else if (ancx.size() < ancy.size()) {
				ancy.pop();
			}
			else {
				ancx.pop();
				ancy.pop();

			}
		}

		printf("%d\n", ans);
	}
}
