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

#define H H4

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

int T,N,M,K,Q;

char bufS[H];
char bufT[H];
int DP[H][H]; // DP[i][j] = S_i, T_j
int B[2*H];
int P[H];

int rd() {int x; scanf("%d",&x); return x;}
void fl() {cout.flush();}

int main() {

    bool trials = 0;

    if (trials) T=rd();
    else T=1;

    while (T--) {

        scanf("%s",bufS+1); N = strlen(bufS+1);
        scanf("%s",bufT+1); M = strlen(bufT+1);

        for (int i = 0; i < 2*H; i++) B[i] = -1; B[H]=0;
        for (int i = 0; i <= M; i++) {
            for (int j = 0; j <= N; j++) {
                DP[j][i] = INF;
            }
        } DP[0][0] = 0;

        int curr = H;
        for (int i = 1; i <= N; i++) {
            curr += 2*((int)(bufS[i]!='.'))-1;
            if (bufS[i]=='.') {
                P[i]=B[curr];
            } else {
                P[i]=-1;
            }
            B[curr]=i;
        }

        for (int i = 1; i <= N; i++) {
            char c = bufS[i];
            if (P[i]>=0) for (int j = 0; j <= M; j++) DP[i][j] = DP[P[i]][j];
            if (c == '.') {
                for (int j = 0; j < M; j++) DP[i][j] = min(DP[i][j],DP[i-1][j+1]);
                for (int j = 0; j <= M; j++) DP[i][j] = min(DP[i][j],DP[i-1][j]+1);
            } else {
                for (int j = 1; j <= M; j++)
                    if (bufT[j]==c) DP[i][j] = min(DP[i][j],DP[i-1][j-1]);
                for (int j = 0; j <= M; j++)
                    DP[i][j] = min(DP[i][j],DP[i-1][j]+1);
            }
        }

        cout << DP[N][M] << endl;

    }
}
*/
