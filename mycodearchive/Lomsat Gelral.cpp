#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 15;
int n, c[N], sub[N], st[N], ft[N], dfa[N], cnt[N], num[N];
vector<int> adj[N];
long long sum[N];

void dfs(int v, int p) {
	static int time = 0;
	dfa[st[v] = time++] = v;
	for (int u: adj[v])
		if (u != p) {
			dfs(u, v);
			sub[v] += sub[u];
		}
	sub[v]++;
	ft[v] = time;
}

void update(int v, int u) {
	cnt[c[u]]++;
	if (cnt[c[u]] == num[v])
		sum[v] += c[u];
	else if (cnt[c[u]] > num[v])
		sum[v] = c[u], num[v] = cnt[c[u]];
}

void sack(int v, int p, bool k) {
	int mx = -1, vl;
	for (int u: adj[v])
		if (u != p && sub[u] > mx)
			mx = sub[u], vl = u;

	for (int u: adj[v])
		if (u != p && u != vl)
			sack(u, v, false);

	if (mx > 0) {
		sack(vl, v, true);
		sum[v] = sum[vl], num[v] = num[vl];
		for (int i = st[v]; i < st[vl]; i++)
			update(v, dfa[i]);
		for (int i = ft[vl]; i < ft[v]; i++)
			update(v, dfa[i]);
	}
	else 
		update(v, v);

	if (!k)
		for (int i = st[v]; i < ft[v]; i++)
			cnt[c[dfa[i]]]--;
}

void read_input() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
}

void solve() {
	dfs(1, 0);
	sack(1, 0, false);

	for (int i = 1; i <= n; i++)
		cout << sum[i] << ' ';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read_input(), solve();
	return cout << '\n', 0;
}
