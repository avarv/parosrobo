int switchPin = 2;
int ledPin = 13 ;
boolean lastButton = LOW;
boolean currentButton = LOW;
boolean Started = false;
boolean timer = false;
long startTime;
long endTime;
long randomTime;
float elapsedTime;

void setup()
{
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
boolean debounce(boolean last)
{
  boolean current = digitalRead(switchPin);
  if(last != current)
  {
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}

void loop()
{
  currentButton = debounce(lastButton);
  if(lastButton == LOW && currentButton == HIGH)
  {
    Started = !Started;
    lastButton = HIGH;
  }
  lastButton = currentButton;
  if(Started == true && timer == false)
  {
    Random();
    timer = true;
  }
  if(Started == false && timer == true)
  {
    Stop();
    timer = false;
  }
 
}
void Random()
{
  randomTime = random(4,10); //σε τυχαία χρονική στιγμή μεταξύ 4 και 10 sec ανάβει το led
  randomTime = randomTime*1000;
 
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(randomTime);
  Start();
}


void Start(){
  startTime = millis();
  digitalWrite(ledPin, HIGH);
}

void Stop(){
  endTime = millis();
  elapsedTime = (endTime - startTime)+5;
  elapsedTime = elapsedTime/1000;
  Serial.print("Time Seconds: ");
  Serial.println(elapsedTime);
  digitalWrite(ledPin, LOW);
   
}

