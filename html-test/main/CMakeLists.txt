idf_component_register(SRCS "main.c" "my-wifi/my_wifi.c"
                       INCLUDE_DIRS "."
                       REQUIRES esp_wifi nvs_flash)
