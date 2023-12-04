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
const int base = 1e6 + 5;
struct bg{
	int val, id;
};
int t[4*base], n, k, f[base];
bg a[base];
void update(ll k, ll l, ll r,ll u,ll value){ //nut k quan li doan l...r tai vt u co gia tri bang value
	if(u<l || r<u)	return;
	if (l == r) {
		t[k] = value; 
		return;
	}
	int m = (l+r)>>1;	//(l+r)/2
	update(k<<1, l, m,u,value);	//k*2
	update(k*2+1, m+1, r,u,value);
	t[k] = t[k<<1]+ t[k*2+1];	//k*2
}
ll get(ll k, ll l, ll r, ll L, ll R) {
	if (r < L || R < l) return 0;
	if (L <= l && r <= R) return t[k];
	int m = (l+r)/2;
	return get(k*2, l, m, L, R)+get(k*2+1, m+1, r, L, R);
}
bool cmp(bg a,bg b){
	if(a.val==b.val) return a.id<b.id;
	return a.val<b.val;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n >> k;
	fod(i,1,n) cin >> a[i].val, a[i].id = i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		// res+=get(1,1,n,a[i].id+1,n);
		f[i] = f[i-1] + get(1,1,n,a[i].id+1,n);
		update(1,1,n,a[i].id,1);
	}
	int res = 0;
	fod(i,1,n-1) fod(j,i+1,n){
		int v = f[n] - f[j-1] + f[i];
		if(v <= k) res++;
	}
	cout << res;
	return 0;
}
