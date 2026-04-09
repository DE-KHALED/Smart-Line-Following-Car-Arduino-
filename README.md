# Smart-Line-Following-Car-Arduino-
This project presents the design and implementation of an autonomous line-following car using Arduino Uno, IR sensors, and a PID control system.
The robot detects and follows a black line on a white surface by continuously adjusting motor speeds based on real-time sensor feedback.

⚙️ Technologies Used
Arduino Uno REV3
C/C++ (Arduino programming)
IR Reflectance Sensors
L298N Motor Driver
PID Control Algorithm
🧠 How It Works
IR sensors detect the position of the line
Sensor readings are converted into an error value (-2 to +2)
A PID controller calculates correction
Motor speeds are adjusted dynamically for smooth tracking
🔌 Hardware Components
Arduino Uno
L298N Motor Driver
DC Motors
IR Sensors (x3)
KYS002 Chassis
12V Battery
📄 Documentation

Full project documentation available here:
👉 docs/Smart_Line_Following_Car.pdf

🎥 Demo
https://drive.google.com/file/d/1X6QHNf0wLn-Tk8HGMoN_ANME5L-VhfHt/view?usp=sharing

🚀 Key Features
Real-time feedback control using PID
Sensor calibration for accuracy
Smooth navigation on curved paths
