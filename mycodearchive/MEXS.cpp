#define TASK "test"
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define el '\n'
#define all(v) begin(v), end(v)
#define str string
#define ve vector
#define BIT(mark, x) ((mark>>x)&1)


const double pi = acos(-1);
struct point {ll x, y;};
struct Data
{

	//bool operator <(const Data& a) const
	//{
	//	return ;
	//}
};

const ll base = 331;
const ll N = 1e6 + 10;
const ll NN = 1e6 + 10;
const ll LO = 20 + 2;
const ll MOD = 998244353;
const ll oo = 1e18;

int n, a[N];
ll f[N], S[N], MEX;

void read()
{
	cin >> n;
	set<ll> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s.insert(a[i]);
	}
	for (int i = 0; i <= n; i++)
	{
		if (s.find(i) == s.end())
		{
			MEX = i;
			break;
		}
	}
}

void solve()
{
	set<int>s;
	map<int, int> pre;
	S[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] < MEX)
		{
			if (s.find(pre[a[i]]) != s.end()) s.erase(pre[a[i]]);
			s.insert(i);
			pre[a[i]] = i;
		}
		if (s.size() == MEX)
		{
			int j = *s.begin() - 1;
			f[i] = S[j];
		}
		S[i] = (S[i - 1] + f[i]) % MOD;
	}
	cout << f[n];
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen(TASK".inp", "r"))
	{
		freopen(TASK".inp", "r", stdin);
		freopen(TASK".out", "w", stdout);
	}
	//cout<<fixed<<setprecision(2);

	int test;
	test = 1;
	//cin>>test;

	while (test--)
	{
		read();
		solve();
	}
	cerr << "\nTime: " << clock() << "ms\n";
	return 0;
}