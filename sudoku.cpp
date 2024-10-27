#include <iostream>                                     
using std::cout, std::endl;

int solutions[9][9] = {};

int countf(int field[9][9]) {                                           /*function that counts the emty (0) squares*/
    int s = 0;
    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {
            if (field[i][k] == 0) s += 1;
        }
    }
    return s;
}

void solution(int field[9][9]) {                                          /*function that copies the solution to a global variable*/
    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {
            solutions[i][k] = field[i][k];
        }
    }
}

bool rows(int field[9][9], int x, int y, int n) {                           /*function that checks if a certain number is in the rows*/
    for (int i = 0; i < 9; i++) {
        if (field[x][i] == n) return false;
    }
    for (int i = 0; i < 9; i++) {
        if (field[i][y] == n) return false;
    }
    return true;
}

bool square(int field[9][9], int x, int y, int n) {                         /*function that checks if a certain number is in the 3*3 Block*/
    x = (x / 3) * 3;
    y = (y / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            if (field[x + i][y + k] == n) return false;
        }
    }
    return true;
}

bool sudoku(int field[9][9], int emptys) {                                      
    for (int x = 0; x < 9; x++) {                                           /*goes through all squares with x and y*/
        for (int y = 0; y < 9; y++) {
            if (field[x][y] != 0) continue;
            for (int n = 1; n <= 9; n++) {                                  /*goes through all numbers 1-9*/
                if (rows(field, x, y, n) && square(field, x, y, n)) {       /*if placeble places number*/
                    field[x][y] = n;
                    if (emptys - 1 == 0) {
                        solution(field);
                        return true;
                    }
                    if (sudoku(field, emptys - 1)) return true;             /*calls function with new fields*/
                    field[x][y] = 0;                                        /*resets the set square to zero*/
                }
            }
            return false;
        }
    }
    return true;
}

int main() {    
    int sudokus[9][9] = {
        {0, 0, 8, 9, 2, 0, 3, 0, 0},
        {9, 4, 0, 0, 5, 0, 0, 2, 0},
        {6, 0, 2, 0, 0, 0, 8, 0, 0},
        {0, 0, 0, 0, 0, 8, 9, 0, 3},
        {5, 1, 0, 3, 4, 0, 6, 8, 0},
        {3, 8, 6, 1, 0, 7, 0, 0, 4},
        {0, 3, 0, 0, 8, 0, 0, 0, 0},
        {8, 9, 5, 0, 3, 4, 0, 6, 0},
        {0, 0, 7, 2, 0, 0, 5, 3, 0}
    };

    int emptys = countf(sudokus);
    bool f = sudoku(sudokus, emptys);

    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            cout << solutions[x][y] << "\t";
        }
        cout << endl;
    }

    return 0;
}