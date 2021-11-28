   int irsense=7;int irsense1=8;int piezo=A0;int threshold=175;int count=0;int stat=0;int statuss=0;
void setup() {
pinMode(irsense,INPUT);pinMode(irsense1,INPUT);pinMode(piezo,INPUT);Serial.begin(9600);
}
void loop() {
  int status1=digitalRead(irsense);int statuspiezo=analogRead(piezo);int status2=digitalRead(irsense1);
  if(status1==0){
    statuss=1;
    delay(2000);}
    if(statuspiezo>=threshold && statuss==1 && statuspiezo<300){
      count=count+1;
      Serial.println("count:");
      Serial.println(count);
      delay(3000);
      statuss=0;statuspiezo=0;
  }
  else if(statuspiezo>=threshold && statuss==1 && statuspiezo>=1000){
    count=count+2;
    Serial.println("count:");
      Serial.println(count);
      delay(3000);
      statuss=0;statuspiezo=0;
  }
  else if(statuspiezo<threshold && statuss==1){
    Serial.print("no");Serial.println(statuspiezo);statuspiezo=0;statuss=0;
    delay(3000);
  }
   if(status2==0){
    stat=1;
    delay(2000);}
    if(statuspiezo>=threshold && stat==1 && statuspiezo<300){
      count=count-1;
      Serial.println("count:");
      Serial.println(count);
      delay(3000);
      stat=0;statuspiezo=0;
  }
   else if(statuspiezo>=threshold && statuss==1 && statuspiezo>=1000){
    count=count-2;
      Serial.println(count); Serial.println(statuspiezo);
      delay(3000);
      statuss=0;statuspiezo=0;
  }
  else if(statuspiezo<threshold && stat==1){
    Serial.print("no");Serial.println(statuspiezo);statuspiezo=0;stat=0;
    delay(3000);
  }
}
