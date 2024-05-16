
enum SI_COMMAND {
  NO_OP = 0,
  SET_PIN = 1,
  SET_DATA = 2,
};

class MatrixSerialInterface {
public:
  int CS_PIN = 0, CLK_PIN = 0, DATA_PIN = 0;
  bool INITIALIZED = false;
  SI_COMMAND cmd = SI_COMMAND::NO_OP;

  bool checkAndRunCommand(){
    
  }

private:
/** Funciton to set pins from string
 * @param pins String formate pin in `CLK`,`CS`,`DATA`
 * @return `true` if pins set sucessfully other false
*/
  bool setPins(String pins) {
    if (INITIALIZED) {
      Serial.println("Already initialized!");
      return false;
    }

    int lastsplit = 0, j = 0;
    int pins_arr[] = {0, 0, 0};
    for (int i = 0; i < pins.length(); i++) {
      if (pins[i] == ',' || i == pins.length() - 1) {
        pins_arr[j] = pins.substring(lastsplit, i).toInt();
        Serial.print("Pin");
        Serial.print(pins_arr[j]);
        lastsplit = i + 1;
        j++;
      }
    }
  }
  
  
  void executeCommand() {
  switch (cmd) {
  case SET_PIN: {
    setPins(Serial.readString());
  } break;

  default:
    String data = Serial.readString();
    Serial.println(cmd);
    Serial.println("NO COMMAND FOUND");
    break;
  }
  cmd = NO_OP;
}

};