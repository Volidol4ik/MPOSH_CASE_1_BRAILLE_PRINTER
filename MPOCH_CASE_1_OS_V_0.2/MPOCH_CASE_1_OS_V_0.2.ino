#include <SoftwareSerial.h>

#define SOL_1 6
#define SOL_2 7
#define SOL_3 8
#define SOL_4 9
#define SOL_5 10
#define SOL_6 11

const int dirPin_HIGH = 2;
const int stepPin_HIGH = 3;

const int dirPin_DOWN = 4;
const int stepPin_DOWN = 5;

const byte rxPin = 12;
const byte txPin = 13;


const int Stepp_for_liter = 200;  // шаг для перехода с буквы на букву (при умножении на счетчик идет в крайнее положение) длинна буквы == шаг
const int Stepp_for_Probel = 200; // шаг для символа пробела "_"
const int Stepp_for_hod = 200; // шаг для перехода строки

int n;
int timer = 0;

int command;
String text;


SoftwareSerial mySerial (rxPin, txPin);


void setup() {
  pinMode(stepPin_HIGH, OUTPUT);
  pinMode(dirPin_HIGH, OUTPUT);

  pinMode(stepPin_DOWN, OUTPUT);
  pinMode(dirPin_DOWN, OUTPUT);

  Serial.begin(31250);
  mySerial.begin(31250);

  pinMode(SOL_1, OUTPUT);
  pinMode(SOL_2, OUTPUT);
  pinMode(SOL_3, OUTPUT);
  pinMode(SOL_4, OUTPUT);
  pinMode(SOL_5, OUTPUT);
  pinMode(SOL_6, OUTPUT);

}

void loop() {
if(mySerial.available() > 0) {
  String data = mySerial.readStringUntil('\n');
  Serial.println(data);
  if( data.startsWith("строка") == true && timer == 0 ) {
    command = 1;
    text = data.substring(12);
    timer = 1;
  }
  else if( data.startsWith("текст") == true && timer == 0 ) {
    command = 2;
    text = data.substring(10);
    timer = 1;
  }
  else if( data.startsWith("список") == true && timer == 0 ) {
    command =  3;
   text = data.substring(12);
   timer = 1;
  }
    Serial.println(text);
    Serial.println(command);
}



  switch(command){
  case 1: // не привышает количество символов в одной строчке
  if(n <= 19){               //!!!!!!!!!!!!!!!!!!!
      if_for_liter_printing(text);
  n =  n + 1;
  }
  else {
  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);
  }

  break;

  case 2: // текст неффиксированной длинны
  if(n < 20){
      if_for_liter_printing(text);                       // направление
  n++;
  } else {
    digitalWrite(dirPin_DOWN, HIGH);                         // направление
    for(int x = 0; x < Stepp_for_hod; x++)
    {
    digitalWrite(stepPin_DOWN, HIGH);
    delayMicroseconds(2500);
    digitalWrite(stepPin_DOWN, LOW);              // перемещение валика
    delayMicroseconds(2500);
    }
   digitalWrite(dirPin_HIGH, LOW);                          // направление
    for(int x = 0; x < (Stepp_for_liter * n); x++)          // перенос сроки
    {
    digitalWrite(stepPin_HIGH, HIGH);
    delayMicroseconds(2500);
    digitalWrite(stepPin_HIGH, LOW);
    delayMicroseconds(2500);
    }
   n == 0;
  }
  break;

  case 3:

  Priting_for_list(text);

  break;
  }
}

void if_for_liter_printing(String printeted){

const int limit = 100; // время для настройки соленойда

for(int lit = 0; lit < (printeted.length() + 1); lit++ ){

  char liter = printeted[lit];

  switch(liter) {
   case  'а':
  digitalWrite(SOL_1, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
    break;

   case 'б':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_3, LOW);
    break;

   case 'в':
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);
  
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_6, LOW);
    break;

   case 'г':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  
  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
    break;

   case 'д':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  
  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_4, LOW);
    break;

  case 'е':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_4, LOW);
    break;

   case 'ё':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_6, LOW);
    break;

    case 'ж':
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);

  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
    break;

    case 'з':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);
    break; 

    case 'и':
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);


  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
    break; 

    case 'й':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);
    break; 

    case 'к':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_5, LOW);
    break; 

    case 'л':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_5, LOW);
    break; 


    case 'м':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_5, LOW);
    break; 

    case 'н':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
    break; 

    case 'о':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
    break; 

    case 'п':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_5, LOW);
    break; 

   case 'р':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
    break; 

  case 'с':
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_5, LOW);
    break; 

   case 'т':
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
    break;
      
   case 'у':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);
    break; 

   case 'ф':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
    break; 

   case 'х':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
    break; 

   case 'ц':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
    break;

   case 'ч':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
    break; 

   case 'ш':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_6, LOW);
    break; 

   case 'щ':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);
    break; 

   case 'ъ':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);
    break;

   case 'ы':
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);
    break;

   case 'ь':
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);
    break;

   case 'э':
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_6, LOW);
    break;

   case 'ю':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_6, LOW);
    break;

   case 'я':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_6, LOW);
    break;

   case '_':
  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);

       digitalWrite(dirPin_HIGH, HIGH);                         // направление
    for(int x = 0; x < Stepp_for_Probel; x++)
   {
    digitalWrite(stepPin_HIGH, HIGH);
    delayMicroseconds(2500);
    digitalWrite(stepPin_HIGH, LOW);
    delayMicroseconds(2500);
   }
    break;

   case '.':
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_6, LOW);
    break;

   case ',':
  digitalWrite(SOL_3, HIGH);
  delay(limit);

  digitalWrite(SOL_3, LOW);
    break;

   case '!':
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
    break;

   case '?':
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_6, LOW);
    break;
    // условие с интом
  }


  digitalWrite(dirPin_HIGH, HIGH);                         // направление
    for(int x = 0; x < Stepp_for_liter; x++)
   {
    digitalWrite(stepPin_HIGH, HIGH);       // расстояние между буквами
    delayMicroseconds(2500);
    digitalWrite(stepPin_HIGH, LOW);
    delayMicroseconds(2500);
   }


}
    
}




