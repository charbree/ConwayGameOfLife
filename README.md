# Conway's Game Of Life

CONWAY'S GAME OF LIFE / VERSION 1.0

This program runs a zero-player game that is a form of cellular automana.

Getting Started
---------------
- Once the program has started, you will be requested to type in the name of the file
  that will be tested.  It is recommended that the full path to the file is typed in.

- If the file does not exist, a message will be displayed stating the file does not exist.
  This is most likely due to the path or file name being incorrect.  Please restart the program
  and attempt to re-type in the file name.


Processing File
---------------
- After the file has been opened, the contents will be read into a multideminsional array/grid.
  NOTE: The contents of the file will be used to fill an array with a maximum of height: 22, width: 44.

- Once the contents of the file have been read in to the array, the update_board will first run the update_previous
  function.  The update_previous function, will simply copy the contents from the 2d array into a temporary 2d array.
  Next, the update_board function will go through each element in the array and call the count_neighbors function.

- The count_neighbors function of the conway class, will check each element in the array/grid for the total count of
  living neighbors it has.  This consist of checking the surrounding elements above, below, and diagonally from the
  initial element. NOTE: The living elements will be marked by an 'X' and the dead neighbors will be marked by a space or ' '.

- In addition to checking the living neighbors, the count_neighbors function ensures that the sides of the array wraps
  around each other, creating a toroidal array.

- Once the living neighbors has been counted for each element, the update_board will then run the count through the rules
  for the game. The rules are as follows:

                1. Any live cell with fewer than 2 live neighbors dies (under-population)
                2. Any live cell with 2 or 3 live neighbors lives on to the next generation
                3. Any live cell with more than 3 live neighbors dies (over-population)
                4. Any dead cell with exactly 3 live neighbors becomes a live cell (reproduction)

- While checking the count of each element in the temporary 2d array against the rule, the primary 2d array will be updated based on the
  rules identified above. After the primary board has finished being updated, it will be printed out to the terminal.  The update_board
  function will be process 350 times in order to view the changes that take place.
