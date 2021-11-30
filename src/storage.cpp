#include <EEPROM.h>

#include "logger.h"

#define MAGIC_STR "maon"

static unsigned int id_addr   = 0x00; // 2 Byte
static unsigned int magic_addr= 0x02; // 4 Byte ("maon")

void storage_init(void) {
  EEPROM.begin(sizeof(uint16_t) + 4 * sizeof(char));

  // Check if EEPROM has been formated
  char magic[5];
  EEPROM.get(magic_addr, magic);

  if (strncmp(magic, MAGIC_STR, 4)) {
    // Format EEPROM
    log("Formatting EEPROM");

    EEPROM.put(id_addr, 0);
    EEPROM.put(magic_addr, MAGIC_STR);
    EEPROM.commit();
  }
}


uint16_t storage_get_id(void) {
  uint16_t id;
  EEPROM.get(id_addr, id);

  return id;
}


void storage_set_id(uint16_t id) {
  EEPROM.put(id_addr, id);
  EEPROM.commit();
}


void storage_fini(void) {
  EEPROM.end();
}
