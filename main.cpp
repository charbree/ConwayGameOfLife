#include <iostream>
#include <fstream>
#include "conway.h"

using namespace std;

int main() 
{
    //Variable Declaration
    int loop = 1;
    string board_name;

    //Request the name of file to be opened.
    cout << "Please enter filename: ";
    cin >> board_name;

    //Delcaration of conway object
    conway conway1;
    
    conway1.init_board(board_name);
    conway1.print();

    //Continue to update board 350 times.
    while (loop < 350) {
        conway1.update_board();
        loop++;
    }

    return 0;
}
