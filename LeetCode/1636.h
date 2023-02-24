#pragma once
class Solution {
public:

    struct NumSet {
        int data;
        int frequency = 0;

        bool operator < (const NumSet& other) const
        {
            if (frequency < other.frequency) { return true; }
            else if (frequency == other.frequency) { return data > other.data; }
            else { return false; }
        }
    };

    vector<int> frequencySort(vector<int>& nums) {
        vector<NumSet> numsCnt(300);
        for (int i = 0; i < nums.size(); i++)
        {
            cout << i << endl;
            numsCnt[nums[i] + 100].data = nums[i];
            numsCnt[nums[i] + 100].frequency++;
        }

        cout << "sort" << endl;
        sort(numsCnt.begin(), numsCnt.end());
        cout << "sort complete" << endl;

        for (int i = 0; i < 300; i++)
        {
            if (numsCnt[i].frequency != 0) cout << numsCnt[i].data << ' ' << numsCnt[i].frequency << endl;
        }
        
        int j = 0;
        while (j < 300 && numsCnt[j].frequency == 0) { j++; }
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = numsCnt[j].data;
            numsCnt[j].frequency--;
            if (numsCnt[j].frequency == 0) { j++; }
        }

        return nums;
    }
};