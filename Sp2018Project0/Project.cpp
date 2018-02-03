#include "Project.h"
/**
* @brief default constructor
* @param sim simulator pointer
*/
Project::Project(Simulator &sim) {
    this->simulator = sim;
    rng = std::mt19937(rd());
}

/**
 * @brief get optimal action
 * @return optimal action
 */
RobotAction Project::getOptimalAction() {
    ////TODO: Replace with logic for finding the target
    int robX = simulator.getRobot()->getPosition().getX();
    int robY = simulator.getRobot()->getPosition().getY();
    int tarX = simulator.getTarget().getX();
    int tarY = simulator.getTarget().getY();

    if(robX < tarX)
      return(MOVE_DOWN);
    else if(robX>tarX)
      return(MOVE_UP);
    else if(robY<tarY)
      return(MOVE_RIGHT);
    else if(robY>tarY)
      return(MOVE_LEFT);
    else
      return(STOP);
}
/**< random device */
std::random_device Project::rd;
/**< random number generator */
std::mt19937 Project::rng;

