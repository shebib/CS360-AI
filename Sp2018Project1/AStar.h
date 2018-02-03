#ifndef AStar_hpp
#define AStar_hpp

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
 * @class AStar
 * @brief runs A* search and holds the current action queue
 * NOTE: Always run runAStar after creating to see if a solution is found
 */
class AStar {
private:
  std::Queue<std::pair<int,int>> answer;
  int xt;
  int yt;

public:
  AStar(int currX, int currY);
  bool runAStar();
  std::pair<int,int> getNext();
  void clearAns();

};

#endif
