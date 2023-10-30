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

void answer()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<vector<int>> a(n + 1, vector<int>(n + 1));
        int row_max = 0, column_max = 0;
        int sum_all = 0;
        for(int i = 1; i <= n; i++)
        {
            int sum = 0;
            for(int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                sum += a[i][j];
                sum_all += a[i][j];
            }
            row_max = max(row_max, sum);
        }
        for(int i = 1; i <= n; i++)
        {
            int sum = 0;
            for(int j = 1; j <= n; j++)
            {
                sum += a[j][i];
            }
            column_max = max(column_max, sum);
        }
        cout << max(column_max, row_max) * n - sum_all << endl;
    }
}
int main()
{
    answer();
}