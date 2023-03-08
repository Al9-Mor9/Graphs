#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
#define INF 2147483647
#define MAX 50001
#define MAX_DEPTH 17

int V, E, u, v, w;
vector<tuple<int, int, int>> adj;
vector<vector<pair<int, int>>> mst;
int parent[MAX], depth[MAX];
int mstParent[MAX][MAX_DEPTH];
int maxWeight[MAX][MAX_DEPTH];
int secondMaxWeight[MAX][MAX_DEPTH];
int mstWeight, mstEdgeCnt;

int kruskal();
int find(int a);
bool uni(int a, int b);
int addEdge(int i);
void makeTree(int cur, int par);
int findLSA(int u, int v);
int getWeightOnPath(int u, int v, int w);

int main(){
    scanf("%d%d", &V, &E);
    for (int i = 0; i < E; i++){
        scanf("%d%d%d", &u, &v, &w);
        adj.push_back({w, u, v}); 
    }

    for (int i = 1; i <= V; i++) parent[i] = i;
     //MST를 만들어 봄
    
    mst.resize(V + 1);
    mstWeight = kruskal();
    if (mstEdgeCnt != V - 1) {
        printf("-1");
        return 0;
    }

    //트리로 만들고 모든 간선들을 보면서 추가해 보자(200,000)
    makeTree(1, 0);
    for (int j = 1; j < MAX_DEPTH; j++) {
        for (int i = 0; i <= V; i++){
            if (mstParent[i][j-1]) {
                mstParent[i][j] = mstParent[mstParent[i][j-1]][j-1];
                maxWeight[i][j] = max(maxWeight[i][j-1], maxWeight[mstParent[i][j-1]][j-1]);
            }
        }
    }

    int secondMstWeight = INF;
    for (int i = 0; i < E; i++) {
        int addedWeight = addEdge(i);
        if (addedWeight < secondMstWeight && addedWeight > mstWeight) secondMstWeight = addedWeight; 
    }
    
    //바뀐 게 없으면 second mst가 존재하지 않는다는 것.
    if (secondMstWeight == INF) printf("-1");
    else printf("%d", secondMstWeight);
}

int kruskal(){
    int weight = 0;//mst의 가중치
    sort(adj.begin(), adj.end());//가중치 크기대로 일단 정렬
    for (auto edge : adj){
        int w = get<0>(edge), u = get<1>(edge), v = get<2>(edge);
        if (uni(u, v)) {
            weight += get<0>(edge);
            mst[u].push_back({v, w});
            mst[v].push_back({u, w});
            mstEdgeCnt++;
        }
    }
    return weight;
}

int find(int a){
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

bool uni(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (a > b) swap(a, b);
    parent[b] = a;
    return true;
}

int addEdge(int i){
    auto edge = adj.at(i);
    int w = get<0>(edge), u = get<1>(edge), v = get<2>(edge);
    //u -> v로 가는 경로에서의 최대 가중치를 찾고 그걸 빼고 내 가중치를 넣으면 됨.
    int LSA= findLSA(u, v);
    int weightOnPath = getWeightOnPath(u, v, w);
    return mstWeight - weightOnPath + w;
}

void makeTree(int cur, int par){
    for (pair<int, int> child : mst[cur]){
        if (child.first != par){
            depth[child.first] = depth[cur] + 1;
            mstParent[child.first][0] = cur;
            maxWeight[child.first][0] = child.second;
            secondMaxWeight[child.first][0] = child.second;
            makeTree(child.first, cur);
        }
    }
}

int findLSA(int a, int b){
    int u = a, v = b;
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    int ret = 0;

    while (diff){
        int d = 0;
        for (int i = 1; i <= diff; i *= 2) d++;
        u = mstParent[u][d-1];
        diff = depth[u] - depth[v];
    }

    if (u != v){
        for (int j = MAX_DEPTH - 1; j>= 0; j--){
            if (mstParent[u][j] && mstParent[u][j] != mstParent[v][j]) {
                u = mstParent[u][j];
                v = mstParent[v][j];
            }
        }

        u = mstParent[u][0];
    }
    //printf("maxWeight_%d-%d: %d, maxWeight_%d-%d: %d\n", a, anc, maxWeight_u, b, anc, maxWeight_v);
    return u;
}

int getWeightOnPath(int u, int anc, int w){
    int diff = depth[u] - depth[anc];
    int weight = 0;
    int idx = 0;

    while (diff){
        if(diff & (1 << idx)) {
            weight = max(weight, maxWeight[u][idx]);
            u = mstParent[u][idx];                
        }
        diff &= ~(1 << idx++);
    }
    return weight;
}
