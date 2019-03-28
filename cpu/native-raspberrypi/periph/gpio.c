/*
 * Copyright (C) 2019 Frank Hessel <frank@fhessel.de>
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for
 * more details.
 */

/**
 * @ingroup     cpu_native
 * @ingroup     drivers_periph_gpio
 * @{
 *
 * @file
 * @brief       GPIO access layer based on wiringPi
 *
 * @author      Frank Hessel <frank@fhessel.de>
 */

#include <wiringPi.h>

#include "periph/gpio.h"

int gpio_init(gpio_t pin, gpio_mode_t mode) {
  switch(mode) {
    case GPIO_IN:
      pinMode(pin, INPUT);
      pullUpDnControl(pin, PUD_OFF);
      break;
    case GPIO_IN_PD:
      pinMode(pin, INPUT);
      pullUpDnControl(pin, PUD_DOWN);
      break;
    case GPIO_IN_PU:
      pinMode(pin, INPUT);
      pullUpDnControl(pin, PUD_UP);
      break;
    case GPIO_OUT:
      pinMode(pin, OUTPUT);
      break;
    default:
      /** Unsupported pinMode */
      return -1;
  }
  return 0;
}

int gpio_read(gpio_t pin) {
  (void) pin;
  return digitalRead(pin);
}

void gpio_set(gpio_t pin) {
  (void) pin;
  digitalWrite(pin, HIGH);
}

void gpio_clear(gpio_t pin) {
  (void) pin;
  digitalWrite(pin, LOW);
}

void gpio_toggle(gpio_t pin) {
  (void) pin;
  digitalWrite(pin, !digitalRead(pin));
}

void gpio_write(gpio_t pin, int value) {
  (void) pin;
  (void) value;
  digitalWrite(pin, value==0 ? LOW : HIGH );
}
/** @} */
