#define SENSORPIN 4
//Ο δέκτης έχει συνδεθεί στην θέση 4
int sensorState = 0, lastState=0;         // μεταβλητή που θα αποθηκεύει την κατάσταση  καθώς και την προηγούμενη κατάσταση
void setup() {
  //αρχικοποίηση
  pinMode(SENSORPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); // άνοιξε το pullup
    Serial.begin(9600);
}

void loop(){
  // read διαβάζω την κατάσταση του αισθητήρα
  sensorState = digitalRead(SENSORPIN);

  // έλεγχος αν έχει διακοπεί η επικοινωνία
    if (sensorState && !lastState) {
    Serial.println("Unbroken");
  } 
  if (!sensorState && lastState) {
    Serial.println("Broken");
  }
  lastState = sensorState;
}

