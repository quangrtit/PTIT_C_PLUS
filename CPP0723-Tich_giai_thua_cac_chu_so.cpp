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
    int t; cin >> t;
    vector<pair<int, vector<int>>> v = {{9, {7, 3, 3, 2}}, {8, {7, 2, 2, 2}}, {6, {5, 3}}, {4, {3, 2, 2}}};
    while(t--)
    {
        int n; cin >> n;
        string a; cin >> a;
        vector<int> result;
        for(int i = 0; i < n; i++)
        {
            if(a[i] != '1' && a[i] != '0')
            {
                if(a[i] == '9')
                {
                    result.push_back(7); 
                    result.push_back(3);
                    result.push_back(3);
                    result.push_back(2);
                }
                else if(a[i] == '8')
                {
                    result.push_back(7);
                    result.push_back(2);
                    result.push_back(2);
                    result.push_back(2);
                }
                else if(a[i] == '6')
                {
                    result.push_back(5);
                    result.push_back(3);
                }
                else if(a[i] == '4')
                {
                    result.push_back(3);
                    result.push_back(2);
                    result.push_back(2);
                }
                else 
                {
                    result.push_back(a[i] - '0');
                }
            }
        }
        sort(result.begin(), result.end(), greater<int>());
        for(auto x: result)
        {
            cout << x;
        }
        cout << endl;
    }
}