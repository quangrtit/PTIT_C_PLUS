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
void task1()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<long long> a(n + 1);
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[1] = 0;
        for(int i = 2; i <= n; i++)
        {
            dp[i] = LLONG_MAX;
            for(int j = 1; j < i; j++)
            {
                if(i - j <= a[j])
                {
                    dp[i] = min(dp[j] + 1, dp[i]);
                }
            }
        }
        cout << dp[n] << endl;
    }
}
int main()
{
    fast();
    task1();
}
