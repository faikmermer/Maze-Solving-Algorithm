#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define ROWS 12
#define COLS 12
#define PATH 2
bool mazeTraverse(char maze[ROWS][COLS], int row, int col);


void printMaze(char maze[ROWS][COLS]);

void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; ++j){
            printf("%3c", maze[i][j]);

        }
        puts("");
    }
}

int main() {
    char maze[ROWS][COLS] = {
    "############",
    "#...#......#",
    "..#.#.####.#",
    "###.#....#.#",
    "#....###.#..",
    "####.#.#.#.#",
    "#..#.#.#.#.#",
    "##.#.#.#.#.#",
    "#........#.#",
    "######.###.#",
    "#......#...#",
    "############"
    };
    mazeTraverse(maze, 2, 0);
    return 0;
}

bool mazeTraverse(char maze[ROWS][COLS], int row, int col){
    void display(char maze[ROWS][COLS]);

    if(row < 0 || row >= ROWS || col < 0 || col >= COLS){
      return false;
    }

    if(maze[row][col] == '.'){
      maze[row][col] = 'X';
      display(maze);

      if(row == 0 || row == ROWS - 1 || col == COLS - 1){
        return true;
      }

      if(mazeTraverse(maze, row, col + 1)){
        return true;
      }
      if(mazeTraverse(maze, row + 1, col)){
        return true;
      }
      if(mazeTraverse(maze, row, col - 1)){
        return true;
      }
      if(mazeTraverse(maze, row - 1, col)){
        return true;
      }
      maze[row][col] = '.';
   }
    return false;
}



void display(char maze[ROWS][COLS]){
    for(int i = 0; i < ROWS; ++i){
        for(int j = 0; j < COLS; ++j){
            printf("%c ", maze[i][j]);
        }
        puts("");
    }
    puts("");

}

