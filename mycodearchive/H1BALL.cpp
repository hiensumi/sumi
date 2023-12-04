#include <bits/stdc++.h>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define name ""
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
typedef pair<int, int> ii;
struct point{
	int x, y;
};
struct edge{
	int u, v;
    vector<int> par;
    void init(int n) {
        par.resize(n + 5, 0);
        fod(i,1,n) par[i] = i;
    }
    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }
    bool join(int u, int v) {
        int paru = find(u), parv = find(v);
        if (paru == parv) return false;
        par[parv] = paru;
        return true;
    }	
};
const int base = 2e6 + 5;
int n, m, a[base], b[base], f[base];
bool check(int gr){
	int cnt = 0, i = 1, j = m - gr + 1;
	fod(k,1,n) if(b[i] < a[k] and a[k] < b[j]){
		cnt++;
		i++;
		j++;
		if(cnt == gr) return 1;
	}
	return 0;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n >> m;
	fod(i,1,n) cin >> a[i];
	fod(i,1,m) cin >> b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	// 1 3 3 4
	// 1 2 4 7
	// # sub 1: 16/ 20
	// int res = 0, lu = 0, lv = 0;
	// fod(i,1,n){
	// 	int v = lower_bound(b+1,b+m+1,a[i]) - b;
	// 	if(v == m + 1) continue;
	// 	int u = v - 1;
	// 	if(b[v] == a[i]) v++;
	// 	if(u < 1 or v > m) continue;
	// 	while(f[u] == 1 and u >= 1) u--;
	// 	while(f[v] == 1 and v <= m) v++;
	// 	if(u < 1 or v > m) continue;
	// 	f[u] = 1; f[v] = 1; res++; 
	// }
	// cout << res;
	// # sub 2
	int d = 1, c = min(n,m/2), ans = 0;
	while(d <= c){
		int mid = d + c >> 1;
		if(check(mid)) d = mid + 1, ans = mid;
		else c = mid - 1;
	}
	cout << ans;
	return 0;
}