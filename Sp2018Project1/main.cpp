#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <unistd.h>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define _USE_MATH_DEFINES
#include <cmath>
#endif
#include <vector>
#include <random>
#include <string>
#include "Vector2D.h"
#include "Robot.h"
#include "Simulator.h"
#include "Project.h"
#define SIZEX 10
#define SIZEY 10
int main(int argc, char **argv)
{
    int steps;  // the steps before found the target
    int waitCounter = 200; // amount to wait between steps (milliseconds)
    int numObstacles = 10; // number of obstacles
    int numHiddenObstacles = 10;
    bool isRobotAlive = true; //robot begins by being alive
    float transitionProb = 1.0; // transition probabilities
    printf("\n\n*** CS360 Project Begin *** \n\n");
    int sx = -1; int sy = -1;
    if (argc==3 && (sx=std::stoi(argv[1])) && (sy=std::stoi(argv[2]))) {
        printf("Project environment size = [%d,%d]\n", sx, sy);
    } else {     
    	sx = SIZEX;       // use SIZEX for your environment
    	sy = SIZEY;       // use SIZEY for your environment
    }
    Robot *r = new Robot(1);    // create your robot
    Simulator sim = Simulator(sx, sy, r);    // create your environment
    printf("Simulator area [%d x %d] is created\n", sx, sy);
    sim.createRandomObstacles(numObstacles);
    sim.createRandomHiddenObstacles(numHiddenObstacles);
    steps = 0;
    //Illustration of how to get the target position
    std::cout<<"Target Position: ("<<sim.getTarget().getX()<<","<<sim.getTarget().getY()<<")"<<std::endl;
	Project p(sim); // project object
    while (!sim.robotFoundTarget()) {  // loop until your robot find the target
        RobotAction a = p.getOptimalAction();
        bool alive = sim.step(a, transitionProb);
        sim.display();
        std::cout<<"Current robot location: ("<<sim.getRobot()->getPosition().getX()<<", "<<sim.getRobot()->getPosition().getY()<<")"<<std::endl;
        if (!alive) {
            std::cout<<"Robot dead. Stepped on obstacle at ("<<
            sim.getRobot()->getPosition().getX()<<", "<<sim.getRobot()->getPosition().getY()<<")"<<std::endl;
            isRobotAlive = false;
            break;
        } else {
            std::vector<Point2D> hs = sim.getCurrentLocalObstacleLocations();
            if (hs.size() > 0) {
                std::cout<<"Hidden object at location(s): "<<std::endl;
                for (int i=0; i<hs.size(); i++) {
                    std::cout<<"("<<hs[i].getX()<<","<<hs[i].getY()<<")"<<std::endl;
                }
            }
        }
        steps++;
        #if defined(_WIN32) || defined(_WIN64)
        Sleep(waitCounter);
        #else
        usleep(1000*waitCounter);
        #endif
    }
    if (isRobotAlive) printf("My robot found the target in %d steps !!! \n\n", steps);
    else printf("Robot died in %d steps\n", steps);
    for (int i=0; i<numObstacles; i++) {
        std::cout<<"Obstacle "<<i + 1<<" at: ("<<sim.getObstacleLocations()[i].getX()<<","<<
        sim.getObstacleLocations()[i].getY()<<")"<<std::endl;
    }
    delete r;
}

