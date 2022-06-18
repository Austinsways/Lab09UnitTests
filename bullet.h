//
//  bullet.hpp
//  Lab07
//
//  Created by Conner Haar on 6/17/22.
//


#ifndef bullet_hpp
#define bullet_hpp
#include "position.h"
class TestBullet;

class Bullet {
public:
    friend TestBullet;
    Position position;
    bool alive = true;
    double speedSound; // for test purposes
    double speed;   // for test purposes
    double mach;    // for test purposes
    void tick(){
        
    }
    bool isAlive(){
        return alive;
    }
    double getArea(){
        return area;
    }
    double getMass(){
        return mass;
    }
    double getTime(){
        return time;
    }
    
    double getCurrentTime(){
        return currentTime;
    }
    void setCurrentTime(){
        currentTime = 0.1;
    }
    
    double getDragCoefficient(){
        return dragCoefficient;
    }
    void setDragCoefficient(){
        dragCoefficient = 5;
    }
    
    double getAirDensity(){
        return airDensity;
    }
    void setAirDensity(){
        airDensity = 5; // for sake of not having everyhitng for testing
    }
    
    double getSpeedSound(){
        return speedSound;
    }
    void setSpeedSound(){
        speedSound = 5; // for sake of not having everyhitng for testing
    }
    
    double getGravity(){
        return gravity;
    }
    void setGravity(){
        gravity = 5; // for sake of not having everyhitng for testing
    }
    
    void calculateMach(){
        mach = speed / speedSound;
    }
    void setMach(double mc){
        mach = mc;
    }// test purposes
private:
    double const area = 0.018842;
    double const mass = 46.7;
    double time = 0.01;
    double currentTime = 0.0;
    double dragCoefficient;
    double airDensity;

    double gravity;
    

    

};
#include <stdio.h>

#endif /* bullet_hpp */
