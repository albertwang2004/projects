/*
// Solves A1 and A2.
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 101
#define MOD 1000000007
#define INF 999999

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N,M;
bool table[H][H];
vector<pair<pair<pair<pair<pair<int,int>,int>,int>,int>,int>> ret;

int main() {
    scanf("%d",&T);
    while (T--) {
        ret.clear();
        scanf("%d%d",&N,&M);
        for (int i = 0; i < N; i++) {
            char buf[M]; scanf("%s",buf);
            for (int j = 0; j < M; j++) {
                table[i][j]=(buf[j]=='1');
            }
        }
        // reduce rows
        for (int i = N-1; i >= 2; i--) {
            for (int j = 0; j < M; j++) {
                if (table[i][j]) {
                    if (j!=M-1) {
                        table[i][j]=!table[i][j];
                        table[i-1][j]=!table[i-1][j];
                        table[i-1][j+1]=!table[i-1][j+1];
                        ret.pb(mp(mp(mp(mp(mp(i+1,j+1),i),j+1),i),j+2)); // this is the dumbest decision of my life
                    } else {
                        table[i][j]=!table[i][j];
                        table[i-1][j]=!table[i-1][j];
                        table[i-1][j-1]=!table[i-1][j-1];
                        ret.pb(mp(mp(mp(mp(mp(i+1,j+1),i),j+1),i),j));
                    }
                }
            }
        }
        // reduce columns
        for (int j = M-1; j >= 2; j--) {
            for (int i = 0; i < 2; i++) {
                if (table[i][j]) {
                    if (i==0) {
                        table[i][j]=!table[i][j];
                        table[i][j-1]=!table[i][j-1];
                        table[i+1][j-1]=!table[i+1][j-1];
                        ret.pb(mp(mp(mp(mp(mp(i+1,j+1),i+1),j),i+2),j)); // this is the dumbest decision of my life
                    } else {
                        table[i][j]=!table[i][j];
                        table[i][j-1]=!table[i][j-1];
                        table[i-1][j-1]=!table[i-1][j-1];
                        ret.pb(mp(mp(mp(mp(mp(i+1,j+1),i+1),j),i),j));
                    }
                }
            }
        }
        if (table[0][0]&&table[0][1]&&table[1][0]&&table[1][1]) {
            ret.pb(mp(mp(mp(mp(mp(2,2),1),2),2),1));
            ret.pb(mp(mp(mp(mp(mp(1,1),1),2),2),1));
            ret.pb(mp(mp(mp(mp(mp(1,1),1),2),2),2));
            ret.pb(mp(mp(mp(mp(mp(1,1),2),2),2),1));
        } else if (table[0][0]&&table[0][1]&&table[1][0]) {
            ret.pb(mp(mp(mp(mp(mp(1,1),1),2),2),1));
        } else if (table[1][1]&&table[0][1]&&table[1][0]) {
            ret.pb(mp(mp(mp(mp(mp(2,2),1),2),2),1));
        } else if (table[0][0]&&table[0][1]&&table[1][1]) {
            ret.pb(mp(mp(mp(mp(mp(2,2),1),1),1),2));
        } else if (table[0][0]&&table[1][1]&&table[1][0]) {
            ret.pb(mp(mp(mp(mp(mp(2,2),1),1),2),1));
        } else if (table[0][0]&&table[1][1]) {
            ret.pb(mp(mp(mp(mp(mp(1,1),1),2),2),1));
            ret.pb(mp(mp(mp(mp(mp(2,2),1),2),2),1));
        } else if (table[0][1]&&table[1][0]) {
            ret.pb(mp(mp(mp(mp(mp(2,2),1),1),1),2));
            ret.pb(mp(mp(mp(mp(mp(2,2),1),1),2),1));
        } else if (table[0][1]&&table[0][0]) {
            ret.pb(mp(mp(mp(mp(mp(1,1),2),2),2),1));
            ret.pb(mp(mp(mp(mp(mp(2,2),1),2),2),1));
        } else if (table[1][0]&&table[0][0]) {
            ret.pb(mp(mp(mp(mp(mp(2,2),1),2),2),1));
            ret.pb(mp(mp(mp(mp(mp(1,1),1),2),2),2));
        } else if (table[0][1]&&table[1][1]) {
            ret.pb(mp(mp(mp(mp(mp(1,1),2),2),2),1));
            ret.pb(mp(mp(mp(mp(mp(1,1),1),2),2),1));
        } else if (table[1][0]&&table[1][1]) {
            ret.pb(mp(mp(mp(mp(mp(1,1),1),2),2),2));
            ret.pb(mp(mp(mp(mp(mp(1,1),1),2),2),1));
        } else if (table[0][0]) {
            ret.pb(mp(mp(mp(mp(mp(1,1),1),2),2),1));
            ret.pb(mp(mp(mp(mp(mp(1,1),1),2),2),2));
            ret.pb(mp(mp(mp(mp(mp(1,1),2),2),2),1));
        } else if (table[0][1]) {
            ret.pb(mp(mp(mp(mp(mp(2,2),1),2),2),1));
            ret.pb(mp(mp(mp(mp(mp(1,1),1),2),2),1));
            ret.pb(mp(mp(mp(mp(mp(1,1),1),2),2),2));
        } else if (table[1][0]) {
            ret.pb(mp(mp(mp(mp(mp(2,2),1),2),2),1));
            ret.pb(mp(mp(mp(mp(mp(1,1),1),2),2),1));
            ret.pb(mp(mp(mp(mp(mp(1,1),2),2),2),1));
        } else if (table[1][1]) {
            ret.pb(mp(mp(mp(mp(mp(2,2),1),2),2),1));
            ret.pb(mp(mp(mp(mp(mp(1,1),1),2),2),2));
            ret.pb(mp(mp(mp(mp(mp(1,1),2),2),2),1));
        }
        cout << ret.size() << endl;
        for (auto x : ret) {
            cout << x.f.f.f.f.f << " "
             << x.f.f.f.f.s << " "
              << x.f.f.f.s << " "
               << x.f.f.s << " "
                << x.f.s << " "
                 << x.s << endl;
        }
    }
}*/
