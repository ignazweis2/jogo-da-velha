/*
É esperado que eu refaça esse código e melhore as funcionalidades,
tornando-o o mais eficiente.
*/

#include <stdio.h>
#include <ctype.h>

int calc(char p[], char player, int move);
char change_player(char player);

int main (void)
{
    // váriaveis criadas na memória.
    char p[9], player;
    bool win = false, stop_move = false;
    int move = 0, buff;
    
    // adiciona um ponto em cada posição do jogo da velha.
    for (int i = 0; i < 9; i++)
    {
        p[i] = '.';
    }

    // escolha o jogador.
    printf("Qual jogador escolhido primeiro? [O/X]\n");
    printf("> ");
    scanf("%1c", &player);
    getchar();
    printf("\n");
    player = toupper(player);

    // verificar se escolha do jogador é válida.
    if (player != 'X' && player != 'O')
    {
        printf("\nJogador inválido.\n\n");
        return 1;
    }

    while (true)
    {
        // mostre o jogo da velha.
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

        // verificação se alguém ganhou ou perdeu.
        if (win == true)
        {
           // trocar o jogador.
            player = change_player(player);

            printf("[%c] ganhou!", player);
            printf("\n\n");
            return 0;
        }
        else if (move == 9)
        {
            printf("Vocês empataram!");
            printf("\n\n");
            return 0;
        }

        printf("> ");

        // coloque a opção no buffer.
        scanf("%1i", &buff);
        getchar();
        printf("\n");

        // criar opções no n[9] de 1 a 9.
        int n[9];
        for (int i = 0; i < 9; i++)
        {
            n[i] = i + 1;
        }

        // mude o jogo da velha para refletir a opção dada anteriormente.
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

        // se a jogada é inválida exiba a mensagem.
        if (stop_move == true)
        {
            printf("\n");
            printf("Jogada inválida.");
            printf("\n\n");
        }

        // caso alguém ganhe finalize o while com a variável win.
        win = calc(p, player, move);

        // trocar o jogador.
        player = change_player(player);

        // adicionar a quantidade de rodadas.
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
    // Micro-otimização inútil. Tentando impedir vários "if" de serem executados sem necessidade.
    static bool full_line[8];
    if (move >= 4)
    {
        if (p[4] == player)
        {
            // 2
            if (full_line[1] == 0)
            {
                if (p[3] == player)
                {
                    if (p[5] == player)
                    {
                        return 1;
                    }
                    else if (p[5] != '.')
                    {
                        full_line[1] = 1;
                    }
                }
            }
            // 5
            if (full_line[4] == 0)
            {
                if (p[1] == player)
                {
                    if (p[7] == player)
                    {
                        return 1;
                    }
                    else if (p[7] != '.')
                    {
                        full_line[4] = 1;
                    }
                }
            }
            // 7
            if (full_line[6] == 0)
            {
                if (p[0] == player)
                {
                    if (p[8] == player)
                    {
                        return 1;
                    }
                    else if (p[8] != '.')
                    {
                        full_line[6] = 1;
                    }
                }
            }
            // 8
            if (full_line[7] == 0)
            {
                if (p[6] == player)
                {
                    if (p[2] == player)
                    {
                        return 1;
                    }
                    else if (p[2] != '.')
                    {
                        full_line[7] = 1;
                    }
                }
            }
        }

        // 1
        if (full_line[0] == 0)
        {
            if (p[1] == player)
            {
                if (p[0] == player)
                {
                    if (p[2] == player)
                    {
                        return 1;
                    }
                    else if (p[2] != '.')
                    {
                        full_line[0] = 1;
                    }
                }
            }
        }

        // 6
        if (full_line[5] == 0)
        {
            if (p[5] == player)
            {
                if (p[2] == player)
                {
                    if (p[8] == player)
                    {
                        return 1;
                    }
                    else if (p[8] != '.')
                    {
                        full_line[5] = 1;
                    }
                }
            }
        }

        // 3
        if (full_line[2] == 0)
        {
            if (p[7] == player)
            {
                if (p[6] == player)
                {
                    if (p[8] == player)
                    {
                        return 1;
                    }
                    else if (p[8] != '.')
                    {
                        full_line[2] = 1;
                    }
                }
            }
        }

        // 4
        if (full_line[3] == 0)
        {
            if (p[3] == player)
            {
                if (p[0] == player)
                {
                    if (p[6] == player)
                    {
                        return 1;
                    }
                    else if (p[6] != '.')
                    {
                        full_line[3] = 1;
                    }
                }
            }
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
