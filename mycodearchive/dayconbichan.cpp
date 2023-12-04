#include<bits/stdc++.h>
using namespace std;
#define TASK ""
#define int long long
#define fi first
#define se second
#define ll long long
#define pb push_back
#define el '\n'

const double pi = acos(-1);
ll sq(ll a) {return (ll)a * a;}
struct point {ll x, y;};

struct bg { int val; int id;};

const ll sz = 1e6 + 10;
const ll szz = 1e6 + 10;
const ll MOD = 1e9 + 7;
const ll oo = 1e18;

ll n, L, R, a[sz], s[sz];
bg Mi[sz];
ll res = -oo;
bg merge(bg a, bg b){
	if(a.val > b.val){
		return b;
	}else{
		return a;
	}
}
void Build(int k, int l, int r)
{
	if (l > r) return ;
	if (l == r)
	{
		Mi[k] = {s[l],l};
		return;
	}
	int mid = (l + r) / 2;
	Build(2 * k, l, mid);
	Build(2 * k + 1, mid + 1, r);
	Mi[k] = merge(Mi[2 * k], Mi[2 * k + 1]);
}
bg get_min(int k, int l, int r, int u, int v)
{
	if (u > r || v < l) { return {oo,-1};}
	if (u <= l && r <= v) return Mi[k];
	int mid = (l + r) / 2;
	return merge( get_min(2 * k, l, mid, u, v), get_min(2 * k + 1, mid + 1, r, u, v));
}
int q;
void doc()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	Build(1, 0, n);
	while(q--){
		cin >> L >> R;
		res = -1e18;
		pair <int,int> ans;
		for (int i = L; i <= n; i++){
			bg xx = get_min(1, 0, n, max(i - R, (ll) 0), i - L );
			int val = xx.val;										
			if(res < s[i] - val){
				res = s[i] - val;
				ans = {i,xx.id};
			}
		}
		cout << res << el << ans.second + 1 << " " << ans.first << el;
	}
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen(TASK".INP", "r")) {
		freopen(TASK".INP", "r", stdin);
		freopen(TASK".OUT", "w", stdout);
	}
	//cout<<fixed<<setprecision(2)<<el;

	int test;
	test = 1;
	//cin>>test;

	while (test--)
	{
		doc();
	}
// 	cout << "\nTime: " << clock() / (double)1000 << " sec\n";
	return 0;
}