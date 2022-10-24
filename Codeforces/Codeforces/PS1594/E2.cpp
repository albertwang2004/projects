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

#define H 3*H2
#define HH 43

#define woof 31051
#define mod 998244353
#define MOD 1000000007
#define lnf 0
#define inf 1069999999
#define INF 2099999999
#define LNF 5e18

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
#define F0(x,n) for(ll x = 0; x < n; ++x)
#define Fr(x,L,R) for(ll x = L; x < R; ++x)
#define R0(x,n) for(ll x = n-1; x >= 0; --x)
#define F1(x,n) for(ll x = 1; x <= n; ++x)
#define FR(x,L,R) for(ll x = L; x <= R; ++x)
#define R1(x,n) for(ll x = n; x >= 1; --x)
#define RR(x,L,R) for(ll x = R; x >= L; --x)
#define Rr(x,L,R) for(ll x = R-1; x >= L; --x)
#define FE(x,ls) for(auto x : ls)
#define FR(x,ls) for(auto &x : ls)
#define srt(x) sort(x.begin(),x.end())
#define ub(x,v) upper_bound(x.begin(),x.end(),v)
#define lb(x,v) lower_bound(x.begin(),x.end(),v)
#define bts(a,x,b) ((a<x)&&(x<b))
#define btw(a,x,b) ((a<=x)&&(x<=b))


ll cases,N,M,Q,K,X,Y;

ll rd() {ll x;cin>>x; return x;}
dbl rdd() {dbl x;cin>>x; return x;}
str rds() {str x;cin>>x; return x;}
template <class T> void rds(char* S, T* sz) {*sz=strlen(strcpy(S,rds().c_str()));}
void fl() {cout.flush();}
template <class T> void ds(vector<T> v) {FE(x,v) cout << x << " "; cout << endl;}
template <class T> void panic(T out) { cout << out << endl; exit(0); }

template<class T> bool updmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0; }
template<class T> bool updmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0; }


ll lvl(ll x) {
    if (x) return -1+lvl(x>>1);
    else return K;
}

map<char,int> colors;
LL untouched[60];

void precalc() {
    colors['o']=0;
    colors['w']=1;
    colors['g']=2;
    colors['b']=3;
    colors['y']=4;
    colors['r']=5;
    untouched[0]=1;
    F1(i,59) untouched[i]=untouched[i-1]*untouched[i-1]*16;
}

ll basic[60];
map<ll,vector<LL>> dp[60];
set<ll> special;
map<ll,int> force;

void reset() {
    F0(i,60) basic[i]=1<<i;
    F0(i,60) dp[i]=map<ll,vector<LL>>();
    special.clear();
    force.clear();
}

void read() {
    reset();
    K=rd(); N=rd();
    vector<LL> z; F0(i,6) z.pb(0);
    F0(i,N) {
        ll x=rd();
        ll c=colors[rds().at(0)];
        ll l=lvl(x);
        force[x]=c;
        while (x) {
            special.ins(x);
            dp[l++][x]=z;
            x>>=1;
        }
    }
    F0(i,K) {
        basic[K-1-i]-=dp[i].size();
        FR(x,dp[i]) {
            if (i==0) {
                dp[i][x.f][force[x.f]]=1;
            } else {
                ll l = x.f<<1; LL sL = 0;
                vector<LL> left;
                if (special.find(l)==special.end()) {
                    F0(j,6) left.pb(untouched[i-1]);
                } else {
                    left = dp[i-1][l];
                }
                F0(j,6) sL+=left[j];
                ll r = l^1; LL sR = 0;
                vector<LL> right;
                if (special.find(r)==special.end()) {
                    F0(j,6) right.pb(untouched[i-1]);
                } else {
                    right = dp[i-1][r];
                }
                F0(j,6) sR+=right[j];
                if (force.find(x.f)==force.end()) F0(j,6)
                    dp[i][x.f][j]=(sL-left[j]-left[5-j])*(sR-right[j]-right[5-j]);
                else {
                    int j = force[x.f];
                    dp[i][x.f][j]=(sL-left[j]-left[5-j])*(sR-right[j]-right[5-j]);
                }
            }
        }
    }
    LL ret = 0;
    if (force.find(1)!=force.end()) ret = dp[K-1][1][force[1]];
    else F0(j,6) ret += dp[K-1][1][j];
    cout << ret << endl;
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
