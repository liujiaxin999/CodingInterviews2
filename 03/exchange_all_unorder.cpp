#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define P -1

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
        int temp,flag=-1;
        i=0;
        //从头到尾遍历
        while(i<nums.size())
        {
            if(nums[i]!=i&&nums[i]!=P)//不在自己的位置上且不是已经找到重复的
            {
                if(nums[i]==nums[nums[i]])//与在自己位置上的值相同
                {
                    cout<<nums[i]<<endl;
                    nums[nums[i]]=P;
                    flag=0;
                    i++;
                }
                else if(nums[nums[i]]!=P)//交换
                {
                    temp=nums[i];
                    nums[i]=nums[temp];
                    nums[temp]=temp;
                    //交换之后i还是指向原来的位置,但是值已经变成nums[nums[i]]
                }
                else//不相等而且交换位置上为P=》说明已经重复
                    i++;
            }
            else //就在自己的位置上 或者 当前位置上元素为P
                i++;//下一个
        }
        return flag;
    }
};

int main()
{
    Solution my_solution = Solution();
    //int b[7]={2,3,1,3,2,5,3};
    int b[7]={2,3,3,3,2,3,3};
    vector<int> c(b,b+7);
    if(my_solution.findRepeatNumber(c)==-1)
        cout<<"error!"<<endl;
    return 0;
}
