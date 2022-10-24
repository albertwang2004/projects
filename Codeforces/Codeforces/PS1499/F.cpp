/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front

#define T1 10
#define T2 100
#define T3 1000
#define T4 10000
#define T5 100000
#define T6 1000000

#define H1 11
#define H2 105
#define H3 1010
#define H4 10010
#define H5 100010
#define H6 1000010

#define H 5*H3

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define lnf 0
#define LNF 5000000000000000000

using namespace std;


// arithmetic

struct LL {

    static const long long int m = mod; // set to LNF for nomod
    long long int val;

    LL(long long int v) {val=reduce(v);};
    LL() {val=0;};
    ~LL(){};
    LL(const LL& l) {val=l.val;};
    LL& operator=(int l) {val=l; return *this;}
    LL& operator=(long long int l) {val=l; return *this;}
    LL& operator=(LL l) {val=l.val; return *this;}

    static long long int reduce(long long int x, long long int md = m) {
        x %= md;
        while (x >= md) x-=md;
        while (x < 0) x+=md;
        return x;
    }

    LL operator+(const LL& b) { return LL(val+b.val); }
    LL operator+(const long long int& b) { return (*this+LL(b)); }
    LL& operator+=(const LL& b) { return (*this=*this+b); }
    LL& operator+=(const long long int& b) { return (*this=*this+b); }

    LL operator-(const LL& b) { return LL(val-b.val); }
    LL operator-(const long long int& b) { return (*this-LL(b)); }
    LL& operator-=(const LL& b) { return (*this=*this-b); }
    LL& operator-=(const long long int& b) { return (*this=*this-b); }

    LL operator*(const LL& b) { return LL(val*b.val); }
    LL operator*(const long long int& b) { return (*this*LL(b)); }
    LL& operator*=(const LL& b) { return (*this=*this*b); }
    LL& operator*=(const long long int& b) { return (*this=*this*b); }

    static LL exp(const LL& x, const long long int& y){
        long long int z = y;
        z = reduce(z,m-1);
        LL ret = 1;
        LL w = x;
        while (z) {
            if (z&1) ret *= w;
            z >>= 1; w *= w;
        }
        return ret;
    }
    LL& operator^=(long long int y) { return (*this=LL(val^y)); }

    LL operator/(const LL& b) { return ((*this)*exp(b,-1)); }
    LL operator/(const long long int& b) { return (*this/LL(b)); }
    LL operator/=(const LL& b) { return ((*this)*=exp(b,-1)); }
    LL& operator/=(const long long int& b) { return (*this=*this/LL(b)); }

}; ostream& operator<<(ostream& os, LL& obj) { return os << obj.val; }

typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

int T,N,M,K,Q;
vector<int> adj[H];
int par[H];
LL DP[H][H]; // DP[n][l].
LL DP2[H];

int dfs(int v) {
    int d = 0;
    DP[v][0] = 1;
    for (int u : adj[v]) {
        if (par[v]==u) continue;
        par[u]=v;
        int dd = dfs(u);
        for (int i = 0; i <= max(d,dd)+5; i++) DP2[i] = 0;
        for (int i = 0; i <= d; i++)
        for (int j = 0; j <= dd; j++) {
            int nd = max(i,j+1);
            DP2[i] += (DP[v][i]*DP[u][j])*((i<=K) && (j<=K));
            DP2[nd] += (DP[v][i]*DP[u][j])*(i+j < K);
            //cout << v << " " << i << " " << j << " " << DP2[nd] << endl;
        }
        for (int i = 0; i <= max(d,dd)+5; i++) DP[v][i]=DP2[i];
        d = max(d,dd+1);
    }
    return d;
}

int main() {

    bool trials = 0;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {
        par[1]=0;
        scanf("%d%d",&N,&K);
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < H; j++) {
                DP[i][j]=0;
            }
        }
        for (int i = 1; i < N; i++) {
            int x,y; scanf("%d%d",&x,&y);
            adj[x].pb(y); adj[y].pb(x);
        }
        dfs(1);
        LL ret = 0;
        for (int i = 0; i <= K; i++) {
            ret += DP[1][i];
        }
        //for (int i = 1; i <= N; i++) {
        //    cout << "node " << i << ": ";
        //    for (int d = 0; d <= K; d++) {
        //        cout << DP[i][d] << " ";
        //    }
        //    cout << endl;
        //}
        cout << ret << endl;
    }

}
*/
