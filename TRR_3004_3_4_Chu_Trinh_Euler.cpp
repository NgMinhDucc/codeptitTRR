#include <bits/stdc++.h>
using namespace std;

int t, n, u;
vector<vector<int>> a;
vector<bool> visited;
vector<int> vao, ra;

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
		if (!visited[i] && (vao[i] > 0 || ra[i] > 0)){
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
				a[s][i] = 0;
				flag = true;
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
	visited.assign(n + 1, false);
	vao.assign(n + 1, 0);
	ra.assign(n + 1, 0);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
			if (a[i][j]){
				vao[j] += 1;
				ra[i] += 1;
			}
		}
	}
	if (t == 1){
		if (!lien_thong()){
			cout << 0;	
		}
		else{
			int rahon = 0, vaohon = 0, invalid = 0;
			for (int i = 1; i <= n; i++){
				if (ra[i] == vao[i]) continue;
				else if (ra[i] - vao[i] == 1) rahon += 1;
				else if (vao[i] - ra[i] == 1) vaohon += 1;
				else invalid += 1;
			}
			if (rahon == 0 && vaohon == 0 && invalid == 0) cout << 1;
			else if (rahon == 1 && vaohon == 1 && invalid == 0) cout << 2;
			else cout << 0;
		}
	}
	if (t == 2){
		euler(u);
	}
	return 0;
}