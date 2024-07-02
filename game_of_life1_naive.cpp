class Solution {
public:
    bool inside(const vector<vector<int>>& board, int x, int y)
    {
        return (board[0].size() > x && x >= 0 && board.size() > y && y >= 0);
    }

    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;
        array<array<int, 2>, 8> neighbors = {{ {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}} };
        vector<vector<int>> board2(board.size());
        for(auto it = board2.begin() ; it != board2.end() ; ++it) {
            (*it).resize(board[0].size(), 0);
        }

        for (int i = 0 ; i < board.size() ; i++) {
            for (int j = 0 ; j < board[0].size() ; j++) {
                // for [i][j] , must be alive to go to next gen with one exception rule.
                int count = 0;
                for (int k = 0 ; k < neighbors.size() ; k++) { // 8 neighbors
                    int x = j + neighbors[k][0];
                    int y = i + neighbors[k][1];
                    if (inside(board, x, y)) {
                        cout << "," << x << ":" << y;
                        count += board[y][x];
                    }
                }

                if (board[i][j]) {
                    if (count >= 2 && count <= 3) {
                        // live
                        board2[i][j] = 1;
                    }
                    else
                        board2[i][j] = 0;
                }
                else if (count == 3) {
                    board2[i][j] = 1;
                }
            }
        }

        // copy board2 to board1
        for (int i = 0 ; i < board.size() ; i++) {
            for (int j = 0 ; j < board[0].size() ; j++) {
                board[i][j] = board2[i][j];
            }
        }
    }
};