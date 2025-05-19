#include<Adafruit_CircuitPlayground.h>
int hero = 0;
int enemy;
int rb;
int lb;
int captured = 0;
int t = 0;
//bool gameActive = false;

//#define BUZZER_PIN 9

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_DB3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_EB3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST     0

int melody[] = {
  NOTE_C4, REST, NOTE_G4, REST, NOTE_AS4, NOTE_C5, NOTE_AS4, REST, NOTE_F4, NOTE_DS4, REST,
  NOTE_C4, REST, NOTE_G4, REST, NOTE_AS4, NOTE_C5, NOTE_AS4, REST, NOTE_F4, NOTE_DS4, REST,
  NOTE_C4, REST, NOTE_G4, REST, NOTE_AS4, NOTE_C5, NOTE_AS4, REST, NOTE_F4, NOTE_DS4, REST,

  NOTE_C4, REST, NOTE_E4, REST, NOTE_G4, NOTE_A4, NOTE_AS4,
  NOTE_C5, REST, NOTE_C5, REST, NOTE_AS4, REST, NOTE_A4, REST,
  NOTE_AS4, REST, NOTE_AS4, NOTE_C5, REST, NOTE_AS4, NOTE_A4, REST,
  REST,
  NOTE_C5, REST, NOTE_AS4, REST, NOTE_A4, REST, NOTE_AS4, REST, NOTE_E5,
  REST,

  NOTE_C5, REST, NOTE_C5, REST, NOTE_AS4, REST, NOTE_A4, REST,
  NOTE_AS4, REST, NOTE_AS4, NOTE_C5, REST, NOTE_AS4, NOTE_A4, REST,
  REST,
  NOTE_C5, REST, NOTE_AS4, REST, NOTE_A4, REST, NOTE_AS4, REST, NOTE_E4,
  REST,
};

int durations[] = {
  4, 8, 4, 8, 4, 8, 8, 16, 8, 8, 16,
  4, 8, 4, 8, 4, 8, 8, 16, 8, 8, 16,
  4, 8, 4, 8, 4, 8, 8, 16, 8, 8, 16,

  4, 8, 4, 8, 4, 4, 4,
  8, 16, 8, 16, 8, 16, 8, 16,
  8, 16, 8, 8, 16, 8, 8, 16,
  4,
  8, 16, 8, 16, 8, 16, 8, 4, 8,
  4,

  8, 16, 8, 16, 8, 16, 8, 16,
  8, 16, 8, 8, 16, 8, 8, 16,
  4,
  8, 16, 8, 16, 8, 16, 8, 4, 8,
  1
};

void setup() {
  CircuitPlayground.begin();
  enemy = random(0, 10);
  //pinMode(BUZZER_PIN, OUTPUT);
}

void color(int p, int r, int g, int b){
  CircuitPlayground.setPixelColor(p,r,g,b);
}

void colorAll(){
  for(int i = 0; i < 10; i++){
    CircuitPlayground.setPixelColor(i,0,255,0);
  }
}
void rainbow(){
  for(int i = 0; i < 10; i++){
    CircuitPlayground.setPixelColor(i,CircuitPlayground.colorWheel(i * 25.5));
  }
}

void losingColors(){
  color(0,255,0,0);
  color(1,0,0,255);
  color(2,255,0,0);
  color(3,0,0,255);
  color(4,255,0,0);
  color(5,0,0,255);
  color(6,255,0,0);
  color(7,0,0,255);
  color(8,255,0,0);
  color(9,0,0,255);
}

//void restartGame(){
 // CircuitPlayground.clearPixels( );
  //gameActive = true;
//}

void loop( ){
  CircuitPlayground.clearPixels( );
  color( hero, 0, 0, 255 );   
  color( enemy, 255, 0, 0 ) ; 
  rb = CircuitPlayground.rightButton();
  lb = CircuitPlayground.leftButton();
  int size = sizeof(durations) / sizeof(int);
  if(rb == 1){
    hero += 1;
  }
  if(hero == 10){
    hero = 0;
  }
  if(lb == 1){
    hero -= 1;
  }
  if(hero == -1){
    hero = 9;
  }
  if(hero == enemy){
    CircuitPlayground.playTone(261,50);
    CircuitPlayground.playTone(294,50);
    CircuitPlayground.playTone(523,50);
    enemy = random(0,10);
    captured++;
  }
  
//    if (gameActive) {
//     if(t > 100){
//       losingColors();
//       delay(1000);
//       CircuitPlayground.clearPixels();
//       delay(1000);
//     }else {
//       if(t < 100 && captured == 5){
//       rainbow();
//       for (int note = 0; note < size; note++) {
//         int duration = 900 / durations[note];
//         CircuitPlayground.playTone(melody[note],duration);
//         Serial.println(melody[note]);
//         int pauseBetweenNotes = duration * 1.30;
//         delay(pauseBetweenNotes);
//       }
//     }
//   }
// }

  // if(captured == 5){
  //   rainbow();
  //   for (int note = 0; note < size; note++) {
  //     int duration = 900 / durations[note];
  //     CircuitPlayground.playTone(melody[note],duration);
  //     Serial.println(melody[note]);
  //     int pauseBetweenNotes = duration * 1.30;
  //     delay(pauseBetweenNotes);
  //   }
  // }
  if(t > 100){
    losingColors();
    delay(1000);
    CircuitPlayground.clearPixels();
    delay(1000);
    //tone(BUZZER_PIN, 1000); //Send 1KHz sound signal
    //delay(1000);
    //noTone(BUZZER_PIN); //Stop sound
    //delay(1000);

    //restartGame();
  }else if(t < 100 && captured == 5){
    rainbow();
    for (int note = 0; note < size; note++) {
      int duration = 900 / durations[note];
      CircuitPlayground.playTone(melody[note],duration);
      Serial.println(melody[note]);
      int pauseBetweenNotes = duration * 1.30;
      delay(pauseBetweenNotes);
    }
  }

  t++;
  delay(100);
}