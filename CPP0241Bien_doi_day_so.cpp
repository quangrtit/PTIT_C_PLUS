#include<iostream>
#include<unistd.h>
#include<math.h>
#include<string>
#include<cctype>
#include<set>
#include<limits.h>
#include<map>
#include<queue>
#include<algorithm>
#include<iomanip>
using namespace std;
#define MOD 1000000007
#define endl '\n'
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}
void solve()
{
    int test; cin >> test;
    while(test--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int cnt = 0;
        int l = 0; int r = n - 1;
        while(l <= r)
        {
            if(a[l] == a[r])
            {
                l++;
                r--;
            }
            else if(a[l] < a[r])
            {
                l++;
                a[l] += a[l - 1];
                cnt++;
            }
            else if(a[l] > a[r])
            {
                r--;
                a[r] += a[r + 1];
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/