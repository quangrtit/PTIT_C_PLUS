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
// template <typename T>
// class Segment_tree 
// {
// public:
//     int size = 0;
//     vector<T> tree;
//     Segment_tree(){}
//     Segment_tree(int n){tree.resize(4 * n + 4); size = n;}
//     void build(vector<T> &a, int l, int r, int id);
//     int get(int u, int v, int l, int r, int id);
//     void update(vector<T> &a, int u, int v, int vtri, int l, int r, int id);
//     ~Segment_tree(){}
// };
// template <typename T>
// void Segment_tree <T> ::build(vector<T> &a, int l, int r, int id)
// {
//     if(l == r)
//     {
//         tree[id] = a[l]; return;
//     }
//     int mid = (l + r) / 2;
//     build(a, l, mid, id * 2);
//     build(a, mid + 1, r, id * 2 + 1);
//     tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
// }
// struct info {
//     int l, r, x; 
// };
// int Find(int u, vector<int> &parent)
// {
//     if(u == parent[u])
//     {
//         return u;
//     }
//     return parent[u] = Find(parent[u], parent);
// }

int solve(vector<int> a)
{
    vector<int>
}
void TASK_A()
{
    string s; cin >> s;
    vector<int> a;
    for(int i = 0; i < s.size(); i++)
    {
        a.push_back(s[i]);
    }
    cout << solve(a);
    // stack<char> st;
    // st.push(s[0]);
    // int ii = 1;
    // vector<int> tmp;
    // while(!st.empty())
    // {   
    //     if(s[ii] == '(')
    //     {
    //         st.push(s[ii]); ii++;
    //     }
    //     else if(s[ii] == ')')
    //     {
    //         st.pop();
    //     }
    // }
}
int main()
{
    fast();
    TASK_A();
}
