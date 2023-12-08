///giangcbg - TST 2022.
#include <bits/stdc++.h>
#define reset(x, val) memset((x), (val), sizeof (x))
#define bit(X, i) (((X) >> (i)) & 1)
#define all(X) (X).begin(), (X).end()
#define pb push_back
#define ep emplace_back
#define fi first
#define se second
using namespace std;

const char ginp[]="DIVISOR.INP";
const char gout[]="DIVISOR.OUT";

void debug_out() { cerr << '\n'; }
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T)
{
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void read() {}
template <typename Head, typename ...Tail>
void read(Head &H, Tail &...T)
{
    register char c;
    bool sign = 0;
    for (c = getchar(); !isdigit(c); c = getchar())
        if (c == '-') sign = !sign;
    H = c - '0';
    for (c = getchar();  isdigit(c); c = getchar())
        H = H * 10 + c - '0';
    if (sign) H = -H;
    read(T...);
}

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef vector <ll> vi;
typedef vector <ii> vii;

mt19937 rd(chrono :: steady_clock :: now().time_since_epoch().count());
#define rand rd
ll Rand(ll l, ll h) { return l + rand() % (h - l + 1); }

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

const int N = 1e3 + 5;
const ll oo = 1e18 + 1;

int d[30];
vi p;
ll dp[10][N], pw[10][61];
int _max[10];

void sieve(int n)
{
    for (int i = 2; i <= n; i++)
    if (!d[i])
    {
        p.pb(i);
        int j = i * i;
        while (j <= n)
        {
            d[j] = 1;
            j += i;
        }
    }
}

int n;
void enter()
{
    cin>>n;
}

ll calc(int i, int j)
{
    //debug(i,j);
    if (j == 1) return 1;
    if (i < 0) return oo;
    ll &res = dp[i][j];
    if (res) return res;
    res = calc(i-1,j); //ko chon p[i].
    for (int k = 2; k <= min(j, _max[i]); k++)
    if (j % k == 0)
    {
        ll t = calc(i-1,j/k), x = pw[i][k-1];
        if (oo/t < x) continue;
        res = min(res, t * x);
    }
    return res;
}

void solve()
{
    sieve(25);
    for (int i = 0; i < p.size(); i++)
    {
        _max[i] = 0;
        pw[i][0] = 1;
        while (oo/pw[i][_max[i]] >= p[i])
        {
            _max[i]++;
            pw[i][_max[i]] = pw[i][_max[i]-1] * p[i];
        }
    }
    cout<<calc(p.size()-1, n);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    //freopen(ginp, "r", stdin);
    //freopen(gout, "w", stdout);

    #endif //ONLINE_JUDGE

    enter();
    solve();

    cerr << "\nTime : " << clock() << "ms\n";
    return 0;
}
