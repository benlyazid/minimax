#include <stdlib.h>
#include <vector>
using namespace std;

typedef vector <vector<char>> board_vec;

struct s_board
{
    board_vec board;
    int score;
};


int calcule_score_board(board_vec)
{
    return 0;
}


vector <s_board>  get_all_possibles_moves(board_vec board, char player)
{
    vector<s_board> all_possible;

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            s_board board_cas;
            if (board[i][j] == ' ')
            {
                board[i][j] = player;
                board_cas.board = board;
                board_cas.score = calcule_score_board(board_cas.board);
                board[i][j] = ' ';
                all_possible.push_back(board_cas);
            }
        }
        
    }
    return all_possible;
}

board_vec initial_board()
{
    board_vec board;
    for (size_t i = 0; i < 3; i++)
    {
        vector <char> line;
        for (size_t j = 0; j < 3; j++)
        {
            line.push_back(' ');
        }
        board.push_back(line);  
    }
    return board;
}


int main(int argc, char const *argv[])
{
    board_vec board;
    board = initial_board();
    

    return 0;

}
