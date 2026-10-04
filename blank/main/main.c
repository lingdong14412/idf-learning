/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#include "sdkconfig.h"


void my_gpio(){
    gpio_config_t led={
        .intr_type=GPIO_INTR_DISABLE,
        .mode=GPIO_MODE_OUTPUT,
        .pin_bit_mask=1ULL<<GPIO_NUM_2,
        .pull_down_en=GPIO_PULLDOWN_DISABLE,
        .pull_up_en=GPIO_PULLUP_DISABLE,
    };
    gpio_config(&led);


}


void app_main(){
    my_gpio();
    gpio_set_level(2,1);






}