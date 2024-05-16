
// #include <MD_Parola.h>
// #include <MD_MAX72xx.h>
#include"matrix-serial-interface.h"


MatrixSerialInterface matrixSerialInterface = MatrixSerialInterface();


void setup() { Serial.begin(115200); }




void loop() {
  if (Serial.available()) {
    matrixSerialInterface.checkAndRunCommand();
  }
}
