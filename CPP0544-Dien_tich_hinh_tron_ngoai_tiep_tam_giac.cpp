#include<iostream>
#include<unistd.h>
#include<math.h>
#include<string>
#include<cctype>
#include<set>
#include<limits.h>
#include<map>
#include<queue>
#include<algorithm>
#include<iomanip>
using namespace std;
#define MOD 1000000007
#define endl '\n'
#define PI 3.141592653589793238
#define fast() ios::sync_with_stdio(false); cin.tie(0);

class triangle
{
public:
    double a, b, c;
    // triangle(double a, double b, double c){this->a = a; this->b = b; this->c = c;}
    friend istream& operator >> (istream& in, triangle& other)
    {
        in >> other.a >> other.b >> other.c;
        return in;
    }
    bool check()
    {
        if(!(a + b > c && a + c > b && b + c > a))
        {
            return false;
        }
        return true;
    }
    void solve()
    {
        if(this->check())
        {
            double S = 1.0 / 4 * sqrt((a + b + c) * (a + b - c) * (b + c - a) * (c + a - b));
            double R = a * b * c / (4 * S);
            double RS = PI * R * R;
            cout << setprecision(3) << fixed << RS << endl;
        }
        else 
        {
            cout << "INVALID" << endl;
        }
    }
};
int main()
{   
    fast();
    int t; cin >> t;
    while(t--)
    {
        triangle aa; 
        vector<pair<double, double>> x(7);
        for(int i = 1; i <= 3; i++)
        {
            cin >> x[i].first >> x[i].second;
        }
        double row1 = sqrt((x[1].first - x[2].first) * (x[1].first - x[2].first) + (x[1].second - x[2].second) * (x[1].second - x[2].second));
        double row2 = sqrt((x[1].first - x[3].first) * (x[1].first - x[3].first) + (x[1].second - x[3].second) * (x[1].second - x[3].second));
        double row3 = sqrt((x[3].first - x[2].first) * (x[3].first - x[2].first) + (x[3].second - x[2].second) * (x[3].second - x[2].second));
        aa.a = row1; aa.b = row2; aa.c = row3;
        aa.solve();
    }
}