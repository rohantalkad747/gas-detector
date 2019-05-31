#include <SoftwareSerial.h>

// Right components are "A"s and Left componnts are "B"s 
#define MOTOR_A 12
#define MOTOR_B 13
#define ROTOR_A 3
#define ROTOR_B 11

// Blinking lights
#define L_LIGHT 4
#define R_LIGHT 5

// Sensors

#define GREEN_THRESHOLD 300
#define RED_THRESHOLD 400
#define DANGER_THRESHOLD 500

#define SMOKE_INPUT A5
#define BUZZER 2

// Define pulse width modulation (how much power there is in the wheels)
// This makes the car go about ~0.5 m/s straight
#define LEFT_MODULATION 80
#define RIGHT_MODULATION 200


void setup() {

  Serial.begin(9600);
  
  pinMode(MOTOR_A, OUTPUT);
  pinMode(MOTOR_B, OUTPUT);

  pinMode(L_LIGHT, OUTPUT);
  pinMode(R_LIGHT, OUTPUT);

  pinMode(SMOKE_INPUT, INPUT);
  pinMode(BUZZER, OUTPUT);
  
  analogWrite(ROTOR_A, 0);
  analogWrite(ROTOR_B, 0);
  delay(5000);

}

void loop() {
  Serial.println(analogRead(SMOKE_INPUT));
  paintLights();
  delay(1000);
// goForward(4000);
//  goHardLeft(500);
//  goForward(2000);
//  goHardRight(500);
  

  
  
  // Hard right for 1 second then forward for 1 second
}

void goForward(long ms) {
  // Move forward for 2 seconds
  
  digitalWrite(MOTOR_A, HIGH);
  digitalWrite(MOTOR_B, HIGH);

  analogWrite(ROTOR_A, RIGHT_MODULATION + 50);
  analogWrite(ROTOR_B, LEFT_MODULATION + 50);


  delay(ms);
  
  // Hold previous instruction for specified amount of time
}

void goHardRight(long ms) {

  digitalWrite(MOTOR_A, LOW);
  digitalWrite(MOTOR_B, HIGH);

  analogWrite(ROTOR_A, RIGHT_MODULATION + 50);
  analogWrite(ROTOR_B, LEFT_MODULATION);

  delay(ms);
}


void goHardLeft(long ms) {

  digitalWrite(MOTOR_A, HIGH);
  digitalWrite(MOTOR_B, LOW);

  analogWrite(ROTOR_A, RIGHT_MODULATION);
  analogWrite(ROTOR_B, LEFT_MODULATION + 50);

  delay(ms);
}

void paintLights() {
  int value = analogRead(SMOKE_INPUT);
  if (value < GREEN_THRESHOLD) {
    digitalWrite(R_LIGHT, HIGH);
    digitalWrite(L_LIGHT, LOW);
    tone(BUZZER, 1000, 100);
  }
  else if (value < RED_THRESHOLD) {
    digitalWrite(R_LIGHT, LOW);
    digitalWrite(L_LIGHT, HIGH);
    tone(BUZZER, 1000, 300);
  }
  else {
    digitalWrite(R_LIGHT, HIGH);
    digitalWrite(L_LIGHT, HIGH);
    tone(BUZZER, 1000, 500);
  }
}
