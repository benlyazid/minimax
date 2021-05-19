
using namespace std;

int *initial_board()
{
    int board [3][3];
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    return board;
}   
int main(int argc, char const *argv[])
{
    int board = initial_board();

    return 0;

}
