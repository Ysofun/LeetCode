#pragma once
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, bool> boardMap;
        for (vector<char> nums : board)
        {
            boardMap.clear();
            for (char num : nums)
            {
                if (num != '.')
                {
                    if (boardMap.find(num) != boardMap.end()) return false;
                    else boardMap.insert(pair<char, bool>(num, true));
                }
            }
        }
        for (int j = 0; j < board[0].size(); j++)
        {
            boardMap.clear();
            for (int i = 0; i < board.size(); i++)
            {
                if (board[i][j] != '.')
                {
                    if (boardMap.find(board[i][j]) != boardMap.end()) return false;
                    else boardMap.insert(pair<char, bool>(board[i][j], true));
                }
            }
        }
        for (int t = 0; t <= 8; t++)
        {
            boardMap.clear();
            int m = t / 3 * 3, n = t % 3 * 3;
            for (int i = m; i < m + 3; i++)
            {
                for (int j = n; j < n + 3; j++)
                {
                    if (board[i][j] != '.')
                    {
                        if (boardMap.find(board[i][j]) != boardMap.end()) return false;
                        else boardMap.insert(pair<char, bool>(board[i][j], true));
                    }
                }
            }
        }
        return true;
    }
};