/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 200100
#define MOD 1000000007
#define INF 999999

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N;
char buf[H];
int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&N);
        scanf("%s",buf);
        bool flag = !((buf[N-1]=='1')&&(buf[0]=='1'));
        while ((buf[N-1]=='1')&&(buf[0]=='1')) {
            int su = 0;
            int sx=0; int sy=0;
            vector<char> ansx;
            vector<char> ansy;
            for (int i = 0; i < N; i++) {
                su+=(int)(buf[i]-'0');
            }
            if (su%2) {
                flag = 1;
                break;
            }
            int su2 = 0;
            bool a = 0;
            for (int i = 0; i < N; i++) {
                if (buf[i]=='1') {
                    if (2*su2>=su) {
                        sx--; sy--;
                        ansx.pb(')');
                        ansy.pb(')');
                    } else {
                        sx++; sy++;
                        ansx.pb('(');
                        ansy.pb('(');
                    }
                } else {
                    if (a) {
                        sx++; sy--;
                        ansx.pb('(');
                        ansy.pb(')');
                    } else {
                        sx--; sy++;
                        ansx.pb(')');
                        ansy.pb('(');
                    }
                    a=!a;
                }
                su2+=(int)(buf[i]-'0');
            }

            cout << "YES\n";
            for (int i = 0; i < N; i++) {
                cout << ansx[i];
            }
            cout << endl;
            for (int i = 0; i < N; i++) {
                cout << ansy[i];
            }
            cout << endl;

            break;
        }
        if (flag) cout << "NO\n";
    }
}
*/
