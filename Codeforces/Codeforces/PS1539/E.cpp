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
#define FER(x,ls) for(auto &x : ls)
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

bool DP[H5][2];
int PR[H5][2];
vector<pair<int,pair<pii,pii>>> C;

bool ok(int c, int b) {
    if (b==0) return btw(C[c].s.f.f,C[c].f,C[c].s.f.s);
    else return btw(C[c].s.s.f,C[c].f,C[c].s.s.s);
}

struct maxTree {

    ll F(ll a, ll b) {
        return max(a,b);
    }

    int sz;
    vector<ll> ST;
    vector<ll> lazy;
    void start(int n) {
        sz = n;
        for (int i = 0; i < 4*n; i++) { ST.pb(0); lazy.pb(0); }
    }

    void build(ll * A, int idx, int b, int e) {
        lazy[idx]=0;
        if(b == e) {
            ST[idx] = A[b];
        } else {
            int mid = (b + e) / 2;
            build(A, 2*idx, b, mid);
            build(A, 2*idx+1, mid+1, e);
            ST[idx] = F(ST[2*idx],ST[2*idx+1]);
        }
    }
    void build(ll * A) { build(A, 1, 0, sz-1); }

    void update(int idx, int b, int e, int l, int r, ll val) {
        if (lazy[idx] != 0) {
            ST[idx] += lazy[idx];
            if(b != e) {
                lazy[idx*2] += lazy[idx];
                lazy[idx*2+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if ((b > e) || (b > r) || (e < l)) return;
        if ((b >= l) && (e <= r)) {
            ST[idx] += val;
            if (b != e) {
                lazy[idx*2] += val;
                lazy[idx*2+1] += val;
            }
            return;
        }
        int mid = (b + e) / 2;
        update(idx*2, b, mid, l, r, val);
        update(idx*2 + 1, mid + 1, e, l, r, val);
        ST[idx] = F(ST[idx*2],ST[idx*2+1]);
    }
    void update(int l, int r, ll val) { update(1,0,sz-1,l,r,val); }

    ll query(int idx, int b, int e, int l, int r) {
        if ((b > e) || (b > r) || (e < l)) return 0;
        if (lazy[idx] != 0) {
            ST[idx] += lazy[idx];
            if (b != e) {
                lazy[idx*2] += lazy[idx];
                lazy[idx*2+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(b >= l and e <= r) return ST[idx];
        int mid = (b + e) / 2;
        ll p1 = query(idx*2, b, mid, l, r);
        ll p2 = query(idx*2 + 1, mid + 1, e, l, r);
        return F(p1,p2);
    }
    ll query(int l, int r) { return query(1,0,sz-1,l,r); }

} L1, R1;

struct minTree {

    ll F(ll a, ll b) {
        return min(a,b);
    }

	int sz;
	vector<ll> ST;

	void start(int n) {
	    sz = n;
	    for (int i = 0; i < 2*n; i++)
            ST.pb(LNF); // i may have to change this value
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
		ll a = LNF; // i may have to change this value
		ll b = LNF; // i may have to change this value
		lp += sz;
		rp += sz + 1;
		while (lp < rp) {
			if (lp&1) a = F(a,ST[lp++]);
			if (rp&1) b = F(ST[--rp],b);
			lp >>= 1; rp >>= 1;
		}
		return F(a,b);
	}

} L2, R2;


void precalc() {
}

void reset() {
}

bool chk(int ans) {
}

void read() {
    N=rd();M=rd();
    L1.start(N+5);
    L2.start(N+5);
    R1.start(N+5);
    R2.start(N+5);
    int L0,R0;
    L0=R0=0;
    F0(i,N) {
        DP[i][0]=DP[i][1]=0;
        int a=rd(),b=rd(),c=rd(),d=rd(),e=rd();
        C.pb({a,{{b,c},{d,e}}});
        L1.update(i,i,b);
        L2.update(i,c);
        R1.update(i,i,d);
        R2.update(i,e);
        if (d==0 && i==L0 && ok(i,0)) L0++;
        if (b==0 && i==R0 && ok(i,1)) R0++;
    }

    DP[N-1][0]=ok(N-1,0);
    DP[N-1][1]=ok(N-1,1);
    int L,R,l,r;
    L=R=N-1;
    l=r=N-1;
    if (DP[N-1][0]) { L=N-1; PR[N-1][0]=N; }
    else l=N-2;
    if (DP[N-1][1]) { R=N-1; PR[N-1][1]=N; }
    else r=N-2;
        //cout << N-1 << " : " << DP[N-1][0] << " " << DP[N-1][1]
        //<< " " << L << " " << R << " " << l << " " << r << endl;
    R0(i,N-1) {
        //cout << i << " | " << L1.query(i,R) << " " << C[i].f << " " << L2.query(i,R) << endl;
        //cout << i << " | " << R1.query(i,L) << " " << C[i].f << " " << R2.query(i,L) << endl;
        DP[i][0]=btw(L1.query(i,R),C[i].f,L2.query(i,R))&&(r>=R);
        DP[i][1]=btw(R1.query(i,L),C[i].f,R2.query(i,L))&&(l>=L);
        if (DP[i][0]) { PR[i][0] = R; }
        if (DP[i][1]) { PR[i][1] = L; }
        if (DP[i][0]) { L = i; }
        if (DP[i][1]) { R = i; }
        if (!ok(i,0)) l=i-1;
        if (!ok(i,1)) r=i-1;
        //cout << i << " : " << DP[i][0] << " " << DP[i][1]
        //<< " : " << PR[i][0] << " " << PR[i][1]
        //<< " : " << L << " " << R << " " << l << " " << r << endl;
    }

    //cout << L0 << " " << R0 << endl;
    int ok = -1;
    int st = -1;
    F0(i,L0) if (DP[i][0]) { ok = i; st = 1; }
    F0(i,R0) if (DP[i][1]) { ok = i; st = 0; }
    if (st == -1) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        int curr = 0;
        while (curr == 0 || ok != 0) {
            //cout << ok << " " << curr << endl;
            st^=1;
            for (;curr <= min(ok,(int)N-1); ++curr) cout << st << " ";
            //cout << endl;
            ok = PR[ok][st];
        }
    }
    cout << endl;
    //cout << 0 << " : " << DP[0][0] << " " << DP[0][1] << " " << L0 << " " << R0 << endl;
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
