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

#define H 400100

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define LNF 500000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N;
vector<pii> A;
int P[H];
bool L[H];
vector<int> lower;
vector<int> upper;
bool U[H];
int curl,curr;

int m[H];
int M[H];

int main() {

    bool trials = 0;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {

        scanf("%d",&N);

        for (int i = 0; i <= 2*N+1; i++) U[i] = 0;

        for (int i = 0; i < N; i++) {
            int x,y; scanf("%d%d",&x,&y);
            A.pb(mp(x,y));
            P[x]=y; P[y]=x;
            L[x]=(x==min(x,y));
            L[y]=(x==min(x,y));
            if ((min(x,y)>N) || (max(x,y)<N+1)) {
                cout << -1 << endl;
                return 0;
            }
        }

        m[0] = INF;
        M[N+1] = -INF;

        for (int i = 1, j = N; i <= N; i++, j--) {
            m[i]=min(m[i-1],P[i]);
            M[j]=max(M[j+1],P[j]);
        }

        //for (int i = 1; i <= N; i++) {
        //    cout << m[i] << " ";
        //} cout << endl;
//
        //for (int i = 1; i <= N; i++) {
        //    cout << M[i] << " ";
        //} cout << endl;

        queue<int> split;

        for (int i = 1; i < N; i++) {
            if (m[i]>M[i+1]) split.p(i);
        }

        split.p(N);

        int curr = 1;
        int ans=0;
        while (split.size()) {
            int x = split.fr();split.pop();
            int ct = 0;
            vector<int> a;
            vector<int> b;
            a.pb(INF); b.pb(INF);
            int ret1 = 0;
            int ret2 = 0;
            int ans1 = 0;
            int ans2 = 0;
            for (curr; curr<=x; ++curr) {
                if (max(a[ret1],b[ret2])<P[curr]) ct=2;
                else if (b[ret2]>a[ret1]) {
                    if (P[curr]<a[ret1]) {
                        ct=0;
                    } else {
                        ct=1;
                    }
                } else {
                    if (P[curr]<b[ret2]) {
                        ct=1;
                    } else {
                        ct=0;
                    }
                }
                //cout << curr << " " << ct << endl;
                if (ct==0) {
                    ret1++;
                    ans1+=L[curr];
                    a.pb(P[curr]);
                }
                if (ct==1) {
                    ret2++;
                    ans2+=L[curr];
                    b.pb(P[curr]);
                }
                if(ct>1) {
                    cout << -1 << endl;
                    return 0;
                }
            }
            //for (int i : a) cout << i << " "; cout << endl;
            //for (int i : b) cout << i << " "; cout << endl;
            ans += min(ret1-ans1+ans2,ret2-ans2+ans1);
        }
        cout << ans << endl;
    }
}*/
