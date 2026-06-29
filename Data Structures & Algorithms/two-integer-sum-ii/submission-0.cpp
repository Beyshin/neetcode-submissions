class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, p = numbers.size()-1;

        while(l<p){
            int sum = numbers[l] + numbers[p];

            if(sum == target) return {l+1, p+1};
            else if(sum > target) p--;
            else l++;
        }

        return {-1, -1};
    }
};
