#pragma once
class Solution {
public:

    int FindQuietestPerson(vector<int>& ans, vector<int>& quiet, vector<vector<int>>& richerPerson, int person)
    {
        if (ans[person] != -1) { return ans[person]; }
        int res = person;
        int minQuiet = quiet[person];
        for (int i = 0; i < richerPerson[person].size(); i++)
        {
            int richer = richerPerson[person][i];
            int tempPerson = FindQuietestPerson(ans, quiet, richerPerson, richer);
            if (quiet[tempPerson] < minQuiet)
            {
                res = tempPerson;
                minQuiet = quiet[tempPerson];
            }
        }

        ans[person] = res;
        return res;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> ans(n, -1);
        vector<vector<int>> richerPerson(n);

        for (int i = 0; i < richer.size(); i++)
        {
            richerPerson[richer[i][1]].push_back(richer[i][0]);
        }

        for (int i = 0; i < n; i++)
        {
            FindQuietestPerson(ans, quiet, richerPerson, i);
        }

        return ans;
    }
};