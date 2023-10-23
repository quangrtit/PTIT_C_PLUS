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
using namespace std;
#define MOD 1000000007
#define endl '\n'
#define fast() ios::sync_with_stdio(false); cin.tie(0);

void p_deque(deque<int> dp)
{
    for(auto x: dp)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
    fast();
    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            //cin >> b[i];
        }
        deque<int> dp;
        dp.push_back(0);
        for(int i = 1; i < n; i++)
        {
            // cout << i << ": ";
            // p_deque(dp);
            while(a[dp.back()] <= a[i])
            {
                dp.pop_back();
                if(dp.empty()) break;
            }
            dp.push_back(i);
            if(dp.front() + k <= i)
            {
                dp.pop_front();
            }
            if(i >= k - 1) cout << a[dp.front()] << " ";
        }
        cout << endl;
    }
}
// deque lưu vị trí chú ý nếu gặp a[back] <= a[i] loại bỏ back nhé
//Liệu rằng phần tử cuối cùng trong hàng đợi kia còn ý nghĩa gì trong việc tính giá trị nhỏ nhất nữa không?
// Câu trả lời là không =))
// Vì nó đã không phải là giá trị nhỏ nhất trong đoạn [i−k+1…i]
//  rồi thì càng không thể là giá trị nhỏ nhất trong đoạn [(i+1)−k+1…i+1]
// Vì vậy ta sẽ loại bỏ tất cả các phần tử cuối cùng trong deque nếu nó có giá trị lớn hơn hoặc bằng giá trị A[i]
//  đang xét.