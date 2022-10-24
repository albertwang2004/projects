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
ll rd() {ll x;cin>>x; return x;}
void fl() {cout.flush();}

void panic() {
    cout << 0 << endl;
    exit(0);
}

// segment tree

struct SegTree {

    ll FF1(ll a, ll b) {
        return min(a,b);
    }

    ll F2(ll a, ll b) {
        return max(a,b);
    }

	int sz;
	vector<ll> ST1;
	vector<ll> ST2;

	void start(int n) {
	    sz = n;
	    for (int i = 0; i < 2*n; i++) {
            ST1.pb(LNF); // i may have to change this value
            ST2.pb(-LNF);
        }
    }

	void lift(int idx) {
	    ST1[idx] = FF1(ST1[2*idx],ST1[2*idx+1]);
	    ST2[idx] = F2(ST2[2*idx],ST2[2*idx+1]);
    }

	void update(int idx, ll x) {
		idx += sz;
		ST1[idx] = x;
		ST2[idx] = x;
		idx >>= 1;
		while (idx) {
            lift(idx); idx >>= 1;
		}
	}

	ll query1(int lp, int rp) {
		ll a = LNF; // i may have to change this value
		ll b = LNF; // i may have to change this value
		lp += sz;
		rp += sz + 1;
		while (lp < rp) {
			if (lp&1) a = FF1(a,ST1[lp++]);
			if (rp&1) b = FF1(ST1[--rp],b);
			lp >>= 1; rp >>= 1;
		}
		return FF1(a,b);
	}

	ll query2(int lp, int rp) {
		ll a = -LNF; // i may have to change this value
		ll b = -LNF; // i may have to change this value
		lp += sz;
		rp += sz + 1;
		while (lp < rp) {
			if (lp&1) a = F2(a,ST2[lp++]);
			if (rp&1) b = F2(ST2[--rp],b);
			lp >>= 1; rp >>= 1;
		}
		return F2(a,b);
	}

} ST;

int main() {

    bool trials = 0;

    if (trials) T = rd();
    else T=1;

    F1(asdf,T) {

        N=rd();Q=rd(); ST.start(N+5);
        vector<ll> A; F0(i,N) A.pb(rd());
        ll S = 0; ST.update(0,0);
        F1(i,N) ST.update(i,S+=rd()-A[i-1]);
        F0(q,Q) {
            int L=rd(),R=rd();
            ll x = ST.query1(L,R)-ST.query1(L-1,L-1);
            ll y = ST.query2(L,R)-ST.query2(L-1,L-1);
            cout << (((x<0)||(ST.query1(R,R)-ST.query1(L-1,L-1)!=0))?-1:y) << endl;
        }
    }

	return 0;

}
*/
