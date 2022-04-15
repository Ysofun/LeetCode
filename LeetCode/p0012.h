#pragma once
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<vector<bool>> boardFlag;
public:
    bool SearchWord(vector<vector<char>>& board, int x, int y, string word, int idx)
    {
        if (idx == word.length()) return true;
        if (x >= board.size() || y >= board[x].size() || x < 0 || y < 0 || boardFlag[x][y]) return false;
        
        bool flag = false;
        boardFlag[x][y] = true;
        if (board[x][y] == word[idx])
        {
            flag |= SearchWord(board, x + 1, y, word, idx + 1);
            if (flag)
            {
                boardFlag[x][y] = false;
                return flag;
            }
            flag |= SearchWord(board, x, y + 1, word, idx + 1);
            if (flag)
            {
                boardFlag[x][y] = false;
                return flag;
            }
            flag |= SearchWord(board, x - 1, y, word, idx + 1);
            if (flag)
            {
                boardFlag[x][y] = false;
                return flag;
            }
            flag |= SearchWord(board, x, y - 1, word, idx + 1);
        }
        boardFlag[x][y] = false;
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                boardFlag.resize(board.size(), vector<bool>(board[i].size(), false));
                if (SearchWord(board, i, j, word, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};