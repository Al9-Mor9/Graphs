#include <stdio.h>
using namespace std;

int N, M, a, b, w;
char cmd;
int parent[100001];
int weight[100001];

int find(int a){
    if (parent[a] == a) return a;
    int findA = find(parent[a]);
    weight[a] += weight[parent[a]];
    return parent[a] = findA; 
}

void uni(int a, int b, int w){
    int findA = find(a);
    int findB = find(b);
    if (findA == findB) return;
    parent[findA] = findB;
    weight[findA] = weight[b] - weight[a] + w;
}

int main(){
    while (true) {
        scanf("%d%d", &N, &M);
        if (!N && !M) return 0;
    
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            weight[i] = 0;
        }

        for (int i = 0; i < M; i++){ 
            scanf("\n%c ", &cmd);
            if (cmd == '!'){//무게 재기
                scanf("%d%d%d", &a, &b, &w);
                uni(a, b, w); 
            }
            else if (cmd == '?') {//물어보기
                scanf("%d%d", &a, &b);
                if (find(a) != find(b)) printf("UNKNOWN\n");
                else printf("%d\n", weight[a] - weight[b]); 
            }
        }
    }
}
