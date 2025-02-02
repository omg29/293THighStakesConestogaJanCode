#include "intake.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "pros/optical.hpp"
#include "pros/screen.hpp"

//intake motors
pros::Motor bottomIntake(13);
pros::Motor upperIntake(-10);

pros::MotorGroup intake{(bottomIntake, upperIntake)};

//color sensor
pros::Optical colorSensor(21);

//color sort
const int RED = 0;
const int BLUE = 1;
const int NEUTRAL = 2;

int allianceColor;

const int redLowThreshold = 340;
const int redHighThreshhold = 20;

const int blueLowThreshold = 20;
const int blueHighThreshold = 60;

int intakeSpeed;

void setIntake(int speed){
    intakeSpeed = speed;
}

void setAllianceColor(int color){
    allianceColor = color;
}

void cycleAllianceColor(){
    allianceColor += 1;
    if (allianceColor == 3){
        allianceColor = 0;
    }
}

void asyncIntakeControl(void * param){
    while(true){
        intake.move(intakeSpeed);
        bottomIntake.move(intakeSpeed);
        upperIntake.move(intakeSpeed);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
        printf("Hue value: %lf \n", colorSensor.get_hue());
        //pros::delay(20);
    }
}