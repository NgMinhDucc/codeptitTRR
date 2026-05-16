#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
vector<vector<int>> a;
vector<int> low, num;
vector<bool> dt;

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
                    dt[u] = true; // da xac dinh duoc 1 dinh tru
                }
            }
            else{
                low[u] = min(low[u], num[i]);
            }
        }
    }
    if (parent == 0 && children >= 2){
        dt[u] = true;
    }
}

void dinhtru(){
    for (int i = 1; i <= n; i++){
        if (num[i] == 0){
            tarjan(i, 0);
        }
    }

    int dem = 0;
    for (int i = 1; i <= n; i++){
        if (dt[i]){
            dem += 1;
        }
    }

    cout << dem << "\n";
    for (int i = 1; i <= n; i++){
        if (dt[i]){
            cout << i << " ";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    a.assign(n + 1, vector<int>(n + 1));
    low.assign(n + 1, false);
    num.assign(n + 1, false);
    dt.assign(n + 1, false);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    dinhtru();
    return 0;
}