#include <NewPing.h>

NewPing s1(12, 11, 200); //sensor 1
NewPing s2(12, 11, 200); //sensor 2
NewPing s3(12, 11, 200); //sensor 3
NewPing s4(12, 11, 200); //sensor 4

int d1, d2, d3, d4; //distancias
int v1=0, v2=0, v3=0, v4=0; //variables inicializadas en cero
String p1, p2; //puertas
int contador=0; //contador de carros


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  //tomar lecturas de los sensores
  d1=s1.ping_cm();
  d2=s2.ping_cm();
  d3=s3.ping_cm();
  d4=s4.ping_cm();

  //aqui viene lo divertido :v

  //comprar si la lectura se encuentra en el rango deseado para cambiar el valo de su variable
  if(d1<40 && d1>=1){
    v1=1;    
  }
  if(d2<40 && d2>=1){
    v2=1;    
  }
  if(d3<40 && d3>=1){
    v3=1;    
  }
  if(d4<40 && d4>=1){
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
    p1="v4";
  }

  //contar de ser necesario
  if(v1==1 && v2==1 && p1=="v1"){
    contador++;
    v1=0;
    v2=0;    
  }else if(v1==1 && v2==1 && p1=="v2"){
    contador--;
    v1=0;
    v2=0;
  }

  if(v3==1 && v4==1 && p1=="v3"){
    contador++;
    v3=0;
    v4=0;    
  }else if(v3==1 && v4==1 && p1=="v4"){
    contador--;
    v3=0;
    v4=0;
  }
  



}
