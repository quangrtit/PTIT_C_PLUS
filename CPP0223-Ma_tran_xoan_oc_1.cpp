// #include<iostream>
// #include<unistd.h>
// #include<math.h>
// #include<string>
// #include<cctype>
// #include<set>
// #include<limits.h>
// #include<map>
// #include<queue>
// #include<algorithm>
// #include<iomanip>
// using namespace std;
// #define MOD 1000000007
// #define endl '\n'
// void fast()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
// }
// template<typename T, typename X>
// int b_s(T valua, int l, int r, X z)
// {
//     while(l <= r)
//     {
//         int mid = (l + r) / 2;
//         if(valua[mid] == z)
//         {
//             return mid;
//         }
//         else if(valua[mid] < z)
//         {
//             l++;
//         }
//         else if(valua[mid] > z)
//         {
//             r--;
//         }
//     }
//     return -1;  
// }
// void segment_tree(int id, int l, int r, vector<int> &save, vector<int> demo)
// {
//     if(l == r)
//     {
//         save[id] = demo[l]; return;
//     }
//     int mid = (l + r) / 2;
//     segment_tree(2 * id, l, mid, save, demo);
//     segment_tree(2 * id + 1, mid + 1, r, save, demo);
//     //cout << id << save[2 * id] << save[2 * id + 1] << endl;
//     save[id] = min(save[2 * id], save[2 * id + 1]);
// }
// bool check(vector<int> a, int l, int r)
// {
//     if(l == r || l + 1 == r) return true;
//     int ii = r - 1;
//     while(a[ii] >= a[ii + 1])
//     {
//         ii--;
//     }
//     for(int i = l; i < ii; i++)
//     {
//         if(a[i] > a[i + 1])
//         {
//             return false;
//         }
//     }
//     return true;

// }
// void solve()
// {
//     int t; cin >> t;
//     while(t--)
//     {
//         int n, m; cin >> n >> m;
//         vector<vector<int>> a(n + 1, vector<int>(m + 1));
//         for(int i = 1; i <= n; i++)
//         {
//             for(int j = 1; j <= m; j++)
//             {
//                 cin >> a[i][j];
//             }
//         }
//         int ii = 1; int jj = 1;
//         int cnt = 0; int n1 = n, m1 = m;
//         while(m > 0 && n > 0)
//         {
//             for(int j = jj; j < jj + m - 1; j++)
//             {
//                 cout << a[ii][j] << " "; cnt++;
//             }
//             for(int i = ii; i < ii + n - 1; i++)
//             {
//                 cout << a[i][jj + m - 1] << " "; cnt++;
//             }
//             for(int j = jj + m - 1; j > jj; j--)
//             {
//                 cout << a[ii + n - 1][j] << " "; cnt++;
//             }
//             for(int i = ii + n - 1; i > ii; i--)
//             {
//                 cout << a[i][jj] << " "; cnt++;
//             }
//             ii++; jj++;
//             m -= 2; n -= 2;
//         }
//         // for(int i = 1; i <= n; i++)
//         // {
//         //     for(int j = 1; j <= m; j++)
//         //     {
//         //         cout << a[i][j] << " ";
//         //     }
//         //     cout << endl;
//         // }
//         // cout << cnt << endl;
//         // cout << ii << " " << jj << " " << cnt << endl;
//         if(cnt != m1 * n1) cout << a[ii - 1][jj - 1];
//         cout << endl;
//     }
// }

// int main()
// {
//     fast();
//     solve(); 
// }
// https://code.ptit.edu.vn/student/question/CPP0223
// MA TRẬN XOẮN ỐC - 1

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void TestCase()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int d = 0;
    int up = 0, down = n - 1;
    int left = 0, right = m - 1;
    while (1) {
        for (int i = left; i <= right; ++i) {
            cout << a[up][i] << " ";
            d++;
        }
        up++;
        if (d == n * m) break;

        for (int i = up; i <= down; ++i) {
            cout << a[i][right] << " ";
            d++;
        }
        right--;
        if (d == n * m) break;

        for (int i = right; i >= left; --i) {
            cout << a[down][i] << " ";
            d++;
        }
        down--;
        if (d == n * m) break;

        for (int i = down; i >= up; --i) {
            cout << a[i][left] << " ";
            d++;
        }
        left++;
        if (d == n * m) break;
    }
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--) TestCase();
    return 0;
}
/*AUTHOR: KHỔNG VĂN QUẢNG*/