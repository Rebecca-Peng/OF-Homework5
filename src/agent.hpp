//
//  agent.hpp
//  Homework-05
//
//  Created by pfy on 2/28/17.
//
//

#ifndef agent_hpp
#define agent_hpp
#include "ofMain.h"

#include <stdio.h>
#define MAX_AGENTS 100

class agent {
public:
    agent();
    void update(agent *arr);
    void draw();
    void start(float X, float Y);
    void calcGravityWell(float x,float y);
    
    
private:
    float getRelAngle(ofVec2f neighbor);
    float calcAlignment(agent *arr, int max);
    ofVec2f calcGravity(agent *arr,int max);
    ofVec2f calcCohesion(agent *arr, int max);
    ofVec2f calcDispersion(agent *arr, int max);
    ofVec2f location;
    ofVec2f velDir; // velocity & direction for each step
    ofVec2f mouse;  //
    ofVec2f ball;
    
    int count;
    float gravity;
    
    bool active = false;	// if this agent is active
};



#endif /* agent_hpp */
