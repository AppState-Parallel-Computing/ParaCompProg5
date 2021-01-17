#include <iostream>
#include <chrono>
#include <algorithm>
#include "Boggle.h"
#include "helpers.h"

/*
 * Boggle constructor
 * Initializes the Boggle game 
 * Input:
 *  Pointer to a BoggleBoard object that contains the 4 by 4
 *  array of char.
 */
Boggle::Boggle(BoggleBoard * board)
{
  this->dict = Dict::getInstance();
  this->board = board;
} 

/*
 * printSolutions
 * Prints the boggle board, the solution to the board, and
 * the best word found (<= 8 letters)
 */
void Boggle::printSolutions()
{
  printf("Board");
  for (int i = 0; i < 16; i++)
  {
    if (i % 4 == 0) printf("\n");
    printf("%3c", this->board->getLetter(i));
  }
  printf("\nSolutions\n");
  for (auto & word: sols)
    printf("%s\n", word.c_str());

  printf("Best Word\n");
  printf("%s\n", getBestWord().c_str());
}

/*
 * equal
 * Takes as input a Boggle object and checks to see if it is 
 * equal to this object. The two objects are equal if their
 * vectors contain the exact same words and if their
 * "best words" are identical.
 * Input:
 *   reference to a Boggle object
 * Output:
 *   true if the input object and this object are identical
 *   false otherwise
 */
bool Boggle::equal(Boggle & boggle)
{
  //see if the vectors of words are the same length
  if (this->sols.size() != boggle.sols.size())
  {
    printf("Lengths do not match: %d != %d\n",
           (int)this->sols.size(), (int)boggle.sols.size());
    return false;
  }
  //see if their best words are identical
  if (this->getBestWord() != boggle.getBestWord())
  {
    printf("Best words do not match: %s != %s\n",
           this->getBestWord().c_str(),
           boggle.getBestWord().c_str());
    return false;
  }
  //sort the two vectors and see if their contents are
  //identical
  std::sort(this->sols.begin(), this->sols.end());
  std::sort(boggle.sols.begin(), boggle.sols.end());
  for (int i = 0; i < (int) this->sols.size(); i++)
  {
    if (this->sols[i] != boggle.sols[i])
    {
      printf("Vectors do not match (index %d): %s != %s\n",
             i, this->sols[i].c_str(), boggle.sols[i].c_str());
      return false;
    }
  }
  //objects match
  return true;
}

