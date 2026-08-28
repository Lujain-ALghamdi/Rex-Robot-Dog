# 🐕  Rex — Arduino Robot Dog

Meet **Rex**, a four-legged robotic dog built using an **Arduino UNO** and four servo motors.

Rex was designed as a simple robotics project that combines hardware assembly, servo control, serial communication, and basic robotic movements.

Rex can perform several actions, including:

- 🕺 Dance
- 🪑 Sit
- 🤝 Handshake
- 👊 Fist Bump
- 🐕 Stand

---

## 📸 Meet Rex

<img width="450" height="762" alt="5803430411487612791_121" src="https://github.com/user-attachments/assets/7cc4e9f2-657f-4141-bc5f-78986a597a89" /><img width="450" height="762" alt="لقطة شاشة 2026-08-29 012116" src="https://github.com/user-attachments/assets/7baebf28-ba54-4436-ad31-e0a8a061a693" />


Rex uses four independently controlled servo motors, with one servo controlling each leg.

---

## 🛠️ Hardware Components

The project uses:

- Arduino UNO
- 4 × Servo Motors
- Breadboard
- Jumper Wires
- USB Cable
- 3D-printed Robot Dog Chassis
- Computer running Arduino IDE

---

## 🔌 Servo Connections

Each servo has three connections:

- **Red** → Power (+)
- **Brown / Black** → Ground (-)
- **Yellow / Orange** → Signal

The servo signal pins are connected to the Arduino as follows:

| Leg | Arduino Pin |
|---|---|
| Front Left | D11 |
| Front Right | D10 |
| Rear Right | D9 |
| Rear Left | D8 |

### Pin Mapping

```text
             REX
          FRONT
      ┌───────────┐
      │           │
 D11 ─┤ FL     FR ├─ D10
      │           │
 D8  ─┤ RL     RR ├─ D9
      │           │
      └───────────┘
           REAR
```

---

## 💻 Software

Rex is programmed using the **Arduino IDE** and the Arduino `Servo` library.

The program communicates with Rex through the USB Serial connection.

Serial communication speed:

```text
9600 baud
```

---

## 🎮 Commands

After uploading the program, open:

**Tools → Serial Monitor**

Set the Serial Monitor to:

```text
9600 baud
```

Then send one of the following commands:

| Command | Action |
|---|---|
| `D` | Dance |
| `S` | Sit |
| `H` | Handshake |
| `F` | Fist Bump |
| `X` | Stand |
| `?` | Print the command menu |

Lowercase commands are also supported. Any other character is reported back as an unknown command.

### Example

Send:

```text
D
```

Rex will perform his dance routine.

Send:

```text
H
```

Rex will sit and raise his front leg for a handshake.

Send:

```text
F
```

Rex will perform a fist-bump gesture while standing.

---

## 🕺 Rex's Movements

### Dance

During the dance routine, Rex repeatedly moves his four legs forward and backward, creating a rhythmic dancing motion.

### Sit

Rex changes the position of his rear legs to create a sitting posture.

### Handshake

Rex first enters the sitting position and then raises his front-right leg to perform a handshake motion.

### Fist Bump

While standing, Rex raises his front-right leg and performs a short movement to simulate a fist bump.

### Stand

Rex returns all four legs to their neutral standing positions.

---

## 🚀 How to Run Rex

1. Connect Rex's Arduino UNO to the computer using USB.
2. Open **Arduino IDE**.
3. Open `Rex_Robot_Dog.ino`.
4. Select:

   **Tools → Board → Arduino UNO**

5. Select the correct COM port.
6. Click **Upload**.
7. Wait for the program to upload successfully.
8. Open **Tools → Serial Monitor**.
9. Set the baud rate to **9600**.
10. Enter a command such as `D`, `S`, `H`, `F`, or `X`.
11. Press **Enter** and watch Rex perform the selected action.

---

## 🧠 How It Works

The Arduino controls four servo motors using the `Servo.h` library.

Each servo represents one of Rex's legs:

```cpp
frontLeft.attach(11);
frontRight.attach(10);
rearRight.attach(9);
rearLeft.attach(8);
```

Different servo angles are combined to create different poses and movements.

The Arduino also listens for commands through Serial communication:

```cpp
if (Serial.available() > 0) {
    char command = Serial.read();
}
```

The received command determines which movement function Rex performs.

---

## 📂 Project Structure

```text
Rex-Robot-Dog/
│
├── Rex_Robot_Dog.ino     # Main Arduino program
├── README.md             # Project documentation
├── LICENSE               # Project license
└── images/
    └── rex.jpg           # Photo of Rex
```

---

## 🔮 Future Improvements

Possible future upgrades for Rex include:

- Bluetooth control
- Wireless mobile control
- Ultrasonic obstacle detection
- Additional movement patterns
- Remote-control interface
- Autonomous walking
- Improved walking balance
- Additional sensors
- Custom control panel

---

## ⚠️ Notes

Servo angles may need minor calibration depending on the mechanical orientation of each servo.

Avoid forcing a servo beyond the physical movement limits of the robot chassis.

Multiple servo motors can draw significant current. For more demanding operation, an appropriate external servo power supply with a common ground should be considered.
