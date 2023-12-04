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
const int base = 1e6 + 5;
int n, m, a[base], st[4*base];
int combine(int a, int b, int f){
	if(f) return a ^ b;
	return a | b;
}
void build(int i, int l, int r, int op){
	if(l == r){
		st[i] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(2*i,l,mid, op ^ 1);
	build(2*i+1,mid+1,r, op ^ 1);
	st[i] = combine(st[2*i],st[2*i+1], op);
}
void update(int i, int l, int r, int u, int v, int val ,int op){
	// u l r v
	if(r < u or v < l) return;
	if(u <= l and r <= v){
		st[i] = a[i] = val;
		return;
	}
	int mid = l + r >> 1;
	// if(u <= mid and u >= l) update(2*i,l,mid,u,v,val,op ^ 1);
	// else if(u > mid and u <= r) update(2*i+1,mid+1,r,u,v,val,op ^ 1);
	update(2*i,l,mid,u,v,val,op ^ 1);
	update(2*i+1,mid+1,r,u,v,val,op ^ 1);
	st[i] = combine(st[2*i], st[2*i+1], op);
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n >> m;
	int nn = 1 << n;
	fod(i,1,nn) cin >> a[i];
	int first_op = (n % 2 == 0);
	build(1,1,nn,first_op);
	fod(i,1,m){
		int p,b; cin >> p >> b;
		update(1,1,nn,p,p,b,first_op);
		cout << st[1] << endl;
	}
	return 0;
}
