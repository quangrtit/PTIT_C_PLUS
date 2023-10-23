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
using namespace std;
#define MOD 1000000007
#define endl '\n'
#define fast() ios::sync_with_stdio(false); cin.tie(0);

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<vector<char>> a(n + 1, vector<char>(n + 1));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
            }
        }       
        int hx = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                for(int d = 1; d <= n; d++)
                {
                    if(i + d - 1 <= n && j + d - 1 <= n)
                    {
                        bool check1 = true;// kiem tra vien
                        bool check2 = false;// kiem tra O
                        for(int i1 = i; i1 <= i + d - 1; i1++)
                        {
                            for(int j1 = j; j1 <= j + d - 1; j1++)
                            {
                                if(i1 == i || i1 == i + d - 1 || j1 == j || j1 == j + d - 1)
                                {
                                    if(a[i1][j1] != 'X') 
                                    {
                                        check1 = false; break;
                                    }
                                }
                                else 
                                {
                                    if(a[i1][j1] == 'O')
                                    {
                                        check2 = true;
                                    }
                                }
                            }
                        }
                        if(check1 == true)
                        {
                            hx = max(hx, d);
                        }
                    }
                }
            }
        }
        cout << hx << endl;
    }
}