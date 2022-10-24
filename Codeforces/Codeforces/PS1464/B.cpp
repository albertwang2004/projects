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

int T,N,M,K,Q; ll X,Y;

int rd() {int x;cin>>x; return x;}
void fl() {cout.flush();}

void panic() {
    cout << 0 << endl;
    exit(0);
}
// dsu

vector<ll> c1;
vector<ll> q1;
vector<ll> c0;
vector<int> chk;
    char buf[H];
void read() {
    string sin; cin>>sin;
    for (int i = 0; i < sin.size(); i++) buf[i] = sin.at(i);
    N=sin.size();
    X=rd();Y=rd();
    if (X>Y) {
        swap(X,Y);
        F0(i,N) {
            if (buf[i]=='1') buf[i]='0';
            else if (buf[i]=='0') buf[i]='1';
        }
    }
    c1.pb(0);
    q1.pb(0);
    c0.pb(0);
    ll ret = LNF;
    ll curr = 0;
    F0(i,N) {
        if (buf[i]!='0') curr+=X*c0[i];
        if (buf[i]=='0') curr+=Y*q1[i];
        //cout << curr << c0[i] << " " << q1[i] << endl;
        c1.pb(c1[i]+(buf[i]=='1'));
        q1.pb(q1[i]+(buf[i]!='0'));
        c0.pb(c0[i]+(buf[i]=='0'));
        if (buf[i]=='?')chk.pb(i+1);
        //cout << i+1 << " " << c1[i+1] << " " << q1[i+1] << " " << c0[i+1] << endl;
    }
    ll bf = -1;
    ll S=chk.size();
    ret = min(curr,ret);
        //cout << ret << endl;
    for (int x : chk) { // last 0 at x
        S--;bf++;
        //cout << curr << "inc " << X*(q1[N]-q1[x])+Y*(c1[x]) << endl;
        curr+=X*(q1[N]-q1[x])+Y*(c1[x]);
        //cout << "dec " << Y*(c0[N]-c0[x])+X*(c0[x]+bf) << endl;
        curr-=Y*(c0[N]-c0[x])+X*(c0[x]+bf);
        //cout << curr << endl;
        ret=min(curr,ret);
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
