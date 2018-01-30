/*turn on and turn off 3 LEDs */

const int LED1 = 52;
const int LED2 = 48;
const int LED3 = 44;
const int LEDR = 4;
const int LEDG = 5;
const int LEDB = 6;

const int BOTTON = 40;
const int SUBMIT = 36;

int b = 0;
int v = 0;
  
void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  Serial.println("Serial conection started");
  // initialize led and bottonS
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(BOTTON, INPUT);
  pinMode(SUBMIT, INPUT);
}

void loop() {
  if(digitalRead(BOTTON) == HIGH) {
      b+=10;
      Serial.println("B:" + String(b));
      Serial.println("V:" + String(v));
      Serial.println("-");
      animation();
   }

  if(digitalRead(SUBMIT) == HIGH) {
      v+=15;
      Serial.println("B:" + String(b));
      Serial.println("V:" + String(v));
      Serial.println("-");
            
      analogWrite(LEDR, 96);
      analogWrite(LEDG, 70);
      analogWrite(LEDB, 0);
      delay(500);
      analogWrite(LEDR, 0);
      analogWrite(LEDG, 0);
      analogWrite(LEDB, 0);
   }

  if(Serial.available() > 0){
    
    String command = Serial.readString();//readLine
    Serial.println(command);
    update_leds(command);
    
  }
  
}



void update_leds(String led){//char
  if (led == "y") {
    digitalWrite(LED1, HIGH);
    delay(300);
    digitalWrite(LED1, LOW);
    return;
  }
  if (led == "g") {
    digitalWrite(LED2, HIGH);
    delay(300);
    digitalWrite(LED2, LOW);
    return;
  }
  if (led == "r") {
    digitalWrite(LED3, HIGH);
    delay(300);
    digitalWrite(LED3, LOW);
    return;
  }
  if (led == "TURN_ON_1") {
    digitalWrite(LED3, HIGH);
    return;
  }  
  if (led == "TURN_OFF_1") {
    digitalWrite(LED3, LOW);
    return;
  }  
  if (led == "TURN_ON_2") {
    digitalWrite(LED2, HIGH);
    return;
  }  
  if (led == "TURN_OFF_2") {
    digitalWrite(LED2, LOW);
    return;
  }
  if (led == "TURN_ON_3") {
    digitalWrite(LED1, HIGH);
    return;
  }  
  if (led == "TURN_OFF_3") {
    digitalWrite(LED1, LOW);
    return;
  }    
  if (led == "a") {
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

