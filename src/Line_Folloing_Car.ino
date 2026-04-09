#define irl A0
#define irm A1
#define irr A2
// Motor driver pins
int mot11 = 2, mot12 = 3;
int mot21 = 4, mot22 = 5;
// PWM speed pins
int mot1sp = 6, mot2sp = 9;
// Sensor readings
int readl, readm, readr;
// Control variables
int error = 0, lastError = 0;
int right = 90, left = 90;
int integral = 0, derivative = 0, correction = 0;
// PID gains (tune these)
float kp = 10.0, ki = 0.2, kd = 15.0;
void setup() {
// Configure motor driver pins as outputspinMode(mot11, OUTPUT);
pinMode(mot12, OUTPUT);
pinMode(mot21, OUTPUT);
pinMode(mot22, OUTPUT);
pinMode(mot1sp, OUTPUT);
pinMode(mot2sp, OUTPUT);
}
void loop() {
// Reset to base speed each cycle
left = 125;
right = 125;
// 1. Read IR sensors (left, middle, right)
readl = analogRead(irl);
readm = analogRead(irm);
readr = analogRead(irr);
// 2. Determine error based on sensor pattern
if (readl < 100 && readm < 100 && readr > 100)
error = -2; // far right sensor sees line
else if (readl < 100 && readm > 100 && readr > 100) error = -1; // middle+right
else if (readl < 100 && readm > 100 && readr < 100) error = 0; // centered
else if (readl > 100 && readm > 100 && readr < 100) error = 1; // left+middle
else if (readl > 100 && readm < 100 && readr < 100) error = 2; // far left sensor sees line
// 3. PID calculations
integral += error;
// accumulate error over time
derivative = error - lastError;
// rate of change
correction = (int)((kp * error)
// P-term
+ (ki * integral)
// I-term
+ (kd * derivative)); // D-term
lastError = error;
// store for next derivative
if (error != 0) {
// 4a. Adjust speeds based on correction
left = constrain(left - correction, 0, 120);
right = constrain(right + correction, 0, 120);
// 4b. Set motor directions to turn
if (error < 0) {
// turn right
digitalWrite(mot11, LOW);
digitalWrite(mot12, HIGH);
digitalWrite(mot21, HIGH);
digitalWrite(mot22, LOW);
}
else {
// turn left (error > 0)
digitalWrite(mot11, HIGH);
digitalWrite(mot12, LOW);
digitalWrite(mot21, LOW);
digitalWrite(mot22, HIGH);
}
// 4c. Apply PWM speeds
analogWrite(mot1sp, right);
analogWrite(mot2sp, left);
}else if (readl > 100 && readm > 100 && readr > 100) {
// 5. All white: stop motors
analogWrite(mot1sp, 0);
analogWrite(mot2sp, 0);
}
else {
// 6. On-line but error == 0: drive forward
digitalWrite(mot11, HIGH);
digitalWrite(mot12, LOW);
digitalWrite(mot21, HIGH);
digitalWrite(mot22, LOW);
analogWrite(mot1sp, right);
analogWrite(mot2sp, left);
}
// 7. Loop delay for stability
_delay_ms(20);
}
