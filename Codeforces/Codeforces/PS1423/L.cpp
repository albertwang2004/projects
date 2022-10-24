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

#define H 30
#define HH 10

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define lnf 0
#define LNF 1e18

// sacrilege
#define F0(x,n) for(int x = 0; x < n; ++x)
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

int T,N,M,K,Q,X,Y;

int rd() {int x;cin>>x; return x;}
void fl() {cout.flush();}

void panic() {
    cout << 0 << endl;
    exit(0);
}

int D;

unordered_map<bitset<N+1>,int> L;
unordered_map<bitset<N+1>,int> R;
bitset<N+1> S[H];
void chk(int bm,int s) {
    vector<bool> bruh;
    F0(i,N+1)bruh.pb(0);
    int c=0;
    for (;bm>0;s++,bm>>=1) if (bm&1) {add(bruh,S[s]);c++;}
    if (L.find(bruh)==L.end()) {
        L[bruh]=c;
    } else {
        L[bruh]=min(L[bruh],c);
    }
}
vector<bool> tgt;
void chkr(int bm,int s) {
    vector<bool> bruh;
    F0(i,N+1)bruh.pb(0);
    int c=0;
    for (;bm>0;s++,bm>>=1) if (bm&1) {add(bruh,S[s]);c++;}
    if (R.find(bruh)==R.end()) {
        R[bruh]=c;
    } else {
        R[bruh]=min(R[bruh],c);
    }
}
vector<bool> rd(int thisisavariabletodistinguishfromthepreviousreadmethod) {
    vector<bool> ans;
    int k = rd();
    int cr = 0;
    F0(j,k) {
        int x = rd();
        while (cr<x) {ans.pb(0); cr++;}
        ans.pb(1); cr++;
    }
    while (cr<=N) {ans.pb(0);cr++;}
    return ans;
}
void read() {
    N=rd();K=rd();D=rd();
    F0(i,K)S[i]=rd(69);
    Q=15;
    int lim=1; F0(i,min(Q,K)) lim<<=1;
    F0(i,lim)chk(i,0);
    if (K<=Q) {
        F0(i,D) {
            tgt = rd(69);
            if (L.find(tgt)==L.end()) cout << -1 << endl;
            else cout << L[tgt] << endl;
        }
    } else {
        int lim=1; F0(i,K-Q) lim<<=1;
        F0(i,lim)chkr(i,Q);
        F0(i,D) {
            tgt = rd(69);
            ll ret = LNF;
            for (auto it : R) {
                add(tgt,it.f);
                if (L.find(tgt)!=L.end()) ret = min(ret,(ll)(L[tgt]+it.s));
                add(tgt,it.f);
            }if(ret==LNF)ret=-1;
            cout << ret << endl;
        }
    }
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
