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

#define H 3*H5
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

ll cases,N,M,Q,K; ll X,Y;

ll rd() {ll x;cin>>x; return x;}
void fl() {cout.flush();}

void panic(ll out) {
    cout << out << endl;
    exit(0);
}

double eps = 1e-8;
double V;
double ret(double c, double m, double p) {
    if (p>=1-eps) return 1;
    double ans = p;
    if (c>=eps) {
        if (V+eps>=c) {
            if (m<=eps) {
                ans+=c*(1+ret(0,0,1));
            } else {
                ans+=c*(1+ret(0,m+c/2,p+c/2));
            }
        } else {
            if (m<=eps) {
                ans+=c*(1+ret(c-V,0,p+V));
            } else {
                ans+=c*(1+ret(c-V,m+V/2,p+V/2));
            }
        }
    }
    if (m>=eps) {
        if (V+eps>=m) {
            if (c<=eps) {
                ans+=m*(1+ret(0,0,1));
            } else {
                ans+=m*(1+ret(c+m/2,0,p+m/2));
            }
        } else {
            if (c<=eps) {
                ans+=m*(1+ret(0,m-V,p+V));
            } else {
                ans+=m*(1+ret(c+V/2,m-V,p+V/2));
            }
        }
    }
    return ans;
}

void read() {
    double C,M,P; cin>>C>>M>>P>>V;
    cout << setprecision(15) << ret(C,M,P) << endl;
}

int main() {
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
