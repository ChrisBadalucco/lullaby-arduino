const int nextPin = 4;  // the number of the next track pushbutton pin
const int playPausePin = 3;  // the number of the play/pause pushbutton pin
const int previousPin = 4;  // the number of the previous track pushbutton pin

const int audioOutPin = 14;    // the number of the audio output pin

// variables will change:
int playPausButtonState = 0;  // variable for reading the pushbutton status
int nextButtonState = 0;  // variable for reading the pushbutton status
int previousButtonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the audio pin as an output:
  pinMode(audioOutPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(playPausePin, INPUT);
  pinMode(nextPin, INPUT);
  pinMode(previousPin, INPUT);

}

void loop() {
  // read the state of the pushbutton value:
  nextButtonState = digitalRead(nextPin);
  playPausButtonState = digitalRead(playPausePin);
  previousButtonState = digitalRead(previousPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

}
