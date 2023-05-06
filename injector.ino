// Potensiometer
int pinA0 =A0;
int pot = 0 ;

// Injektor 0 derajat
unsigned int durasi1 = 1;
unsigned int durasi2 = 2;
unsigned int durasi5 = 3;
int s1 = durasi1;
int s2 = durasi2;
int s5 = durasi5;

// Injektor 70 derajat
float durasi3 = 0.5;
unsigned int durasi4 = 3;
float durasi6 = 0.5;
float s3 = durasi3;
int s4 = durasi4;
float s6 = durasi6;

//Rumus Sensor Suhu
float T0 = 25 + 273.15;

//Define Sensor
#define VCC 5 
#define B 3977 
#define RT0 7200
#define R 7200

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT); //Membuat pin input
  pinMode(A1,INPUT); //Membuat pin input

}

void loop() {

  //Potensiometer
  pot = analogRead(A0);
  pot = map (pot,0,1023,-10,76);

  // Sensor Suhu
  float suhu = analogRead(A1); //Memasukkan nilai A1 ke suhu
  suhu = (5.00 / 1023.00) * suhu; //Rumus Suhu
  float voltage = VCC - suhu;
  float RT = suhu / (voltage/R);
  float ln = log(RT/RT0);
  float sensor = (1/((ln/B) + (1/T0)));
  sensor = (sensor - 249.15) - 15.5 ;

      // Print ke Serial
      Serial.print("TPS : ");
      Serial.print(pot);
      Serial.print("   Suhu : ");
      Serial.println(sensor);

  //Durasi Injeksi saat TPS 0 derajat
  if (pot == 0 && sensor >= 0 && sensor <= 39 || pot == 0 && sensor >= 41 && sensor <= 99){
    //for (s2;s2 > 0 ;s2--){
      Serial.println("Injector Hidup");
      for (s1 = 1;s1 < 5;s1++){
      digitalWrite(6,HIGH);
      Serial.print("TPS : ");
      Serial.print(pot);
      Serial.print("   Suhu : ");
      Serial.print(sensor);
      Serial.print("   Durasi : ");
      Serial.print(s1);
      Serial.println(" mS");
      delay(1000);
    }
    if (pot == 0 && sensor >= 0 && sensor <= 39 || pot == 0 && sensor >= 41 && sensor <= 99){
      //LED Mati
      digitalWrite(6,LOW);
      Serial.println("Injector Mati");
      Serial.println("   ");
      delay(700);
    }}

  //Durasi Injector saat TPS 0 derajat dan Suhu 40
   if (pot == 0 && sensor >= 40 && sensor <= 41 ){
    //for (s2;s2 > 0 ;s2--){
      Serial.println("Injector Hidup");
      for (s5 = 1;s5 < 4;s5++){
      digitalWrite(6,HIGH);
      Serial.print("TPS : ");
      Serial.print(pot);
      Serial.print("   Suhu : ");
      Serial.print(sensor);
      Serial.print("   Durasi : ");
      Serial.print(s5);
      Serial.println(" mS");
      delay(1000);
    }
    if (pot == 0 && sensor >= 40 && sensor <= 41 ){
      //LED Mati
      digitalWrite(6,LOW);
      Serial.println("Injector Mati");
      Serial.println("   ");
      delay(700);
    }}

 //Durasi Injector saat TPS 0 derajat dan Suhu 100
   if (pot == 0 && sensor >= 100 && sensor <= 102 ){
    //for (s2;s2 > 0 ;s2--){
      Serial.println("Injector Hidup");
      for (s5 = 1;s5 < 7;s5++){
      digitalWrite(6,HIGH);
      Serial.print("TPS : ");
      Serial.print(pot);
      Serial.print("   Suhu : ");
      Serial.print(sensor);
      Serial.print("   Durasi : ");
      Serial.print(s5);
      Serial.println(" mS");
      delay(1000);
    }
    if (pot == 0 && sensor >= 100 && sensor <= 102 ){
      //LED Mati
      digitalWrite(6,LOW);
      Serial.println("Injector Mati");
      Serial.println("   ");
      delay(700);
    }}

//Durasi Injeksi saat TPS 70 derajat
  if (pot == 70 && sensor >= 0 && sensor <= 39 || pot == 70 && sensor >= 41 && sensor <= 99){
    //for (s2;s2 > 0 ;s2--){
      Serial.println("Injector Hidup");
      for (s3 = -0.5;s3 < 7;s3++){
      digitalWrite(6,HIGH);
      Serial.print("TPS : ");
      Serial.print(pot);
      Serial.print("   Suhu : ");
      Serial.print(sensor);
      Serial.print("   Durasi : ");
      Serial.print(s3);
      Serial.println(" mS");
      delay(1000);
    }
    if (pot == 70 && sensor >= 0 && sensor <= 39 || pot == 70 && sensor >= 41 && sensor <= 99){
      //LED Mati
      digitalWrite(6,LOW);
      Serial.println("Injector Mati");
      Serial.println("   ");
      delay(700);
    }}

  //Durasi Injector saat TPS 70 derajat dan Suhu 100
   if (pot == 70 && sensor >= 100 && sensor <= 102 ){
    //for (s2;s2 > 0 ;s2--){
      Serial.println("Injector Hidup");
      for (s6 = -0.5 ; s6 < 9 ;s6++){
      digitalWrite(6,HIGH);
      Serial.print("TPS : ");
      Serial.print(pot);
      Serial.print("   Suhu : ");
      Serial.print(sensor);
      Serial.print("   Durasi : ");
      Serial.print(s6);
      Serial.println(" mS");
      delay(1000);
    }
    if (pot == 70 && sensor >= 100 && sensor <= 102 ){
      //LED Mati
      digitalWrite(6,LOW);
      Serial.println("Injector Mati");
      Serial.println("   ");
      delay(700);
    }}

 //Durasi Injector saat TPS 70 derajat dan Suhu 40
   if (pot == 70 && sensor >= 40 && sensor <= 41 ){
    //for (s2;s2 > 0 ;s2--){
      Serial.println("Injector Hidup");
      for (s6 = -0.5 ; s6 < 6 ;s6++){
      digitalWrite(6,HIGH);
      Serial.print("TPS : ");
      Serial.print(pot);
      Serial.print("   Suhu : ");
      Serial.print(sensor);
      Serial.print("   Durasi : ");
      Serial.print(s6);
      Serial.println(" mS");
      delay(1000);
    }
    if (pot == 70 && sensor >= 40 && sensor <= 41 ){
      //LED Mati
      digitalWrite(6,LOW);
      Serial.println("Injector Mati");
      Serial.println("   ");
      delay(700);
    }}

    
    delay(1000);
  }
