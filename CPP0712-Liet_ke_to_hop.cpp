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
void back_track(int j, vector<int> &a, int k, int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(a[j - 1] < i)
        {
            a[j] = i;
            if(j == k)
            {
                for(int e = 1; e <= k; e++)
                {
                    cout << a[e];
                }
                cout << " ";
            }
            else 
            {
                back_track(j + 1, a, k, n);
            }
        }
    }
}
void solve()
{
    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<int> a(n + 1);
        a[0] = -1;
        back_track(1, a, k, n);
        cout << endl;
    }   
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/