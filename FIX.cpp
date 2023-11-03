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
#include<fstream>
#include<deque>
#include<stack>
using namespace std;
#define MOD 1000000007
#define endl '\n'
#define fast() ios::sync_with_stdio(false); cin.tie(0);
template <typename T>
class Segment_tree 
{
public:
    int size = 0;
    vector<T> tree;
    Segment_tree(){}
    Segment_tree(int n){tree.resize(4 * n + 4); size = n;}
    void build(vector<T> &a, int l, int r, int id);
    int get(int u, int v, int l, int r, int id);
    void update(vector<T> &a, int u, int v, int vtri, int l, int r, int id);
    ~Segment_tree(){}
};
template <typename T>
void Segment_tree <T> ::build(vector<T> &a, int l, int r, int id)
{
    if(l == r)
    {
        tree[id] = a[l]; return;
    }
    int mid = (l + r) / 2;
    build(a, l, mid, id * 2);
    build(a, mid + 1, r, id * 2 + 1);
    tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
}
int Find(int u, vector<int> &parent)
{
    if(u == parent[u])
    {
        return u;
    }
    return parent[u] = Find(parent[u], parent);
}
class vcl {
public: 
    double x;
    char ktu;
    bool check;
    vcl(){}
    vcl(double x, char ktu, bool check){this->x = x; this->ktu = ktu; this->check = check;}
};

double solve(vector<vcl> a)
{
    int ii = 0;
    vector<pair<int, int>> adress;
    vector<double> res; // luu ket qua cua cac bo so nhan hoac chia 
    while(ii < a.size())
    {
        if(a[ii].ktu == '*' || a[ii].ktu == ':')
        {
            double what = a[ii - 1].x;
            int jj = ii;
            while((a[jj].ktu == '*' || a[jj].ktu == ':') && jj < (int)a.size())
            {
                if(a[jj].ktu == '*')
                {
                    what *= a[jj + 1].x;
                }
                else if(a[jj].ktu == ':')
                {
                    what /= a[jj + 1].x;
                }
                jj += 2;
                if(jj >= a.size()) break;// lát quay lại kiểm tra 
            }
            adress.push_back({ii - 1, jj - 1});
            res.push_back(what);
            ii = jj;
        }
        else 
        {
            ii ++;
        }
    }
    adress.push_back({-1, -1});
    res.push_back(-1);
    reverse(adress.begin(), adress.end());
    reverse(res.begin(), res.end());
    double kq = 0;
    int k = 0;
    while(k < a.size())
    {
        if(k == 0)
        {
            if(k != adress.back().first) 
            {
                kq += a[k].x;
                k += 2; 
            }
            else 
            {
                kq += res.back(); res.pop_back();
                k = adress.back().second + 2; adress.pop_back();
            }
            continue;
        }
        if(k != adress.back().first)
        {
            if(a[k - 1].ktu == '+')
            {
                kq += a[k].x;
            }
            else if(a[k - 1].ktu == '-')
            {
                kq += 0 - a[k].x;
            }
            k += 2;
        }
        else 
        {
            if(a[k - 1].ktu == '+')
            {
                kq += res.back(); res.pop_back();
                k = adress.back().second + 2;
            }
            else if(a[k - 1].ktu == '-') 
            {
                kq += 0 - res.back(); res.pop_back();
                k = adress.back().second + 2; adress.pop_back();
            }
        }
    }
    return kq; 
}
void task2()
{
    char x;
    // vector<info> a;
    vector<char> a1;
    while(1)
    {
        cin >> x;
        if(x == '=') break;
        a1.push_back(x);
    }
    // chuan hoa a1
    int ii = 0;
    vector<char> a2;
    vector<double> hi;
    vector<vcl> res;
    while(ii < a1.size())
    {
        if(isdigit(a1[ii]))
        {
            int jj = ii;
            double tmp = 0;
            while(isdigit(a1[jj]) && jj < a1.size())
            {
                tmp = tmp * 10 + a1[jj] - '0';
                jj++;
            }
            if(a1[jj] == '.')
            {
                jj++; int cnt = -1;
                while(isdigit(a1[jj]) && jj < a1.size())
                {
                    tmp = tmp + (a1[jj] - '0') * (double)pow(10, cnt);
                    cnt--;
                    jj++;
                }
            }
            if(ii == 0)
            {
                res.push_back(vcl(tmp, '+', true));// neu check = true tuc la 1 so 
            }
            else 
            {
                res.push_back(vcl(tmp, '+', true));
            }
            ii = jj;
        }
        else if(a1[ii] == '-')
        {
            int jj = ii;
            int tru = 0;// dem so luong dau tru
            while(a1[jj] == '-' && jj < a1.size())
            {
                tru++; jj++;
            }
            while(a1[jj] == '+' && jj < a1.size())
            {
                jj++;
            }
            int ee = jj;
            double tmp = 0;
            while(isdigit(a1[ee]) && ee < a1.size())
            {
                tmp = tmp * 10 + a1[ee] - '0';
                ee++;
            }
            if(a1[ee] == '.')
            {
                ee++; int cnt = -1;
                while(isdigit(a1[ee]) && ee < a1.size())
                {
                    tmp = tmp + (a1[ee] - '0') * (double)pow(10, cnt);
                    cnt--;
                    ee++;
                }
            }
            if(ii - 1 >= 0)
            {
                if(!(a1[ii - 1] == ':' || a1[ii - 1] == '*')) res.push_back(vcl(0, '+', false));
            }
            res.push_back(vcl(tmp * pow(-1.0, tru % 2), '+', true)); 
            ii = ee;
        }
        else if(a1[ii] == '+')
        {
            int jj = ii;
            int tru = 0;// dem so luong dau tru
            while(a1[jj] == '+' && jj < a1.size())
            {
                jj++;
            }
            while(a1[jj] == '-' && jj < a1.size())
            {
                tru++;
                jj++;
            }
            int ee = jj;
            double tmp = 0;
            while(isdigit(a1[ee]) && ee < a1.size())
            {
                tmp = tmp * 10 + a1[ee] - '0';
                ee++;
            }
            if(a1[ee] == '.')
            {
                ee++; int cnt = -1;
                while(isdigit(a1[ee]) && ee < a1.size())
                {
                    tmp = tmp + (a1[ee] - '0') * (double)pow(10, cnt);
                    cnt--;
                    ee++;
                }
            }
            if(ii - 1 >= 0)
            {
                if(!(a1[ii - 1] == ':' || a1[ii - 1] == '*')) res.push_back(vcl(0, '+', false));
            }
            res.push_back(vcl(tmp * pow(-1.0, tru % 2), '+', true)); 
            ii = ee;
        }
        else if(a1[ii] == '*')
        {
            res.push_back(vcl(0, '*', false));
            ii++;
        }
        else if(a1[ii] == ':')
        {
            res.push_back(vcl(0, ':', false));
            ii++;
        }
    }
    // chuan hoa res gom cac class vcl
    cout << solve(res) << endl;
}
int main()
{
    fast();
    task2();
}
