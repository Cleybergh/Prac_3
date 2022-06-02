# Práctica 3b

El objetivo de la práctica és comprender el funcionamiento de BT.

## Código:

```
#include <Arduino.h>
#include "BluetoothSerial.h"
 
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
 
BluetoothSerial SerialBT;
 
void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}
 
void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}

```
## Funcionamiento:

Queremos ver como funciona la comunicación bluetooth entre nuestra placa ESP32 y un teléfono móbil.
Des del teléfono se enviaran los mensajes hacia la maquina y nos saldran los mensajes en la pantalla del ordenador que esté cargando la información al procesador. Necesitaremos descargar una aplicación para el teléfono. 

Una vez estén los dos dispositivos emparejados podremos enviar mensajes directamente a partir de la aplicación de móbil y del terminal del ordenador al móbil también.