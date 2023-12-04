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
int mi = -1e18, res = -1e18;
const int base = 1e6 + 5;
int n, a[base], l, r;
void update(int x, int i){
	if(r <= x) x= r;
	if(l >= x) x = r;
	if(a[i-1] <= x and x <= a[i]){
		// mi = min(mi, min(x - a[i-1], a[i] - x));
		// res = max(res, mi);
		int v = min(x - a[i-1], a[i] - x);
		if(mi <= v){
			mi = v;
			res = x;
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n >> l >> r;
	fod(i,1,n) cin >> a[i];
	sort(a+1,a+n+1);
	if(l < a[1]) res = l, mi = abs(l - a[1]);
	// if(mi != 1e18) res = max(res, mi);
	if(r > a[n] and mi <= r - a[n]) res = r, mi = r - a[n];
	if(mi != 1e18) res = max(res, mi);
	fod(i,2,n){
		int x = (a[i] + a[i-1]) >> 1;
		update(x-1,i);
		update(x,i);
		update(x+1,i);
	}
	cout << res;
	return 0;
}
