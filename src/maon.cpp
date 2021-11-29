#include <Arduino.h>

#include "logger.h"
#include "network.h"

void maon_init(void) {
  logger_init();
  log("CPU running at: ", esp_get_cpu_freq_mhz());
  network_init();
}

void maon_loop(void) {

}
