/* fan cung Bui Hong Duc 20 nam */
#include <bits/stdc++.h>
using namespace std;
#define uwu "uwu"
typedef long long ll;
#define pb push_back
#define endl '\n'
#define int long long
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i>=b;i--)
bool multitest = false;
const int N=4e3+3;
const int H = N - 3;
const ll INF=1e17+7;
const int modd=1e9+7;

int n, d, h[N], c[N];
ll f[N][N];
ll be[N], lon[N];

void input(){
	cin >> n >> d;
	FOR(i, 1, n - 1) cin >> c[i];
	FOR(i, 1, n) cin >> h[i];
}
void prep(void){
	input();
}
void solve(void){
	memset(f, 0x3f, sizeof(f));

	FOR(x, h[1], H) f[1][x] = (x - h[1]) * (x - h[1]);

	FOR(i, 2, n){
		FOR(x, 1, H) be[x] = f[i - 1][x] - x * c[i - 1];
	 	FORD(x, H, 1) lon[x] = f[i - 1][x] + x * c[i - 1];

	 	deque <ll> dqbe;
	 	FOR(j, h[i], H){
	 		while(!dqbe.empty() && be[dqbe.back()] > be[j]) dqbe.pop_back();
	 		dqbe.push_back(j);
	 		while(!dqbe.empty() && dqbe.front() < j - d) dqbe.pop_front();

	 		ll cost = 1ll * (j - h[i]) * (j - h[i]);
	 		f[i][j] = min(f[i][j], be[dqbe.front()] + (j * c[i - 1]) + cost);
	 	}

	 	deque <ll> dqlon;
	 	FORD(j, H, h[i]){
	 		while(!dqlon.empty() && lon[dqlon.back()] > lon[j]) dqlon.pop_back();
	 		dqlon.push_back(j);
	 		while(!dqlon.empty() && dqlon.front() > j + d) dqlon.pop_front();

	 		ll cost = 1ll * (j - h[i]) * (j - h[i]);
	 		f[i][j] = min(f[i][j], lon[dqlon.front()] - (j * c[i - 1]) + cost);
	 	}
	}

	ll ans = INF;
	FOR(x, 0, H) ans = min(ans, f[n][x]);
	cout << ans;
}
signed main(){
 	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (fopen(uwu".inp", "r")){
	   freopen(uwu".inp","r",stdin);
	   freopen(uwu".out","w",stdout);
	}
	int test = 1;
	if (multitest) cin >> test;
	while(test--){
		prep(); solve();
		cout << '\n';
	}
	return 0;
}