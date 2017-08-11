const int startValue=700;
const int endValue=650;  
void setup() { 

  Serial.begin(9600);
  delay(1000);
}

void loop() { 
  digitalWrite(13,LOW);
delay(500);
  digitalWrite(13,HIGH);
  delay(500);


doTask(A0,2);

doTask(A1,3);
}


void doTask(int sensor,int relay)
{
pinMode(sensor, INPUT);  
pinMode(relay, OUTPUT);  
int sensorValTemp = analogRead(sensor);
  Serial.println("");
  Serial.print("sensor: ");
  Serial.print(sensor);
  Serial.print(" - value: "); 
  Serial.print(sensorValTemp);
  
  Serial.print(" - STATUS: "); 
  
  if(sensorValTemp > startValue ) 
  { 
    digitalWrite (relay, LOW);
    Serial.print(" --ON");
  }
  else if(sensorValTemp <endValue)
  {
    digitalWrite (relay, HIGH);
    Serial.print(" --OFF");
  }
  else
  {
    Serial.print(" --RUNNING"); 
    }
}

