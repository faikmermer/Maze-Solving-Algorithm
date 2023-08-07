#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define ROWS 12
#define COLS 12


// Labirenti temsil eden 2 boyutlu karakter dizisi
char maze[ROWS][COLS];
//Labirentimizden çıkışı bulan fonksiyon
bool mazeTraverse(char maze[ROWS][COLS], int row, int col, int endX, int endY);
// Rastgele kendi labirentimizi oluşturuyoruz.
int mazeGenerator(int *endX, int *endY, int *startX, int *startY);

int main(void){
    int endx = 0, endy = 0, startx = 0, starty = 0;
    mazeGenerator(&endx, &endy, &startx, &starty);
    if(!mazeTraverse(maze, startx, starty, endx, endy)){
        printf("Not exit from the Maze!");
    }
}

bool mazeTraverse(char maze[ROWS][COLS], int row, int col, int endX, int endY){
    void printMaze(); // Fonksiyonu sadece mazeTraver içinde kullandığımızdan kısıtlıyoruz.

    // Labirent dışına çıkışı engelleme
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS){
        return false;
    }

    //Labirent '.' olan yerleri 'X' ile dolduruyoruz. 'X' hareketi ile ilerliyoruz.
    if(maze[row][col] == '.'){
        maze[row][col] = 'X';
        printMaze(); // Her adımda görüntülüyoruz.

        //Hareket yönlerini hesaplayıp ilerliyoruz.
        if(row == endX && col == endY){
            return true;
        }
        if(mazeTraverse(maze, row, col + 1, endX, endY)){
            return true;
        }
        if(mazeTraverse(maze, row + 1, col, endX, endY)){
            return true;
        }
        if(mazeTraverse(maze, row, col - 1, endX, endY)){
            return true;
        }
        if(mazeTraverse(maze, row - 1, col, endX, endY)){
            return true;
        }
        //Backtracking ile çıkmaz yerden geri dönüyoruz.
        maze[row][col] = '.';
        printMaze();
    }
    return false;

}
//Bütün yolları duvar ile oluşturuyoruz.
void initializeMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = '#'; // Duvarları '#' ile dolduruyoruz
        }
    }
}

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; ++j){
            printf("%3c", maze[i][j]);
        }
        puts("");
    }
    puts("");
}

int mazeGenerator(int *endX, int *endY, int *startX, int *startY) {

    void initializeMaze();
    srand(time(NULL));

    initializeMaze();
     
     // 0 <= *startx <= 11 arasında baslangic satiri oluşturur.
     *startX = rand() % ROWS;

    switch(*startX){
        case 0:
             *startY = rand() % (COLS - 2) + 1; // 1 <= startY <= 10 arasında sütun oluşturur. Diger 'Case' durumları aynı mantıkla yazıldı.
             *endX = ROWS - 1;
             *endY = rand() % (COLS - 2) + 1;
             maze[*startX + 1][*startY] = '.';
             maze[*endX - 1][*endY] = '.';
             break;

        case ROWS - 1:
            *startY = rand() % (COLS - 2) + 1;
            *endX = 0;
            *endY = rand() % (COLS - 2) + 1;
            maze[*startX - 1][*startY] = '.';
            maze[*endX + 1][*endY] = '.';
            break;

        default:
            *startY = 0;
            *endX = rand() % (ROWS - 2) + 1;
            *endY = COLS - 1;
            maze[*startX][*startY + 1] = '.';
            maze[*endX][*endY - 1] = '.';
            break;
    }



    maze[*startX][*startY] = '.';
    maze[*endX][*endY] = '.';



    for(int i = 1; i < ROWS - 1; ++i ){
        for(int j = 1 ; j < COLS - 1; ++j ){

             if (rand() % 3 == 0 || rand() % 2 == 0) { // Rastgele 2 ve 3 kalansız bölülenleri 
                if(maze[i][j] == '#'){
                    maze[i][j] = '.';
                }

            }
        }
    }
    printMaze();
    return 0;

}


