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

#define H 7*H4
#define HH 43

#define woof 31051
#define mod 998244353
#define MOD 1000000007
#define lnf 0
#define inf 1069999999
#define INF 2099999999
#define LNF 1e18

// sacrilege
#define F0(x,n) for(int x = 0; x < n; ++x)
#define FR0(x,L,R) for(int x = L; x < R; ++x)
#define R0(x,n) for(int x = n-1; x >= 0; --x)
#define F1(x,n) for(int x = 1; x <= n; ++x)
#define FR1(x,L,R) for(int x = L; x <= R; ++x)
#define R1(x,n) for(int x = n; x >= 1; --x)


using namespace std;
mt19937 mr(time(0));
typedef long long int ll;
struct LL {

    static const ll m = MOD; // set to LNF for nomod
    long long int val;

    LL(ll v) {val=reduce(v);};
    LL(int v) {val=reduce((ll)v);};
    LL() {val=0;};
    ~LL(){};
    LL(const LL& l) {val=l.val;};
    LL& operator=(int l) {val=l; return *this;}
    LL& operator=(ll l) {val=l; return *this;}
    LL& operator=(LL l) {val=l.val; return *this;}

    static long long int reduce(ll x, ll md = m) {
        x %= md;
        while (x >= md) x-=md;
        while (x < 0) x+=md;
        return x;
    }

    bool operator<(const LL& b) { return val<b.val; }
    bool operator<=(const LL& b) { return val<=b.val; }
    bool operator!=(const LL& b) { return val!=b.val; }
    bool operator==(const LL& b) { return val==b.val; }
    bool operator>=(const LL& b) { return val>=b.val; }
    bool operator>(const LL& b) { return val>b.val; }

    LL operator+(const LL& b) { return LL(val+b.val); }
    LL operator+(const ll& b) { return (*this+LL(b)); }
    LL& operator+=(const LL& b) { return (*this=*this+b); }
    LL& operator+=(const ll& b) { return (*this=*this+b); }

    LL operator-(const LL& b) { return LL(val-b.val); }
    LL operator-(const ll& b) { return (*this-LL(b)); }
    LL& operator-=(const LL& b) { return (*this=*this-b); }
    LL& operator-=(const ll& b) { return (*this=*this-b); }

    LL operator*(const LL& b) { return LL(val*b.val); }
    LL operator*(const ll& b) { return (*this*LL(b)); }
    LL& operator*=(const LL& b) { return (*this=*this*b); }
    LL& operator*=(const ll& b) { return (*this=*this*b); }

    static LL exp(const LL& x, const ll& y){
        ll z = y;
        z = reduce(z,m-1);
        LL ret = 1;
        LL w = x;
        while (z) {
            if (z&1) ret *= w;
            z >>= 1; w *= w;
        }
        return ret;
    }
    LL& operator^=(ll y) { return (*this=LL(val^y)); }

    LL operator/(const LL& b) { return ((*this)*exp(b,-1)); }
    LL operator/(const ll& b) { return (*this/LL(b)); }
    LL operator/=(const LL& b) { return ((*this)*=exp(b,-1)); }
    LL& operator/=(const ll& b) { return (*this=*this/LL(b)); }

}; ostream& operator<<(ostream& os, const LL& obj) { return os << obj.val; }
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<int,LL> piL;
typedef pair<ll,ll> pll;
typedef pair<LL,LL> pLL;
typedef pair<pll,ll> tri;
typedef pair<LL,pLL> TRI;
using namespace std;

ll cases,N,M,Q,K;

ll rd() {ll x;cin>>x; return x;}
void fl() {cout.flush();}

void panic(ll out) {
    cout << out << endl;
    exit(0);
}

vector<int> adj[H];
bool V[H];
int I[H];
int P[H];
int cnt[H];
int build(int a, int b) {
    int ret = -1;
    for (int u : adj[a]) ++cnt[u];
    for (int v : adj[b]) if (cnt[v]) if (V[v]) ret=v;
    for (int u : adj[a]) --cnt[u];
    return ret;
}
vector<int> B[20];
vector<int> coloring[20];
int S[H];
void read() {
    N=rd(); int P2 = 1<<N;
    F0(i,P2) {adj[i].clear(); V[i]=1;
        I[i]=0;
        P[i]=0;
    }
    F0(i,(N*P2)>>1) {
        int a=rd(); int b=rd();
        adj[a].pb(b);
        adj[b].pb(a);
    }
    I[0]=0;
    P[0]=0;
    int c = 1; for (int u : adj[0]) {
        I[c]=u;
        P[u]=c;
        c<<=1;
    }
    for (int dim=2; dim<=N; dim++) {
        for (int k : B[dim-2]) {
            if (k>=P2) break;
            V[I[k]]=0;
            vector<int> x;
            for (int c=1;c<P2;c<<=1) if ((c&k)==0) x.pb(c);
            for (int i : x) { // lol
                for (int j : x) {
                    if (i<j) {
                        I[k^i^j]=build(I[k^i],I[k^j]);
                        P[I[k^i^j]]=k^i^j;
                    }
                }
            }
        }
    }
    for (int i = 0; i < P2; i++) cout << I[i] << " " ; cout << endl;
    if (coloring[N].size()) F0(i,P2) cout << coloring[N][P[i]] << " ";
        else cout << -1;
    cout << endl;
}

int main() {
    coloring[1].pb(0);
    coloring[1].pb(0);
    int c,j; F1(i,4) {
        coloring[1<<i]=coloring[(1<<i)>>1];
        for (c=1<<i>>1,j = 1<<(1<<i>>1);
                            j < 1<<(1<<i); c++, j<<=1) {
        F0(k,j) coloring[1<<i].pb(coloring[1<<i][k]^c);
    }}

    for (int i = 0; i < (1<<16); i++) {
        int c,j; for (c=0, j=1; j<(1<<16); j<<=1) if (j&i)c++;
        B[c].pb(i);
        S[i]=c;
    }
    bool trials = 1;
    bool interactive = 0;

    if (!interactive) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    if (trials) cases=rd();
    else cases=1;
    while (cases--) {
        read();
    }

}
*/
