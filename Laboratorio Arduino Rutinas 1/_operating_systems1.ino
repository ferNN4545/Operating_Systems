const int green = 11;
const int red = 12;
const int orange = 13;

int estadoGreen = LOW;
int estadoRed = LOW;
int estadoOrange = LOW;
bool lucesEncendidas = false; 
bool parpadeoActivo = false;  
unsigned long tiempoParpadeo = 0; 
const unsigned long intervaloParpadeo = 500; 

void setup() {
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(orange, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char option = Serial.read();
    
    switch(option) {
      case '1': 
        controlarLuz(green, HIGH);
        estadoGreen = HIGH;
        break;
      
      case '2':
        toggleLuz(green, estadoGreen);
        break;
      
      case '3':
        controlarLuz(red, HIGH);
        estadoRed = HIGH;
        break;
      
      case '4':
        toggleLuz(red, estadoRed);
        break;
      
      case '5':
        controlarLuz(orange, HIGH);
        estadoOrange = HIGH;
        break;
      
      case '6':
        toggleLuz(orange, estadoOrange);
        break;
      
      case '7':
        controlarTodas(HIGH);
        Serial.println("Luces Prendidas");
        lucesEncendidas = true; 
        break;
      
      case '8':
        if (lucesEncendidas) {
          controlarTodas(LOW);
          Serial.println("Luces Apagadas");
        } else {
          controlarTodas(HIGH);
          Serial.println("Luces Encendidas");
        }
        lucesEncendidas = !lucesEncendidas; 
        break;
      
      case '9':
        if (parpadeoActivo) {
          parpadeoActivo = false; 
          controlarTodas(LOW); 
          Serial.println("Parpadeo Detenido");
        } else {
          parpadeoActivo = true; 
          Serial.println("Parpadeo Iniciado");
        }
        break;
      
      default:
        Serial.println("Opción no válida");
        break;
    }
  }

  if (parpadeoActivo) {
    unsigned long tiempoActual = millis();
    if (tiempoActual - tiempoParpadeo >= intervaloParpadeo) {
      if (digitalRead(green) == HIGH) {
        controlarTodas(LOW);
      } else {
        controlarTodas(HIGH);
      }
      tiempoParpadeo = tiempoActual;
    }
  }
}

void toggleLuz(int luz, int &estado) {
  if (estado == LOW) {
    digitalWrite(luz, HIGH);
    estado = HIGH;
    Serial.print("Luz ");
    Serial.print(luz);
    Serial.println(" prendida");
  } else {
    digitalWrite(luz, LOW);
    estado = LOW;
    Serial.print("Luz ");
    Serial.print(luz);
    Serial.println(" apagada");
  }
}

void controlarLuz(int luz, int estado) {
  digitalWrite(luz, estado);
}

void controlarTodas(int estado) {
  digitalWrite(green, estado);
  digitalWrite(red, estado);
  digitalWrite(orange, estado);
}

