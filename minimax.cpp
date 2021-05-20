#include <stdlib.h>
#include <vector>
using namespace std;

const char PLAYER_1 = 'X' ;
const char PLAYER_2 = 'O' ;
const int WIN = 1;
const int LOSE = -1;
const int TIE = 0;

typedef vector <vector<char> > board_vec;


struct s_board
{
    board_vec board;
    int score;
};

int calcule_score_board(board_vec board)
{
    for (size_t i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] == board[i][2])
        {
            if (board[i][0] == PLAYER_1)
                return 10;
            else
                return -10;
        } 
        if (board[0][i] == board[1][i] == board[2][i])
        {
            if (board[i][0] == PLAYER_1)
                return 10;
            else
                return -10;
        }
    }
    if (board[0][0] == board[1][1] == board[2][2])
    {
        if (board[0][0] == PLAYER_1)
            return 10;
        else
            return -10;
    } 
    
    if (board[2][0] == board[1][1] == board[0][2])
    {
        if (board[0][0] == PLAYER_1)
            return 10;
        else
            return -10;
    }
    return 0;
}


int minimax(board_vec board, int dept, char player)
{
    int score = calcule_score_board(board);
    if (score != 0)
    {
        if (score == WIN)
            return WIN;
        return LOSE;
    }
    if (player == PLAYER_1)
    {
        for (size_t i = 0; i < 3; i++)
        { 
            for (size_t j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = player;
                    score = minimax(board, dept + 1, PLAYER_1);
                    board[i][j] = ' ';
                }
            }
        }
    }
    return 1;
}

vector <s_board>  get_the_best_move(board_vec board, char player)
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
                board_cas.score = minimax(board_cas.board, 1, PLAYER_1);
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