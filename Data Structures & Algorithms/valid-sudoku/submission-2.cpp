#define element board[i][j]


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> columns(9);
        vector<set<char>> area(9);

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(element == '.')
                    continue;
                if(rows[i].contains(element) || columns[j].contains(element) || area[(i / 3) * 3 + (j / 3)].contains(element))
                    return false;
                else{
                    rows[i].insert(element);
                    columns[j].insert(element);
                    area[(i / 3) * 3 + (j / 3)].insert(element);
                }
            }
        }


        return true;
    }
};
