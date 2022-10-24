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
#define INF 1069999999
#define lnf 0
#define LNF 1e18

// sacrilege
#define F0(x,n) for(int x = 0; x < n; ++x)
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
typedef pair<LL,pLL> TRI;

int T,N,M,K,Q,X,Y;
bool V[H];
int rd() {int x;cin>>x; return x;}
void fl() {cout.flush();}

void panic() {
    cout << 0 << endl;
    exit(0);
}

vector<int> adj[H];

// dfs

TRI dfs(int v) {

    V[v]=true;

    LL prod = 1;

    LL dp01 = 0;
    LL dp00 = 1;

    LL dp11 = 0;
    LL dp10 = 1;

    LL dp22 = 0;
    LL dp21 = 0;
    LL dp20 = 1;

    for (int u : adj[v]) if (!V[u]) {

        TRI x = dfs(u);

        LL a = x.f; LL b = x.s.f; LL c = x.s.s;
        LL r = a+b; LL s = a+c;

        prod = prod*c;

        dp01 = dp01*c + dp00*r;
        dp00 = dp00*c;

        dp11 = dp11*s + dp10*r;
        dp10 = dp10*s;

        dp22 = dp22*s + dp21*r;
        dp21 = dp21*s + dp20*r;
        dp20 = dp20*s;

    }

    return mp(prod+dp01,mp(dp11-dp01,dp22));
}

LL su(TRI x) {return x.f+x.s.s;}

void read() {
    N=rd();
    F0(i,N-1) {
        int a = rd(); int b = rd();
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cout << su(dfs(1)) << endl;
}

int main() {
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool trials = 0;

    if (trials) T=rd();
    else T=1;

    while (T--) {

        read();


    }

}
*/
