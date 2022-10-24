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

#define H H5
#define HH 10

#define mod 998244353
#define MOD 1000000007
#define lnf 0
#define inf 1069999999
#define INF 2099999999
#define LNF 1e18

// sacrilege
#define F0(x,n) for(int x = 0; x < n; ++x)
#define R0(x,n) for(int x = n-1; x >= 0; --x)
#define F1(x,n) for(int x = 1; x <= n; ++x)


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

int cases,N,M,K,Q; ll X,Y;

ll rd() {ll x;cin>>x; return x;}
void fl() {cout.flush();}

void panic() {
    cout << 0 << endl;
    exit(0);
}

// <50mb
vector<pii> adj[H];
vector<pii> G[6*H];
vector<int> O[6*H][T1]; // oh god memory
bool V[6*H];
int T[6*H];
LL DP[6*H];
bool debug = 0;

queue<pii> process;
stack<pair<vector<int>,LL>> greedy; // THIS IS AWFUL


void bfs(int v, int t) { // direct the graph
    t++;  if(debug)cout << "\t\t\t" << v << " current time " << t << endl;
    for (pii u : G[v]) {
        if ((T[u.f]==t) || !V[u.f])  {
            O[v][u.s].pb(u.f);
             if(debug)cout << "\tAdding " << v << " "
             << u.f << " : " << u.s << " : "
             << T[u.f] << " " << t << endl;
        }
        if (!V[u.f]) {
            process.p(mp(u.f,t));
            T[u.f] = t;
            V[u.f] = 1;
             if(debug)cout << "\t\tTime " << u.f << " = " << t << endl;
        }
    }
}

bool temp[6*H];

void brain(vector<int>& vv, LL dp) { // conditional bfs/dfs
    for (int v : vv) {V[v] = 1; DP[v] = dp;}
    vector<int> uuu[T1];
    F0(d,T1) {
        vector<int> uu = vector<int>();
        for (int v : vv) for (int u : O[v][d]) {
            if (!V[u] && !temp[u]) {
                uu.pb(u);
                temp[u] = 1;
            }
        }
        uuu[d]=uu;
        if(debug) if (uu.size()) {
             cout << "\tAdding " << dp*10+d << ": ";
             for (int u : uu) cout << u << ", "; if(debug)cout << endl;

        }
    }
    R0(d,T1) if (uuu[d].size()) {
        greedy.p(mp(uuu[d],dp*10+d));
        for (int u : uuu[d]) temp[u] = 0;
    }
}

// dijkstra n log n

priority_queue<pii,vector<pii>,greater<pii>> PQ;
int D[H];
void dijk(int v) {
    for (int i = 0; i <= N; i++) {
        D[i]=MOD;
    }
    D[v]=0;
    PQ.p(mp(0,v));
    while (PQ.size()) {
        int d = PQ.t().f; int u = PQ.t().s; PQ.pop();
        if (d!=D[u]) continue;
        for (pii e : adj[u]) {
            if (D[e.f]>D[u]+e.s) {
                PQ.p(mp(D[e.f]=D[u]+e.s,e.f));
            }
        }
    }
}

vector<pii> E;

void read() {
    N=rd();M=rd();

    // preliminary
    F1(i,M) {
        int a,b; a=rd(); b=rd();
        int L = to_string(i).size();
        adj[a].pb(mp(b,L));
        adj[b].pb(mp(a,L));
        E.pb(mp(a,b));
    }
    dijk(1);
    if(debug)F1(i,N) cout << "D(" << i << "): " << D[i] << endl;

    int ex = N+1;
    F1(i,M) {
        int a,b; a=E[i-1].f;b=E[i-1].s;
        string S = to_string(i);
        int L = S.size();
        vector<int> v;
        if (D[a]>D[b]) swap(a,b);
        v.pb(a); F0(i,L-1) v.pb(ex++); v.pb(b);
        F0(i,L) {
            G[v[i]].pb(mp(v[i+1],S.at(i)-'0'));
            G[v[i+1]].pb(mp(v[i],S.at(i)-'0'));
        }
    }

    F0(i,6*H) {V[i]=0;T[i]=0;}
    process.p(mp(1,0));
    T[1] = 0; V[1] = 1;
    while (process.size()) {
        pii k = process.fr();
        process.pop();
         if(debug)cout << "Doing " << k.f << " " << k.s << endl;
        bfs(k.f,k.s);
    }

    F0(i,6*H) V[i]=0;
    vector<int> x; x.pb(1);
    greedy.p(mp(x,LL(0)));
    while (greedy.size()) {
        auto k = greedy.t();
        greedy.pop();
         if(debug)cout << "DFS ";
         if(debug)for (int i : k.f) cout << i << ", ";
         if(debug)cout << "| " << k.s << endl;
        brain(k.f,k.s);
    }

    F1(i,N-1) cout << DP[i+1] << endl;
}

int main() {
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool trials = 0;

    if (trials) cases=rd();
    else cases=1;
    while (cases--) {

        read();


    }

}
*/
