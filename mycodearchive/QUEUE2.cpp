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
	int vala, valb, id;
}a[base];
int n, ans[base];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n;
	fod(i,1,n) cin >> a[i].vala, a[i].id = i;
	fod(i,1,n) cin >> a[i].valb;
	deque <bg> dq;
	fod(i,1,n) dq.pb(a[i]);
	int t = 1;
	while(!dq.empty()){
		// t++;
		bg top = dq.front();
		dq.pop_front();
		if(top.valb <= t){
			ans[top.id] = t + top.vala;
			t = t + top.vala + 1;
			continue;
		}
		else{
			dq.pb(top);
		}
		t++;
	}
	
	fod(i,1,n){
		cout << ans[i] << " ";
	}
	return 0;
}
