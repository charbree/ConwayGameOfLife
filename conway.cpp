#include <iostream>
#include <fstream>
#include "conway.h"

using namespace std;

void conway::init_board(string board_name) {
    //Open file
    ifstream infile;
    infile.open(board_name.c_str());
    //If file does not exist
    if (infile.fail()) {
        cout << "File does not exist." << endl;
        cout << "Please exit the program and try again." << endl;
    }
    
    //Loop for array rows
    for (int i = 0; i < height; i++) {
        //Loop for array columns
        for (int j = 0; j < width; j++) {
            //Read in data from file to array
            infile.get(board[i][j]);
        }
        
        //Read in new line character
        infile.get();
    }
   
    //Close file
    infile.close();
}


void conway::print() {
    //Loop for array rows
    for (int i = 0; i < height; i++) {
        //Loop for array columns
        for (int j = 0; j < width; j++) {
            //Print out array
            cout << board[i][j];
        }
            //Print out new line character
            cout << '\n';
    }

}

void conway::update_previous() {

    for (int i = 0; i < height; i++) {

        for (int j = 0; j < width; j++)
            //Copy board array to previous array
            previous[i][j] = board[i][j];

    }
}

void conway::update_board() {
    //Update temporary board to use for comparison
    update_previous();

    char alive = 'X';
    char dead = ' ';

    for (int i = 0; i < height; i++) {

        for (int j = 0; j < width; j++) {
            //Check count against game rules
            if (previous[i][j] == alive && count_neighbors(i,j) < 2) { //rule 1
                board[i][j] = dead;
            }

            if (previous[i][j] == alive && (count_neighbors(i,j) == 2 || count_neighbors(i,j) == 3)) { //rule 2
                    board[i][j] = alive;
            }

            if (previous[i][j] == alive && count_neighbors(i,j) > 3 ) { //rule 3
                    board[i][j] = dead;
            }

            if (previous[i][j] == dead && count_neighbors(i,j) == 3) { //rule 4
                    board[i][j] = alive;
            }

        }
    }
    //Print out updated board
    print();
}


int conway::count_neighbors(int row, int col) {
    int count = 0;
    char alive = 'X';

            //Count neighbors and wrap array
            if (previous[row][col-1] == alive) {
                if (col == 0)
                    col = width;
                count++;
            }
            if (previous[row-1][col] == alive) {
                if (row == 0)
                    row = height;
                count++;
            }

            if (previous[row+1][col] == alive) {
                if (row == height)
                    row = 0;
                count++;
            }

            if (previous[row][col+1] == alive) {
                if (col == width)
                    col = 0;
                count++;
            }

            if (previous[row-1][col-1] == alive) {
                if (row == 0)
                    row = height;
                if (col == 0)
                    col = width;
                count++;
            }

            if (previous[row-1][col+1] == alive) {
                if (row == 0)
                    row = height;
                if (col == width)
                    col = 0;
                count++;
            }

            if (previous[row+1][col-1] == alive) {
                if (row == height)
                    row = 0;
                if (col == 0)
                    col = width;
                count++;
            }

            if (previous[row+1][col+1] == alive) {
                if (row == height)
                    row = 0;
                if (col == width)
                    col = 0;
                count++;
            }

    return count;

}
