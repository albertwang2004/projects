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

#define H 2*H3

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define lnf 0
#define LNF 5000000000000000000

using namespace std;
mt19937 mr(time(0));
struct LL {

    static const long long int m = mod; // set to LNF for nomod
    long long int val;

    LL(long long int v) {val=reduce(v);};
    LL() {val=0;};
    ~LL(){};
    LL(const LL& l) {val=l.val;};
    LL& operator=(int l) {val=l; return *this;}
    LL& operator=(long long int l) {val=l; return *this;}
    LL& operator=(LL l) {val=l.val; return *this;}

    static long long int reduce(long long int x, long long int md = m) {
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
    LL operator+(const long long int& b) { return (*this+LL(b)); }
    LL& operator+=(const LL& b) { return (*this=*this+b); }
    LL& operator+=(const long long int& b) { return (*this=*this+b); }

    LL operator-(const LL& b) { return LL(val-b.val); }
    LL operator-(const long long int& b) { return (*this-LL(b)); }
    LL& operator-=(const LL& b) { return (*this=*this-b); }
    LL& operator-=(const long long int& b) { return (*this=*this-b); }

    LL operator*(const LL& b) { return LL(val*b.val); }
    LL operator*(const long long int& b) { return (*this*LL(b)); }
    LL& operator*=(const LL& b) { return (*this=*this*b); }
    LL& operator*=(const long long int& b) { return (*this=*this*b); }

    static LL exp(const LL& x, const long long int& y){
        long long int z = y;
        z = reduce(z,m-1);
        LL ret = 1;
        LL w = x;
        while (z) {
            if (z&1) ret *= w;
            z >>= 1; w *= w;
        }
        return ret;
    }
    LL& operator^=(long long int y) { return (*this=LL(val^y)); }

    LL operator/(const LL& b) { return ((*this)*exp(b,-1)); }
    LL operator/(const long long int& b) { return (*this/LL(b)); }
    LL operator/=(const LL& b) { return ((*this)*=exp(b,-1)); }
    LL& operator/=(const long long int& b) { return (*this=*this/LL(b)); }

}; ostream& operator<<(ostream& os, const LL& obj) { return os << obj.val; }

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<int,LL> piL;
typedef pair<ll,int> pli;
typedef pair<LL,int> pLi;
typedef pair<ll,ll> pll;
typedef pair<ll,LL> plL;
typedef pair<LL,ll> pLl;
typedef pair<LL,LL> pLL;
typedef pair<pii,ll> edge;

int T,N,M,K,Q;
vector<edge> E;
vector<pil> adj[H];
bool V[H];
bool U[H];
ll DP[H][H];
int MX[H];

int rd() {int x; scanf("%d",&x); return x;}
ll rl() {ll x; scanf("%lld",&x); return x;}
void rd(int* x) {scanf("%d",x);}
void rd(int* x,int* y) {scanf("%d%d",x,y);}
void rd(int* x,int* y,int* z) {scanf("%d%d%d",x,y,z);}
void rd(int* x,int* y,int* z,int* w) {scanf("%d%d%d%d",x,y,z,w);}

void fl() {cout.flush();}

int main() {

    bool trials = 0;

    if (trials) rd(&T);
    else T=1;

    while (T--) {

        rd(&N,&M,&Q);

        for (int v = 1; v <= N; v++) {
            V[v] = 0;
            for (int i = 0; i <= M; i++) DP[i][v] = 0;
        } V[1] = 1;

        for (int i = 0; i < M; i++) {
            int a,b,c; rd(&a,&b,&c);
            E.pb(mp(mp(a,b),c));
            MX[a]=max(MX[a],c);
            MX[b]=max(MX[b],c);
        }

        for (int i = 1; i <= M; i++) {
            for (int u = 0; u <= H; u++) U[u] = 0;
            for (edge e : E) {
                if (V[e.f.f]) {
                    DP[i][e.f.s] = max(DP[i][e.f.s],DP[i-1][e.f.f]+e.s);
                    U[e.f.s] = 1;
                }
                if (V[e.f.s]) {
                    DP[i][e.f.f] = max(DP[i][e.f.f],DP[i-1][e.f.s]+e.s);
                    U[e.f.f] = 1;
                }
            }
            for (int u = 0; u <= H; u++) V[u] = U[u];
        }

        for (int i = 0; i <= M; i++) {
            cout << "Repetition " << i << endl;
            for (int v = 1; v <= N; v++) {
                cout << v << " " << DP[i][v] << endl;
            }
        }
    }
}
*/
