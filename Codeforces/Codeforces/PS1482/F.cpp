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

#define H 6*H2

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define lnf 0
#define LNF 2000000000000000000

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

int rd() {int x; scanf("%d",&x); return x;}
void fl() {cout.flush();}

vector<pll> adj[H];
vector<tri> que[H];
vector<pll> edges;
ll adjj[H][H];
bool ans[H][H];

ll dist[H][H];
void fw() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i==j) dist[i][j] = 0;
            else dist[i][j] = LNF;
        }
        for (pll e : adj[i]) {
            adjj[i][e.f] = e.s;
            dist[i][e.f] = e.s;
        }
    }
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

vector<int> D;
void dijk(int c) {
    D.assign(N+5,LNF);
    vector<bool> U(N+5,0);
    for (tri i : que[c]) {
        D[i.f.f] = -i.f.s;
    }
    for (int i = 1; i <= N; i++) {
        int v = -1;
        for (int j = 1; j <= N; j++)
        if (!U[j] && (v == -1 || D[j] < D[v])) v = j;
        if (D[v] == LNF) break;
        U[v] = 1;
        for (auto e : adj[v]) {
            int u = e.f;
            int d = e.s;
            if (D[v] + d < D[u]) {
                D[u] = D[v] + d;
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

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                ans[i][j] = false;
            }
        }

        for (int i = 0; i < M; i++) {
            ll u=rd(); ll v=rd(); ll w=rd();
            adj[u].pb(mp(v,w));
            adj[v].pb(mp(u,w));
            edges.pb(mp(u,v));
        }

        fw();

        Q=rd();

        for (int i = 0; i < Q; i++) {
            ll u=rd(); ll v=rd(); ll w=rd();
            if (u>v) swap(u,v);
            que[u].pb(mp(mp(v,w),i));
        }

        for (int i = 1; i <= N; i++) {
            if (que[i].size()) {
                dijk(i);
                for (pll e : edges) {
                    if ((D[e.s] <= (-dist[i][e.f] - adjj[e.f][e.s])) || (D[e.f] <= (-dist[i][e.s] - adjj[e.f][e.s]))) {
                        ans[e.f][e.s] = 1;
                    }
                }
            }
        }


        ll ret = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                ret += ans[i][j];
            }
        }
        cout << ret << endl;
    }
}
*/
