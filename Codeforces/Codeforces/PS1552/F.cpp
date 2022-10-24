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
#define lnf 0
#define inf 1069999999
#define INF 2099999999
#define LNF 1e18

// sacrilege
#define F0(x,n) for(int x = 0; x < n; ++x)
#define R0(x,n) for(int x = n-1; x >= 0; --x)
#define F1(x,n) for(int x = 1; x <= n; ++x)


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
typedef pair<ll,ll> pll;
typedef pair<LL,LL> pLL;
typedef pair<pll,ll> tri;
typedef pair<LL,pLL> TRI;

int T,N,M,K,Q,X,Y;

int rd() {int x;cin>>x; return x;}
void fl() {cout.flush();}

void panic() {
    cout << 0 << endl;
    exit(0);
}


// seg tree but stronger
struct Cheese {

    LL F(LL a, LL b) {
        return a+b;
    }

    int sz;
    vector<LL> ST;
    vector<LL> lazy;

    Cheese(int n){start(n);}
    void start(int n) {
        sz = n;
        for (int i = 0; i < 4*n; i++) { ST.pb(0); lazy.pb(0); }
    }

    void update(int idx, int b, int e, int l, int r, LL val) {
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
    void update(int l, int r, LL val) { update(1,0,sz-1,l,r,val); }

    LL query(int idx, int b, int e, int l, int r) {
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
        LL p1 = query(idx*2, b, mid, l, r);
        LL p2 = query(idx*2 + 1, mid + 1, e, l, r);
        return F(p1,p2);
    }
    LL query(int l, int r) { return query(1,0,sz-1,l,r); }

};


unordered_map<int,int> compress;
vector<pair<pii,bool>> intervals;
vector<int> stuff;
void read() {
    int N = rd();
    stuff.pb(0);
    F0(i,N) {
        int a=rd(); int b=rd(); int c=rd();
        stuff.pb(a);
        stuff.pb(b);
        intervals.pb(mp(mp(a,b),c));
    }
    sort(stuff.begin(),stuff.end());
    F0(i,2*N+1) compress[stuff[i]]=i;
    LL ret = stuff[2*N]+1;
    Cheese ST(2*N+1);
    for (auto k : intervals) {
        int st = k.f.s;
        int ed = k.f.f;
        int inc = k.s;
        LL curr = ST.query(compress[st],compress[ed])+ed-st;
        ST.update(compress[ed],compress[ed],curr);
        ret+=curr*inc;
    }
    cout << ret << endl;
}

int main() {
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool trials = 0;

    if (trials) T=rd();
    else T=1;

    while (T--) {

        read();


    }

}
*/
