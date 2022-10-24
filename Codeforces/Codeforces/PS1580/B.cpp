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

#define H H2
#define HH 43

#define woof 31051
#define mod 998244353
#define MOD 1000000007
#define lnf 0
#define inf 1069999999
#define INF 2099999999
#define LNF 5e18

// sacrilege
#define F0(x,n) for(int x = 0; x < n; ++x)
#define FR0(x,L,R) for(int x = L; x < R; ++x)
#define R0(x,n) for(int x = n-1; x >= 0; --x)
#define F1(x,n) for(int x = 1; x <= n; ++x)
#define FR1(x,L,R) for(int x = L; x <= R; ++x)
#define R1(x,n) for(int x = n; x >= 1; --x)
#define RR(x,L,R) for(int x = R; x >= L; --x)
#define FE(x,ls) for(auto x : ls)
#define ub(x,v) upper_bound(x.begin(),x.end(),v)
#define lb(x,v) lower_bound(x.begin(),x.end(),v)
#define btws(a,x,b) ((a<x)&&(x<b))
#define btw(a,x,b) ((a<=x)&&(x<=b))
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

    static void setMod(ll m) { LL::m = m; }

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

ll cases,N,M,Q,K,X,Y;

ll rd() {ll x;cin>>x; return x;}
dbl rdd() {dbl x;cin>>x; return x;}
void fl() {cout.flush();}

template <class T> void panic(T out) { cout << out << endl; exit(0); }

LL C[H][H];
LL DP[H][H][H];
bool V[H][H][H];
LL F[H];

LL dp(int n, int m, int k) {
    if (V[n][m][k]) return DP[n][m][k];
    if (k==0) {
        V[n][m][k] = 1;
        return DP[n][m][k]=0;
    }
    if ((m==1) && (k==1)) {
        V[n][m][k]=1;
        return DP[n][m][k]=F[n];
    }
    DP[n][m][k] = 0;
    F0(i,n) FR1(j,max(0,m-n+1+i),min(i,m)) {
        DP[n][m][k] += C[n-1][i] * dp(i,j,k-1) * dp(n-1-i,m-j,k-1);
    }
    V[n][m][k] = 1;
    return DP[n][m][k];
}

void read() {
    N=rd(); M=rd(); K=rd(); LL::setMod(rd());

    F[0] = 1;
    F1(i,H-1) F[i] = F[i-1]*i;
    F0(i,H) C[i][0]=C[i][i]=1;
    F0(i,H) FR0(j,1,i) C[i][j]=C[i-1][j-1]+C[i-1][j];

    F0(n,H) F0(m,H) F0(k,H) DP[n][m][k]=V[n][m][k]=0;
    F0(i,H) DP[0][0][i] = V[0][0][i] = 1;
    DP[1][1][1] = V[1][1][1] = 1;
    FR0(i,2,H) DP[1][0][i] = V[1][0][i] = 1;
    F0(n,H) F0(m,H) F0(k,H) {
        if (k>n) {
            if (m==0) DP[n][m][k] = F[n];
            else DP[n][m][k] = 0;
            V[n][m][k] = 1;
        }
    }
    F0(n,2) F0(m,H) F0(k,H) V[n][m][k]=1;
    cout << dp(N,K,M) << endl;
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
