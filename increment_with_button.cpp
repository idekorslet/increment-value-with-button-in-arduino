const int btnUp = 9;
const int btnDown = 8;

bool lastBtnUpState, lastBtnDownState;
bool btnUpPressed, btnDownPressed;

int counter;

void setup() {
  Serial.begin(9600);
  pinMode(btnUp, INPUT);
  pinMode(btnDown, INPUT);
}

void loop() {

  btnUpPressed = digitalRead(btnUp);
  btnDownPressed = digitalRead(btnDown);

  setCounter(btnUpPressed, lastBtnUpState, counter, true);
  setCounter(btnDownPressed, lastBtnDownState, counter, false);
    
  Serial.println(counter);
}

// cara 1 / method 1
void setCounter(bool btnName, bool &lastBtnState, int &varName, bool add) {
  
  if (btnName) {
    if (lastBtnState == LOW) {
      // &var_name      --> mengambil lokasi address
      // *(&var_name)   --> mengambil nilai dilokasi address
      // *(&var_name)+1 --> stlh diambil nilainya kemudian nilainya ditambah 1
      if (add) varName = *(&varName) + 1; else varName = *(&varName) - 1;
    }
    
    lastBtnState = HIGH;
  }
  else 
    lastBtnState = LOW;
}

// cara 2 / method 2
void setCounter2(bool btnName, bool &lastBtnState, bool add) {
  if (btnName) {
    if (lastBtnState == LOW) {
      if (add) counter++; else counter--; // jika add = true --> penambahan, jika false --> pengurangan
    }
    
    lastBtnState = HIGH;
  }
  else 
    lastBtnState = LOW;
}
