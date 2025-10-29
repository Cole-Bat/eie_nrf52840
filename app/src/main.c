/*
 * main.c
 */


#include <zephyr/kernel.h>

#include "BTN.h"
#include "LED.h"

#define SLEEP_MS 1

int main(void) {

  int count = 0;

  if (0 > BTN_init()) {
    return 0;
  }
  
  if (0 > LED_init()){
    return 0;
  }
  
  while(1) {

    LED_set(LED0, count % 2);
  
    LED_set(LED1, (count / 2) % 2);
  
    LED_set(LED2, (count / 4) % 2);

    LED_set(LED3, (count / 8) % 2);

    
    if (BTN_check_clear_pressed(BTN0)){
      count++;
      printk("Button 0 pressed!\n");
    }

    if (count == 16)
      count = 0;
    
    k_msleep(SLEEP_MS);
  }
	return 0;
}
