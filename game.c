#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

void closeSystem(){
    exit(0);
}
void saveScore(char playerName[4], int score){
    char eachScoreLine[15];
    if(score > 0){
        FILE *addScore;
        addScore = fopen("scores.txt", "r");

        while(fgets(eachScoreLine, 15, addScore) != NULL){
            printf("\n\t%s", eachScoreLine);
        }


        fprintf(addScore, "%s\t-", playerName);
        fprintf(addScore, "\t%i\n", score);
        fclose(addScore);

        if(addScore != NULL){
            printf("\n\n\t=== Seu Score foi salvo! ===\n");
        }else{
            printf("\n\tErro ao salvar Score");
        }

        closeSystem();
    }else{
        printf("\n\n\t=== Não é possivel salvar Score 0 ===\n");
        closeSystem();
    }
}
void showScores(){
    char ch;
    char eachScoreLine[15];
    int keyReceiver;
    int num = 0 ;
    int auxArray, smaller, bigger;
    char numberReceiver[15];
    int scoreReceiver = 0;

    system("cls");
    printf("\n\t=== Arroba Catcher ===\n");
    printf("\n\t=== Melhores Pontuações === || \tAperte ESC para fechar.\n");
    printf("\n\tPlayer\t\tScore\n\t=====================\n");

    FILE *scoresFile;
    scoresFile = fopen("scores.txt", "r");

    //while para descobrir quantidade de linhas do arquivo
    //e printar cada score
    while(fgets(eachScoreLine, 15, scoresFile) != NULL){
        printf("\n\t%s", eachScoreLine);
    }

    fclose(scoresFile);
    do{
        keyReceiver = getch();
    }while(keyReceiver != 27);
    closeSystem();
}
void renderTable(int yPlayer, int xPlayer, int yFruit, int xFruit, int score)
{
    system("cls");
    char table[10][10];

    for(int i = 0; i < 10; i++)
    {

        for(int j = 0; j < 10; j++)
        {
            if(i == xPlayer && j == yPlayer)
            {
                table[i][j] = 'O';
            }
            else if(i == xFruit && j == yFruit)
            {
                table[i][j] = '@';
            }
            else
            {
                table[i][j] = '.';
            }
        }
    }

    printf("\n\t=== Arroba Catcher ===\t\t==== Seu Score: %i ====", score);
    printf("\n\n\t%c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n\n", table[0][0], table[0][1], table[0][2], table[0][3], table[0][4], table[0][5], table[0][6], table[0][7], table[0][8], table[0][9]);
    printf("\t%c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n\t\n", table[1][0], table[1][1], table[1][2], table[1][3], table[1][4], table[1][5], table[1][6], table[1][7], table[1][8], table[1][9]);
    printf("\t%c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n\t\n", table[2][0], table[2][1], table[2][2], table[2][3], table[2][4], table[2][5], table[2][6], table[2][7], table[2][8], table[2][9]);
    printf("\t%c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n\t\n", table[3][0], table[3][1], table[3][2], table[3][3], table[3][4], table[3][5], table[3][6], table[3][7], table[3][8], table[3][9]);
    printf("\t%c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n\t\n", table[4][0], table[4][1], table[4][2], table[4][3], table[4][4], table[4][5], table[4][6], table[4][7], table[4][8], table[4][9]);
    printf("\t%c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n\t\n", table[5][0], table[5][1], table[5][2], table[5][3], table[5][4], table[5][5], table[5][6], table[5][7], table[5][8], table[5][9]);
    printf("\t%c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n\t\n", table[6][0], table[6][1], table[6][2], table[6][3], table[6][4], table[6][5], table[6][6], table[6][7], table[6][8], table[6][9]);
    printf("\t%c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n\t\n", table[7][0], table[7][1], table[7][2], table[7][3], table[7][4], table[7][5], table[7][6], table[7][7], table[7][8], table[7][9]);
    printf("\t%c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n\t\n", table[8][0], table[8][1], table[8][2], table[8][3], table[8][4], table[8][5], table[8][6], table[8][7], table[8][8], table[8][9]);
    printf("\t%c    %c    %c    %c    %c    %c    %c    %c    %c    %c\n\t\n", table[9][0], table[9][1], table[9][2], table[9][3], table[9][4], table[9][5], table[9][6], table[9][7], table[9][8], table[9][9]);
}

