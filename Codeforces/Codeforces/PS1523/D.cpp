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
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

int red(int x) { if (x) return red(x>>1)+(x&1); return 0; }

int blyat[4*H4];
int DP[4*H4];
int blah[6*T1];
int T,N,M,K,Q;
char buf[H][6*T1];
int p2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
int main() {

    bool trials = 0;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {
        scanf("%d%d%d",&N,&M,&K);

        for (int i = 0; i < N; i++) {
            scanf("%s",buf[i]);
        }

        pii ret; ret.s=0;
        for (int attempt = 0; clock() < CLOCKS_PER_SEC; attempt++) {
            for (int i = 0; i < 4*H4; i++) { blyat[i]=0; DP[i] = 0; }
            int i = mr()%N;
            vector<int> stuff;
            int tick = 0;
            for (int j = 0; j < M; j++) {
                if (buf[i][j]=='1') {
                    stuff.pb(j);
                    blah[j]=tick++;
                }
            }
            for (int j = 0; j < N; j++) {
                int bruh = 0;
                for (int x : stuff) if (buf[j][x]=='1') bruh|=p2[blah[x]];
                blyat[bruh]++;
            }
            int dfjk = p2[tick]-1;
            for (int j = 0; j <= dfjk; j++) {
                DP[dfjk-j]=blyat[dfjk];
                for (int k = j; k; k = (k-1)&j) {
                    DP[dfjk-j]+=blyat[dfjk-k];
                }
                if (DP[dfjk-j]>=((N+1)/2)) if (red(dfjk-j)>red(ret.s))
                    { ret.f=i; ret.s=dfjk-j; }
            }
        }
        int x = 1;
        for (int j = 0; j < M; j++) {
            if (buf[ret.f][j]=='1') {
                if (ret.s&x) cout << '1';
                else cout << '0';
                x<<=1;
            } else {
                cout << '0';
            }
        }
        cout << endl;
    }
}
*/
