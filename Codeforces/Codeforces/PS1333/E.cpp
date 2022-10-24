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

#define H 5*H3
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

int T,N,M,K,Q,X,Y;

ll rd() {ll x; scanf("%lld",&x); return x;}
void fl() {cout.flush();}

int A[H][H];
int bruh[4][4] = {
{4,3,6,12},
{7,5,9,15},
{14,1,11,10},
{13,8,16,2}
};

int main() {

    bool trials = 0;

    if (trials) T=rd();
    else T=1;

    while (T--) {

        N = rd();

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                A[i][j]=N*N-16+bruh[i][j];
            }
        }

        int curr = N*N-16;
        for (int r = 4; r < N; r++) {
            A[r][1] = curr--;
        }
        for (int r = N-1; r >= 4; r--) {
            A[r][0] = curr--;
        }
        bool dir = 0;
        for (int layer = 4; layer < N; layer++) {
            if (dir) {
                for (int r=0; r<layer; r++) {
                    A[r][layer] = curr--;
                }
                for (int c=layer; c>=2; c--) {
                    A[layer][c] = curr--;
                }
            } else {
                for (int c=2; c<layer; c++) {
                    A[layer][c] = curr--;
                }
                for (int r=layer; r>=0; r--) {
                    A[r][layer] = curr--;
                }
            }
            dir = !dir;
        }

        if (N<3) cout << -1 << endl;
        else {
            if (N==3) {
                A[0][0] = 1;
                A[0][1] = 7;
                A[0][2] = 9;
                A[1][0] = 3;
                A[1][1] = 2;
                A[1][2] = 5;
                A[2][0] = 4;
                A[2][1] = 8;
                A[2][2] = 6;
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }
        }

    }

}
*/
