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
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, soHang, soCot, vtHang, vtCot, cnt = 1;
        cin >> n >> m;
        int a[n][m];
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
        int ans[n * m], idx = n * m - 1;
        soHang = n;
        soCot = m;
        vtHang = vtCot = 0;
        while(cnt <= m * n)
        {
            for(int i = vtCot; i < soCot; i++)
            {
                ans[idx] = a[vtHang][i];
                cnt++;
                idx--;
            }
            for(int i = vtHang + 1; i < soHang; i++)
            {
                ans[idx] = a[i][soCot - 1];
                cnt++;
                idx--;
            }
            for(int i = soCot - 2; i >= vtCot; i--)
            {
                ans[idx] = a[soHang - 1][i];
                cnt++;
                idx--;
            }
            for(int i = soHang - 2; i > vtHang; i--)
            {
                ans[idx] = a[i][vtCot];
                cnt++;
                idx--;
            }
            vtHang++;
            vtCot++;
            soHang--;
            soCot--;
        }
        for(int i = 0; i < n * m; i++) cout << ans[i] << ' ';
        cout << endl;
    }
}
int main()
{
    fast();
    solve();
}
