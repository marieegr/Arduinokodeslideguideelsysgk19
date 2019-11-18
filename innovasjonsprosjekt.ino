#define trigPin1 7
  #define echoPin1 6
  #define trigPin2 5
  #define echoPin2 4
 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

int value1 = 5000   ;
int value2 = 5000   ;

void loop() {
  // put your main code here, to run repeatedly:
  long duration2, distance2;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;
  if (value2>distance2) {
    value2=distance2;
  }
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  distance = (duration/2) / 29.1;
  if (value1>distance) {
    value1=distance;
  }

if (distance < 500 || distance < 0 ) {
  if (distance <= value1 ) {
    value1 = distance;
    Serial.print("a1");
    Serial.print(value1);
    Serial.print(" \n");
    }
}

if ( distance2 < 500 || distance2 <  0) {
  if ( distance2 <= value2) {
    value2 = distance2;
    Serial.print("a2");
    Serial.print(value2);
    Serial.print(" \n");
    }
}

  Serial.println();
  delay(50);
}
/*
if value1 < value2 {
  kat = value2 - value1
  }
else {
  kat = value1 - value2
  }
  //teta = tan(kat/200)
*/
