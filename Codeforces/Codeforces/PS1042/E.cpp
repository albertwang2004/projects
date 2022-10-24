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

    static const ll m = mod; // set to LNF for nomod
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

int cases,N,M,Q,K; ll X,Y;

ll rd() {ll x;cin>>x; return x;}
void fl() {cout.flush();}

void panic(ll out) {
    cout << out << endl;
    exit(0);
}

int A[H][H];

bool comp(pii a, pii b) {
    return A[a.f][a.s]<A[b.f][b.s];
}

vector<pii> B;
LL DP=0;
LL DS=0;
LL S2=0;
LL SX=0;
LL SY=0;
LL ds=0;
LL s2=0;
LL sx=0;
LL sy=0;
void read() {
    N=rd();M=rd();
    F0(i,N) F0(j,M) {
        A[i][j]=rd();
        B.pb(mp(i,j));
    }
    LL r=rd()-1; LL c=rd()-1;
    sort(B.begin(),B.end(),comp);
    int k = 0;
    F0(i,N*M) {
        LL x = B[i].f; LL y = B[i].s;
        if (i) if (A[B[i].f][B[i].s]>A[B[i-1].f][B[i-1].s]) {
            k=i;
            DS=ds;
            S2=s2;
            SX=sx;
            SY=sy;
        }
        if (k==0) DP=0;
        else DP=(DS+S2-SX*x-SY*y)/k+x*x+y*y;
        if ((x==r) && (c==y)) panic(DP.val);
        ds+=DP;
        s2+=x*x+y*y;
        sx+=x*2;
        sy+=y*2;
    }
}

int main() {
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
