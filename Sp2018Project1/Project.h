#ifndef Project_hpp
#define Project_hpp

#include <stdio.h>
#include <vector>
#include "Robot.h"
#include "Vector2D.h"
#include "Simulator.h"

/**@struct pos
 * @brief represents a position on the board
 */
struct pos {
  int x;
  int y;
  int xp;
  int yp;
  bool obs;
  int g;
  double h;
}

/**@class Comparer
 * @brief Comparison class for heuristic
 */
class ACompare {
  public bool operator() (pos* lhs, pos* rhs) {
    if ((lhs->h+lhs->g)<(rhs->h+rhs->g))
      return true;
    else
      return false;
  }
}

/**
 * @class Project
 * @brief represents the project to be completed
 */
class Project {
private:
    /**< random device */
    static std::random_device rd;
    /**< random number generator */
    static std::mt19937 rng;
    /**< simulator instance */
    Simulator simulator;
    /**< Internal model of simulation with obstacles */
    pos*** model;
    std::Queue<std::pair<int,int>> answer;
    int xt;
    int yt;


public:
    /**
     * @brief default constructor
     * @param sim simulator pointer
     */
    Project(Simulator &sim);

    /**
     * @brief get optimal action
     * @return optimal action (the one the robot should take
     */
    RobotAction getOptimalAction();

    /**
     * runs AStar and outputs the answer into answer
     */
    bool runAStar();

    /**
     * clears the current answer queue
     */
    void clearAns();
};

#endif
