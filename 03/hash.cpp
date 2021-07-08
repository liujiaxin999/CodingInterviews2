#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums)
    {
        if (nums.size()==0)//��ֹ����Ϊ��
            return -1;
        unordered_map<int,int> mp;//��¼Ԫ�ص�hashֵ������hashֵ�ж�Ԫ���Ƿ���ͬ
        //���ڹ�ϣ��ʵ��
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0 || nums[i]>=nums.size())
                return -1;
            if(mp.find(nums[i])!=mp.end())//˵��ԭ�������ҵ���
                return nums[i];//�����ظ�������
            else//��¼������һ��
                mp[nums[i]]++;
        }
        return -1;//˵��û���ҵ�
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
