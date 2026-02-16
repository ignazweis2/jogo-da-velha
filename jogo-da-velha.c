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