void Priting_for_list(String printeted){

const int limit = 100; // время для настройки соленойда

for(int lit = 0; lit < (printeted.length() + 1); lit++ ){

  int list = 0;

  char liter = printeted[lit];

  switch(liter) {
   case  'а':
  digitalWrite(SOL_1, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
    break;

   case 'б':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_3, LOW);
    break;

   case 'в':
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);
  
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_6, LOW);
    break;

   case 'г':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  
  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
    break;

   case 'д':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  
  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_4, LOW);
    break;

  case 'е':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_4, LOW);
    break;

   case 'ё':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_6, LOW);
    break;

    case 'ж':
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);

  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
    break;

    case 'з':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);
    break; 

    case 'и':
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);


  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
    break; 

    case 'й':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);
    break; 

    case 'к':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_5, LOW);
    break; 

    case 'л':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_5, LOW);
    break; 


    case 'м':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_5, LOW);
    break; 

    case 'н':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
    break; 

    case 'о':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
    break; 

    case 'п':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_5, LOW);
    break; 

   case 'р':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
    break; 

  case 'с':
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_5, LOW);
    break; 

   case 'т':
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
    break;
      
   case 'у':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);
    break; 

   case 'ф':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
    break; 

   case 'х':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
    break; 

   case 'ц':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
    break;

   case 'ч':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
    break; 

   case 'ш':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_6, LOW);
    break; 

   case 'щ':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);
    break; 

   case 'ъ':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);
    break;

   case 'ы':
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);
    break;

   case 'ь':
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);
    break;

   case 'э':
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_6, LOW);
    break;

   case 'ю':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_6, LOW);
    break;

   case 'я':
  digitalWrite(SOL_1, HIGH);
  delay(limit);
  digitalWrite(SOL_2, HIGH);
  delay(limit);
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_6, LOW);
    break;

   case '_':
  digitalWrite(SOL_1, LOW);
  digitalWrite(SOL_2, LOW);
  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
  digitalWrite(SOL_6, LOW);

      digitalWrite(dirPin_DOWN, HIGH);                         // направление
    for(int x = 0; x < Stepp_for_hod; x++)
    {
    digitalWrite(stepPin_DOWN, HIGH);
    delayMicroseconds(2500);
    digitalWrite(stepPin_DOWN, LOW);              // перемещение валика
    delayMicroseconds(2500);
    }
   digitalWrite(dirPin_HIGH, LOW);                          // направление
    for(int x = 0; x < (Stepp_for_liter * list); x++)          // перенос сроки
    {
    digitalWrite(stepPin_HIGH, HIGH);
    delayMicroseconds(2500);
    digitalWrite(stepPin_HIGH, LOW);
    delayMicroseconds(2500);
    }
    list = 0;

    break;

   case '.':
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_6, LOW);
    break;

   case ',':
  digitalWrite(SOL_3, HIGH);
  delay(limit);

  digitalWrite(SOL_3, LOW);
    break;

   case '!':
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_4, HIGH);
  delay(limit);
  digitalWrite(SOL_5, HIGH);
  delay(limit);

  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_4, LOW);
  digitalWrite(SOL_5, LOW);
    break;

   case '?':
  digitalWrite(SOL_3, HIGH);
  delay(limit);
  digitalWrite(SOL_6, HIGH);
  delay(limit);

  digitalWrite(SOL_3, LOW);
  digitalWrite(SOL_6, LOW);
    break;
    // условие с интом
  }


  digitalWrite(dirPin_HIGH, HIGH);                         // направление
    for(int x = 0; x < Stepp_for_liter; x++)
   {
    digitalWrite(stepPin_HIGH, HIGH);       // расстояние между буквами
    delayMicroseconds(2500);
    digitalWrite(stepPin_HIGH, LOW);
    delayMicroseconds(2500);
   }

   lit++ ;

}
    
}