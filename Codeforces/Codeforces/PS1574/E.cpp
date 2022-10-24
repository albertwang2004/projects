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

#define H H6+H5
#define HH 43

#define woof 31051
#define mod 998244353
#define MOD 1000000007
#define lnf 0
#define inf 1069999999
#define INF 2099999999
#define LNF 1e18

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
typedef pair<int,ll> pil;
typedef pair<int,LL> piL;
typedef pair<ll,ll> pll;
typedef pair<LL,LL> pLL;
typedef pair<pll,ll> tri;
typedef pair<LL,pLL> TRI;
using namespace std;

ll cases,N,M,Q,K;

ll rd() {ll x;cin>>x; return x;}
void fl() {cout.flush();}

void panic(ll out) {
    cout << out << endl;
    exit(0);
}


map<pii,int> key;
int A[H];
int X[H]; LL PX = 1; int X0 = 0; int CX[H][2];
int Y[H]; LL PY = 1; int Y0 = 0; int CY[H][2];
int B[2];
int ovr = 2;
void wash(int x, int y) {
    ovr=2-(B[0]>0)-(B[1]>0);
    if (X[x]) PX/=X[x];
    else X0--;
    X[x]=2-(CX[x][0]>0)-(CX[x][1]>0);
    if (X[x]) PX*=X[x];
    else X0++;
    if (Y[y]) PY/=Y[y];
    else Y0--;
    Y[y]=2-(CY[y][0]>0)-(CY[y][1]>0);
    if (Y[y]) PY*=Y[y];
    else Y0++;
}
void clr(int x, int y) {
    int md = (x+y+A[key[{x,y}]])&1;
    B[md]--;CX[x][md]--;CY[y][md]--;
    wash(x,y);A[key[{x,y}]]=-1;
}
void add(int x, int y, int t){
    int md = (x+y+t)&1;
    B[md]++;CX[x][md]++;CY[y][md]++;
    wash(x,y);A[key[{x,y}]]=t;
}
void read() {
    N=rd();M=rd();K=rd();Q=0;
    F0(i,N) {X[i]=2;PX*=2;CX[i][0]=CX[i][1]=0;}
    F0(i,M) {Y[i]=2;PY*=2;CY[i][0]=CY[i][1]=0;}
    B[0]=0; B[1]=0;
    F0(q,K) {
        int x=rd()-1; int y=rd()-1; int t=rd();
        if (key.find({x,y})==key.end()){key[{x,y}]=Q;A[Q++]=-1;}
        if (A[key[{x,y}]]!=-1) clr(x,y);
        if (t>=0) add(x,y,t);
        cout << (X0?0:PX)+(Y0?0:PY)-ovr << endl;
    }
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
