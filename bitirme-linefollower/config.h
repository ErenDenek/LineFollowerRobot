#define in1 6
#define in2 9
#define in3 10
#define in4 11

int analogPin[6] = {A0, A1, A2, A3, A4, A5};
int maxVal[6],minVal[6];
int sens[6];

unsigned long numerator, denominator;
double average;

float kp = 0.2, kd = 10.0;
int maxSpeed= 70;

int rM, lM;
int speedCar = 0, wheelCar = 0, recordData = 0;

String sendData;
char sends[50];
