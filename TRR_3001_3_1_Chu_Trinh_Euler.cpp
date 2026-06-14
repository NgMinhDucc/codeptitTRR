#include <bits/stdc++.h>
using namespace std;

int t, n, u;
vector<vector<int>> a;
vector<int> deg;
vector<bool> visited;

void dfs(int u){
	visited[u] = true;
	for (int i = 1; i <= n; i++){
		if (!visited[i] && a[u][i]){
			dfs(i);
		}
	}
}

bool lien_thong(){
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (!visited[i] && deg[i] > 0){
			cnt += 1;
			dfs(i);
		}
	}
	if (cnt > 1){
		return false;
	}
	return true;
}

void euler(int u){
	stack<int> st;
	st.push(u);
	vector<int> ec;
	while (!st.empty()){
		int s = st.top();
		bool flag = false;
		for (int i = 1; i <= n; i++){
			if (a[s][i]){
				st.push(i);
				flag = true;
				a[s][i] = a[i][s] = 0;
				break;
			}
		}
		if (!flag){
			st.pop();
			ec.push_back(s);
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
	deg.assign(n + 1, 0);
	visited.assign(n + 1, false);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
			if (a[i][j]){
				deg[i] += 1;
			}
		}
	}
	if (t == 1){
		if (!lien_thong()){
			cout << 0; // khong lien thong
		}
		else{
			int cnt = 0;
			for (int i = 1; i <= n; i++){
				if (deg[i] % 2 == 1){
					cnt += 1;
				}
			}
			if (cnt == 0) cout << 1; // euler
			else if (cnt == 2) cout << 2; // nua euler
			else cout << 0;
		}
	}
	else{
		euler(u);
	}
	return 0;
}