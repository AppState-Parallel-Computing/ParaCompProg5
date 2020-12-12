#include <iostream>
#include "ThreadedBoggle.h"
#include "helpers.h"

/* Your work is in this file and ThreadedBoggle.h. */
/* You'll need more data members and possibly more methods. */

/*
 * ThreadedBoggle
 * Initialize the ThreadedBoggle game.
 * Input:
 *   board - pointer to the BoggleBoard object containing the 4 by 4 board
 *   threadPoolSize - number of threads in the ThreadPool
 */
ThreadedBoggle::ThreadedBoggle(BoggleBoard * board, int threadPoolSize):Boggle(board)
{
  //initialize the thread pool and the bestWord
} 

/*
 * updateSolution
 * Adds a new word to the solution vector.  It needs to be done
 * atomically.
 * Inputs:
 *   newWord - word to add to the solution vector
 */
void ThreadedBoggle::updateSolution(std::string newWord)
{
}

/*
 * updateBestWord
 * Updates the std::atomic bestWord.
 *
 */
void ThreadedBoggle::updateBestWord(std::string newWord)
{
  //Get the up to 8 character that make up the bestWord
  //out of the 64 bit atomic variable
  //You'll need to add a declaration of the atomic variable to
  //ThreadedBoggle.h
  //
    //convert the 8 characters into a string

    //compare the current best word string to the newWord string
    //to see if the best word should be updated to the newWord
    //current word should be updated if:
    //1) it is less than 9 characters in length and longer than 
    //   best word
    //2) it is the same length as best word and alphabetically less
    //   than best word.  For example, "are" < "our"
    //See SequentialBoggle code for assistance.
    
    //if the bestword should be updated with the newWord then
    //build a 64-bit unsigned out of the newWord and try to update
    //it.  Note: multiple threads may be trying to do this at the
    //same time! The best word needs to win!
    //See book for how to do this.
}

/*
 * playGame
 * Determines the solution to the boggle board.  The threadpool
 * is used to build the solution and spawn is called for each 
 * of the 16 squares in the boggle board.
*/
float ThreadedBoggle::playGame()
{

  //start timing the solver (see helpers.h)

  TIMERSTART(parallel)
  //See code in SequentialBoggle.C
  //Call spawn on each of the 16 squares
  //However the traverse function can not be a member of
  //the ThreadedBoggle class.  It can be a lambda expression
  //or a function that is not part of a class.

  //You'll need these two calls to tell the Thread Pool that
  //you are finished adding tasks and then to wait until
  //the Thread Pool is empty
  //TP->no_more_tasks();
  //TP->wait_and_stop();

  //stop timing the solver
  TIMERSTOP(parallel)

  //delete the ThreadPool
  delete TP;
  //return the difference between the starting time
  //and the ending timing
  return GETTIME(parallel);
}

/*
 * getBestWord
 * Get the best word out of the 64-bit atomic, build a string
 * out of it, and return it.
 */
std::string ThreadedBoggle::getBestWord()
{
  return "";
}
