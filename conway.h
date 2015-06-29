#ifndef CONWAY_H
#define CONWAY_H

using namespace std;

//Constant size for rows and columns of the array.
const int height = 22;
const int width = 44;

class conway {
  /*
   * Purpose:
   *    The conway class stores information read in from a file into a 2d array, and performs
   *    an update of the array based a set of rules.
   */
    private:
        char board[height][width];
        char previous[height][width];

    public:
        void init_board(string board_name);
        /*
         * Description:
         *   Initializes the 2d array by reading in data from a file
         *   and placing the data the 2d array elements.  The array
         *   will have a height of 22 and a width of 44.
         *
         * Inputs:
         *   string board name
         *     This is the name of the file that will be opened and
         *     read in to create the board array.
         *
         * Return:
         *   None
         */

        void print();
        /*
         * Purpose:
         *   Draws the board to the terminal.
         *
         * Notes:
         *   The board is printed on the height being 22 and the width
         *   width being 44.
         */

        void update_previous();
        /*
         * Purpose:
         *   Copies the board array to the previous array.
         *
         * Notes:
         *   The previous array is copied from the board array
         *   using the same dimensions for the rows, 22, and
         *   height, 44.
         */

        int count_neighbors(int row, int col);
        /*
         * Description:
         *   Calculates the total number of "alive" neighbors by checking above, below,
         *   and diagonally.
         *
         * Inputs:
         *   int row - The height location of the element.
         *
         *   int col - The width location of the element.
         *
         * Return:
         *   int - The total number of neighbors surrounding the element location.
         */

        void update_board();
        /*
         * Purpose:
         *   Updates the board based on the total number of neighbors
         *   each element has.
         *
         * Notes:
         *   First calls to the update_previous function to set up temporary
         *   board that will be checked against the rules of the game.  After
         *   each element has been checked, the print function is called to print
         *   out the updated board.
         */


};

#endif // CONWAY_H

