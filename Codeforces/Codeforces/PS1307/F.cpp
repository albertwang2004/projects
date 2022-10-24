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

#define woof 31051
#define mod 998244353
#define MOD 1000000007
#define lnf 0
#define inf 1069999999
#define INF 2099999999
#define LNF 5e18

#define tc(T) template <class T>
#define tcc(S, T) template <class S, class T>
#define tccc(S, T, U) template <class S, class T, class U>

using namespace std;
mt19937 mr(time(0));
typedef long long int ll;
typedef string str;
typedef double dbl;
struct LL {

    static ll m; // set to LNF for nomod
    long long int val;

    LL(ll v) {val=reduce(v);};
    LL(int v) {val=reduce((ll)v);};
    LL() {val=0;};
    ~LL(){};
    LL(const LL& l) {val=l.val;};
    LL& operator=(int l) {val=l; return *this;}
    LL& operator=(ll l) {val=l; return *this;}
    LL& operator=(LL l) {val=l.val; return *this;}

    static void setMod(ll m) { assert(m); LL::m = m; }

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
ll LL::m = MOD;

typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<int,LL> piL;
typedef pair<ll,ll> pll;
typedef pair<LL,LL> pLL;
typedef pair<dbl,dbl> pdd;
using namespace std;

// sacrilege

#define bts(a,x,b) ((a<x)&&(x<b))
#define btw(a,x,b) ((a<=x)&&(x<=b))

#define F0(x,n) for(ll x = 0; x < n; ++x)
#define Fr(x,L,R) for(ll x = L; x < R; ++x)
#define R0(x,n) for(ll x = n-1; x >= 0; --x)
#define F1(x,n) for(ll x = 1; x <= n; ++x)
#define FR(x,L,R) for(ll x = L; x <= R; ++x)
#define R1(x,n) for(ll x = n; x >= 1; --x)
#define RR(x,L,R) for(ll x = R; x >= L; --x)
#define Rr(x,L,R) for(ll x = R-1; x >= L; --x)
#define FE(x,ls) for(auto x : ls)
#define FER(x,ls) for(auto &x : ls)

#define srt(x) sort(x.begin(),x.end())
#define srtc(x,c) sort(x.begin(),x.end(),c)
#define rev(x) reverse(x.begin(),x.end())

#define ub(x,v) upper_bound(x.begin(),x.end(),v)
#define lb(x,v) lower_bound(x.begin(),x.end(),v)
#define bs(x,v) binary_search(x.begin(),x.end(),v)
#define dst(x,y) (ll)distance(x,y)
#define nlt(x,v) (ll)dst(x.begin(),lb(x,v))
#define nle(x,v) (ll)dst(x.begin(),ub(x,v))

ll cases,N,M,Q,K,X,Y;

ll rd() {ll x;cin>>x; return x;}
dbl rdd() {dbl x;cin>>x; return x;}
str rds() {str x;cin>>x; return x;}
tc(T) void rds(char* S, T* sz) {*sz=strlen(strcpy(S,rds().c_str()));}
tc(T) void rG(int sz, vector<vector<T>>& adj, int E = -18852946) {
    if (E == -18852946) E = sz-1;
    adj.clear();
    F0(i,sz+1) adj.pb(vector<T>());
    F0(i,E) {
        T a = rd(); T b = rd();
        adj[a].pb(b); adj[b].pb(a);
    }
}

void fl() {cout.flush();}
tc(T) void ds(vector<T> v) {FE(x,v) cout << x << " "; cout << endl;}
tc(T) void panic(T out) { cout << out << endl; exit(0); }

tcc(S,T) bool updmin(S &a, T b) {
    S B = (S)b;
    if (B < a) {a = B; return 1;}
    return 0;
}

tcc(S,T) bool updmax(S &a, T b) {
    S B = (S)b;
    if (B > a) {a = B; return 1;}
    return 0;
}

tcc(S,T) S min(S a, T b) {
    S c = a; updmin(c, b); return c;
}

tcc(S,T) S max(S a, T b) {
    S c = a; updmax(c, b); return c;
}

#define H 2*H5
#define HH 43

// dsu

struct DSUt {
    vector<int> P;
    vector<int> S;
    vector<int> U;
    int NC;

