// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
#include "bits/stdc++.h"
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define mask(i) (1LL<<(i))
#define BITpos(a,i) ((a >> i) & 1LL)
#define pb push_back
#define el '\n'
#define all(v) v.begin(), v.end()
#define odd(i) (i & 1LL)
using namespace std;
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { int tmp = x; mul(tmp, Inv(y, mod), mod); return tmp;}
template<class T> bool mini(T& a,T b){return (a>=b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<=b)?a=b,1:0;}
struct point{int x, y;};
struct edge{int u, v, c;};
/*int find(int u) { if (par[u] == u) return u; return par[u] = find(par[u]);}
bool join(int u, int v) {int paru = find(u), parv = find(v); if (paru == parv) return false; par[parv] = paru; return true; }*/ 
const ll INF = 1e18, base = 1e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
	
}
int n;
string s, p[base];
const int MAX_CHAR = 4;
// gọi dp[i] là xâu con dài nhất được xét như là chuỗi tiếng cười
struct Node{
    int exist, cnt;
    Node* child[MAX_CHAR];
    Node(){
        cnt = exist = 0;
        fod(i,0,MAX_CHAR-1){
            child[i] = nullptr;
        }
    }
};
void insert(Node* root, const string& s) {
    Node* cur = root;
    for (char c : s){
        int idx = c - 'a';
        if(idx > 3) idx = 3;
        if (cur->child[idx] == nullptr) {
            cur->child[idx] = new Node();
        }
        cur = cur->child[idx];
        cur->cnt++;
    }
    cur->exist = 1;
}
int dp[base];
int find(Node* root, int id){
    int res = 0;
    Node* cur = root;
    fod(i,id,s.size()-1){
        int idx = s[i] - 'a';
        if(idx > 3) idx = 3;
        if(cur->child[idx] == nullptr) return res;
        cur = cur->child[idx];
        if(cur->exist == 1){
            maxi(res, i - id + 1 + dp[i+1]);
        }
    }
    return res;
}
void inp(){
    cin >> n >> s;
}
namespace sub_task1{
	void solve(){
        Node* root = new Node();
		fod(i,1,n){
            string x; cin >> x;
            insert(root, x);
        }
        int res = 0;
        fok(i,s.size()-1,0) dp[i] = find(root, i), res = max(res, dp[i]);
        cout << res;
        // fod(i,0,s.size() - 1){
        //     cout << dp[i] << el;
        // }
    
    }	
	
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	  freopen(name".inp", "r", stdin);
	  freopen(name".out", "w", stdout);
	}
	int Test = 1; if(multitest) cin >> Test;
	init();
	while(Test--){
		inp();
		sub_task1 :: solve();
	}
	kill();
}