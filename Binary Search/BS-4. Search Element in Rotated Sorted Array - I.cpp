#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> nums = {
        4, 5, 6, 7, 0, 1, 2};
    int target = 3;
    int l = 0, r = nums.size() - 1;
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int a = nums[l], b = nums[mid], c = nums[r];
        cout << a << " " << b << " " << c << endl;
        if (a == target)
        {
            ans = l;
        }
        else if (b == target)
        {
            ans = mid;
        }
        else if (c == target)
        {
            ans = r;
        }

        if ((a < b and b > c) or (a > b and b < c))
        {
            if (a < b)
            {
                if (a <= target and target <= b)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (b <= target and target <= c)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        else
        {
            if (b <= target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}