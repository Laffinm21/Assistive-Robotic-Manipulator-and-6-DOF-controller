#include <AccelStepper.h>
#include <MultiStepper.h>
#define ANALOG_J1 34
#define ANALOG_J2 35 
#define ANALOG_J3 36 
#define ANALOG_J4 37 
#define ANALOG_J5 38 
#define ANALOG_J6 39 
// Input pins for limit switches
#define J1_LIMIT 26
#define J2_LIMIT 27
#define J3_LIMIT 28
#define J4_LIMIT 29
#define J5_LIMIT 30
#define J6_LIMIT 31

AccelStepper J1(AccelStepper::FULL2WIRE, 0, 1);
AccelStepper J2(AccelStepper::FULL2WIRE, 2, 3);
AccelStepper J3(AccelStepper::FULL2WIRE, 4, 5);
AccelStepper J4(AccelStepper::FULL2WIRE, 6, 7);
AccelStepper J5(AccelStepper::FULL2WIRE, 8, 9);
AccelStepper J6(AccelStepper::FULL2WIRE, 10, 11);

const float J1_Mult = 200000; // 10:1 gear reduction, 4:1 pulley ratio, 800 pulses/revolution, 340deg ROM
const float J2_Mult = 30000; // 50:1 gear reduction, 400 pulses/revolution, 132deg ROM
const float J3_Mult = 45000; // 50:1 gear reduction, 400 pulses/revolution, 140deg ROM
const float J4_Mult = 35000; // 10:1 gear reduction, 4:1 pulley ratio, 800 pulses/revolution, 340deg ROM
const float J5_Mult = 20000; // 50:1 gear reduction, 400 pulses/revolution, 132deg ROM
const float J6_Mult = 10000; // 50:1 gear reduction, 400 pulses/revolution, 140deg ROM

void setup()
{
  Serial.begin(9600);
  float J1target = ( 255.0 - ((analogRead(ANALOG_J1) >> 2) / 255.0) * J1_Mult);
  J1.setMaxSpeed(100000);
  J1.setAcceleration(50000);
  J1.moveTo(J1target);

  float J2target = ( 255.0 - ((analogRead(ANALOG_J2) >> 2) / 255.0) * J2_Mult);
  J2.setMaxSpeed(40000);
  J2.setAcceleration(1500);
  J2.moveTo(J2target);

  float J3target = ( 255.0 - ((analogRead(ANALOG_J3) >> 2) / 255.0) * J3_Mult);
  J3.setMaxSpeed(30000);
  J3.setAcceleration(1500);
  J3.moveTo(J3target);

  float J4target = ( 255.0 - ((analogRead(ANALOG_J4) >> 2) / 255.0) * J4_Mult);
  J4.setMaxSpeed(10000);
  J4.setAcceleration(3000);
  J4.moveTo(J4target);

  float J5target = ( 255.0 - ((analogRead(ANALOG_J5) >> 2) / 255.0) * J5_Mult);
  J5.setMaxSpeed(800);
  J5.setAcceleration(100);
  J5.moveTo(J5target);

  float J6target = ( 255.0 - ((analogRead(ANALOG_J6) >> 2) / 255.0) * J6_Mult);
  J6.setMaxSpeed(30000);
  J6.setAcceleration(1000);
  J6.moveTo(J6target);

  pinMode(J1_LIMIT, INPUT);
  pinMode(J2_LIMIT, INPUT);
  pinMode(J3_LIMIT, INPUT);
  pinMode(J4_LIMIT, INPUT);
  pinMode(J5_LIMIT, INPUT);
  pinMode(J6_LIMIT, INPUT);
}

void loop()
{
  if (digitalRead(J1_LIMIT) == HIGH){  // Limit reached
      J1.moveTo((((analogRead(ANALOG_J1) >> 2)- 255.0) / 255.0) * J1_Mult); 
      J1.run(); 
   } else {
      J1.moveTo( 255.0 - ((analogRead(ANALOG_J1) >> 2) / 255.0) * J1_Mult);
      J1.run();
   }
   if (digitalRead(J2_LIMIT) == HIGH){  
      J2.moveTo((((analogRead(ANALOG_J2) >> 2)- 255.0) / 255.0) * J2_Mult); 
      J2.run(); 
   } else {
      J2.moveTo( 255.0 - ((analogRead(ANALOG_J2) >> 2) / 255.0) * J2_Mult);
      J2.run();
   }
  J3.moveTo( 255.0 - ((analogRead(ANALOG_J3) >> 2) / 255.0) * J3_Mult);
  J3.run();
  if (digitalRead(J5_LIMIT) == HIGH){ 
    J4.moveTo(((analogRead(ANALOG_J4) >> 2) / 255.0) * J4_Mult);
    J4.run();
  } else {
    J4.moveTo( 255.0 - ((analogRead(ANALOG_J4) >> 2) / 255.0) * J4_Mult);
    J4.run();
   }
   if (digitalRead(J5_LIMIT) == HIGH){ 
    J5.moveTo(((255.0 - (analogRead(ANALOG_J5) >> 2)- 255.0) / 255.0) * J5_Mult - 225.0);
    J5.run();
   } else {
    J5.moveTo((((analogRead(ANALOG_J5) >> 2)) / 255.0) * J5_Mult - 255.0);
    J5.run(); 
   }
  J6.moveTo( 255.0 - ((analogRead(ANALOG_J6) >> 2) / 255.0) * J6_Mult);
  J6.run();
  
  Serial.print("ANALOG_J5: ");
  Serial.print(analogRead(ANALOG_J5));
  Serial.print("  J5.currentPosition(): ");
  Serial.print(J5.currentPosition());
  Serial.print("  J5.targetPosition(): ");
  Serial.println(J5.targetPosition());
}
