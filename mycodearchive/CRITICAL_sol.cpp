///This code was edited by "dacphu(one punch man)"
///Do not copy in any form

#include <iostream>
#include <iomanip>
#include <bitset>
#include <array>
#include <cmath>
#include <cctype>
#include <complex>
#include <cstring>
#include <fstream>
#include <sstream>
#include <ostream>
#include <istream>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdbool>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <valarray>
#include <vector>
#include <iterator>
#include <algorithm>

#define Thesingledimensionalvectorofint vector <int>
#define Themultidismensionalvectorofint vector < vector <int> >
#define Thesingledimensionalvectorofbool vector <bool>
#define FOR(i , a , b) for(int i = a ; i <= b ; ++i)
#define FORD(i , a , b) for(int i = a ; i >= b ; --i)
#define FORX(i , a , b) for(int i = a ; i < b ; ++i)
#define FORDX(i , a , b) for(int i = a ; i > b ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define REPD(i , n) for(int i = n - 1 ; i >= 0 ;--i)
#define ii pair<int ,int>
#define TASK "CRITICAL"
#define maxx_int (int)0x3f3f3f3f
#define maxx_int64_t (int64_t) 0x3f3f3f3f3f3f3f3f
#define sp " "
#define en "\n"

using namespace std;

class Theupdatevector : public Thesingledimensionalvectorofint{
public:
    void popfront(){
        erase(begin());
    }

    void popback(){
        erase(end());
    }

    void pushback(int x){
        push_back(x);
    }

    void pushfront(int x){
        (*this).push_back(0);
        FORDX(index , (*this).size() , 0){
            (*this).at(index) = (*this).at(index - 1);
        }
    }

    int front(){
        return at(0);
    }

    int back(){
        return at((*this).size() - 1);
    }
};

vector <Theupdatevector> Graph;
Theupdatevector Num;
Theupdatevector Low;
Thesingledimensionalvectorofbool CriticalNode;
Theupdatevector ThesecondCountGraph;
Theupdatevector Previous;
Theupdatevector Turbo;
Theupdatevector PartGraph;
Theupdatevector CountGraph;
int Count = 0;
int CriticalEdge = 0;
int n , m;
int countturbo = 0;
int Numberofpartgraph = 0;

inline int read(){
    char c;
    int tmp = 1;
    for(c = getchar() ; c < '0' || c > '9' ; c = getchar())
        if(c == '-')
            tmp = -1;
    int res = c - '0';
    for(c = getchar() ; c <= '9' && c >= '0' ; c = getchar())
        res = res * 10 + c - '0';
    return res * tmp;
}

void input(){
    freopen ( ".inp" , "r" , stdin);
    freopen ( ".out" , "w" , stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n = read();
    Graph.resize(n + 1);
    Low.resize(n + 1);
    Num.resize(n + 1 , 0);
    ThesecondCountGraph.resize(n + 1);
    CriticalNode.resize(n + 1 , false);
    Previous.resize(n + 1);
    Turbo.resize(n + 1);
    CountGraph.resize(n + 1);
    PartGraph.resize(n + 1);
    m = read();
    REP(i , m){
        int a , b;
        a = read();
        b = read();
        Graph[a].pushback(b);
        Graph[b].pushback(a);
    }
}

void DFS(int u){
    Num[u] = Low[u] = ++Count;
    CountGraph[Numberofpartgraph]++;
    PartGraph[u] = Numberofpartgraph;
    Turbo[++countturbo] = u;
    for(auto v : Graph[u]){
        if(Previous[u] != v){
            if(!Num[v]){
                Previous[v] = u;
                DFS(v);
                Low[u] = min(Low[u] , Low[v]);
            }
            else{
                Low[u] = min(Low[u] , Num[v]);
            }
        }
    }
}

void proccess(){
    FOR(i , 1 , n){
        if(!Num[i]){
            Numberofpartgraph++;
            DFS(i);
        }
    }
    FOR(u , 1 , n){
        int minx = -maxx_int , pre = 0;
        for(auto v : Graph[u]){
            if(Previous[v] == u){
                pre++;
                minx = max(minx , Low[v]);
            }
        }
        if(!Previous[u] && pre >= 2){
            CriticalNode[u] = true;
        }
        if(minx >= Num[u] && Previous[u]){
            CriticalNode[u] = true;
        }
        if(CriticalNode[u]){
            // cout << u << " ";
        }
    }
    FORD(i , n , 1){
        int u = Turbo[i];
        ThesecondCountGraph[u] = 1;
        for(int v : Graph[u]){
            if(Previous[v] == u){
                ThesecondCountGraph[u] += ThesecondCountGraph[v];
            }
        }
    }
    double res = 0;
    FOR(u , 1 , n){
        int k  = 0;
        if(CriticalNode[u]){
            int count = 0;
            for(auto v : Graph[u]){
                if(Previous[v] == u && Low[v] >= Num[u]) {
                    res += ThesecondCountGraph[v] * (CountGraph[PartGraph[u]] - ThesecondCountGraph[v] - 1);
                    count += ThesecondCountGraph[v];
                }
            }
            res += count * (CountGraph[PartGraph[u]] - count - 1);
        }
        cout << res << " ";
    }
    // res = res / (2 * n);
    // cout << fixed << setprecision(2) << res;
}

int main(){
    input();
    proccess();
    return 0;
}
