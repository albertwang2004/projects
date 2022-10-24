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

ll rd() {ll x; scanf("%lld",&x); return x;}
void fl() {cout.flush();}

ll d = 0;

vector<ll> A;
vector<ll> B;
vector<ll> C;

ll panic(int neg) {
    ll ret = d;
    for (int i = 0; i < neg-1; i++) {
        ret -= 2*A[i];
    }
    ret -= 2*A[neg];
    //cout << "Panic " << neg << " " << ret << endl;
    return ret;
}

int main() {

    bool trials = 0;

    if (trials) T=rd();
    else T=1;

    while (T--) {

        N = rd();
        ll best = 0;
        for (int i = 0; i < N; i++) {
            A.pb(rd()); best+=A[i]; d+=A[i];
            if (i&1) B.pb(A[i]);
            else C.pb(A[i]);
        }
        if (N==1) { cout << best << endl; exit(0); }

        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        sort(C.begin(),C.end());

        int neg = (3000001-N)%3;
        int flagB = 0; int flagC = 0;

        ll ret = -LNF;
        for (int i = 0; i < neg; i++) {
            best-=2*A[i];
            if ((A[i]==B[flagB]) && (flagB == i) && (flagB < B.size()))
                flagB++;
            else flagB = -1;
            if ((A[i]==C[flagC]) && (flagC == i) && (flagC < C.size()))
                flagC++;
            else flagC = -1;
        }

        //cout << "(" << flagB << ", " << B.size() << ") "
        // << "(" << flagC << ", " << C.size() << ") "
        // << neg << ": " << best << endl;

        if ((flagB != B.size()) && (flagC != C.size())) ret = max(best,ret);
        else ret = max(ret, panic(neg));

       //for (int i = 0; i < N; i++) cout << A[i] << " "; cout << endl;
       // for (int i = 0; i < B.size(); i++) cout << B[i] << " "; cout << endl;
       // for (int i = 0; i < C.size(); i++) cout << C[i] << " "; cout << endl;

for (;neg+3<=N;) {
    for (int i = 0; i < 3; i++) {
        best-=2*A[neg];
        if ((A[neg]==B[flagB]) && (flagB == neg) && (flagB < B.size()))
            {flagB++; //cout << "b " << neg << endl;
            }
        else flagB = -1;
        if ((A[neg]==C[flagC]) && (flagC == neg) && (flagC < C.size()))
            flagC++;
        else flagC = -1;
        neg++;
    }
       // cout << "(" << flagB << ", " << B.size() << ") "
        // << "(" << flagC << ", " << C.size() << ") "
       //  << neg << ": " << best << endl;
    if ((flagB != B.size()) && (flagC != C.size())) ret = max(best,ret);
        else ret = max(ret, panic(neg));
}
        cout << ret << endl;

    }

}
*/
