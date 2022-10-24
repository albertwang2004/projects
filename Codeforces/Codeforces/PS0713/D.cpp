/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 1010
#define MOD 1000000007
#define INF 999999

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int N,M;
int DP[H][H];

int main() {
    scanf("%d%d",&N,&M);
    for (int i = 0; i <= N+1; i++) {
        for (int j = 0; j <= N+1; j++) {
            DP[i][j]=0;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d",DP[i]+j);
            if (DP[i][j]==1) DP[i][j]=1+min(DP[i-1][j],DP[i][j-1]);
        }
    }
}
*/
