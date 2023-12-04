/* fan cung Bui Hong Duc 20 nam */
#include <bits/stdc++.h>
using namespace std;
#define uwu "elecar"
typedef long long ll;
#define pb push_back
#define endl '\n'
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i>=b;i--)
bool multitest = false;
const int N=2e5+3;
const int INF=1e9+7;
const int modd=1e9+7;

int n, q;
struct bg{
	int x, y, id;
} a[N];
int pos[N];
bool cmp(bg u, bg v){
	return u.y < v.y;
}

int floyd[102][102];

int rmq[N][20];
int lg[N];

void input(){
	cin >> n >> q;
	FOR(i, 1, n){
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}
}
void prep(void){
	input();
}
void subtask_1(void){
	FOR(i, 1, n) FOR(j, 1, n) floyd[i][j] = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
	FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) floyd[i][j] = min(floyd[i][j], max(floyd[i][k], floyd[k][j]));
	while(q--){
		int s, t; cin >> s >> t;
		cout << floyd[s][t] << endl;
	}
}
int get(int l, int r){
	int k = lg[r - l + 1];
	return max(rmq[l][k], rmq[r - (1 << k)][k]);
}
void subtask_3(){
	sort(a + 1, a + n + 1, cmp);
	FOR(i, 1, n) pos[a[i].id] = i;

	FOR(i, 1, n - 1) rmq[i][0] = a[i + 1].y - a[i].y; 
	FOR(j, 1, 20) FOR(i, 1, n - (1 << j))
		rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);

	lg[1] = 0;
	FOR(i, 2, n) lg[i] = lg[i / 2] + 1;

	while(q--){
		int s, t; cin >> s >> t;
		s = pos[s]; t = pos[t];
		if (s > t) swap(s, t);

		cout << get(s, t - 1) << endl;
	}
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
		prep(); 
		
		cout << '\n';
	}
	return 0;
}