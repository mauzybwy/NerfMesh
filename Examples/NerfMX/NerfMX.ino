#include <SPI.h>
#include <printf.h>

#include "RF24.h"
#include "NerfMesh.h"

NerfMesh nerf;

void setup() {
  Serial.begin(115200);
  printf_begin();

  nerf.begin(0x33);
}

void loop() {
  if(Serial.available()){
    switch(toupper(Serial.read())){
    case 'T':
      nerf.PingAddress(0x22);
      break;
    case 'S':
      nerf.PrintRadioDetails();
      break;
    case 'F':
      nerf.FindNeighbors();
      break;
    case 'N':
      nerf.PrintNeighbors();
      break;
    case 'D':
      nerf.PrintRoutingDirectory();
      break;
    }
  }
}