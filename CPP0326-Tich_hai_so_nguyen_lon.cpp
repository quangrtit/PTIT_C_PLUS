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

deque<int> sum_string(deque<int> a, deque<int> b)
{
    if(a.size() > b.size())
    {
        int cnt = a.size() - b.size();
        while(cnt--) b.push_front(0);
    }
    else if(a.size() < b.size())
    {
        int cnt = b.size() - a.size();
        while(cnt--) a.push_front(0);
    }
    int tmp = 0, n = a.size();
    deque<int> result(n);
    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] + b[i] + tmp < 10)
        {
            result[i] = a[i] + b[i] + tmp;
            tmp = 0;
        }
        else 
        {
            result[i] = a[i] + b[i] + tmp - 10;
            tmp = 1;
        }
    }
    if(tmp == 1) result.push_front(tmp);
    return result;
}
deque<int> product_string(deque<int> a, int p)
{
    int mod = 0;
    deque<int> result((int)a.size());
    for(int i = a.size() - 1; i >= 0; i--)
    {
        if(a[i] * p + mod < 10)
        {
            result[i] = a[i] * p + mod; mod = 0;
        }
        else 
        {
            result[i] = (a[i] * p + mod) % 10; mod = (a[i] * p + mod) / 10;
        }
    }
    if(mod != 0) result.push_front(mod);
    return result;
}
void p_deque(deque<int> a)
{
    for(auto x: a)
    {
        cout << x;
    }
    cout << endl;
}
int main()
{
    fast();
    int t; cin >> t;
    while(t--)
    {
        string a, b;
        cin >> a >> b;
        deque<int> d_a, d_b;
        for(int i = 0; i < a.size(); i++) d_a.push_back(a[i] - '0');
        for(int i = 0; i < b.size(); i++) d_b.push_back(b[i] - '0');
        deque<int> kq;
        for(int i = 0; i < d_b.size(); i++)
        {
            deque<int> tmp(d_b.size() - i, 0);
            tmp[0] = d_b[i];
            deque<int> q = product_string(d_a, tmp[0]);
            int x = d_b.size() - i - 1;
            while(x--)
            {
                q.push_back(0);
            }
            kq = sum_string(kq, q);
        }
        p_deque(kq);
    }
}