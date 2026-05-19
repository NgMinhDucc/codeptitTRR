#include <bits/stdc++.h>
using namespace std;

int t, n, u;
vector<vector<int>> a;
vector<bool> visited;
vector<int> ra, vao;

void dfs(int u){
    visited[u] = true;
    for (int i = 1; i <= n; i++){
        if ((a[u][i] == 1 || a[i][u] == 1) && !visited[i]){
            dfs(i);
        }
    }
}

bool lienthong(){
    int s = -1;
    for (int i = 1; i <= n; i++){
        if (ra[i] > 0 || vao[i] > 0){
            s = i;
            break;
        }
    }
    if (s == -1) return true;

    dfs(s);
    for (int i = 1; i <= n; i++){
        if ((ra[i] > 0 || vao[i] > 0) && !visited[i]) return false;
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
            if (a[x][i] == 1){
                st.push(i);
                a[x][i] = 0;
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
    ra.assign(n + 1, 0);
    vao.assign(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j] == 1){
                ra[i] += 1;
                vao[j] += 1;
            }
        }
    }
    if (t == 1){
        if (!lienthong()){
            cout << 0;
        }
        else{
            int rahon = 0, vaohon = 0, khonghople = 0;
            for (int i = 1; i <= n; i++){
                if (ra[i] == vao[i]) continue;
                else if (ra[i] - vao[i] == 1) rahon += 1;
                else if (vao[i] - ra[i] == 1) vaohon += 1;
                else khonghople += 1;
            }

            if (rahon == 0 && vaohon == 0 && khonghople == 0) cout << 1; // euler
            else if (rahon == 1 && vaohon == 1 && khonghople == 0) cout << 2; // nua euler
            else cout << 0; // khong euler cung khong nua euler
        }
    }
    if (t == 2){
        euler(u);
    }
    return 0;
}