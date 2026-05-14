#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;
vector<bool> visited;
vector<int> dinh;

void bfs(int u){
    queue<int> qu;
    qu.push(u);
    visited[u] = true;
    while (!qu.empty()){
        int s = qu.front();
        qu.pop();
        for (int i = 1; i <= n; i++){
            if (!visited[i] && a[s][i]){
                visited[i] = true;
                qu.push(i);
            }
        }
    }
}

void dinhtru(){
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cnt += 1;
            bfs(i);
        }
    }

    for (int i = 1; i <= n; i++){
        int dem = 0;
        visited.assign(n + 1, false);
        visited[i] = true;
        for (int j = 1; j <= n; j++){
            if (!visited[j]){
                dem += 1;
                bfs(j);
            }
        }
        if (dem > cnt){
            dinh.push_back(i);
        }
    }
    cout << dinh.size() << "\n";
    for (int i : dinh){
        cout << i << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    a.assign(n + 1, vector<int>(n + 1));
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    dinhtru();
    return 0;
}