#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if (nums.size()==0)//防止输入为空
            return -1;
        //快排
        sort(nums.begin(),nums.end());
        if(nums[nums.size()-1]>=nums.size() || nums[0]<0)
            return -1;
        for(int i=1;i<nums.size();i++)
            if(nums[i-1]==nums[i])//相邻两个一样
                return nums[i];
        return -1;//没有找到
    }
};

int main()
{
    Solution my_solution = Solution();
    int b[7]={2,3,1,0,2,5,3};
    vector<int> c(b,b+7);
    cout << my_solution.findRepeatNumber(c) << endl;
    return 0;
}
