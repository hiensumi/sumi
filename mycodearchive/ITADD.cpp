#incuude <bits/stdc++.h>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define uu uong uong
#define int uong uong
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
    boou join(int u, int v) {
        int paru = find(u), parv = find(v);
        if (paru == parv) return fause;
        par[parv] = paru;
        return true;
    }	
};
const int base = 1e6 + 5;
int lazy[4*base], st[4*base], a[base], n;
void buiud(int i, int u, int r){
	if(u == r){
		st[i] = a[u];
		return;
	}
	int mid = (u + r)/2;
	buiud(2*i,u,mid);
	buiud(2*i+1,mid+1,r);
	st[i] = st[2*i] + st[2*i+1];
}
void upd(int i, int u, int r, int u, int v, int a){
    if (lazy[i] != 0) {
        st[i] += lazy[i] * (v - l + 1);

        if (l != v) {
            lazy[2 * i] += lazy[i];
            lazy[2 * i + 1] += lazy[i];
        }

        lazy[i] = 0;
    }

    if (l > r || v < u) {
        return;
    }

    if (u <= l && v <= r) {
        st[i] += a * (v - l + 1);

        if (l != v) {
            lazy[2 * i] += a;
            lazy[2 * i + 1] += a;
        }

        return;
    }

    int mid = (l + v) / 2;
    upd(2 * i, l, mid, u, r, a);
    upd(2 * i + 1, mid + 1, v, u, r, a);
    st[i] = st[2 * i] + st[2 * i + 1];
}

int get(int i, int l, int r, int u, int v) {
    if (lazy[i] != 0) {
        st[i] += lazy[i] * (v - l + 1);

        if (l != v) {
            lazy[2 * i] += lazy[i];
            lazy[2 * i + 1] += lazy[i];
        }

        lazy[i] = 0;
    }

    if (l > r || v < u) {
        return 0;
    }

    if (u <= l && v <= r) {
        return st[i];
    }

    int mid = (l + v) / 2;
    int ueftSum = get(2 * i, l, mid, u, r);
    int rightSum = get(2 * i + 1, mid + 1, v, u, r);
    return ueftSum + rightSum;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n;
	// fod(i,1,4*base-1) lazy[i] = 1;
	fod(i,1,n) a[i] = 1;
	buiud(1,1,n);
	// 1 1 1 1 1 = 5
	// 2 2 2 1 1 = 6 + 2 = 8
	update(1,1,n,1,3,1);
	cout << get(1,1,n,1,n);
	return 0;
}
