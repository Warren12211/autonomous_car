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

void motor1_f(int delay_time = 1000, int PWM = 255){
// Turns motor 1 forward
  // Resets all motors
  motor_reset();

  // Sets the pins to  make the first motor go forward
  digitalWrite(motor1_pin1, HIGH);
  digitalWrite(motor1_pin2, LOW);

  // Sends the PWM pulses to the L298N using the variable declared in the function
  analogWrite(speedcontrol_1, PWM);
  analogWrite(speedcontrol_2, PWM);

  // Runs the motor as long as 
  delay(delay_time);
  motor_reset();  
}

void motor1_b(int delay_time = 1000, int PWM = 255){
// Turns motor 1 backward
  motor_reset();
  digitalWrite(motor1_pin1, LOW);
  digitalWrite(motor1_pin2, HIGH);
  analogWrite(speedcontrol_1, PWM);
  analogWrite(speedcontrol_2, PWM);
  delay(delay_time);
  motor_reset();  
}

void motor2_f(int delay_time = 1000, int PWM = 255){
// Turns motor 2 forward
  motor_reset();
  digitalWrite(motor2_pin1, HIGH);
  digitalWrite(motor2_pin2, LOW);
  delay(delay_time);
  motor_reset();  
}

void motor2_b(int delay_time = 1000, int PWM = 255){
// Turns motor 2 backward
  motor_reset();  
  digitalWrite(motor2_pin1, LOW);
  digitalWrite(motor2_pin2, HIGH);
  delay(delay_time);
  motor_reset();  
}

void motor1and2_f(int delay_time = 1000, int PWM = 255){
  // Turns motor 1 and 2 forward
     motor_reset();
     digitalWrite(motor1_pin1, HIGH);
     digitalWrite(motor1_pin2, LOW);
     digitalWrite(motor2_pin1, HIGH);
     digitalWrite(motor1_pin2, LOW);
     analogWrite(speedcontrol_1, PWM);
     analogWrite(speedcontrol_2, PWM);
     delay(delay_time);
     motor_reset();
}

void motor1and2_b(int delay_time = 1000, int PWM = 255){
  // Turns motor 1 and 2 backwards
     motor_reset();
     digitalWrite(motor1_pin1, LOW);
     digitalWrite(motor1_pin2, HIGH);
     digitalWrite(motor2_pin1, LOW);
     digitalWrite(motor2_pin2, HIGH);
     analogWrite(speedcontrol_1, PWM);
     analogWrite(speedcontrol_2, PWM);
     delay(delay_time);
     motor_reset();
}

void loop() {
// Tests each function 
  delay(1000);
  motor1and2_f(3000);


  
  delay(1000);
  motor1_b(1000);
  delay(1000);
  motor2_f(1000);
  delay(1000);
  motor2_b(1000);
  delay(1000);
  motor1and2_f(1000);
  delay(1000);
  motor1and2_b(1000);
  delay(1000);
}