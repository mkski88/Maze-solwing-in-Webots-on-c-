  #include <webots/DistanceSensor.hpp>
  #include <webots/PositionSensor.hpp>
  #include <webots/Accelerometer.hpp>
  #include <webots/Camera.hpp>
  #include <webots/Motor.hpp>
  #include <webots/Robot.hpp>
  #define TIME_STEP 64
  #include <iostream>     
  int qw=0,a=0,qw1=0,qw2=0;
  int sa,as,x=0,y=1;
  float wh,hh;
//  int image;
  double s,re,ge,be;
  using namespace webots;
  using namespace std;

  int main(int argc, char **argv) {
    Robot *robot = new Robot();
    
    int timeStep = (int)robot->getBasicTimeStep();
  
 Motor *wheels[2];
    DistanceSensor *ds = robot->getDistanceSensor("ps5");
     ds->enable(TIME_STEP);
     
      DistanceSensor *ds1 = robot->getDistanceSensor("ps7");
     ds1->enable(TIME_STEP);
           DistanceSensor *ds2 = robot->getDistanceSensor("ps6");
     ds2->enable(TIME_STEP);
          
    
    char wheels_names[2][48] = {"left wheel motor","right wheel motor"};
    for (int i = 0; i < 2; i++) {
      wheels[i] = robot->getMotor(wheels_names[i]);
      wheels[i]->setPosition(INFINITY);
      wheels[i]->setVelocity(0);
    }

 int a0,a1,a2,a3,a4,a5,a6,a7;
 float ms=6;
 
int left_wall,right_wall,front_wall,left_w;
    while (robot->step(timeStep) != -1)
  {


left_wall=ds->getValue();
front_wall=ds1->getValue();
left_w=ds2->getValue();

if(left_wall>500)
{
wheels[0]->setVelocity(ms);
wheels[1]->setVelocity(ms);
}
else if(front_wall>80)
{
wheels[0]->setVelocity(ms);
wheels[1]->setVelocity(-ms);
}

else if(left_w>100)
{wheels[0]->setVelocity(ms);
wheels[1]->setVelocity(ms/8);
}

else
{
wheels[0]->setVelocity(ms/8);
wheels[1]->setVelocity(ms);
}
};

  delete robot;
  return 0;
}