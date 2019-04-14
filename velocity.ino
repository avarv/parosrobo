int trigPin = 11;    // Trigger PIN για τον sensor
int echoPin = 12;    // Echo pin για τον sensor
long duration, cm; //ορισμός μεταβλητών
 
void setup() {
  //άνοιγμα σειριακής
  Serial.begin (9600);
  //ποιες πόρτες αποτελούν την έισοδο και την έξοδο
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {
  // Δίνω έναν παλμό low και στη συνέχεια ένα παλμό HIGH για 10 ή περισσότερα microseconds.
   digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Διαβάζουμε το σήμα από τον δέκτη και υπολογίζουμε την διαφορά του χρόνου από την στιγμή που στείλαμε HIGH
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
// Μετατροπή του χρόνου σε εκατοστά
  cm = (duration/2) / 29.1;     // Divide by 29.1
Serial.print(millis());
Serial.print("ms ");
Serial.print(cm);
Serial.print("cm");
Serial.println();
  
  delay(250);
}

