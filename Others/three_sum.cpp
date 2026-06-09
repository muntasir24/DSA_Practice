#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int n = nums.size();

    vector<vector<int>> st;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 and nums[i] == nums[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {

            if (nums[i] + nums[j] + nums[k] == 0)
            {
                
                st.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (j < k and nums[j] == nums[j - 1])
                    j++;
                while (j < k and nums[k] == nums[k + 1])
                    k--;
            }
            else if (nums[i] + nums[j] + nums[k] < 0)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    for (auto u : st)
        cout << u[0] << " " << u[1] << " " << u[2] << endl;

    return 0;
}