    DSUt(int N) {start(N);}

    void start(int N) {
        NC=N;
        U.clear();
        for (int i = 0; i <= N; i++) {
            P.pb(i);
            S.pb(1);
        }
    }

    int SZ(int x) {return S[pp(x)];}

    int pp(int x) {
        if (P[x]==x) return x;
        return (P[x] = pp(P[x]));
    }

    bool un(int a, int b) {
        int A = pp(a);
        int B = pp(b);
        if (A == B) {
            return 0;
        }
        if (S[A] > S[B]) {swap(A,B);}
        S[B] += S[A];
        P[A] = B;
        NC--;
        return 1;
    }
};

vector<vector<ll>> adj;
struct LCA {
    // segment tree
    ll sz,rt,lg;
    vector<int> depth;
    vector<vector<int>> up;
    vector<pii> bruh;
    //vector<vector<ll>> adj;
    LCA(ll _sz, ll _rt = 1) :
        sz(_sz), rt(_rt) {lg=ceil(log2(_sz)); build(_rt);}
    vector<bool> V;
    void dfs(ll& t, ll v, ll x, ll p) {
        V[v]=1;
        depth[v]=x;
        bruh[v].f=t++;
        up[v].pb(p);
        F1(i,lg) up[v].pb(up[up[v][i-1]][i-1]);
        FE(u,adj[v]) if (!V[u]) {
            dfs(t,u,x+1,v);
        }
        bruh[v].s=t++;
    }
    void build(ll rt) {
        V.clear(); depth.clear(); bruh.clear(); up.clear();
        F0(i,sz+1) { V.pb(0); bruh.pb({-1,-1}); up.pb(vector<ll>()); depth.pb(0);}
        ll t = 0; dfs(t,rt,0,rt);
    }
    bool is_ancestor(int u, int v) { return bruh[u].f <= bruh[v].f && bruh[u].s >= bruh[v].s; }
    int query(int v, int u) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = lg; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    int walk(int v, int u, int d) {
        ll dv = depth[v];
        ll da = depth[query(v,u)];
        ll du = depth[u];
        ll lt = dv+du-(da<<1);
        if (lt<=d) return u;
        if (d<dv-da) {
            R0(x,lg+1) if (d&(1ll<<x)) {
                d^=1ll<<x; v=up[v][x];
            }
        } else {
            d=lt-d; v=u; R0(x,lg+1) if (d&(1ll<<x)) {
                d^=1ll<<x; v=up[v][x];
            }
        }
        return v;
    }
};



int color[2*H];

void precalc() {
}

void reset() {
    F0(i,2*H) color[i] = 0;
}


bool cmp(pii a, pii b) {
}

void read() {
    N=rd();X=rd();M=rd();
    reset();
    F0(i,2*N+10) adj.pb(vector<ll>());
    int c = N+1;
    F0(i,N-1) {
        int a = rd(); int b = rd();
        adj[a].pb(c);
        adj[c].pb(b);
        adj[b].pb(c);
        adj[c].pb(a);
        c++;
    }
    DSUt D(2*N);
    LCA T(2*N);
    queue<pair<int,pii>> bfs;
    F0(i,M) {
        int rs = rd();
        bfs.p({0,{rs,rs}});
    }
    while (bfs.size()) {
        pair<int,pii> curr = bfs.fr();
        if (curr.f>X) break;
        if (color[curr.s.f]) D.un(color[curr.s.f],curr.s.s);
        else {
            color[curr.s.f]=curr.s.s;
            FE(v,adj[curr.s.f])
                if (color[v]!=curr.s.s) bfs.p({curr.f+1,{v,curr.s.s}});
        }
        bfs.pop();
    }
    Q=rd(); F0(i,Q) {
        int a = rd(); int b = rd();
        int v = T.walk(a,b,X);
        int u = T.walk(b,a,X);
        cout << (((color[v] && color[u] && (D.pp(color[v])==D.pp(color[u]))) || (T.walk(a,b,X<<1)==b))?"YES":"NO") << endl;
    }
}

int main() {

    precalc();

    bool trials = 0;
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
