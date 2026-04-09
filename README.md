This project presents the design and implementation of an autonomous line-following car using an Arduino Uno, IR sensors, and a PID control system.
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
A PID controller calculates the correction
Motor speeds are dynamically adjusted for smooth and stable tracking

🔌 Hardware Components
Arduino Uno
L298N Motor Driver
DC Motors
IR Sensors (×3)
KYS002 Smart Car Chassis
12V Battery

📄 Documentation

Full project documentation is available here:
👉 [Project Documentation](https://github.com/DE-KHALED/Smart-Line-Following-Car-Arduino-/blob/main/docs/Smart_Line_Following_Car.pdf)

🎥 Demo

Watch the project in action:
👉 [Video](https://drive.google.com/file/d/1X6QHNf0wLn-Tk8HGMoN_ANME5L-VhfHt/view?usp=sharing)

🚀 Key Features
Real-time feedback control using PID
Sensor calibration for improved accuracy
Smooth navigation across straight and curved paths
📈 What I Learned
Embedded systems programming with Arduino
PID control implementation and tuning
Sensor calibration and signal processing
Hardware and software integration
👨‍💻 Author

Khaled Assaf
