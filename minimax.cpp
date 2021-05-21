#include <stdlib.h>
#include <vector>
#include <iostream>
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
    int bets_score;
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
                    if (player == PLAYER_1)
                    {
                        bets_score = -100;
                        score = minimax(board, dept + 1, PLAYER_2);
                        bets_score = max(score, bets_score);
                    }
                    else
                    {
                        bets_score = 100;
                        score = minimax(board, dept + 1, PLAYER_1);
                        bets_score = min(score, bets_score);
                    }
                    board[i][j] = ' ';
                }
            }
        }
    }
    return (bets_score);
}

int   *get_the_best_move(board_vec board, char player)
{
    int best_score = -100;
    int score;
    int *move = new int[2];

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = player;
                score = minimax(board, 1, player);
                if (score > best_score)
                {
                    best_score = score;
                    move[0] = i;
                    move[1] = j;
                }
                board[i][j] = ' ';
            }
        }
    }
    return (move);
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

void    print_board(board_vec board)
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%c |", board[i][j]);
        }
        printf("\n---------\n");
    }
}

int game_still_running(board_vec board)
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
           if (board[i][j] == ' ') 
                return 1;
        }
        
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    board_vec board;
    board = initial_board();
    int *best_move;
    int x, y, p_x, p_y;
    while (game_still_running(board))
    {
        best_move = get_the_best_move(board, PLAYER_1);
        y = best_move[0];
        x = best_move[1];
        board[y][x] = PLAYER_1;
        print_board(board);
        cin >> p_y >> p_x;
        board[p_y][p_x] = PLAYER_2;
        print_board(board);
    }
    
    return 0;
}
