// Definir los pines
const int ledRed1 = 13; 
const int ledGreen1 = 11; 
const int ledBlue1 = 12; 

const int ledRed2 = 10;
const int ledGreen2 = 8;
const int ledBlue2 = 9;

const int ledRed3 = 7;
const int ledGreen3 = 5;
const int ledBlue3 = 6;

// Definir el switch
#define switchPin 4

void setup() {
    pinMode(ledRed1, OUTPUT);
    pinMode(ledGreen1, OUTPUT);
    pinMode(ledBlue1, OUTPUT);

    pinMode(ledRed2, OUTPUT);
    pinMode(ledGreen2, OUTPUT);
    pinMode(ledBlue2, OUTPUT);

    pinMode(ledRed3, OUTPUT);
    pinMode(ledGreen3, OUTPUT);
    pinMode(ledBlue3, OUTPUT);
  
    pinMode(switchPin, INPUT);
  
    Serial.begin(9600);
}

void loop() {
    int statu = digitalRead(switchPin);

    if (statu == HIGH) {
        while (digitalRead(switchPin) == HIGH) {
            // Semáforo 1
            Serial.println("Semaforo 1 esta en verde, semaforo 2 en rojo, semaforo 3 en rojo.");
            activateTrafficLight1();
            setTrafficLightColor(ledRed2, ledGreen2, ledBlue2, 255, 0, 0); 
            setTrafficLightColor(ledRed3, ledGreen3, ledBlue3, 255, 0, 0); 
            delay(1000);

            if (digitalRead(switchPin) == LOW) break;

            // Semáforo 2
            Serial.println("Semaforo 2 esta en verde, semaforo 1 en rojo, semaforo 3 en rojo.");
            activateTrafficLight2(); 
            setTrafficLightColor(ledRed1, ledGreen1, ledBlue1, 255, 0, 0); 
            setTrafficLightColor(ledRed3, ledGreen3, ledBlue3, 255, 0, 0); 
            delay(1000);

            if (digitalRead(switchPin) == LOW) break;

            // Semáforo 3
            Serial.println("Semaforo 3 esta en verde, semaforo 1 en rojo, semaforo 2 en rojo.");
            activateTrafficLight3(); 
            setTrafficLightColor(ledRed1, ledGreen1, ledBlue1, 255, 0, 0); 
            setTrafficLightColor(ledRed2, ledGreen2, ledBlue2, 255, 0, 0); 
            delay(1000);

            if (digitalRead(switchPin) == LOW) break;
        }
    } else {
        Serial.println("Interruptor apagado, semaforos parpadearan en amarillo.");
        flashYellowLights();
    }
}

// Crear funciones
void setTrafficLightColor(int redPin, int greenPin, int bluePin, int r, int g, int b) {
    analogWrite(redPin, r);
    analogWrite(greenPin, g);
    analogWrite(bluePin, b);
}

void activateTrafficLight1() {
    setTrafficLightColor(ledRed1, ledGreen1, ledBlue1, 0, 255, 0); // Verde
}

void activateTrafficLight2() {
    setTrafficLightColor(ledRed2, ledGreen2, ledBlue2, 0, 255, 0); // Verde
}

void activateTrafficLight3() {
    setTrafficLightColor(ledRed3, ledGreen3, ledBlue3, 0, 255, 0); // Verde
}

void flashYellowLights() {
    for (int i = 0; i < 5; i++) { 
        setTrafficLightColor(ledRed1, ledGreen1, ledBlue1, 255, 255, 0); // Amarillo
        setTrafficLightColor(ledRed2, ledGreen2, ledBlue2, 255, 255, 0);
        setTrafficLightColor(ledRed3, ledGreen3, ledBlue3, 255, 255, 0);
        delay(500);
        setTrafficLightColor(ledRed1, ledGreen1, ledBlue1, 0, 0, 0); // Apagar
        setTrafficLightColor(ledRed2, ledGreen2, ledBlue2, 0, 0, 0);
        setTrafficLightColor(ledRed3, ledGreen3, ledBlue3, 0, 0, 0);
        delay(500);
    }
}
