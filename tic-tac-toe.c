/*
It is expected that I will rewrite this code and improve its features,
making it as efficient as possible.
*/

#include <stdio.h>
#include <ctype.h>

int calc(char p[], char player, int move);
char change_player(char player);

int main (void)
{
    // variables created in memory.
    char p[9], player;
    bool win = false, stop_move = false;
    int move = 0, buff;
    
    // add a dot in each position of the tic-tac-toe board.
    for (int i = 0; i < 9; i++)
    {
        p[i] = '.';
    }

    // choose the starting player.
    printf("Which player goes first? [O/X]\n");
    printf("> ");
    scanf("%1c", &player);
    getchar();
    printf("\n");
    player = toupper(player);

    // check if the chosen player is valid.
    if (player != 'X' && player != 'O')
    {
        printf("\nInvalid player.\n\n");
        return 1;
    }

    while (true)
    {
        // display the tic-tac-toe board.
        printf("  ╔═══╤═══╤═══╗\n");
        printf("  ║ %c │ %c │ %c ║  1   2   3\n", p[0], p[1], p[2]);
        printf("  ╟───┼───┼───╢\n");
        printf("  ║ %c │ %c │ %c ║  4   5   6\n", p[3], p[4], p[5]);
        printf("  ╟───┼───┼───╢\n");
        printf("  ║ %c │ %c │ %c ║  7   8   9\n", p[6], p[7], p[8]);
        printf("  ╚═══╧═══╧═══╝\n");

        if (!(move == 9) && !win)
        {
            printf("[%c] player\n", player);
        }

        // check if someone has won or if the game ended.
        if (win == true)
        {
            // switch the player.
            player = change_player(player);

            printf("[%c] won!", player);
            printf("\n\n");
            return 0;
        }
        else if (move == 9)
        {
            printf("It's a draw!");
            printf("\n\n");
            return 0;
        }

        printf("> ");

        // store the option in the buffer.
        scanf("%1i", &buff);
        getchar();
        printf("\n");

        // create options in n[9] from 1 to 9.
        int n[9];
        for (int i = 0; i < 9; i++)
        {
            n[i] = i + 1;
        }

        // update the board to reflect the chosen option.
        stop_move = true;
        for (int i = 0; i < 9; i++)
        {
            if ((n[i] == buff) && (p[i] == '.'))
            {
                p[i] = player;
                stop_move = false;
                break;
            }
        }

        // if the move is invalid, display a message.
        if (stop_move == true)
        {
            printf("\n");
            printf("Jogada inválida.");
            printf("\n\n");
        }

        // if someone wins, end the loop using the win variable.
        win = calc(p, player, move);

        // switch the player.
        player = change_player(player);

        // increment the number of rounds.
        if (stop_move == false)
        {
            move++;
        }
        else
        {
            stop_move = false;
        }
    }
    return 0;
}

int calc(char p[], char player, int move)
{
    if (move >= 4)
    {
        if ((p[0] == player && p[1] == player && p[2] == player) ||
            (p[3] == player && p[4] == player && p[5] == player) ||
            (p[6] == player && p[7] == player && p[8] == player) ||

            (p[0] == player && p[3] == player && p[6] == player) ||
            (p[1] == player && p[4] == player && p[7] == player) ||
            (p[2] == player && p[5] == player && p[8] == player) ||

            (p[0] == player && p[4] == player && p[8] == player) ||
            (p[6] == player && p[4] == player && p[2] == player))
            {
                return 1;
            }
    }
    return 0;
}

char change_player(char player)
{
    if (player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
    return player;
}
