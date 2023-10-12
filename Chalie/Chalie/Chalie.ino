
void setup() 
{

  //LED1 ติด
  pinMode(10,OUTPUT);
  digitalWrite(10,LOW);
  pinMode(11,OUTPUT);
  digitalWrite(11,HIGH);
  pinMode(12,INPUT);
  delay(500);

}
void loop() 
{
 
  //10=R1 
  //11=R2
  //12=R3

  //LED2 ติด
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
  pinMode(11,OUTPUT);
  digitalWrite(11,LOW);
  pinMode(12,INPUT);
  delay(500);
  
  //LED3 ติด
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  digitalWrite(11,LOW);
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
  delay(500);

  //LED4 ติด
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  digitalWrite(11,HIGH);
  pinMode(12,OUTPUT);
  digitalWrite(12,LOW);
  delay(500);

  //LED5 ติด
  pinMode(10,OUTPUT);
  digitalWrite(10,LOW);
  pinMode(11,INPUT);
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
  delay(500);
  
  //LED6 ติด
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
  pinMode(11,INPUT);
  pinMode(12,OUTPUT);
  digitalWrite(12,LOW);
  delay(500);

  //LED5 ติด
  pinMode(10,OUTPUT);
  digitalWrite(10,LOW);
  pinMode(11,INPUT);
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
  delay(500);

  //LED4 ติด
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  digitalWrite(11,HIGH);
  pinMode(12,OUTPUT);
  digitalWrite(12,LOW);
  delay(500);

  //LED3 ติด
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  digitalWrite(11,LOW);
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
  delay(500);

  //LED2 ติด
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
  pinMode(11,OUTPUT);
  digitalWrite(11,LOW);
  pinMode(12,INPUT);
  delay(500);

  //LED1 ติด
  pinMode(10,OUTPUT);
  digitalWrite(10,LOW);
  pinMode(11,OUTPUT);
  digitalWrite(11,HIGH);
  pinMode(12,INPUT);
  delay(500);
  
}
