#ifndef _WIFI_H_
#define _WIFI_H_
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include <string.h>

#define SSID "oneplusace5"
#define PWD "qwqaa2333"

void wifi_start(void);

#endif
