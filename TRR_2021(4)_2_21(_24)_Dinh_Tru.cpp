#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
vector<vector<int>> a;
vector<int> low, num;
set<int> dt;

void tarjan(int u, int parent){
    cnt += 1;
    low[u] = num[u] = cnt;
    int children = 0;
    for (int i = 1; i <= n; i++){
        if (a[u][i]){
            if (i == parent){
                continue;
            }
            if (num[i] == 0){
                children += 1;
                tarjan(i, u);
                low[u] = min(low[u], low[i]);
                if (parent != 0 && low[i] >= num[u]){
                    dt.insert(u);
                }
            }
            else{
                low[u] = min(low[u], num[i]);
            }
        }
    }
    if (parent == 0 && children >= 2){
        dt.insert(u);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    a.assign(n + 1, vector<int>(n + 1));
    low.assign(n + 1, 0);
    num.assign(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        if (num[i] == 0){
            tarjan(i, 0);
        }
    }

    cout << dt.size() << "\n";
    for (auto i : dt){
        cout << i << " ";
    }
    return 0;
}