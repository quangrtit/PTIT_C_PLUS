#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<math.h>

using namespace std;
class point_three
{
public:
    vector<pair<int, int>> xy;
    double S = 0;
    point_three(){xy.resize(4);}
    point_three(pair<int, int> a, pair<int, int> b, pair<int, int> c)
    {
        xy.resize(4);
        xy[1].first = a.first; xy[1].second = a.second;
        xy[2].first = b.first; xy[2].second = b.second;
        xy[3].first = c.first; xy[3].second = c.second;
    }
    void area()
    {
        double c1 = sqrt((xy[1].first - xy[2].first) * (xy[1].first - xy[2].first) + (xy[1].second - xy[2].second) * (xy[1].second - xy[2].second));
        double c2 = sqrt((xy[1].first - xy[3].first) * (xy[1].first - xy[3].first) + (xy[1].second - xy[3].second) * (xy[1].second - xy[3].second));
        double c3 = sqrt((xy[3].first - xy[2].first) * (xy[3].first - xy[2].first) + (xy[3].second - xy[2].second) * (xy[3].second - xy[2].second));
        S = 1.0 / 4 * sqrt((c1 + c2 + c3) * (c1 + c2 - c3) * (c1 + c3 - c2) * (c2 + c3 - c1));     
    }
};
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<pair<int, int>> tmp(n + 1);
        vector<point_three> result;
        for(int i = 1; i <= n; i++)
        {
            cin >> tmp[i].first >> tmp[i].second;
        }
        double sum_area = 0;
        for(int i = 3; i <= n; i++)
        {
            result.push_back(point_three(tmp[1], tmp[i - 1], tmp[i]));
            result[result.size() - 1].area();
            sum_area += result[result.size() - 1].S;
        }
        cout << setprecision(3) << fixed << sum_area << endl;
    }
}