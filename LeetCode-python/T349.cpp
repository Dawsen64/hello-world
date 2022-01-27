//暴力遍历
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    int flag = 0;
                    for (int i = 0; i < a.size(); i++)
                    {
                        if (nums2[j] == a[i])
                            flag = 1;
                    }
                    if (flag == 0)
                    {
                        a.push_back(nums2[j]);
                    }
                }
            }
        }
        return a;
    }
};
//unordered_set的使用
// auto& 减少拷贝
//set.erase()删去某个集合元素
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>b;
        unordered_set<int> set1(nums1.begin(), nums1.end());
        for (auto& iter : nums2)
        {
            if (set1.find(iter) != set1.end())
            {
                set1.erase(iter);
                b.emplace_back(iter);
            }
        }
        return b;
    }
};
