/*
 *------------------------------------------------------------------------------
 *
 * fireplace.ino
 *
 * Fireplace emulator using 2 LED strips from Adafruit
 *
 * Copyright (c) 2017 Zoltan Toth <ztoth AT thetothfamily DOT net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 *
 *------------------------------------------------------------------------------
 */
#include <Adafruit_NeoPixel.h>

/** globals */
#define LED_RING_ORANGE   0xff5000
#define LED_RING_REDISH   0xff4500
#define LED_RING_RED      0xff0000
#define LED_RING_PIN 10
#define LED_RING2_PIN 11
#define LED_RING_NUM 60
#define LED_RING_MIN_BRIGHTNESS 100
#define LED_RING_BRIGHTNESS_RANGE 50
Adafruit_NeoPixel led_ring = Adafruit_NeoPixel(LED_RING_NUM, LED_RING_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_ring2 = Adafruit_NeoPixel(LED_RING_NUM, LED_RING2_PIN, NEO_GRB + NEO_KHZ800);

static int led;
static int brightness;
static int one_third = LED_RING_NUM / 3;

/**
 * Set LED color
 */
static void
set_led_color (unsigned long color, int led)
{
    byte red = (color & 0xFF0000) >> 16;
    byte green = (color & 0x00FF00) >> 8;
    byte blue = (color & 0x0000FF);
    led_ring.setPixelColor(led, red, green, blue);
    led_ring2.setPixelColor(led, red, green, blue);
}

/**
 * Color all LEDs
 */
static void
color_leds (unsigned long color)
{
    for (int i = 0; i < LED_RING_NUM; i++) {
        set_led_color(color, i);
    }
}

/**
 * Setup
 */
void
setup (void)
{
    led_ring.begin();
    led_ring.setBrightness(150);
    led_ring2.begin();
    led_ring2.setBrightness(150);
}

/**
 * Loop
 *
 * The idea is simple: in each round randomly select a few LEDs and change their
 * color and brightness
 */
void
loop (void)
{
    led = random(LED_RING_NUM);
    led_ring.setBrightness(LED_RING_MIN_BRIGHTNESS + random(LED_RING_BRIGHTNESS_RANGE));
    led_ring2.setBrightness(LED_RING_MIN_BRIGHTNESS + random(LED_RING_BRIGHTNESS_RANGE));
    set_led_color(LED_RING_ORANGE, led);
    set_led_color(LED_RING_ORANGE, (led+1)%LED_RING_NUM);
    set_led_color(LED_RING_ORANGE, (led+2)%LED_RING_NUM);

    led = random(LED_RING_NUM);
    led_ring.setBrightness(LED_RING_MIN_BRIGHTNESS + random(LED_RING_BRIGHTNESS_RANGE));
    led_ring2.setBrightness(LED_RING_MIN_BRIGHTNESS + random(LED_RING_BRIGHTNESS_RANGE));
    set_led_color(LED_RING_REDISH, led);
    set_led_color(LED_RING_REDISH, (led+1)%LED_RING_NUM);

    led = random(LED_RING_NUM);
    led_ring.setBrightness(LED_RING_MIN_BRIGHTNESS + random(LED_RING_BRIGHTNESS_RANGE));
    led_ring2.setBrightness(LED_RING_MIN_BRIGHTNESS + random(LED_RING_BRIGHTNESS_RANGE));
    set_led_color(LED_RING_ORANGE, led);
    set_led_color(LED_RING_ORANGE, (led+1)%LED_RING_NUM);
    set_led_color(LED_RING_ORANGE, (led+2)%LED_RING_NUM);

    led = random(LED_RING_NUM);
    led_ring.setBrightness(LED_RING_MIN_BRIGHTNESS + random(LED_RING_BRIGHTNESS_RANGE));
    led_ring2.setBrightness(LED_RING_MIN_BRIGHTNESS + random(LED_RING_BRIGHTNESS_RANGE));
    set_led_color(LED_RING_ORANGE, led);
    set_led_color(LED_RING_ORANGE, (led+1)%LED_RING_NUM);
    set_led_color(LED_RING_ORANGE, (led+2)%LED_RING_NUM);

    led = random(LED_RING_NUM);
    led_ring.setBrightness(LED_RING_MIN_BRIGHTNESS + random(LED_RING_BRIGHTNESS_RANGE));
    led_ring2.setBrightness(LED_RING_MIN_BRIGHTNESS + random(LED_RING_BRIGHTNESS_RANGE));
    set_led_color(LED_RING_ORANGE, led);
    set_led_color(LED_RING_ORANGE, (led+1)%LED_RING_NUM);
    set_led_color(LED_RING_ORANGE, (led+2)%LED_RING_NUM);

    led = 10 + random(LED_RING_NUM - 10);
    led_ring.setBrightness(LED_RING_MIN_BRIGHTNESS + random(LED_RING_BRIGHTNESS_RANGE));
    led_ring2.setBrightness(LED_RING_MIN_BRIGHTNESS + random(LED_RING_BRIGHTNESS_RANGE));
    set_led_color(LED_RING_RED, led);
    set_led_color(LED_RING_RED, (led+2)%LED_RING_NUM);

    led = one_third + random(one_third);
    led_ring.setBrightness(LED_RING_MIN_BRIGHTNESS + random(LED_RING_BRIGHTNESS_RANGE));
    led_ring2.setBrightness(LED_RING_MIN_BRIGHTNESS + random(LED_RING_BRIGHTNESS_RANGE));
    set_led_color(LED_RING_ORANGE, led);
    set_led_color(LED_RING_ORANGE, (led+1)%LED_RING_NUM);
    set_led_color(LED_RING_ORANGE, (led+2)%LED_RING_NUM);

    led = one_third + random(one_third);
    led_ring.setBrightness(LED_RING_MIN_BRIGHTNESS + random(LED_RING_BRIGHTNESS_RANGE));
    led_ring2.setBrightness(LED_RING_MIN_BRIGHTNESS + random(LED_RING_BRIGHTNESS_RANGE));
    set_led_color(LED_RING_ORANGE, led);
    set_led_color(LED_RING_ORANGE, (led+1)%LED_RING_NUM);
    set_led_color(LED_RING_ORANGE, (led+2)%LED_RING_NUM);

    led_ring.show();
    led_ring2.show();
    delay(100);
}
