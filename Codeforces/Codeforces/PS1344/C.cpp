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
    cout << -1 << endl;
    exit(0);
}

// topsort
vector<int> adj[H];
vector<int> rev[H];
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topsort() {
    visited.assign(H, false);
    ans.clear();
    for (int i = 1; i <= N; ++i) {
        if (!visited[i])
            dfs(i);
    }
    //reverse(ans.begin(), ans.end());
}

int C[H];
int D[H];
bool ret[H];
int inv[H];
void read() {
    N=rd(); M=rd();
    F1(i,N) {C[i] = i;D[i] = i;}
    F0(i,M) {
        int a = rd(); int b = rd();
        adj[a].pb(b);
        rev[b].pb(a);
    }
    topsort();
    F1(i,N) inv[ans[i-1]]=i;
    F1(v,N) {
        for (int u : adj[v]) {
            //cout << v << " " << u << " " << inv[v] << " " << inv[u] << endl;
            if (inv[u]>=inv[v]) panic();
        }
    }
    for (int v : ans) {
        for (int u : adj[v]) {
            C[v] = min(C[v],C[u]);
        }
    }
    reverse(ans.begin(),ans.end());
    for (int v : ans) {
        for (int u : rev[v]) {
            D[v] = min(D[v],D[u]);
        }
    }
    int x = 0;
    F1(i,N) {
        //cout << "C[" << i << "] = " << C[i] << endl;
        if ((C[i]==i) && (D[i]==i)) ret[i] = 1;
        else ret[i] = 0;
        x+=ret[i];
    }
    cout << x << endl;
    F1(i,N) {
        cout << (ret[i]?'A':'E');
    }
    cout << endl;
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
