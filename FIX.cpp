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
struct info {
    int l, r, x; 
};
int Find(int u, vector<int> &parent)
{
    if(u == parent[u])
    {
        return u;
    }
    return parent[u] = Find(parent[u], parent);
}
void TASK_A()
{
    int n, m; cin >> n >> m;
    vector<info> a(m + 1);
    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i].l >> a[i].r >> a[i].x;
        int begin = Find(a[i].l, parent);// tim hiep si dau tien con song trong cac hiep si tu l den r
        while(begin <= a[i].r)
        {
            if(parent[begin] == begin && begin != a[i].x)
            {
                parent[begin] = a[i].x;
            }
            begin = Find(begin, parent);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(parent[i] != i) cout << parent[i] << " ";
        else cout << 0 << " ";
    }
    cout << endl;
}
int main()
{
    fast();
    TASK_A();
}
