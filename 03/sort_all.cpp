#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define P -1

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if (nums.size()==0)//��ֹ����Ϊ��
            return -1;
        //����
        sort(nums.begin(),nums.end());
        //��ֵ�Ƿ񳬷�Χ
        if(nums[nums.size()-1]>=nums.size() || nums[0]<0)
            return -1;
        int i=1,flag = -1,change=1;
        while(i<nums.size())
        {
            if(nums[i-1]==nums[i])//���ڼ���һ��
            {
                if(change)//�ǵ�һ�γ��ֵ���ͬ
                {
                    change = 0;
                    cout<<nums[i]<<endl;
                }
                flag = 0;
            }
            else//ǰ��������ͬ
                change = 1;
            i++;
        }

        return flag;//û���ҵ�
    }
};

int main()
{
    Solution my_solution = Solution();
    int b[7]={2,3,1,3,2,5,3};
    vector<int> c(b,b+7);
    if(my_solution.findRepeatNumber(c)==-1)
        cout<<"error!"<<endl;
    return 0;
}
