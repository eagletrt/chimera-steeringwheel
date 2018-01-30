/* A simple program to sequentially turn on and turn off 3 LEDs */

const int LED1 = 52;
const int LED2 = 48;
const int LED3 = 44;
const int BOTTON = 40;
const int SUBMIT = 36;

String inData = "";
char recieved;
int a = 0;

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  Serial.print("Serial conection started");
  // initialize led and bottonS
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BOTTON, INPUT);
  pinMode(SUBMIT, INPUT);
}

void loop() {
  if(digitalRead(BOTTON) == HIGH) {
      a++;
   }

  if(digitalRead(SUBMIT) == HIGH) {
      Serial.println(a);
      animation();
   }
  
  if(Serial.available() > 0){
    inData = ""; // Clear Buffer
    while(Serial.available() > 0){
      recieved = Serial.read();
      update_leds(recieved);
      inData.concat(recieved);
    }
    Serial.println(inData);
    Serial.flush();

  }
}


void update_leds(char led){
  if (led == 'y') {
    digitalWrite(LED1, HIGH);
    delay(300);
    digitalWrite(LED1, LOW);
    return;
  }
  if (led == 'g') {
    digitalWrite(LED2, HIGH);
    delay(300);
    digitalWrite(LED2, LOW);
    return;
  }
  if (led == 'r') {
    digitalWrite(LED3, HIGH);
    delay(300);
    digitalWrite(LED3, LOW);
    return;
  }
  if (led == 'a') {
    animation();
    return;
  }

  return;
}

void animation(){
  digitalWrite(LED1, HIGH);    // turn on LED1
  delay(100);                  // wait for 200ms
  digitalWrite(LED2, HIGH);    // turn on LED2
  delay(100);                  // wait for 200ms
  digitalWrite(LED3, HIGH);    // turn on LED3
  delay(100);                  // wait for 200ms
  digitalWrite(LED1, LOW);     // turn off LED1
  delay(100);                  // wait for 200ms
  digitalWrite(LED2, LOW);     // turn off LED2
  delay(100);                  // wait for 200ms
  digitalWrite(LED3, LOW);     // turn off LED3
  delay(100);

  digitalWrite(LED3, HIGH);    // turn on LED1
  delay(100);                  // wait for 200ms
  digitalWrite(LED2, HIGH);    // turn on LED2
  delay(100);                  // wait for 200ms
  digitalWrite(LED1, HIGH);    // turn on LED3
  delay(100);                  // wait for 200ms
  digitalWrite(LED3, LOW);     // turn off LED1
  delay(100);                  // wait for 200ms
  digitalWrite(LED2, LOW);     // turn off LED2
  delay(100);                  // wait for 200ms
  digitalWrite(LED1, LOW);     // turn off LED3
  delay(100);
}

