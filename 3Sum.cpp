#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Sort the input vector in non-descending order
        int n = nums.size();

        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            { // Avoid duplicates
                int j = i + 1, k = n - 1;
                while (j < k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0)
                    {
                        result.push_back({nums[i], nums[j], nums[k]});
                        while (j < k && nums[j] == nums[j + 1])
                            j++; // Avoid duplicates
                        while (j < k && nums[k] == nums[k - 1])
                            k--; // Avoid duplicates
                        j++;
                        k--;
                    }
                    else if (sum < 0)
                    {
                        j++;
                    }
                    else
                    {
                        k--;
                    }
                }
            }
        }
        return result;
    }
};

// helper function to print a vector of vectors
void printVector(vector<vector<int>> &vec)
{
    for (auto v : vec)
    {
        cout << "[ ";
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << "]" << endl;
    }
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int>> result = s.threeSum(nums);
    printVector(result);
    return 0;
}
