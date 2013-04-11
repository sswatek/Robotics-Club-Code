//Simple Bluetooth Rover Demo
//Takes a Bluetooth signal and controls a robot to move around
//at full speed

int ltop=8;
int lbot=9;
int rtop=10;
int rbot=11;

void setup(){
  Serial1.begin(115200);
  pinMode(ltop,OUTPUT);
  pinMode(lbot,OUTPUT);
  pinMode(rtop,OUTPUT);
  pinMode(rbot,OUTPUT);
}

int right=1;
int left=1;

void loop(){
  switch(right){
    case 1:
      digitalWrite(rtop,HIGH);
      digitalWrite(rbot,LOW);
      break;
    case 0:
      digitalWrite(rtop,LOW);
      digitalWrite(rbot,LOW);
      break;
    case -1:
      digitalWrite(rtop,LOW);
      digitalWrite(rbot,HIGH);
      break;
  }
  switch(left){
    case 1:
      digitalWrite(ltop,HIGH);
      digitalWrite(lbot,LOW);
      break;
    case 0:
      digitalWrite(ltop,LOW);
      digitalWrite(lbot,LOW);
      break;
    case -1:
      digitalWrite(ltop,LOW);
      digitalWrite(lbot,HIGH);
      break;
  }
  while(Serial.available()==0);
  int tmpchar=Serial.read();
  Serial1.write(tmpchar);
  switch(tmpchar){
    default:
      right=0;
      left=0;
      break;
    case 'w':
      right=1;
      left=1;
      break;
    case 's':
      right=-1;
      left=-1;
      break;
    case 'a':
      right=1;
      left=-1;
      break;
    case 'd':
      right=-1;
      left=1;
      break;
  }
}
      
  
