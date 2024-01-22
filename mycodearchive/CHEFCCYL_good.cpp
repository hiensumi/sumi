#include <bits/stdc++.h>

using namespace std;



typedef long long ll;

typedef double ld;

typedef pair<ll,ll> pii;



#define mp make_pair

#define pb push_back

#define fi first

#define se second

#define debug1(x) cerr<<#x<<" : "<<(x)<<endl

#define debug2(x,y) cerr<<#x<<" : "<<(x)<<" "<<#y<<" : "<<(y)<<endl

#define debug3(x,y,z) cerr<<#x<<" : "<<(x)<<" "<<#y<<" : "<<(y)<<" "<<#z<<" : "<<(z)<<endl

#define fastt ios_base::sync_with_stdio(false); cin.tie(NULL) ; cout.tie(NULL)



const ll modd=1e9+7;

const ll inff=1e18;



ll poww(ll a,ll b){

  ll res=1;

  while(b){

    if(b&1LL) res=(res*a);

    a=(a*a);

    b=b>>1LL;

  }

  return res;

}



/*-----------------------------------------------------------------------------------------------*/



const ll N = 1e5+5;



class cycle{

  public:



  vector <ll> u;



  cycle(){ u.pb(0); }



  void init(){ for(ll i = 1; i < (ll)u.size(); i++) u[i] += u[i-1]; }



  ll finddist(ll x, ll y){

    if (x > y) swap(x, y); ll d = u[y] - u[x];

    return min(d, u[u.size() - 1] - d);

  }



} cycles[N], maincycle, initcycle;



ll n, q, adj[N][2];



void clr(){

  for(ll i = 0; i < n; i++) cycles[i] = initcycle, adj[i][0] = adj[i][1] = 0;

  maincycle = initcycle;

  n = q = 0;

}

#define name "CHEFCCYL"

int main(){

    fastt;
	if(fopen(name".inp", "r")){
		freopen(name".inp", "r", stdin);
		freopen(name".ans", "w", stdout);
    }


    ll tc;

    cin >> tc;



    while(tc--){

      clr();

      cin >> n >> q;



      for(ll i = 0; i < n; i++){

        ll nodes;

        cin >> nodes;

        while(nodes--){

          ll weight;

          cin >> weight;

          cycles[i].u.pb(weight);

        }

        cycles[i].init();

      }



      maincycle.u.pb(-1); // just a placeholder no actual importance



      for(ll i = 0; i < n; i++){

        ll v1, v2, w;

        cin >> v1 >> v2 >> w;

        v1--; v2--;

        adj[i][1] = v1;

        adj[(i+1)%n][0] = v2;

        if(i){

          maincycle.u.pb(cycles[i].finddist(adj[i][0],adj[i][1]));

        }

        maincycle.u.pb(w);

      }

      

      maincycle.u[1] = cycles[0].finddist(adj[0][0],adj[0][1]);

      maincycle.init();



      while(q--){

        ll v1, c1, v2, c2;

        cin >> v1 >> c1 >> v2 >> c2;

        v1--; v2--; c1--; c2--;

        ll ans = inff;

        for(ll i = 0; i < 2; i++)

          for(ll j = 0; j < 2; j++)

            ans = min(ans, maincycle.finddist(c1 << 1LL | i ,c2 << 1LL | j) + cycles[c1].finddist(v1,adj[c1][i]) + cycles[c2].finddist(v2,adj[c2][j]));

        cout << ans << '\n';

      }



    }



    return 0;

}
//fghjrtyui$%^&*