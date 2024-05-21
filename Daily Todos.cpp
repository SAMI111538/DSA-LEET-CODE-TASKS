//Contain Duplicates
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }

//Valid anagram
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;
        
        for(int i = 0; i < s.size(); i++){
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        
        for(int i = 0; i < smap.size(); i++){
            if(smap[i] != tmap[i]) return false;
        }
        return true;
    }
};


//Two Sum (LeetCode easy)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> newArr;

        for(int i =0;i<nums.size();i++)
        {
            for(int j =i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    newArr.push_back(i);
                    newArr.push_back(j);
                }
            }
        }

        return newArr;
    }
};