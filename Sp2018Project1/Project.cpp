#include "Project.h"
/**
* @brief default constructor
* @param sim simulator pointer
*/
Project::Project(Simulator &sim) {
    this->simulator = sim;
    rng = std::mt19937(rd());
    this.xt = simulator->getTarget().x;
    this.yt = simulator->getTarget().y;
    model = new pos**[simulator->getWidth()];
    for(int i = 0; i<simulator->getWidth(); i++)
    {
      model[i] = new pos*[simulator->getHeight];
      for(int j = 0; j<simulator->getHeight(); j++)
      {
        model[i][j] = new pos;
        model[i][j]->x = i;
        model[i][j]->y = j;
        model[i][j]->xp = -1;
        model[i][j]->yp = -1;
        model[i][j]->obs = false;
        model[i][j]->g = 0;
        model[i][j]->h = sqrt((simulator->getTarget().x
      }
    }
    std::vector<Point2D> obstacles = simulator->getObstacleLocations();
    for(Point2D pt : obstacles)
    {
      model[pt.x][pt.y]->obs = true;
    }
}

/**
 * @brief get optimal action
 * @return optimal action
 */
RobotAction Project::getOptimalAction() {
    ////TODO: Replace with logic for finding the target
    std::uniform_int_distribution<> actionDist(0, 3);
    return (RobotAction)actionDist(rng);
}
/**< random device */
std::random_device Project::rd;
/**< random number generator */
std::mt19937 Project::rng;

bool Project::runAStar() {
    std::priority_queue<pos,std::vector<pos>,ACompare> openq;
    openq.push(model[simulator->getRobot()->getX(), simulator->getRobot()->getY());
