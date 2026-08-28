#include <Servo.h>

// =========================
// Servo Objects
// =========================
Servo frontLeft;
Servo frontRight;
Servo rearRight;
Servo rearLeft;

// =========================
// Pin Mapping
// =========================
const int FL_PIN = 11;
const int FR_PIN = 10;
const int RR_PIN = 9;
const int RL_PIN = 8;

// =========================
// Neutral / Standing Angles
// Adjust these if your robot
// does not stand straight.
// =========================
const int FL_CENTER = 90;
const int FR_CENTER = 90;
const int RR_CENTER = 90;
const int RL_CENTER = 90;

// =========================
// Helper Function
// =========================
void moveAll(int fl, int fr, int rr, int rl, int waitTime = 400) {
  frontLeft.write(fl);
  frontRight.write(fr);
  rearRight.write(rr);
  rearLeft.write(rl);
  delay(waitTime);
}

// =========================
// Stand
// =========================
void standPosition() {
  moveAll(
    FL_CENTER,
    FR_CENTER,
    RR_CENTER,
    RL_CENTER,
    500
  );
}

// =========================
// Sit
// =========================
void sitPosition() {
  // Front legs stay almost upright
  // Rear legs fold backward
  moveAll(
    FL_CENTER,
    FR_CENTER,
    55,
    125,
    700
  );
}

// =========================
// Handshake
// =========================
void handshake() {
  sitPosition();
  delay(400);

  // Lift front-right leg
  frontRight.write(45);
  delay(800);

  // Small handshake movement
  for (int i = 0; i < 3; i++) {
    frontRight.write(55);
    delay(250);

    frontRight.write(40);
    delay(250);
  }

  frontRight.write(FR_CENTER);
  delay(500);
}

// =========================
// Fist Bump
// =========================
void fistBump() {
  standPosition();
  delay(300);

  // Raise front-right leg while standing
  frontRight.write(40);
  delay(700);

  // Small forward "bump"
  frontRight.write(55);
  delay(250);

  frontRight.write(40);
  delay(250);

  frontRight.write(FR_CENTER);
  delay(500);
}

// =========================
// Dance
// =========================
void dance() {

  standPosition();
  delay(300);

  for (int i = 0; i < 5; i++) {

    // Front Left forward
    frontLeft.write(60);

    // Front Right backward
    frontRight.write(120);

    // Rear Right forward
    rearRight.write(60);

    // Rear Left backward
    rearLeft.write(120);

    delay(300);

    // Reverse direction
    frontLeft.write(120);
    frontRight.write(60);
    rearRight.write(120);
    rearLeft.write(60);

    delay(300);
  }

  standPosition();
}

// =========================
// Print Command Menu
// =========================
void printMenu() {
  Serial.println("================================");
  Serial.println("        REX IS READY!");
  Serial.println("================================");
  Serial.println("D = Dance");
  Serial.println("S = Sit");
  Serial.println("H = Handshake");
  Serial.println("F = Fist Bump");
  Serial.println("X = Stand");
  Serial.println("? = Show this menu");
  Serial.println("================================");
}

// =========================
// Setup
// =========================
void setup() {

  Serial.begin(9600);

  frontLeft.attach(FL_PIN);
  frontRight.attach(FR_PIN);
  rearRight.attach(RR_PIN);
  rearLeft.attach(RL_PIN);

  standPosition();

  printMenu();
}

// =========================
// Main Loop
// =========================
void loop() {

  if (Serial.available() > 0) {

    char command = Serial.read();

    // Ignore line endings and spaces sent by the Serial Monitor
    if (command == '\r' || command == '\n' || command == ' ') {
      return;
    }

    switch (command) {

      case 'D':
      case 'd':
        Serial.println("Dance");
        dance();
        break;

      case 'S':
      case 's':
        Serial.println("Sit");
        sitPosition();
        break;

      case 'H':
      case 'h':
        Serial.println("Handshake");
        handshake();
        break;

      case 'F':
      case 'f':
        Serial.println("Fist Bump");
        fistBump();
        break;

      case 'X':
      case 'x':
        Serial.println("Stand");
        standPosition();
        break;

      case '?':
        printMenu();
        break;

      default:
        Serial.print("Unknown command: ");
        Serial.println(command);
        Serial.println("Send ? for the list of commands.");
        break;
    }
  }
}