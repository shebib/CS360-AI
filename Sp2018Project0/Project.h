#ifndef Project_hpp
#define Project_hpp

#include <stdio.h>
#include <vector>
#include "Robot.h"
#include "Vector2D.h"
#include "Simulator.h"
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
};

#endif
