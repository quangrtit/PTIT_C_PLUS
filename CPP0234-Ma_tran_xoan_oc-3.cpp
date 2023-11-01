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

void solve()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m, k; cin >> n >> m >> k;
        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        vector<int> res;
        int jj = m;
        int jj1 = 1;
        int ii = n;
        while(jj1 <= jj && jj1 <= ii)
        {
            if(jj1 == jj)
            {
                for(int i = jj1; i <= ii; i++)
                {
                    res.push_back(a[i][jj]);
                }
                break;
            }
            if(jj1 == ii)
            {
                for(int j = jj1; j <= jj; j++)
                {
                    res.push_back(a[jj1][j]);
                }
                break;
            }
            for(int j = jj1; j < jj; j++)
            {
                res.push_back(a[jj1][j]);
            }
            for(int i = jj1; i < ii; i++)
            {
                res.push_back(a[i][jj]);
            }
            for(int j = jj; j > jj1; j--)
            {
                res.push_back(a[ii][j]);
            }
            
            for(int i = ii; i > jj1; i--)
            {
                res.push_back(a[i][jj1]);
            }
            //cout << jj1 << " " << ii << " " << jj << endl;
            jj1++;
            jj--; ii--;     
        }
        
        cout << res[k - 1];
        cout << endl;
    }
}
int main()
{
    fast();
    solve();
}
