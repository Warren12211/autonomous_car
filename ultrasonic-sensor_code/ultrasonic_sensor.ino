int trigger = 12;
int echo = 13;

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

// A function I started adding in all of my code that sets all pins to LOW 
// to make sure that no pins are accidentally left HIGH
void reset_pins() {
  digitalWrite(trigger, LOW);
  digitalWrite(echo, LOW);
}

void loop() {
  // Ultrasonic sensors send out a 10 microsecond pulse at the speed of light
  // and the echo pin stays high until it receives that pulse back
  // Using that value, we can determine how far way a solid object ike a wall is
  // using the equation "speed * time"
  // We then divide that value by 2 because we only need half of the time since
  // the time that it takes the pulse to travel back is counted too

  reset_pins();
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  int duration = pulseIn(echo, HIGH);
  int distance = ceil(duration * 0.0133 / 2);
  Serial.println(distance);
  delay(50);
}
