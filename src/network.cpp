#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

#include "logger.h"

// Create client which connects to the webserver
// The secure client is needed to perform a TLS encrypted connection
static HTTPClient http;
static WiFiClientSecure secure_client;

void network_init(void) {
  // Connect to the wifi
  log("Connecting to: ", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASW);

  // Wait until connected
  while (WiFi.status() !=  WL_CONNECTED) {
    delay(500);
    log(".");
  }

  log("Connected to WiFi");
}


int network_get_highest_order_id(void) {
  // Trust the server and connect to it securely
  secure_client.setInsecure();
  secure_client.connect(SERVER_URL, SERVER_PORT);

  if (secure_client.connected()) log("Connected to Server");

  // Pass the API key as authorization and make http connection
  http.setAuthorization(SERVER_API_KEY, "");
  http.begin(secure_client, SERVER_URL);

  // Get the information
  int httpCode = http.GET();

  log("HTTP GET returned: ", httpCode);

  if (httpCode != 200) { //Check the returning code
    return -1;
  } else {
    // Get the request response payload
    String payload = http.getString();

    // Find the last order id
    // End of the JSON looks like this: '{"id":764}]}'
    int index_start = payload.lastIndexOf(":");
    int index_end   = payload.lastIndexOf("]") - 1;
    int highest_id  = atoi(payload.substring(index_start +1, index_end).c_str());
   
    if (highest_id == 0) {
      log(payload);
    }
    return highest_id;
  }
}


void network_fini(void) {
  http.end();   //Close connection
}
