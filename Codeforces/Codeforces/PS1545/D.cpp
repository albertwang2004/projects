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

#define H H3
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

// fenwick tree

ll BT[H];
ll A[H];

void update(ll idx, ll x) {
   ll d = x;
   A[idx] += d;
   while (idx < H) {
       BT[idx] += d;
       idx += (idx & -idx);
   }
}

ll sum(ll idx) {
   ll s = 0;
   while (idx >= 1) {
       s += BT[idx];
       idx -= (idx & -idx);
   }
   return s;
}

// fenwick tree

ll P[H][H];
ll S1[H];
ll S2[H];
int bad = 0;
unordered_map<ll,int> detect;

void read() {
    M=rd();N=rd();
    ll d = -6969696969696969;
    F0(i,N){
        S1[i]=S2[i]=0;
        F0(j,M) {
            P[i][j]=rd();
            S1[i]+=P[i][j];
            S2[i]+=P[i][j]*P[i][j];
        }
        if(i>0) {
            detect[S1[i]-S1[i-1]]+=T5+i;
        }
    }
    int bad = T5;
    for (auto it : detect) {
        if (it.s<T5<<1) {
            bad=min(bad,it.s%T5);
        }
    }
    cout << bad << " " << (((S2[bad] - S2[0] - ((2*(((S2[N-1]-S2[0])/(N-1))-(abs((2*(((S2[N-1]-S2[0])/(N-1))-(S2[((bad==1)?(N-1):1)]-S2[((bad==1)?(N-1):1)-1])))/(N-2))*(N-2))/2)+(bad-1)*abs((2*(((S2[N-1]-S2[0])/(N-1))-(S2[((bad==1)?(N-1):1)]-S2[((bad==1)?(N-1):1)-1])))/(N-2)))*bad/2))/((S1[bad] - ((S1[N-1] - S1[0])/(N-1)*bad+S1[0]))))-((S1[bad] - ((S1[N-1] - S1[0])/(N-1)*bad+S1[0]))))/2 << endl; fl();

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
