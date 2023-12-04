#include<bits/stdc++.h>
#define SSS ""

using namespace std;
int n, a[100001], q;
struct Top{
	int value[10];
	Top(){
		memset(value, 0, sizeof value);
	}
};
Top st[400001];
Top mere(Top A, Top B){
	Top tmp;
	int i(0), j(0);
	for(int t(0); t < 2; ++t){
		tmp.value[t] = A.value[i] > B.value[j] ? A.value[i++] : B.value[j++];
	}
	return tmp;
}
void build(int id, int l, int r){
	if(l == r){
		st[id].value[0] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(2*id, l, mid); build(2*id+1, mid+1, r);
	st[id] = mere(st[2*id], st[2*id+1]);
}
Top get(int id, int l, int r, int u, int v){
	if(v < l || r < u) return Top();
	if(u <= l && r <= v) return st[id];
	int mid = l + r >> 1;
	return mere(get(2*id, l, mid, u, v), get(2*id+1, mid+1, r, u, v));
}
void input(){
	cin >> n >> q;
	for(int i(1); i <= n; ++i) cin >> a[i];
	build(1, 1, n);
}
void solve(){
	int l, r;
	while(q--){
		cin >> l >> r;
		Top tmp = get(1, 1, n, l, r);
		cout << tmp.value[0] + tmp.value[1] << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	if(fopen(SSS".inp", "r")) freopen(SSS".inp","r",stdin), freopen(SSS".out","w",stdout);
	input();
	solve();
	return 0;
}


