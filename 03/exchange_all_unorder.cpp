#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define P -1

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
        int temp,flag=-1;
        i=0;
        //��ͷ��β����
        while(i<nums.size())
        {
            if(nums[i]!=i&&nums[i]!=P)//�����Լ���λ�����Ҳ����Ѿ��ҵ��ظ���
            {
                if(nums[i]==nums[nums[i]])//�����Լ�λ���ϵ�ֵ��ͬ
                {
                    cout<<nums[i]<<endl;
                    nums[nums[i]]=P;
                    flag=0;
                    i++;
                }
                else if(nums[nums[i]]!=P)//����
                {
                    temp=nums[i];
                    nums[i]=nums[temp];
                    nums[temp]=temp;
                    //����֮��i����ָ��ԭ����λ��,����ֵ�Ѿ����nums[nums[i]]
                }
                else//����ȶ��ҽ���λ����ΪP=��˵���Ѿ��ظ�
                    i++;
            }
            else //�����Լ���λ���� ���� ��ǰλ����Ԫ��ΪP
                i++;//��һ��
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
