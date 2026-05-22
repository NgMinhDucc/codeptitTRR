#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
};

int n, m;
vector<edge> a;
vector<int> parent;
vector<int> sz;

void make(){
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v){
    if (v == parent[v]){
        return v;
    }
    return parent[v] = find(parent[v]); // tiep tuc tim len tren
}

bool unionn(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b){
        return false; // chung cha --> cung tplt --> tao thanh chu trinh
    }
    if (sz[a] < sz[b]){
        parent[a] = b;
        sz[b] += sz[a];
    }
    else{
        parent[b] = a;
        sz[a] += sz[b];
    }
    return true;
}

bool cmp(edge a, edge b){
    return a.w < b.w;
}

void kruskal(){
    vector<edge> mst;
    int d = 0;
    stable_sort(begin(a), end(a), cmp);
    for (int i = 0; i < m; i++){
        if ((int)mst.size() == n - 1){
            break;
        }
        edge e = a[i];
        if (unionn(e.u, e.v)){
            mst.push_back(e);
            d += e.w;
        }
    }

    // in
    if ((int)mst.size() != n - 1){
        cout << 0;
    }
    else{
        cout << d << "\n";
        for (edge e : mst){
            cout << min(e.u, e.v) << " " << max(e.u, e.v) << " " << e.w << "\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    cin >> n >> m;
    parent.assign(n + 1, 0);
    sz.assign(n + 1, 0);
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a.push_back({u, v, w});
    }

    make();
    kruskal();
    return 0;
}