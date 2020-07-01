#include <VescUart.h>

constexpr bool CAN = false;
constexpr float startRPM = 100.0;
constexpr float endRPM = 1000.0;
float rpm = startRPM;

VescUart UART;

void setup() {
  Serial.begin(115200);

  while (!Serial) {
    ;
  }

  UART.setSerialPort(&Serial);
}

void loop() {
  if (CAN) {
    UART.setRPMCAN(0, rpm);
    UART.setRPMCAN(1, endRPM - (rpm - startRPM));
  } else {
    UART.setRPM(100.0);
  }

  rpm++;
  if (rpm > endRPM) {
    rpm = endRPM;
  }
  delay(10);
}
