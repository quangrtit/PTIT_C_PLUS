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
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> b(a.begin(), a.end());
        sort(a.begin(), a.end());
        int ii = 0; int jj = n - 1;
        while(1)
        {
            if(a[ii] == b[ii])
            {
                ii++;
            }
            if(a[jj] == b[jj])
            {
                jj--;
            }
            if(a[ii] != b[ii] && a[jj] != b[jj])
            {
                break;
            }
        }
        cout << ii + 1 << " " << jj + 1 << endl;
    }   
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/