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

ll cases,N,M,Q,K,X,Y;

ll rd() {ll x;cin>>x; return x;}
dbl rdd() {dbl x;cin>>x; return x;}
void fl() {cout.flush();}

template <class T> void panic(T out) { cout << out << endl; exit(0); }

map<ll,int> PI;
vector<ll> P;
vector<pll> I;
vector<pll> J[H];
vector<ll> DP[H];
vector<ll> PF;
vector<ll> SF;

template <class T> void PV(vector<T> out, int k=-1) {
    if (k==-1) k=out.size();
    cout << "( "; F0(i,k) cout << out[i] << " "; cout << ")" << endl;
}

void read() {

    while (PF.size()<H) PF.pb(LNF);
    while (SF.size()<H) SF.pb(LNF);

    N=rd(); M=rd();

    F0(i,N+5) { DP[i].clear(); J[i].clear(); PF[i]=SF[i]=LNF; }
    P.clear(); I.clear(); PI.clear();

    P.pb(-10000000000ll); P.pb(-5000000000ll); P.pb(5000000000ll);

    F1(i,N) P.pb(rd());
    F0(i,M) I.pb(mp(rd(),-rd()));

    sort(P.begin(),P.end());
    sort(I.begin(),I.end());

    F0(i,N+3) PI[P[i]]=i;

    ll m = -LNF; FE(x,I) if (lb(P,x.f)==lb(P,x.s=-x.s))
        if (x.s>m) { m=x.s; J[PI[*lb(P,x.f)]].pb(x); }

    DP[0].pb(0); F0(i,N+2) {
        vector<ll> DL; F0(j,J[i+1].size()) DL.pb(P[i+1]-J[i+1][j].f); DL.pb(0);
        vector<ll> DR; F0(j,J[i+2].size()) DR.pb(J[i+2][j].s-P[i+1]); DR.pb(0);
        sort(DR.begin(),DR.end());
        F0(j,J[i+1].size()+1) PF[j] = min(PF[max(j-1,0)],DP[i][j]+DL[j]);
        RR(j,0,J[i+1].size()) SF[j] = min(SF[j+1],DP[i][j]+2*DL[j]);
        sort(DL.begin(),DL.end());
        FE(d,DR) DP[i+1].pb(
            min(PF[J[i+1].size()+1-(int)distance(DL.begin(),ub(DL,d))]+2*d,
                SF[J[i+1].size()-(int)distance(DL.begin(),--ub(DL,d))]+d));
        F0(j,J[i+1].size()+5) PF[j]=SF[j]=LNF;
    }

    cout << DP[N+1].back() << endl;

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
