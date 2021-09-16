int enA = 0;
int in1 = 2;
int in2 = 14;
int inputPinR = 16; // choose input pin (for Infrared sensor) 
int inputPinM = 5;
int inputPinL = 4;
int Sensor_R;
int Sensor_M;
int Sensor_L;
// variable for reading the pin status


// Motor B

int enB = 15;
int in3 = 12;
int in4 = 13;

void setup()

{

    // Set all the motor control pins to outputs
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(inputPinR, INPUT); // declare Infrared sensor as input
    pinMode(inputPinM, INPUT);
    pinMode(inputPinL, INPUT);
    Serial.begin(9600);
   
}

void robotForward()

{


  // Turn on motor A

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200); // Speedcontrol

  // Turn on motor B

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);// Speedcontrol
  //delay(100);
}
void robotCrawl()

{
  // The robot moves foward slowly until a black line is spotted

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 150); // Speedcontrol

  // Turn on motor B

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 100);// Speedcontrol
  //delay(100);
}
void robotLeft(){  

 // Turn on motor A

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200); // Speedcontrol

  // Turn off motor B

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);// Speedcontrol

}

void robotRight(){  

 // Turn off motor A

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200); // Speedcontrol

  // Turn on motor B

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);// Speedcontrol

}

void robotStop(){  

 // Turn off motor A

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200); // Speedcontrol

  // Turn off motor B

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);// Speedcontrol

}


void loop()

{

Sensor_R = digitalRead(inputPinR);
Sensor_M = digitalRead(inputPinM);
Sensor_L = digitalRead(inputPinL);

Serial.print(Sensor_R);
Serial.print(" ");
Serial.print(Sensor_M);
Serial.print(" ");
Serial.println(Sensor_L);


 if (Sensor_R == 0 && Sensor_L == 0 && Sensor_M == 1){
  robotForward();
 } 
 
 if (Sensor_R == 0 && Sensor_L == 0 && Sensor_M == 0){
  robotCrawl();
 }
 if ((Sensor_R == 0 && Sensor_L == 0 && Sensor_M == 0)||(Sensor_R == 1 && Sensor_L == 1 && Sensor_M == 1)){
  robotStop();
  } 
 if (Sensor_R == 1 && Sensor_L == 0 ){
  robotRight();
  } 
 if (Sensor_R == 0 && Sensor_L == 1 ){
  robotLeft();
  } 

}
