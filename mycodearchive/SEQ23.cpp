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
	int val, x,y;
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
const int base = 1e6 + 5;
int n, q, k, a[base], c[base], l[base], r[base];
point b[base];
bool cmp(point a, point b){
	return a.val < b.val;
}
int st[4*base];
void build(int i, int l, int r){
	if(l == r){
		st[i] = b[l].y - b[l].x + 1;
		return;
	}
	int mid = (l + r)/2;
	build(2*i,l,mid);
	build(2*i+1,mid+1,r);
	st[i] = max(st[2*i],st[2*i+1]);
}
int get(int i, int l, int r, int u, int v){
	// u l r v
	if(r < u or v < l) return -1e18;
	if(u <= l and r <= v) return st[i];
	int mid = l + r >> 1;
	return max(get(2*i,l,mid,u,v), get(2*i+1,mid+1,r,u,v));
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n >> q;
	fod(i,1,n) cin >> a[i];
	stack <int> s;
	fod(i,1,n){
		while(!s.empty() and a[s.top()] <= a[i]) s.pop();
		if(s.empty()) l[i] = 1;
		else l[i] = s.top() + 1;
		s.push(i);
	}
	while(!s.empty()) s.pop();
	fok(i,n,1){
		while(!s.empty() and a[s.top()] <= a[i]) s.pop();
		if(s.empty()) r[i] = n;
		else r[i] = s.top() - 1;
		s.push(i);
	}
	fod(i,1,n) b[i].val = a[i], b[i].x = l[i], b[i].y = r[i];
	sort(b+1,b+n+1,cmp);
	fod(i,1,n) c[i] = b[i].val;
	build(1,1,n);
	c[n+1] = -1e18;
	while(q--){
		cin >> k;
		int id = lower_bound(c+1,c+n+1,k) - c;
		if(c[id] > k) id--;
		if(k >= c[1]){
			int res = -1e18;
			// fod(i,1,id) res = max(res, b[i].y - b[i].x + 1);
			cout << get(1,1,n,1,id);
		}
		else cout << 0;
		cout << endl;
	}
	return 0;
}
