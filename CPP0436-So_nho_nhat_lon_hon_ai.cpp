#include<iostream>
#include<unistd.h>
#include<math.h>
#include<string.h>
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
#define fast() ios::sync_with_stdio(false); cin.tie(0);

int main()
{
    fast();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());
        for(int i = 0; i < n; i++)
        {
            auto location = upper_bound(b.begin(), b.end(), a[i]);
            if(location != b.end())
            {
                cout << *location << " ";
            }
            else 
            {
                cout << "_" << " ";
            }
        }
        cout << endl;
    }
}