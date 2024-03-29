#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n,k;
int a[maxn];
int ans[maxn];


int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n >> k;
        for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
        sort(a+1,a+1+n);
        int maxx = 1;
        for ( int i = 2 ; i <= n ; i++ ) {
            int cnt = 1;
            while(i <= n && a[i]-a[i-1] <= k) {
                cnt++;
                i++;
            }
            maxx = max(maxx,cnt);
        }
        ans[cas] = n - maxx;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}