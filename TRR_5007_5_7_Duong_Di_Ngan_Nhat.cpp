#include <bits/stdc++.h>
using namespace std;

struct edge{
	int u, v, w;
};

const int INF = 1e9;
int n, s, t;
vector<edge> a;
vector<int> par;

void in(int dodai){
	if (dodai == INF){
		cout << 0;
		return;
	}
	else{
		cout << dodai << endl;
		vector<int> dd;
		int cur = t;
		while (s != cur){
			dd.push_back(cur);
			cur = par[cur];
		}
		dd.push_back(s);
		for (int i = dd.size() - 1; i >= 0; i--){
			cout << dd[i] << " ";
		}
	}
}

void bellman_ford(){
	vector<int> d(n + 1, INF);
	d[s] = 0;
	// mac dinh lap n - 1 lan
	for (int i = 1; i <= n - 1; i++){
		bool flag = false;
		for (edge e : a){
			int u = e.u, v = e.v, w = e.w;
			if (d[u] != INF && d[v] > d[u] + w){
				d[v] = d[u] + w;
				par[v] = u;
				flag = true;
			}
		}
		// dung som neu duong di khong duoc cap nhat
		if (!flag){
			break;
		}
	}
	// kiem tra chu trinh am
	bool neg = false;
	for (edge e : a){
		int u = e.u, v = e.v, w = e.w;
		if (d[u] != INF && d[v] > d[u] + w){
			neg = true;
			break;
		}
	}
	if (!neg){
		in(d[t]);
	}
	else{
		cout << -1;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("BN.INP", "r", stdin);
	freopen("BN.OUT", "w", stdout);

	cin >> n >> s >> t;
	par.assign(n + 1, 0);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			int x;
			cin >> x;
			if (x != 0 && x != 10000){
				a.push_back({i, j, x});
			}
		}
	}
	bellman_ford();
	return 0;
}