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
int dem, cnt;
int n, m, low[base], num[base];
stack <int> st;
vector <int> adj[base];
vector <vector<int>> comp;
int com = 0;
void dfs(int u){
    num[u] = low[u] = ++cnt;
    st.push(u);
    for(auto v : adj[u])
    {
        if(num[v])
            low[u] = min(low[u], num[v]);
        else{
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u]){
        dem++;
        int v;
        do
        {
            v = st.top();
            st.pop();
            // cout << v << " ";
            // comp.push
            low[v] = num[v] = oo;
        } while (v != u);
        cout << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(name".inp", "r")){
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    cin >> n >> m;
    fod(i,1,m){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    fod(i,1,n){
        if(!num[i]){
            dfs(i);
            // cout << endl;
        }
    }
    cout << dem << '\n';
    return 0;
}
