

int inputPin=4; // signal receiver pin ECHO to D2 
int outputPin=5; // signal transmitter pin TRIG to D5


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  // start serial communication at this speed
 pinMode(inputPin, INPUT); 
 pinMode(outputPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(outputPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH); 

  delayMicroseconds(10); 
  digitalWrite(outputPin, LOW);

  int distance = pulseIn(inputPin, HIGH);    // Read receiver pulse time 
  distance= distance/58;                     // Transform pulse time to distance 
  Serial.println(distance);                  //Output distancedelay(50);
  delay(1000);
  Serial.print(distance);            // send the number to Serial port
  Serial.println();          // send New Line to Serial port
  delay(15000);             // wait for 15 sec (Thingspeakupdate rate)

}
