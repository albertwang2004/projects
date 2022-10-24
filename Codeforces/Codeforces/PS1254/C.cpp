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

#define H H3
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

ll tot = 0;
ll S[H];
set<ll> pf;
void primes(ll n) {
    while (n % 2 == 0)
    {
        pf.ins(2);
        n = n/2;
    }

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            pf.ins(i);
            n = n/i;
        }
    }

    if (n > 2)
        pf.ins(n);
}

vector<int> L;
vector<int> R;
vector<int> ret;
ll A[H];

bool comp(int a, int b) {return A[a] < A[b];}

ll ask(int t, int i, int j, int k) {
    cout << t << " " << i << " " << j << " " << k << endl; fl();
    return rd();
}

void read() {
    N=rd();
    FR1(i,3,N) {
        if (ask(2,1,2,i)==1) L.pb(i);
        else R.pb(i);
        A[i]=ask(1,1,2,i);
    }
    sort(L.begin(),L.end(),comp);
    sort(R.begin(),R.end(),comp);
    ret.pb(1);
    if (L.size()) {
        queue<int> S;
        stack<int> T;
        int piv = L[L.size()-1];
        for (int v : L) {
                if (v==piv) continue;
            if (ask(2,1,piv,v)==1) S.p(v);
            else T.p(v);
        }
        while (S.size()) {
            int k = S.fr(); S.pop(); ret.pb(k);
        }
        ret.pb(piv);
        while (T.size()) {
            int k = T.t(); T.pop(); ret.pb(k);
        }
    }
    ret.pb(2);
    if (R.size()) {
        queue<int> S;
        stack<int> T;
        int piv = R[R.size()-1];
        for (int v : R) {
                if (v==piv) continue;
            if (ask(2,2,piv,v)==1) S.p(v);
            else T.p(v);
        }
        while (S.size()) {
            int k = S.fr(); S.pop(); ret.pb(k);
        }
        ret.pb(piv);
        while (T.size()) {
            int k = T.t(); T.pop(); ret.pb(k);
        }
    }
    reverse(ret.begin()+1,ret.end());
    cout << 0 << " " ;
    for (int v : ret) cout << v << " "; cout << endl;
}

int main() {

    bool trials = 0;
    bool interactive = 1;

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
