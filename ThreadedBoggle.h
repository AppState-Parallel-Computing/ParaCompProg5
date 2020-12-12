#ifndef THREADEDBOGGLE_H
#define THREADEBOGGLE_H

#include <atomic>
#include <mutex>
#include <string>
#include "ThreadPool.h"
#include "Boggle.h"

class ThreadedBoggle : public Boggle
{
  private:
    ThreadPool * TP;
    //you'll need more data members and
    //possibly more methods
    void updateSolution(std::string word);
    void updateBestWord(std::string newWord);
  public:
    ThreadedBoggle(BoggleBoard *, int);
    float playGame();
    std::string getBestWord();
}; 
#endif
