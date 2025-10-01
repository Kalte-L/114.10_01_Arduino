const int PushBtn = 11;
const int LedR = 3;
const int LedG = 5;
const int LedB = 6;

String currentcolor = "led";

int BtnState = 0;
int BtnColor = 0;

unsigned long lastClickedTime = 0;

bool IsPressed = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LedR, OUTPUT);
  pinMode(LedG, OUTPUT);
  pinMode(LedB, OUTPUT);
  pinMode(PushBtn, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  BtnState = digitalRead(PushBtn);

  Serial.print("Current Color:");
  Serial.println(currentcolor);

  if (BtnState == LOW && IsPressed == false){
    IsPressed = true;
    unsigned long now = millis();
    if (now - lastClickedTime < 200){
      BtnColor = 5;
    }else {
      if (BtnColor > 4){
        BtnColor = 0;
      }else {
        BtnColor += 1;
      }
    }
    delay(100);
    lastClickedTime = now;
  }
  if (BtnState == HIGH && IsPressed == true){
    IsPressed = false;
  }

  if (BtnColor == 0){
    currentcolor = "Green";
    analogWrite(LedR, 255);
    analogWrite(LedG, 255);
    analogWrite(LedB, 0);
  }else if (BtnColor == 1){
    currentcolor = "Red";
    analogWrite(LedR, 0);
    analogWrite(LedG, 255);
    analogWrite(LedB, 255);
  }else if (BtnColor == 2){
    currentcolor = "Blue";
    analogWrite(LedR, 255);
    analogWrite(LedG, 0);
    analogWrite(LedB, 255);
  }else if (BtnColor == 3){
    currentcolor = "Yellow";
    analogWrite(LedR, 170);
    analogWrite(LedG, 255);
    analogWrite(LedB, 170);
  }else if (BtnColor == 4){
    currentcolor = "Purple";
    analogWrite(LedR, 80);
    analogWrite(LedG, 0);
    analogWrite(LedB, 255);
  }else if (BtnColor == 5){
    currentcolor = "LED off";
    analogWrite(LedR, 255);
    analogWrite(LedG, 255);
    analogWrite(LedB, 255);
  }

}
