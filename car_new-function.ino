/*
Simple sketch to test car movement forward and backward with L298N.
Used 9V battery to power L298N and then used the 5V+ pin to power the Arduino.
Connected OUT1 and OUT2 to motor 1, and OUT3 and OUT4 to motor 2.
ENA is connected to PWM pin 9, and ENB is connected to PWN pin 10
*/

int motor1_pin1 = 2; // IN1 of L298N
int motor1_pin2 = 3; // IN2 of L298N
int motor2_pin1 = 4; // IN3 of L298N
int motor2_pin2 = 5; // IN4 of L298N
int speedcontrol_1 = 9; // EN1 of L298N
int speedcontrol_2 = 10; // EN1 of L298N

void setup() {
    pinMode(motor1_pin1, OUTPUT);
    pinMode(motor1_pin2, OUTPUT);
    pinMode(motor2_pin1, OUTPUT);
    pinMode(motor2_pin2, OUTPUT);
    pinMode(speedcontrol_1, OUTPUT);
    pinMode(speedcontrol_2, OUTPUT);
}

/* 
The following functions are for controlling the motors
and the input parameters for each function control how long they are on and the speed control (PWM)
*/

void motor_reset(){
// Turns all motors off
  digitalWrite(motor1_pin1, LOW);
  digitalWrite(motor1_pin2, LOW);
  digitalWrite(motor2_pin1, LOW);
  digitalWrite(motor2_pin2, LOW);
  analogWrite(speedcontrol_1, 0);
  analogWrite(speedcontrol_2, 0);
}

void car_move(char direction1 = 'f', int duration = 0, int speed = 0, char direction2 = 'f', int duration2  = 0, int speed2 = 0) {
  // If direction1 or direction2 is "f", turns wheel forward, and if "b", turns it backwards
  if (direction1 == 'f') {
    digitalWrite(motor1_pin1, HIGH);
    digitalWrite(motor1_pin2, LOW);
  }
  if (direction1 == 'b') {
    digitalWrite(motor1_pin1, LOW);
    digitalWrite(motor1_pin2, HIGH);
  }

  if (direction2 == 'f') {
    digitalWrite(motor2_pin1, HIGH);
    digitalWrite(motor2_pin2, LOW);
  }
  if (direction2 == 'b') {
    digitalWrite(motor2_pin1, LOW);
    digitalWrite(motor2_pin2, HIGH);
  }

  analogWrite(speedcontrol_1, speed);
  analogWrite(speedcontrol_2, speed2);
  
  delay(duration)

  motor_reset();
}

// Code Loop

void loop(){
  car_move('f', 1000, 255, 'b', 1000, 75);
  delay(1000);
}