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

#define H 2*H5

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define lnf 0
#define LNF 1e18

using namespace std;
mt19937 mr(time(0));
typedef long long int ll;
struct LL {

    static const ll m = mod; // set to LNF for nomod
    long long int val;

    LL(ll v) {val=reduce(v);};
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
typedef pair<ll,ll> pll;
typedef pair<LL,LL> pLL;
typedef pair<pll,ll> tri;

int T,N,M,K,Q;

ll rd() {ll x; scanf("%lld",&x); return x;}
void fl() {cout.flush();}

ll D[4*H];
vector<pll> adj[4*H];
priority_queue<pll,vector<pll>,greater<pll>> PQ;
void dijk(int v) {
    for (int i = 0; i < 4*H; i++) {
        D[i]=LNF;
    }
    D[v]=0;
    PQ.p(mp(0,v));
    while (PQ.size()) {
        ll d = PQ.t().f; ll u = PQ.t().s; PQ.pop();
        if (d!=D[u]) continue;
        for (pii e : adj[u]) {
            if (D[e.f]>D[u]+e.s) {
                PQ.p(mp(D[e.f]=D[u]+e.s,e.f));
            }
        }
    }
}

int main() {

    bool trials = 0;

    if (trials) T=rd();
    else T=1;

    while (T--) {

        N=rd(); M=rd();

        for (int thisnamedoesntmatter = 0; thisnamedoesntmatter < M; thisnamedoesntmatter++) {
            ll u=rd(); ll v=rd(); ll w=rd();

            // normal transition
            for (int i = 0; i < 4; i++) {
                adj[u+i*H].pb(mp(v+i*H,w));
                adj[v+i*H].pb(mp(u+i*H,w));
            }

            // do both
                adj[u].pb(mp(v+3*H,w));
                adj[v].pb(mp(u+3*H,w));


            w*=2;

            // add a thing from u to v
                adj[u].pb(mp(v+H,w));
                adj[u+2*H].pb(mp(v+3*H,w));

            // add a thing from v to u
                adj[v].pb(mp(u+H,w));
                adj[v+2*H].pb(mp(u+3*H,w));


            // sub a thing from u to v
                adj[u].pb(mp(v+2*H,0));
                adj[u+H].pb(mp(v+3*H,0));

            // sub a thing from v to u
                adj[v].pb(mp(u+2*H,0));
                adj[v+H].pb(mp(u+3*H,0));
        }

        dijk(1);

        for (int i = 2+3*H; i <= N+3*H; i++) {
            cout << D[i] << " ";
        }

        cout << endl;

    }
}
*/
