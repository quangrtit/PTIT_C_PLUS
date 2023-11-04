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
struct vcl { 
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
    vector<pair<int, int>> demo1;
    vector<double> demo2;
    for(int i = adress.size() - 1; i >= 0; i--) demo1.push_back(adress[i]);
    for(int i = 0; i < demo1.size(); i++) adress[i] = demo1[i];
    for(int i = res.size() - 1; i >= 0; i--) demo2.push_back(res[i]);
    for(int i = 0; i < demo2.size(); i++) res[i] = demo2[i];
    // reverse(adress.begin(), adress.end());
    // reverse(res.begin(), res.end());
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
void compact(vector<char> &a1, vector<vcl> &a)
{
    int ii = 0;
    while(ii < a1.size())
    {
        if(isdigit(a1[ii]))
        {
            int jj = ii;
            double tmp = 0;
            if(jj < a1.size())
            {
                while(isdigit(a1[jj]) && jj < a1.size())
                {
                    tmp = tmp * 10 + a1[jj] - '0';
                    jj++; if(jj >= a1.size()) break;
                }
            }
            if(jj < a1.size())
            {
                if(a1[jj] == '.')
                {
                    jj++; int cnt = -1;
                    if(jj < a1.size())
                    {
                        while(isdigit(a1[jj]) && jj < a1.size())
                        {
                            tmp = tmp + (a1[jj] - '0') * (double)pow(10, cnt);
                            cnt--;
                            jj++; if(jj >= a1.size()) break;
                        }
                    }
                }
            }
            if(ii == 0)
            {
                a.push_back(vcl(tmp, '+', true));// neu check = true tuc la 1 so 
            }
            else 
            {
                a.push_back(vcl(tmp, '+', true));
            }
            ii = jj;
        }
        else if(a1[ii] == '-')
        {
            int jj = ii;
            int tru = 0;// dem so luong dau tru
            if(jj < a1.size())
            {
                while(a1[jj] == '-' && jj < a1.size())
                {
                    tru++; jj++; if(jj >= a1.size()) break;
                }
            }
            if(jj < a1.size())
            {
                while(a1[jj] == '+' && jj < a1.size())
                {
                    jj++; if(jj >= a1.size()) break;
                }
            }
            int ee = jj;
            double tmp = 0;
            if(ee < a1.size())
            {
                while(isdigit(a1[ee]) && ee < a1.size())
                {
                    tmp = tmp * 10 + a1[ee] - '0';
                    ee++; if(ee >= a1.size()) break;
                }
            }
            if(ee < a1.size())
            {
                if(a1[ee] == '.')
                {
                    ee++; int cnt = -1;
                    if(ee < a1.size())
                    {
                        while(isdigit(a1[ee]) && ee < a1.size())
                        {
                            tmp = tmp + (a1[ee] - '0') * (double)pow(10, cnt);
                            cnt--;
                            ee++; if(ee >= a1.size()) break;
                        }
                    }
                }
            }
            if(ii - 1 >= 0)
            {
                if(!(a1[ii - 1] == ':' || a1[ii - 1] == '*')) a.push_back(vcl(0, '+', false));
            }
            a.push_back(vcl(tmp * pow(-1.0, tru % 2), '+', true)); 
            ii = ee;
        }
        else if(a1[ii] == '+')
        {
            int jj = ii;
            int tru = 0;// dem so luong dau tru
            if(jj < a1.size())
            {
                while(a1[jj] == '+' && jj < a1.size())
                {
                    jj++; if(jj >= a1.size()) break;
                }
            }
            if(jj < a1.size())
            {
                while(a1[jj] == '-' && jj < a1.size())
                {
                    tru++;
                    jj++; if(jj >= a1.size()) break;
                }
            }
            int ee = jj;
            double tmp = 0;
            if(ee < a1.size())
            {
                while(isdigit(a1[ee]) && ee < a1.size())
                {
                    tmp = tmp * 10 + a1[ee] - '0';
                    ee++; if(ee >= a1.size()) break;
                }
            }
            if(ee < a1.size())
            {
                if(a1[ee] == '.')
                {
                    ee++; int cnt = -1;
                    if(ee < a1.size())
                    {
                        while(isdigit(a1[ee]) && ee < a1.size())
                        {
                            tmp = tmp + (a1[ee] - '0') * (double)pow(10, cnt);
                            cnt--;
                            ee++; if(ee >= a1.size()) break;
                        }
                    }
                }
            }
            if(ii - 1 >= 0)
            {
                if(!(a1[ii - 1] == ':' || a1[ii - 1] == '*')) a.push_back(vcl(0, '+', false));
            }
            a.push_back(vcl(tmp * pow(-1.0, tru % 2), '+', true)); 
            ii = ee;
        }
        else if(a1[ii] == '*')
        {
            a.push_back(vcl(0, '*', false));
            ii++;
        }
        else if(a1[ii] == ':')
        {
            a.push_back(vcl(0, ':', false));
            ii++;
        }
    }
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
    vector<vcl> a;
    compact(a1, a);
    // chuan hoa a gom cac class vcl
    cout << solve(a) << endl;
}
bool check(string s, int l, int r)
{
    for(int i = l; i <= r; i++)
    {
        if(s[i] == ')' || s[i] == '(') return false;
    }
    return true;
}
int finx(int i, string s)
{
    for(int j = i; j < s.size(); j++)
    {
        if(s[j] == ')')
        {
            return j;
        }
    }
    return 0;
}
void task3()
{
    char x; 
    vector<char> a;
    vector<vcl> res;
    int close = 0, open = 0;
    while(1)
    {
        cin >> x;
        if(x == '=') break;
        a.push_back(x);
        if(x == '(') open++;
        else if(x == ')') close++;
    }
    vector<pair<char, int>> info;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == '(')
        {
            info.push_back({'(', i});
        }
        else if(a[i] == ')')
        {
            info.push_back({')', i});
        }
    }
    if(info.empty())
    {
        cout << "chuyen qua phuong an 1: \n";
        return;
    }
    stack<pair<int, int>> st;
    map<int, int> vtri;// luu vi tri cua cac cap ngoac
    for(int i = 0; i < info.size(); i++)
    {   
        if(st.empty())
        {
            st.push({info[i].first, info[i].second});
        }
        else 
        {
            if(st.top().first == '(' && info[i].first == ')')
            {
                vtri[st.top().second] = info[i].second;
                st.pop();
            }
            else 
            {
                st.push({info[i].first, info[i].second});
            }
        }
    }
    vector<char> b;
    string s = ""; 
    for(int i = 0; i < a.size(); i++)
    {
        s += a[i];
    }

    while(!check(s, 0, (int)s.size() - 1))
    {
        int i = 0;
        for(int i = 0; i < s.size() - 1; i++)
        {
            if(finx(i, s) != 0)
            {
                if(check(s, i + 1, finx(i, s) - 1))// kiem tra trong cap ngoac do co ton tai cap ngoac nao khac khong
                {
                    //cout << "1000000" << endl; return;
                    vector<char> att; 
                    vector<vcl> btt;
                    for(int j = i + 1; j <= finx(i, s) - 1; j++) att.push_back(s[j]);
                    compact(att, btt);
                    double c1 = solve(btt);
                    string ye = to_string(c1);// ket qua cua gia tri trong dau ngoac
                    string tmp1 = "";
                    int jj = 0; 
                    while(jj < s.size())
                    {
                        if(jj < i) {tmp1 += s[jj]; jj++;}
                        else if(jj >= i && jj <= finx(i, s)) 
                        {
                            for(int e = 0; e < ye.size(); e++) tmp1 += ye[e];
                            jj = finx(i, s) + 1;
                        }
                        else {tmp1 += s[jj]; jj++;}
                    }
                    s = tmp1;
                    cout << s << endl;
                    cout << "stt: "  << c1 << endl; 
                    //cout << c1 << " " << i << " " << vtri[i] << endl; return;
                    break;
                }
            }
        }
    }
}
void tn()
{
    double x = -4.514522;
    string s = to_string(x);
    for(auto x: s) cout << x << " ";
}
int main()
{
    fast();
    task3();
}
