/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 100100
#define MOD 1000000007
#define INF 999999

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;


int T,N;
int main() {
    scanf("%d",&T);
    while (T--) {
vector<double> diamond;
vector<double> mine;
        scanf("%d",&N);
        for (int i = 0; i < 2*N; i++) {
            int x, y; scanf("%d%d",&x, &y);
            if (x) mine.pb(abs(x));
            else diamond.pb(abs(y));
        }
        sort(diamond.begin(),diamond.end());
        sort(mine.begin(),mine.end());
        double ret = 0.0;
        for (int i = 0; i < N; i++) {
            ret += sqrt(diamond[i]*diamond[i]+mine[i]*mine[i]);
        }
        cout << setprecision(15) << ret << endl;
    }
}*/
