#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void renderTable(int yPlayer, int xPlayer, int yFruit, int xFruit){
    system("cls");

    char table[10][10];

    for(int i = 0; i < 10; i++){

        for(int j = 0; j < 10; j++){
            if(i == xPlayer && j == yPlayer){
                table[i][j] = 'O';
            }else if(i == xFruit && j == yFruit){

                table[i][j] = '@';
            }else{
                table[i][j] = '.';
            }
        }
    }

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

int main(){
    setlocale(LC_ALL, "");
    int yPlayerNum;
    int xPlayerNum;
    int yFruitNum;
    int xFruitNum;

    srand( (unsigned)time(NULL) );
    xPlayerNum = (rand() % 9);
    yPlayerNum = (rand() % 9);
    srand( (unsigned)time(NULL) );
    xFruitNum = (rand() % 9);
    yFruitNum = (rand() % 9);


    int moveReceiver;
    do{

        if(xPlayerNum == xFruitNum && yPlayerNum == yFruitNum){
           xFruitNum = (rand() % 9);
           yFruitNum = (rand() % 9);
        }

        if(xPlayerNum > 9){
            xPlayerNum = 0;
        }
        else if(xPlayerNum < 0){
            xPlayerNum = 9;
        }else if(yPlayerNum > 9){
            yPlayerNum = 0;
        }
        else if(yPlayerNum < 0){
            yPlayerNum = 9;
        }

        if(xFruitNum > 9){
            xFruitNum = 0;
        }else if(xFruitNum < 0){
            xFruitNum = 0;
        }else if(yFruitNum > 9){
            yFruitNum = 0;
        }else if(yFruitNum < 0){
            yFruitNum = 9;
        }

        renderTable(xPlayerNum, yPlayerNum, xFruitNum, yFruitNum);
        moveReceiver = getch();
        if(moveReceiver == 72){
            //arrowUp
            renderTable(xPlayerNum, --yPlayerNum, xFruitNum, yFruitNum);
        }
        else if(moveReceiver == 77){
            //arrow right
            renderTable(++xPlayerNum, yPlayerNum, xFruitNum, yFruitNum);
        }else if(moveReceiver == 80){
            //arrow down
            renderTable(xPlayerNum, ++yPlayerNum, xFruitNum, yFruitNum);
        }else if(moveReceiver == 75){
            //arrow left
            renderTable(--xPlayerNum, yPlayerNum, xFruitNum, yFruitNum);
        }

    }while(1==1);

    return 0;
}