int showMenu()
{
    char *optionsLines[] = {"Jogar", "Score", "Sair"};
    char choosenSymbol = '>';
    int choosenOption = 1;
    int arrowMovies;

    system("color 02");
    do
    {
        system("cls");
        printf("\n\t=== Arroba Catcher ===\n\n");
        //printf("%i", arrowMovies);
        for(int i = 0; i < 3; i++)
        {
            printf("\t");
            if((choosenOption - 1) == i)
            {
                printf(" %c %s \n", choosenSymbol, optionsLines[i]);
            }
            else
            {
                printf("   %s \n", optionsLines[i]);
            }
        }

        arrowMovies = getch();

        if(arrowMovies == 80)  //arrowDown
        {
            choosenOption++;
            if(choosenOption > 3)
            {
                choosenOption = 1;
            }
        }
        else if(arrowMovies == 72)  //arrowUp
        {
            choosenOption--;
            if(choosenOption < 1)
            {
                choosenOption = 3;
            }
        }
    }
    while(arrowMovies != 13);

    return choosenOption;
}
void confirmSaveGame(char playerName[3], int score){
    int answer;

    system("cls");
    printf("\n\t=== Arroba Catcher ===\n");
    printf("\n\tSeu score foi %i, deseja salvar? (S/N)", score);
    do{
        answer = getch();
        if(answer == 115 || answer == 83){ //player deseja salvar score;
        saveScore(playerName, score);
    }else if(answer == 110 || answer == 78){ //player não deseja salvar score;
        closeSystem();
        return;
    }
    }while(answer != 110 || answer != 115 || answer != 83 || answer != 78);

}
void startGame(){
    int yPlayer;
    int xPlayer;
    int yFruit;
    int xFruit;
    int score = 0;
    int moveReceiver;
    char playerName[4] = "";

    system("cls");
    printf("\n\t=== Arroba Catcher ===\n");
    printf("\n\tDigite seu nick [3 caractéres]: ");
    scanf("%s", &playerName);
    printf("%s", playerName);

    score = 0;
    srand( (unsigned)time(NULL) );
    xPlayer = (rand() % 9);
    yPlayer = (rand() % 9);
    srand( (unsigned)time(NULL) + time(NULL));
    xFruit = (rand() % 9);
    yFruit = (rand() % 9);

    do
        {
            renderTable(xPlayer, yPlayer, xFruit, yFruit, score);

            //muda o posicionamento do cursor para o inicio da linha/coluna
            //quando for invalido
            //renderTable(xPlayerNum, yPlayerNum, xFruitNum, yFruitNum, score);
            moveReceiver = getch();
            if(moveReceiver == 72)
            {
                //arrowUp
                renderTable(xPlayer, --yPlayer, xFruit, yFruit, score);
                if(yPlayer < 0){
                    yPlayer = 9;
                }
            }
            else if(moveReceiver == 77)
            {
                //arrow right
                renderTable(++xPlayer, yPlayer, xFruit, yFruit, score);
                if(xPlayer > 9){
                    xPlayer = 0;
                }

            }
            else if(moveReceiver == 80)
            {
                //arrow down
                renderTable(xPlayer, ++yPlayer, xFruit, yFruit, score);
                if(yPlayer > 9){
                    yPlayer = 0;
                }
            }
            else if(moveReceiver == 75)
            {
                //arrow left
                renderTable(--xPlayer, yPlayer, xFruit, yFruit, score);
                if(xPlayer < 0){
                    xPlayer = 9;
                }
            }
            //config para fechar o game
            else if(moveReceiver == 27){
                confirmSaveGame(playerName, score);
            }

            //quando usuario alcançar o @, o @ recebe uma nova posicao
            //e o score é incrementado
            if(xPlayer == xFruit && yPlayer == yFruit){
                srand( (unsigned)time(NULL) + time(NULL));
                xFruit = (rand() % 9);
                yFruit = (rand() % 9);
                score++;
            }
        }
        while(1==1);
        return playerName;
}

void executeChoosedOption(int chooseResult)
{
    //system("cls");
    if(chooseResult == 1){
        startGame();
    }else if(chooseResult == 2){
        showScores();
    }
    else if(chooseResult == 3){
        closeSystem();
    }
}

int main()
{
    setlocale(LC_ALL, "");

    int showMenuResult;
    showMenuResult = showMenu();
    //do while para permitir que entre e saia do score
    do{

        //pega o retorno da escolha do menu
        //e o usa como argumento para a funcao que executa
        //acao de acordo com a escolha do usuário

        executeChoosedOption(showMenuResult);
    }while(showMenuResult != 0);

    return 0;
}
