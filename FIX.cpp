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
using namespace std;
#define MOD 1000000007
#define endl '\n'
#define fast() ios::sync_with_stdio(false); cin.tie(0);

int fin(int u, vector<int> &parent)
{
    if(u == parent[u])
    {
        return u;
    }
    return parent[u] = fin(parent[u], parent);
}
void uni(int u, int v, vector<int> &parent, vector<int> &size)
{
    int x = fin(u, parent);
    int y = fin(v, parent);
    if(x == y) return;
    if(size[x] >= size[y])
    {
        parent[y] = x;
        size[x] += size[y];
    }
    else 
    {
        parent[x] = y;
        size[y] += size[x];
    }
}
void DFS(int start, int begin, int end, vector<vector<int>> &a, vector<bool> &vs, int &cnt)
{
    cnt++;
    vs[start] = true;
    for(int i = 0; i < a[start].size(); i++)
    {
        if(!vs[a[start][i]] && !(start == begin && a[start][i] == end))
        {
            DFS(a[start][i], begin, end, a, vs, cnt);
        }
    }
}
void TASK_A()
{
    int n; cin >> n;
    vector<vector<int>> a(n + 1);
    vector<int> parent(n + 1), size(n + 1, 1);
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
    vector<pair<int, int>> save;
    for(int i = 1; i <= n - 1; i++)
    {
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        if(tmp1 > tmp2) swap(tmp1, tmp2);
        save.push_back({tmp1, tmp2});
        a[tmp1].push_back(tmp2);
        a[tmp2].push_back(tmp1);
        uni(tmp1, tmp2, parent, size);
    }
    // luu cac dinh ko lien thong
    map<int, int> mp;
    vector<int> no;
    for(int i = 1; i <= n; i++)
    {
        mp[parent[i]]++;
    }
    for(auto x: mp)
    {
        no.push_back(x.first);
    }
    // tim kiem cac canh khong phai la canh cau 
    cout << no.size() - 1 << endl;
    vector<pair<int, int>> yes;
    // danh dau cac canh ko phai canh cau da duoc xoa
    map<int, int> mp_e;
    for(int i = 0; i < save.size(); i++)
    {
        vector<int> pa(n + 1), si(n + 1, 1);
        for(int j = 1; j <= n; j++)
        {
            pa[j] = j;
            si[j] = 1;
        }
        for(int j = 0; j < save.size(); j++)
        {
            if(mp_e[j] == 0 && j != i) uni(save[j].first, save[j].second, pa, si);
        }
        map<int, int> mp_check;
        for(int j = 1; j <= n; j++)
        {
            mp_check[pa[j]]++;
        }
        // for(int j = 1; j <= n; j++)
        // {
        //     cout << pa[j] << " ";
        // }
        // cout << endl;
        if(mp_check.size() == mp.size())
        {
            mp_e[i]++;
            yes.push_back({save[i].first, save[i].second});
        }
    }
}
struct NODE {
    NODE* l;
    NODE* r;
    int value;
};
NODE* makenode(NODE* a)
{
    a = new NODE;
    a->l = NULL;
    a->r = NULL;
    return a;
}
void update(NODE* &a, int x)
{
    // NODE* b = new NODE;
    // b = a;
    if(a == NULL)
    {
        a = new NODE;
        a->value = x;
        a->l = NULL;
        a->r = NULL;
        return;
    }
    if(a->value >= x)
    {
        update(a->l, x);
    }
    else if(a->value < x)
    {
        update(a->r, x);
    }
}
int find_min(NODE* a)
{
    if(a == NULL)
    {
        return -1;
    }
    if(a->l == NULL)
    {
        return a->value;
    }
    find_min(a->l);
}
int find_max(NODE* a)
{
    if(a == NULL)
    {
        return -1;
    }
    if(a->r == NULL)
    {
        return a->value;
    }
    find_max(a->r);
}
void era_l(NODE* &a)
{
    if(a == NULL)
    {
        return;
    }
    if(a->l == NULL)
    {
        a = NULL;
        return;
    }
    era_l(a->l);
}
void era_r(NODE* &a)
{
    if(a == NULL)
    {
        return;
    }
    if(a->r == NULL)
    {
        a = NULL;
        return;
    }
    era_r(a->r);
}
bool find(NODE* a, int x)
{
    if(a == NULL)
    {
        return false;
    }
    if(a->value == x)
    {
        return true;
    }
    if(a->value < x)
    {
        find(a->r, x);
    }
    else if(a->value > x)
    {
        find(a->l, x);
    }
    return false;
}
void pr(NODE* a)
{
    if(a == NULL) return;
    cout << a->value << endl;
    pr(a->l);
    pr(a->r);
}
void TASK_C()
{
    NODE* a = NULL;
    for(int i = 0; i <= 9; i++)
    {
        update(a, i);
    }
    //pr(a);
    int n; cin >> n;
    vector<int> res(10, 0);
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'L')
        {
            res[find_min(a)] = 1;
            NODE* b = a;
            era_l(b);
        }
        else if(s[i] == 'R')
        {
            res[find_max(a)] = 1;
            NODE* b = a;
            era_r(b);
        }
        else 
        {
            res[s[i] - '0'] = 0;
            if(find(a, s[i] - '0') == false) update(a, s[i] - '0');
        }
        cout << "ok\n";
        pr(a);
        cout << "ok\n";
    }
    for(auto x: res)
    {
        cout << x;
    }
    cout << endl;
    // update(a, 2);
    // update(a, 100);
    // update(a, 10);
    // update(a, 5);
    // update(a, -1);
    // pr(a);
    // NODE* b = a;
    // era_l(b);
    // cout << "ok\n";
    // pr(a);
    // era_r(a);
    // cout << "ok\n";
    // pr(a);
}
int main()
{
    TASK_C();
}
