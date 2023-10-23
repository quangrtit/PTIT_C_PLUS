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
#define MIN = LLONG_MIN
#define MAX = LLONG_MAX
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}
void merge(int a[], int l, int r, int mid)
{
    vector<int> v1(a + l, a + mid + 1);
    vector<int> v2(a + mid + 1, a + r + 1);
    int ii = 0, jj = 0;
    while(ii < v1.size() && jj < v2.size())
    {
        if(v1[ii] < v2[jj])
        {
            a[l] = v1[ii];
            ii++; l++;
        }
        else if(v1[ii] > v2[jj])
        {
            a[l] = v2[jj];
            jj++; l++;
        }
        else 
        {
            a[l] = v1[ii];l++;
            a[l] = v2[jj];
            ii++; jj++; l++;
        }
    }
    if(ii < v1.size())
    {
        for(int i = ii; i < v1.size(); i++)
        {
            a[l] = v1[i]; l++;
        }
    }
    if(jj < v2.size())
    {
        for(int i = jj; i < v2.size(); i++)
        {
            a[l] = v2[i]; l++;
        }
    }
}
void merge_sort(int a[], int l, int r)
{
    if(l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    merge(a, l, r, mid);
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
            int a[n];
            for(int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            merge_sort(a, 0, n - 1);
            for(int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
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