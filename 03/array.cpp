#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums)
    {
        if (nums.size()==0)//��ֹ����Ϊ��
            return -1;

        vector<int> tmp(nums.size(),0);
        //���ڹ�ϣ��ʵ��
        for(int i=0;i<nums.size();i++)
        {
            //��ֵ����Χ
            if(nums[i]<0 || nums[i]>=nums.size())
                return -1;
            tmp[nums[i]]++;
        }
        int flag=0;
        for(int i=0;i<tmp.size();i++)
        {
            if(tmp[i]>1)
            {
                cout<<i<<endl;
                flag=1;
            }
        }
        if(flag==1)
            return 0;//˵���ҵ�
        else
            return -1;//û���ظ���
    }
};

int main()
{
    Solution my_solution = Solution();
    int b[7]={2,3,1,0,2,5,3};
    vector<int> c(b,b+7);
    if(my_solution.findRepeatNumber(c)==-1)
        cout<<"error!"<<endl;
    return 0;
}
