#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        //�����������
        if (nums.size()==0)//��ֹ����Ϊ��
            return -1;
        //��������Ƿ���Խ��
        int i=0;
        for(i=0;i<nums.size();i++)
            if(nums[i]<0 || nums[i]>=nums.size())
                return -1;
        int temp;
        i=0;
        while(i<nums.size())
        {
            if(nums[i]!=i)//�����Լ���λ����
            {
                if(nums[i]==nums[nums[i]])//�����Լ�λ���ϵ�ֵ��ֱͬ���ҵ�
                    return nums[i];
                else//����
                {
                    temp=nums[i];
                    nums[i]=nums[temp];
                    nums[temp]=temp;
                    //����֮��i����ָ��ԭ����λ��,����ֵ�Ѿ����nums[nums[i]]
                }
            }
            else if(nums[i]==i)//�����Լ���λ����
                i++;//��һ��
        }
        return -1;//û���ҵ�
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
