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
template<typename T, typename X>
int b_s(T valua, int l, int r, X z)
{
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(valua[mid] == z)
        {
            return mid;
        }
        else if(valua[mid] < z)
        {
            l++;
        }
        else if(valua[mid] > z)
        {
            r--;
        }
    }
    return -1;  
}
class ptit
{
public:
    int t; 
    ptit(){};
    friend istream& operator>>(istream& in, ptit &other)
    {
        in >> other.t;
        return in;
    }
    void menu()
    {
        while(t--)
        {
            int n; cin >> n;
            vector<int> a(n);
            for(int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            long long check_min = abs(a[0] + a[1]);
            long long check_minz = a[0] + a[1];
            for(int i = 0; i < n; i++)
            {
                for(int j = i + 1; j < n; j ++)
                {
                    if(abs(a[j] + a[i]) < check_min)
                    {
                        check_min = abs(a[j] + a[i]);
                        check_minz = a[j] + a[i];
                    }
                }
            }
            cout << check_minz << endl;
            
        }
    } 
    ~ptit(){}
};
void solve()
{
    ptit a;
    cin >> a;
    a.menu();
}
int main()
{
    fast();
    solve(); 
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/