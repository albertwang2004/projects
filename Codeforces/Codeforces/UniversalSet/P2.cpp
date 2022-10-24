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

#define H 2*H6
#define HH 10

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define lnf 0
#define LNF 1e12

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

// seg tree but STRONGERERERERERER

// H should be 8N

ll seg[H];
ll lazy[H];
bool mark[H];


struct Cheese {

    ll F(ll a, ll b) {
        return a+b;
    }

    int n;

    Cheese(int n){start(n);}

    void start(int n) {
        this->n = n;
        for (int i = 0; i < 4*n+5; i++) { seg[i]=0;lazy[i]=0;mark[i]=0; }
    }

    void push(ll v, ll tl, ll tr) {
    //	if (!mark[v]) return;
    //	mark[v] = false;
        if (lazy1[v] != 0) {
            ll tm = (tl + tr) / 2;
            seg[2 * v] = lazy1[v] * (tm - tl + 1);
            seg[2 * v + 1] = lazy1[v] * (tr - tm);
            lazy1[2 * v] = lazy1[v];
            lazy1[2 * v + 1] = lazy1[v];
            lazy2[2 * v] = 0;
            lazy2[2 * v + 1] = 0;
            lazy1[v] = 0;
            return;
        }
        if (lazy1[2 * v] == 0) lazy2[2 * v] += lazy2[v];
        else {
            lazy1[2 * v] += lazy2[v];
            lazy2[2 * v] = 0;
        }
        if (lazy1[2 * v + 1] == 0) lazy2[2 * v + 1] += lazy2[v];
        else {
            lazy1[2 * v + 1] += lazy2[v];
            lazy2[2 * v + 1] = 0;
        }
        ll tm = (tl + tr) / 2;
        seg[2 * v] += lazy2[v] * (tm - tl + 1);
        seg[2 * v + 1] += lazy2[v] * (tr - tm);
        lazy2[v] = 0;

    }

    void update(ll v, ll tl, ll tr, ll l, ll r, ll rep, ll t) {
        if (l > r) return;
        push(v, tl, tr);
        if (l == tl && r == tr) {
            if (t == 0) {
                lazy1[v] = rep;
                lazy2[v] = 0;
                seg[v] = (tr - tl + 1) * rep;
            }
            if (t == 1) {
                lazy2[v] += rep;
                seg[v] += (tr - tl + 1) * rep;
            }
            //mark[v] = true;
            return;
        }
        ll tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), rep, t);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, rep, t);
        seg[v] = seg[2 * v] + seg[2 * v + 1];
    }

    ll query(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > r) return 0;
        push(v, tl, tr);
        if (l == tl && r == tr) return seg[v];
        ll tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, l, min(tm, r)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }
void update1(ll l, ll r, ll rep) { update(1, 0, 200005, l, r, rep, 1); }
void update2(ll l, ll r, ll rep) { update(1, 0, 200005, l, r, rep, 0); }
    int query(int l, int r) { return query(1, 0, n-1, l, r); }


};

int main() {

    bool trials = 0;

    if (trials) T = rd();
    else T=1;

    F1(asdf,T) {

        N=rd();Q=rd();
        Cheese ST(N);
        F0(i,N) {
            ll a=rd();
            ST.update(i,i,a);
        }
        for (ll i = 0; i < q; ++i) {
            ll t = rd();
            if (t == 1) {
                ll a=rd(),b=rd(),x=rd();
                ST.update1(a, b, x);
            }
            if (t == 2) {
                ll a=rd(),b=rd(),x=rd()+LNF;
                ST.update2(a, b, x);
            }
            if (t == 3) {
                ll a=rd(),b=rd();
                cout << ST.query(a, b) << endl;
            }
        }


    }

	return 0;

}
*/
