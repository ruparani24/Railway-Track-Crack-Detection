#define trigPin1 A5////right
#define echoPin1 A4
#define irs A0
#define m1 2
#define m2 3

#define buzzer A2

long duration, distance,sensor1,sensor2; 
String latitude ="28.6759786";//28.6759786,77.4357733
String longitude="";
int temp=0,i,ir=0;  
boolean Serial_status=0;
int counter =0;
void setup()
{
  Serial.begin(9600);  ///baudrate bps
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  //digitalWrite(buzzer,HIGH);
  delay(10000);
  digitalWrite(buzzer,HIGH);
  delay(1000);
 digitalWrite(buzzer,LOW);
 delay(1000);
 // tracking();
} 
  
void loop()
{
  ir=digitalRead(irs);
  ultrasensor(trigPin1, echoPin1);
  sensor1 = distance;
  Serial.println(sensor1);
  //delay(50);
   if(ir==LOW)
   {
    digitalWrite(buzzer, HIGH);
    digitalWrite(m1, LOW); 
    digitalWrite(m2, LOW); 
   tracking(); 
  }
  else if ((sensor1<20) &&( sensor1>=2))
  {
    digitalWrite(buzzer, HIGH);
   digitalWrite(m1, LOW); 
   digitalWrite(m2, LOW); 
   tracking1();
  }
 
  else 
  {
   digitalWrite(buzzer,LOW);
   digitalWrite(m1, HIGH);
   digitalWrite(m2, HIGH);
  }
 delay(100);
}

 void init_sms()
 {
  Serial.println("AT+CMGF=1");
  delay(400);
  Serial.println("AT+CMGS=\"+918742960961\"");   // use your 10 digit cell no. here
  delay(400);
 }
  void init_sms1()
 {
  Serial.println("AT+CMGF=1");
  delay(400);
  Serial.println("AT+CMGS=\"+919368389316\"");   // use your 10 digit cell no. here
  delay(400);
 }
  
 void send_data(String message)
 {
  Serial.println(message);
  delay(200);
 }
 
 void send_sms()
 {
  Serial.write(26);
 }
 
 void tracking()
 {
  init_sms();
  send_data("Track fault");
  //send_data(latitude);
   //send_data("Longitude:");
   //send_data(longitude);
  send_sms();
  delay(5000);
  init_sms1();
  send_data("Track fault");
  //send_data(latitude);
   //send_data("Longitude:");
   //send_data(longitude);
  send_sms();
  delay(5000);
 }
 
 void tracking1()
 {
  init_sms();
  send_data("Obstraction Ahead");
  
  send_sms();
  delay(5000);
   init_sms1();
  send_data("Obstraction Ahead");
  send_sms();
  delay(5000);
 }
 
 void ultrasensor(int trigPin,int echoPin)
 { 
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 }
