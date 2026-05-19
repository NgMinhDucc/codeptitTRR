#include <bits/stdc++.h>
using namespace std;

int t, n, u;
vector<vector<int>> a;
vector<bool> visited;
vector<int> degree;

void dfs(int u){
    visited[u] = true;
    for (int i = 1; i <= n; i++){
        if (a[u][i] == 1 && !visited[i]){
            dfs(i);
        }
    }
}

bool lienthong(){
    int s = -1;
    for (int i = 1; i <= n; i++){
        if (degree[i] > 0){
            s = i;
            break;
        }
    }
    if (s == -1){
        return true; // khong co canh nao --> euler
    }

    dfs(s);
    for (int i = 1; i <= n; i++){
        if (degree[i] > 0 && !visited[i]){
            return false; // khong lien thong
        }
    }
    return true;
}

void euler(int u){
    vector<int> ec;
    stack<int> st;
    st.push(u);
    while (!st.empty()){
        int x = st.top();
        bool flag = false;
        for (int i = 1; i <= n; i++){
            if (a[x][i]){
                st.push(i);
                a[x][i] = a[i][x] = 0;
                flag = true;
                break;
            }
        }
        if (!flag){
            st.pop();
            ec.push_back(x);
        }
    }
    for (int i = ec.size() - 1; i >= 0; i--){
        cout << ec[i] << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> t >> n;
    if (t == 2){
        cin >> u;
    }
    a.assign(n + 1, vector<int>(n + 1));
    visited.assign(n + 1, false);
    degree.assign(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j] == 1){
                degree[i] += 1;
            }
        }
    }
    if (t == 1){
        if (!lienthong()){
            cout << 0; // khong lien thong --> khong euler cung khong nua euler
        }
        else{
            int cnt = 0;
            for (int i = 1; i <= n; i++){
                if (degree[i] % 2 == 1){
                    cnt += 1;
                }
            }
            if (cnt == 0) cout << 1;
            else if (cnt == 2) cout << 2;
            else cout << 0;
        }
    }
    if (t == 2){
        euler(u);
    }
    return 0;
}