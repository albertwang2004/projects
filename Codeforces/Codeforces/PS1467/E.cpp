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
#define HH 10

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define lnf 0
#define LNF 1e16

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

int T,N,M,K,Q,X,Y;

ll rd() {ll x; scanf("%lld",&x); return x;}
void fl() {cout.flush();}
struct Cheese {

    ll F(ll a, ll b) {
        return a+b;
    }

    int sz;
    vector<ll> ST;
    vector<ll> lazy;
    void start(int n) {
        sz = n;
        for (int i = 0; i < 4*n; i++) { ST.pb(0); lazy.pb(0); }
    }

    void build(ll * A, int idx, int b, int e) {
        lazy[idx]=0;
        if(b == e) {
            ST[idx] = A[b];
        } else {
            int mid = (b + e) / 2;
            build(A, 2*idx, b, mid);
            build(A, 2*idx+1, mid+1, e);
            ST[idx] = F(ST[2*idx],ST[2*idx+1]);
        }
    }
    void build(ll * A) { build(A, 1, 0, sz-1); }

    void update(int idx, int b, int e, int l, int r, ll val) {
        if (lazy[idx] != 0) {
            ST[idx] += lazy[idx];
            if(b != e) {
                lazy[idx*2] += lazy[idx];
                lazy[idx*2+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if ((b > e) || (b > r) || (e < l)) return;
        if ((b >= l) && (e <= r)) {
            ST[idx] += val;
            if (b != e) {
                lazy[idx*2] += val;
                lazy[idx*2+1] += val;
            }
            return;
        }
        int mid = (b + e) / 2;
        update(idx*2, b, mid, l, r, val);
        update(idx*2 + 1, mid + 1, e, l, r, val);
        ST[idx] = F(ST[idx*2],ST[idx*2+1]);
    }
    void update(int l, int r, ll val) { update(1,0,sz-1,l,r,val); }

    ll query(int idx, int b, int e, int l, int r) {
        if ((b > e) || (b > r) || (e < l)) return 0;
        if (lazy[idx] != 0) {
            ST[idx] += lazy[idx];
            if (b != e) {
                lazy[idx*2] += lazy[idx];
                lazy[idx*2+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(b >= l and e <= r) return ST[idx];
        int mid = (b + e) / 2;
        ll p1 = query(idx*2, b, mid, l, r);
        ll p2 = query(idx*2 + 1, mid + 1, e, l, r);
        return F(p1,p2);
    }
    ll query(int l, int r) { return query(1,0,sz-1,l,r); }

} ST;

int P[H];
map<int,int> CC;
vector<int> TR[H];
ll C[H];
vector<int> CS[H];
bool V[H];
int curr = 0;
vector<int> adj[H];
int TRR[H];

void dfs(int v) {
    if (!V[v]) {
        TR[CC[P[v]]].pb(++curr);
        TRR[v]=curr;
        V[v]=true;
        ll ret = 1;
        for (int u : adj[v]) {
            if (!V[u]) {
                dfs(u);
                ret+=C[u];
                CS[v].pb(C[u]);
            }
        }
        C[v]=ret;
    }
}

bool has(int v, int ls, int rs) {
    //cout << "Has " << v << " " << ls << " " << rs << endl;
    for (int i : TR[CC[P[v]]]) //cout << i << " " ; cout << endl;
    return (lower_bound(TR[CC[P[v]]].begin(),TR[CC[P[v]]].end(),ls)
    != lower_bound(TR[CC[P[v]]].begin(),TR[CC[P[v]]].end(),rs));
}

bool has(int v) {
    return (TR[CC[P[v]]][0]<TRR[v])||(TR[CC[P[v]]][TR[CC[P[v]]].size()-1]>TRR[v]+C[v]-1);
}

void panic() {
    cout << 0 << endl;
    exit(0);
}

int main() {

    for (int i = 0; i < H; i++) {
        TR[i] = vector<int>();
        CS[i] = vector<int>();
        V[i] = 0;
        C[i] = 0;
    }

    bool trials = 0;

    if (trials) T=rd();
    else T=1;

    while (T--) {

        N = rd();


        int coord = 0;
        for (int i = 1; i <= N; i++) {
            P[i] = rd();
            if (CC.find(P[i])==CC.end()) {
                CC[P[i]] = coord++;
            }
        }

        for (int i = 1; i < N; i++) {
            int a = rd(); int b = rd();
            adj[a].pb(b);
            adj[b].pb(a);
        }

        dfs(1);

        ST.start(N+5);

        int tot = 0;
        for (int v = 1; v <= N; v++) {
            int bruh = -2;
            if (has(v)) bruh = -1;
            int cur = TRR[v]+1;
            int temp = cur;
            for (int i = 0; i < CS[v].size(); i++) {
                if (has(v,cur,cur+CS[v][i])) {
                    if (bruh != -2) panic();
                    bruh = i;
                    temp = cur+CS[v][i];
                }
                    cur+=CS[v][i];
            }
            if (bruh == -2) continue;
            tot++;
            if (bruh == -1) {
                ST.update(0,TRR[v]-1,1);
                ST.update(cur,N+4,1);
            } else {
                ST.update(temp-CS[v][bruh],temp-1,1);
            }
        }

        int ret = 0;
        for (int i = 1; i <= N; i++) {
            ret += (tot==ST.query(i,i));
        }
        cout << ret << endl;

    }

}
*/
