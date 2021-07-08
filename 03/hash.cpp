#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums)
    {
        if (nums.size()==0)//防止输入为空
            return -1;
        unordered_map<int,int> mp;//记录元素的hash值，根据hash值判断元素是否相同
        //基于哈希表实现
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0 || nums[i]>=nums.size())
                return -1;
            if(mp.find(nums[i])!=mp.end())//说明原来中有找到了
                return nums[i];//返回重复的数字
            else//记录下来过一次
                mp[nums[i]]++;
        }
        return -1;//说明没有找到
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
