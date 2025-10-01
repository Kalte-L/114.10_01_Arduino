const int PushBtn = 11;
const int LedR = 3;
const int LedG = 5;
const int LedB = 6;

int BtnState = 0;
int BtnColor = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LedR, OUTPUT);
  pinMode(LedG, OUTPUT);
  pinMode(LedB, OUTPUT);
  pinMode(PushBtn, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  BtnState = digitalRead(PushBtn);
  if (BtnState == HIGH){
    if (BtnColor > 4){
      BtnColor = 0;
      delay(500);
    }else {
      BtnColor += 1;
      delay(500);
    }
  }

  if (BtnColor == 0){
    analogWrite(LedR, 255);
    analogWrite(LedG, 255);
    analogWrite(LedB, 0);
  }else if (BtnColor == 1){
    analogWrite(LedR, 0);
    analogWrite(LedG, 255);
    analogWrite(LedB, 255);
  }else if (BtnColor == 2){
    analogWrite(LedR, 255);
    analogWrite(LedG, 0);
    analogWrite(LedB, 255);
  }else if (BtnColor == 3){
    analogWrite(LedR, 170);
    analogWrite(LedG, 255);
    analogWrite(LedB, 170);
  }else if (BtnColor == 4){
    analogWrite(LedR, 80);
    analogWrite(LedG, 0);
    analogWrite(LedB, 255);
  }else if (BtnColor == 5){
    analogWrite(LedR, 255);
    analogWrite(LedG, 255);
    analogWrite(LedB, 255);
  }

}
