/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "driver/gptimer.h"
#include "driver/gpio.h"

gptimer_handle_t gptim;

void gpio_init(){
    gpio_config_t gpio_cfg={
        .mode=GPIO_MODE_OUTPUT,
        .pin_bit_mask=(1<<GPIO_NUM_2),
        .pull_down_en=GPIO_PULLDOWN_DISABLE,
        .pull_up_en=GPIO_PULLUP_ENABLE,
        .intr_type=GPIO_INTR_DISABLE
    };
    gpio_config(&gpio_cfg);
}

static bool led_level=0;
bool TimerCallback(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_ctx)
{
    led_level=!led_level;
    gpio_set_level(GPIO_NUM_2,led_level);
    return false;
}
void timer_init(void)
{
    gptimer_config_t gptimer_cfg = {
        .clk_src = GPTIMER_CLK_SRC_DEFAULT,
        .direction = GPTIMER_COUNT_UP,
        .flags.intr_shared = 0,
        .intr_priority = 0,
        .resolution_hz = 1000000,
    };
    gptimer_new_timer(&gptimer_cfg, &gptim);
    gptimer_alarm_config_t gptimer_alarm_cfg = {
        .alarm_count = 500000,
        .flags.auto_reload_on_alarm = 1,
        .reload_count = 0,
    };
    gptimer_set_alarm_action(gptim, &gptimer_alarm_cfg);

    gptimer_event_callbacks_t event_cfg = {
        .on_alarm =TimerCallback,
    };
     gptimer_register_event_callbacks(gptim, &event_cfg, NULL);
    gptimer_enable(gptim);
    gptimer_start(gptim);
}
void app_main(void)
{
    gpio_init();
    timer_init();


}
