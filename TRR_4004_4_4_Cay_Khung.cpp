#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
};

int n, s;
vector<vector<pair<int, int>>> a;
vector<bool> visited;
vector<int> parent, dis;

void prim(){
    vector<edge> mst;
    int d = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        int kc = top.first;
        int v = top.second;
        if (visited[v]){
            continue;
        }
        d += kc;
        visited[v] = true;
        if (s != v){
            mst.push_back({v, parent[v], kc});
        }
        for (auto it : a[v]){
            int y = it.first, w = it.second;
            if (!visited[y] && w < dis[y]){
                pq.push({w, y});
                dis[y] = w;
                parent[y] = v;
            }
        }
    }
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

    cin >> n >> s;
    a.resize(n + 1);
    visited.assign(n + 1, false);
    dis.assign(n + 1, 1e9);
    parent.assign(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if (x != 0 && x != 10000){
                a[i].push_back({j, x});
                a[j].push_back({i, x});
            }
        }
    }

    prim();
    return 0;
}