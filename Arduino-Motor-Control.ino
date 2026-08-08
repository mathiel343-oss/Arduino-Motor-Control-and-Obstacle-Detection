#include <Servo.h>

Servo myServo;

#define ENA1 5
#define IN1 2
#define IN2 3
#define ENB1 6
#define IN3 4
#define IN4 7

#define ENA2 11
#define IN5 8
#define IN6 9
#define ENB2 10
#define IN7 12
#define IN8 13

#define TRIG A0
#define ECHO A1
#define SERVO_PIN A2

#define DETECTION_DISTANCE 10
#define SERVO_CENTER 90
#define SERVO_RIGHT 0
#define SERVO_LEFT 180

void setup() {
  pinMode(ENA1, OUTPUT); pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(ENB1, OUTPUT); pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(ENA2, OUTPUT); pinMode(IN5, OUTPUT); pinMode(IN6, OUTPUT);
  pinMode(ENB2, OUTPUT); pinMode(IN7, OUTPUT); pinMode(IN8, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  myServo.attach(SERVO_PIN);
  myServo.write(SERVO_CENTER);

  analogWrite(ENA1, 255);
  analogWrite(ENB1, 255);
  analogWrite(ENA2, 255);
  analogWrite(ENB2, 255);

  Serial.begin(9600);
  stopMotors();
}

void loop() {
  if (!moveForward(30000)) return;
  if (!moveBackward(60000)) return;
  if (!moveRight(30000)) return;
  if (!moveLeft(30000)) return;

  stopMotors();
  delay(1000);
}

bool moveForward(unsigned long duration) {
  unsigned long startTime = millis();
  while (millis() - startTime < duration) {
    if (checkObstacle()) return false;
    forward();
    delay(50);
  }
  stopMotors();
  return true;
}

bool moveBackward(unsigned long duration) {
  unsigned long startTime = millis();
  while (millis() - startTime < duration) {
    if (checkObstacle()) return false;
    backward();
    delay(50);
  }
  stopMotors();
  return true;
}

bool moveRight(unsigned long duration) {
  unsigned long startTime = millis();
  while (millis() - startTime < duration) {
    if (checkObstacle()) return false;
    turnRight();
    delay(50);
  }
  stopMotors();
  return true;
}

bool moveLeft(unsigned long duration) {
  unsigned long startTime = millis();
  while (millis() - startTime < duration) {
    if (checkObstacle()) return false;
    turnLeft();
    delay(50);
  }
  stopMotors();
  return true;
}

bool checkObstacle() {
  long distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= DETECTION_DISTANCE) {
    stopMotors();

    myServo.write(SERVO_RIGHT);
    delay(700);

    myServo.write(SERVO_LEFT);
    delay(700);

    myServo.write(SERVO_CENTER);
    delay(700);

    backward();
    delay(2000);

    stopMotors();
    delay(500);

    return true;
  }

  return false;
}

long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000);

  if (duration == 0) return 999;

  return duration * 0.034 / 2;
}

void forward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  digitalWrite(IN5, HIGH); digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH); digitalWrite(IN8, LOW);
}

void backward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  digitalWrite(IN5, LOW); digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW); digitalWrite(IN8, HIGH);
}

void turnRight() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW); digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW); digitalWrite(IN8, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  digitalWrite(IN5, HIGH); digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH); digitalWrite(IN8, LOW);
}

void stopMotors() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW); digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW); digitalWrite(IN8, LOW);
}
