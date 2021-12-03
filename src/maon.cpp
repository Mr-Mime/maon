#include <Arduino.h>

#include "logger.h"
#include "network.h"
#include "storage.h"

void maon_init(void) {
  logger_init();
  network_init();
  storage_init();
}

void maon_loop(void) {
  // Get newest order id from the shop api
  uint16_t server_id = network_get_highest_order_id();

  // Get saved order id, which was highest so far
  uint16_t local_id = storage_get_id();

  log("Server id is: ", server_id);
  log("Local id is : ", local_id);

  // Do stuff if the server id is greater
  if (server_id > local_id) {
    // First store the new id
    storage_set_id(server_id);

    // TODO: Turn transistor for light on
  }
  

  // Finalize things
  network_fini();
  storage_fini();
  logger_fini();

  // Send ESP to sleep
  ESP.deepSleep(6e6);
}
