#include <AudioZero.h>
#include <SD.h>

const int nextPin = 2;  // the number of the next track pushbutton pin
const int playPin = 3;  // the number of the play pushbutton pin
const int previousPin = 4;  // the number of the previous track pushbutton pin

const int audioOutPin = 14;    // the number of the audio output pin

// variables will change:
int nextButtonState = 0;  // variable for reading the pushbutton status
int playButtonState = 0;  // variable for reading the pushbutton status
int previousButtonState = 0;  // variable for reading the pushbutton status
String currentSong = "";

void playSong() {
  File cs = SD.open(currentSong)
  if (!cs) {
    // if the file didn't open, print an error and stop
    Serial.println("error opening test.wav");
    while (true);  // TODO do i need this? what does it serve?
  }

  Serial.print("Playing");
  AudioZero.play(cs);

  //Serial.println("End of file. Thank you for listening!");
}

void setup() {
  // initialize the audio pin as an output:
  pinMode(audioOutPin, OUTPUT);
  
  // initialize the pushbutton pins as an input:
  pinMode(playPin, INPUT);
  pinMode(nextPin, INPUT);
  pinMode(previousPin, INPUT);

  // debug output at 115200 baud
  Serial.begin(115200);

  // setup SD-card
  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println(" failed!");
    while(true);
  }

  Serial.println(" done.");

  // 44100kHz stereo => 88200 sample rate
  AudioZero.begin(2*44100);

}

void loop() {
  // read the state of the pushbutton value:
  nextButtonState = digitalRead(nextPin);
  playButtonState = digitalRead(playPin);
  previousButtonState = digitalRead(previousPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (playButtonState == PinStatus.HIGH) {
    // turn LED on:
    // digitalWrite(ledPin, HIGH);
    playSong();

  } else if (nextButtonState == HIGH) {
    
  } else if (previousButtonState == HIGH) {

}
