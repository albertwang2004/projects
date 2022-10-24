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

#define woof 31051
#define mod 998244353
#define MOD 1000000007
#define lnf 0
#define inf 1069999999
#define INF 2099999999
#define LNF 5e18

#define tc(T) template <class T>
#define tcc(S, T) template <class S, class T>
#define tccc(S, T, U) template <class S, class T, class U>

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
ll LL::m = mod;

typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<int,LL> piL;
typedef pair<ll,ll> pll;
typedef pair<LL,LL> pLL;
typedef pair<dbl,dbl> pdd;
using namespace std;

// sacrilege

#define bts(a,x,b) ((a<x)&&(x<b))
#define btw(a,x,b) ((a<=x)&&(x<=b))

#define F0(x,n) for(ll x = 0; x < n; ++x)
#define Fr(x,L,R) for(ll x = L; x < R; ++x)
#define R0(x,n) for(ll x = n-1; x >= 0; --x)
#define F1(x,n) for(ll x = 1; x <= n; ++x)
#define FR(x,L,R) for(ll x = L; x <= R; ++x)
#define R1(x,n) for(ll x = n; x >= 1; --x)
#define RR(x,L,R) for(ll x = R; x >= L; --x)
#define Rr(x,L,R) for(ll x = R-1; x >= L; --x)
#define FE(x,ls) for(auto x : ls)
#define FER(x,ls) for(auto &x : ls)

#define srt(x) sort(x.begin(),x.end())
#define srtc(x,c) sort(x.begin(),x.end(),c)
#define rev(x) reverse(x.begin(),x.end())

#define ub(x,v) upper_bound(x.begin(),x.end(),v)
#define lb(x,v) lower_bound(x.begin(),x.end(),v)
#define bs(x,v) binary_search(x.begin(),x.end(),v)
#define dst(x,y) (ll)distance(x,y)
#define nlt(x,v) (ll)dst(x.begin(),lb(x,v))
#define nle(x,v) (ll)dst(x.begin(),ub(x,v))

ll cases,N,M,Q,K,X,Y;

ll rd() {ll x;cin>>x; return x;}
tc(T) void rd(vector<T>& A, int sz) { A.clear(); F0(i,sz) A.pb(rd()); }
tc(T) void rd(T* A, int sz) { F0(i,sz) *(A+i) = rd(); }
dbl rdd() {dbl x;cin>>x; return x;}
str rds() {str x;cin>>x; return x;}
tc(T) void rds(char* S, T* sz) {*sz=strlen(strcpy(S,rds().c_str()));}
tc(T) void rG(int sz, vector<vector<T>>& adj, int E = -18852946) {
    if (E == -18852946) E = sz-1;
    adj.clear();
    F0(i,sz+1) adj.pb(vector<T>());
    F0(i,E) {
        T a = rd(); T b = rd();
        adj[a].pb(b); adj[b].pb(a);
    }
}

void fl() {cout.flush();}
void ds(int v) { cout << v << " "; }
void ds(ll v) { cout << v << " "; }
void ds(LL v) { cout << v << " "; }
void ds(dbl v) { cout << v << " "; }
void ds(char v) { cout << v << " "; }
void ds(str v) { cout << v << " "; }
tc(T) void ds(T v) { FE(x,v) ds(x); cout << endl; }
tc(T) void panic(T out) { cout << out << endl; exit(0); }

tcc(S,T) bool updmin(S &a, T b) {
    S B = (S)b;
    if (B < a) {a = B; return 1;}
    return 0;
}

tcc(S,T) bool updmax(S &a, T b) {
    S B = (S)b;
    if (B > a) {a = B; return 1;}
    return 0;
}

tcc(S,T) S min(S a, T b) {
    S c = a; updmin(c, b); return c;
}

tcc(S,T) S max(S a, T b) {
    S c = a; updmax(c, b); return c;
}

#define H 2*H6
#define HH 43

struct SegTree {

    ll F(ll a, ll b) {
        return max(a,b);
    }

	int sz;
	vector<ll> ST;

	SegTree(int n){start(n);}
	void start(int n) {
	    sz = n;
	    for (int i = 0; i < 2*n; i++)
            ST.pb(-LNF); // i may have to change this value
    }

	void lift(int idx) {
	    ST[idx] = F(ST[2*idx],ST[2*idx+1]);
    }

	void update(int idx, ll x) {
		idx += sz;
		ST[idx] = x;
		idx >>= 1;
		while (idx) {
            lift(idx); idx >>= 1;
		}
	}

	ll query(int lp, int rp) {
		ll a = -LNF; // i may have to change this value
		ll b = -LNF; // i may have to change this value
		lp += sz;
		rp += sz + 1;
		while (lp < rp) {
			if (lp&1) a = F(a,ST[lp++]);
			if (rp&1) b = F(ST[--rp],b);
			lp >>= 1; rp >>= 1;
		}
		return F(a,b);
	}

};


ll gcd(ll a, ll b) {
   return b?gcd(b, a % b):a;
}

void precalc() {
}

ll S[69][20069];
ll DP[20069];

void read() {
    N=rd(); M=rd(); K=rd();
    F0(i,N) F1(j,M) S[i][j]=S[i][j-1]+rd();
    SegTree tbf(M+5), taf(M+5), tno(M+5);
    F1(j,M-K+1) DP[j]=S[0][j+K-1]-S[0][j-1];
    F0(i,N) {
        if (i) F1(j,M-K+1) {
            DP[j] = 0;
            updmax(DP[j],tbf.query(j,min(j+K,M-K+1))-S[i][j-1]);
            updmax(DP[j],taf.query(max(1,j-K),j)+S[i][j+K-1]);
            updmax(DP[j],max(tno.query(1,j-K),tno.query(j+K,M-K+1))
                        +S[i][j+K-1]-S[i][j-1]);
        }
        F1(j,M-K+1) {
            tbf.update(j,DP[j]+S[i+1][j+K-1]);
            taf.update(j,DP[j]-S[i+1][j-1]);
            tno.update(j,DP[j]+S[i+1][j+K-1]-S[i+1][j-1]);
        }
    }
    panic(tno.query(1,M));

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
