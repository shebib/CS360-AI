#include "AStar.h"

AStar::AStar(int x, int y, int xtarget, int ytarget) {
  answer.push(std::make_pair(x, y));//push starting val
  this.xt = xtarget;
  this.yt = ytarget;
}

bool AStar::runAStar() {
  std::priority_queue<pos,std::vector<pos>,ACompare> openq;
  openq.push(answer.pop());
  

  




