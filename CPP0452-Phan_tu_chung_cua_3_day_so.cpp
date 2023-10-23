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
#include<vector>
#include<deque>
using namespace std;
#define MOD 1000000007
#define endl '\n'
#define fast() ios::sync_with_stdio(false); cin.tie(0);

void task15()
{
    int t; cin >> t;
    while(t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        vector<long long> a(n1), b(n2), c(n3);
        for(int i = 0; i < n1; i++)
        {
            cin >> a[i];
        }
        for(int j = 0; j < n2; j++)
        {
            cin >> b[j]; 
        }
        for(int e = 0; e < n3; e++)
        {
            cin >> c[e];
        }
        vector<long long> result;
        int ii = 0, jj = 0, ee = 0;
        while(ii < n1 && jj < n2 && ee < n3)
        {
            if(a[ii] == b[jj] && b[jj] == c[ee])
            {
                result.push_back(a[ii]);
                ii++; jj++; ee++;
            }
            else if(a[ii] < b[jj])
            {
                ii++;
            }
            else if(b[jj] < c[ee])
            {
                jj++;
            }
            else
            {
                ee++;
            }
        }
        if(result.size() == 0)
        {
            cout << -1 << endl; continue;
        }
        for(auto x: result)
        {
            cout << x << " ";
        }
        cout << endl;
    }   
}
int main()
{
    fast();
    task15();
}