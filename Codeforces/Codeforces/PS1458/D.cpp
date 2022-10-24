/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 501000
#define MOD 1000000007
#define INF 9999999999

using namespace std;
typedef long long int LL;

int T,N;
char buf[H];
vector<vector<int>> A;
int adj[2*H]; // adj[i] rep num edge to adj[i+1]

int main() {
    scanf("%d",&T);
    for (int i = 0; i < 2*H; i++) adj[i]=0;
    //T=1;
    while (T--) {scanf("%s",buf);
        int N = strlen(buf);
        int b = H;
        for (int i = 0; i < N; i++) {
            if (buf[i]=='0') {
                adj[b-1]++;
                b--;
            } else {
                adj[b]++;
                b++;
            }
        }
        //for (int i = 0; i < 2*H; i++) {
        //    if (adj[i]) {
        //        cout << i-H << " " << adj[i] << endl;
        //    }
        //}
        //cout << N << " HI " << endl;
        int curr = H;
        for (int i = 0; i < N; i++) {
            if ((adj[curr]>0) && (adj[curr-1]==1)) {
                    adj[curr]--;
                    curr++;
                    cout << "1";

            } else if (adj[curr-1]>0) {adj[curr-1]--;
                curr--;
                cout << "0";
            } else {
                adj[curr]--;
                curr++;
                cout << "1";
            }
        }
        cout << endl;
    }
    return 0;
}
*/
