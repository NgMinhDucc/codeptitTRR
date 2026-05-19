#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
vector<vector<int>> a;
vector<int> low, num;
vector<pair<int, int>> cc;

void tarjan(int u, int parent){
    cnt += 1;
    low[u] = num[u] = cnt;
    for (int i = 1; i <= n; i++){
        if (a[u][i]){
            if (i == parent){
                continue;
            }
            if (num[i] == 0){
                tarjan(i, u);
                low[u] = min(low[u], low[i]);
                if (low[i] > num[u]){
                    cc.push_back({min(u, i), max(u, i)});
                }
            }
            else{
                low[u] = min(low[u], num[i]);
            }
        }
    }
}

void canhcau(){
    for (int i = 1; i <= n; i++){
        if (num[i] == 0){
            tarjan(i, 0);
        }
    }

    sort(cc.begin(), cc.end());
    cout << cc.size() << "\n";
    for (auto it : cc){
        cout << it.first << " " << it.second << "\n";
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

    canhcau();
    return 0;
}