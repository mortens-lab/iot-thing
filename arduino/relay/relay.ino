#define SDA     22 
#define SCL     23 
#define LED_R   15
#define LED_G   14
#define LED_B   13
#define RELAY   25
#define LEDSTR1 16
#define LEDSTR2 17
#define LEDSTR3 18
#define LEDSTR4 19
#define SW      21
#define GPIO26  26
#define GPIO27  27
#define GPIO32  32
#define GPIO33  33
#define GPIO34  34
#define GPIO35  35


void setup() 
{
  pinMode(RELAY, OUTPUT);
  pinMode(SW, INPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  digitalWrite(RELAY, LOW);  
  digitalWrite(LED_R, HIGH);  
  digitalWrite(LED_G, HIGH);  
  digitalWrite(LED_B, HIGH);  
  delay(1000);
  digitalWrite(LED_R, LOW);    // RED
  delay(1000);
  digitalWrite(LED_R, HIGH);  
  delay(300);
  digitalWrite(LED_G, LOW);    // GREEN
  delay(1000);
  digitalWrite(LED_G, HIGH);  
  delay(300);
  digitalWrite(LED_B, LOW);    // BLUE
  delay(1000);
  digitalWrite(LED_B, HIGH);  
  delay(300);
}


void loop() 
{
  if (digitalRead(SW)==1)
  {
    digitalWrite(RELAY, LOW);  
    digitalWrite(LED_R, HIGH);  
  }
  else
  {
    digitalWrite(RELAY, HIGH);  
    digitalWrite(LED_R, LOW);  
  }
}
