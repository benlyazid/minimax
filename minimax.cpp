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

void    print_board(board_vec board);

struct s_board
{
    board_vec board;
    int score;
};

int game_still_running(board_vec board);

int calcule_score_board(board_vec board)
{
    //printf("board\n");
    //print_board(board);
    for (size_t i = 0; i < 3; i++)
    {
        //printf("check10 %c  %c  %c  %ld\n", board[0][i], board[1][i],board[2][i], i);
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            //printf("check11\n");
            if (board[i][0] == PLAYER_1)
                return 10;
            else if (board[i][0] == PLAYER_2)
                return -10;
        } 
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            //printf("check12 %ld\n", i);
            if (board[0][i] == PLAYER_1)
                return 10;
            if (board[0][i] == PLAYER_2)
                return -10;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[0][0] == PLAYER_1)
            return 10;
        if (board[0][0] == PLAYER_2)
            return -10;
    } 
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
    {
        if (board[2][0] == PLAYER_1)
            return 10;
        if (board[2][0] == PLAYER_2)
            return -10;
    }
    return 0;
}


int minimax(board_vec board, int dept, char player, bool print)
{
    int score = calcule_score_board(board);
    int best_score = 0;


    //print_board(board);
    //printf("check score is %d   %d last paly by %c \n", score, dept, player);

    if (score != 0)
    {
        if (score == WIN)
        {
           // printf("win score is %d\n", 1);

            return WIN;
        }
        //printf("lose score is %d\n", -1);

        return LOSE;
    }
    if ((game_still_running(board)) == 0)
        return TIE;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = player;
                printf("palyer is %c    %d\n", player, dept);
                if (player == PLAYER_1)
                {
                    best_score = -100;
                    score = minimax(board, dept + 1, PLAYER_2, print);
                    best_score = max(score, best_score);
                }
                else
                {
                    best_score = 100;
                    score = minimax(board, dept + 1, PLAYER_1, print);
                    //printf("min score is %d %d\n", score, best_score);
                    best_score = min(score, best_score);
                }
                board[i][j] = ' ';
            }
        }
    }
    return (best_score);
}

int   *get_the_best_move(board_vec board, char player)
{
    int best_score = -100;
    int score;
    int *move = new int[2];
    bool print = false;

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                //board[i][j] = player;
                score = minimax(board, 1, player, true);
                printf("%d  for %ld %ld\n", score, i, j);
                if (score > best_score)
                {
                    best_score = score;
                    move[0] = i;
                    move[1] = j;
                }
                //board[i][j] = ' ';
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
    printf("\n");
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
    board[0][0] = 'O';
    board[0][2] = 'X';
    board[1][1] = 'O';
    board[1][2] = 'O';
    board[2][2] = 'X';
    print_board(board);
    int *best_move;

    int x, y, p_x, p_y;
    while (game_still_running(board))
    {
        best_move = get_the_best_move(board, PLAYER_1);
        printf("---------------\n");
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
