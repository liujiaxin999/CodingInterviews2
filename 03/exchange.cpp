#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        //重排这个数组
        if (nums.size()==0)//防止输入为空
            return -1;
        //检查输入是否有越界
        int i=0;
        for(i=0;i<nums.size();i++)
            if(nums[i]<0 || nums[i]>=nums.size())
                return -1;
        int temp;
        i=0;
        while(i<nums.size())
        {
            if(nums[i]!=i)//不在自己的位置上
            {
                if(nums[i]==nums[nums[i]])//与在自己位置上的值相同直接找到
                    return nums[i];
                else//交换
                {
                    temp=nums[i];
                    nums[i]=nums[temp];
                    nums[temp]=temp;
                    //交换之后i还是指向原来的位置,但是值已经变成nums[nums[i]]
                }
            }
            else if(nums[i]==i)//就在自己的位置上
                i++;//下一个
        }
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
