#include <NewPing.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); // Panata LCD
NewPing s1(12, 11, 200); //sensor 1 (trigger, echo, max distance)
NewPing s2(10, 9, 200); //sensor 2
NewPing s3(8, 7, 200); //sensor 3
NewPing s4(6, 5, 200); //sensor 4
int luces=3; // pin para controlar luces
int d1, d2, d3, d4; //distancias
int v1=0, v2=0, v3=0, v4=0; //variables inicializadas en cero
String p1, p2; //puertas
int contador=0; //contador de carros


void setup() {
   lcd.init(); 
   // initialize the lcd 

  pinMode(luces, OUTPUT);
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Universidad de");
  lcd.setCursor(4,1);
  lcd.print("El Salvador");
  lcd.setCursor(0,3);
  lcd.print("Cargando");

  for(int i=8; i<16; i++){
    lcd.setCursor(i,3);
    lcd.print(".");
    delay(500);
  }
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Encienda las luces");
  lcd.setCursor(4,1);
  lcd.print("en el Tunel");
  lcd.setCursor(3,2);
  lcd.print("Autos dentro:");
  lcd.setCursor(9,3);
  lcd.print(contador);
  
  Serial.begin(9600);

}

void loop() {
  //tomar lecturas de los sensores
  d1=s1.ping_cm();
  d2=s2.ping_cm();
  d3=s3.ping_cm();
  d4=s4.ping_cm();
    

  //comprar si la lectura se encuentra en el rango deseado para cambiar el valo de su variable
  if(d1<20 && d1>=1 && v1==0){
    v1=1;      
  }
  if(d2<20 && d2>=1 && v2==0){
    v2=1;    
  }
  if(d3<20 && d3>=1 && v3==0){
    v3=1;    
  }
  if(d4<20 && d4>=1 && v4==0){
    v4=1;    
  }

  //comprobar que sensor se registro primero
  if(v1==1 && v2==0){
    p1="v1";
  }else if(v1==0 && v2==1){
    p1="v2";
  }

  if(v3==1 && v4==0){
    p2="v3";
  }else if(v3==0 && v4==1){
    p2="v4";
  }

  if(!p1==""){
    //contar de ser necesario
    if(v1==1 && v2==1 && p1=="v1"){
      contador++;
      lcd.setCursor(9,3);
      lcd.print(contador);
      Serial.println(contador);
      v1=0;
      v2=0;
      p1="";
          
    }else if(v1==1 && v2==1 && p1=="v2"){
      contador--;
      lcd.setCursor(9,3);
      lcd.print(contador);
      //Serial.println(contador);
      v1=0;
      v2=0;
      p1="";
      
    }
  }
  if(!p2==""){
    if(v3==1 && v4==1 && p2=="v3"){
      contador--;
      lcd.setCursor(9,3);
      lcd.print(contador);
      //Serial.println(contador);
      v3=0;
      v4=0;
      p2=""; 
          
    }else if(v3==1 && v4==1 && p2=="v4"){
      contador++;
      lcd.setCursor(9,3);
      lcd.print(contador);
      //Serial.println(contador);
      v3=0;
      v4=0;
      p2=""; 
    }
  }

delay(100);

}
