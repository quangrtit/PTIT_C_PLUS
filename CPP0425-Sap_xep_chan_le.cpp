#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin() + 1, a.begin() + n + 1);
        vector<int> b(n + 1);
        int ii = 1;
        for(int i = 1; i <= n; i += 2) {b[i] = a[ii]; ii++;}
        for(int i = 2; i <= n; i += 2) {b[i] = a[ii]; ii++;}
        for(int i = 1; i <= n; i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }
}