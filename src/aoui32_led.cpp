// aoui32_led.cpp - drivers for the signaling LEDs (UI) on the OSP32 board.
/*****************************************************************************
 * Copyright 2024 by ams OSRAM AG                                            *
 * All rights are reserved.                                                  *
 *                                                                           *
 * IMPORTANT - PLEASE READ CAREFULLY BEFORE COPYING, INSTALLING OR USING     *
 * THE SOFTWARE.                                                             *
 *                                                                           *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS       *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT         *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS         *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,     *
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT          *
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     *
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY     *
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT       *
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE     *
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.      *
 *****************************************************************************/
#include <Arduino.h> // pinMode
#include <aoui32.h>  // own


// LED pins are hardwired matching the OSP32 board.
#define AOUI32_LED_GRN_PIN  7
#define AOUI32_LED_RED_PIN 15


/*!
    @brief  Initializes the signaling LED pins.
    @note   All pins are hardwired matching the OSP32 board.
*/
void aoui32_led_init() {
  // Switch LEDs off (high active)
  digitalWrite(AOUI32_LED_GRN_PIN, LOW );
  digitalWrite(AOUI32_LED_RED_PIN, LOW );
  // Configure the GPIO pins
  pinMode( AOUI32_LED_GRN_PIN, OUTPUT );
  pinMode( AOUI32_LED_RED_PIN, OUTPUT );
}


/*!
    @brief  This function sets the LEDs in mask `leds` to "on".
    @param  leds
            A mask, formed by OR-ing AOUI32_LED_... macros.
*/
void aoui32_led_on(int leds) {
  if( leds & AOUI32_LED_GRN ) digitalWrite(AOUI32_LED_GRN_PIN, HIGH);
  if( leds & AOUI32_LED_RED ) digitalWrite(AOUI32_LED_RED_PIN, HIGH);
}


/*!
    @brief  This function sets the LEDs in mask `leds` to "off".
    @param  leds
            A mask, formed by OR-ing AOUI32_LED_... macros.
*/
void aoui32_led_off(int leds) {
  if( leds & AOUI32_LED_GRN ) digitalWrite(AOUI32_LED_GRN_PIN, LOW);
  if( leds & AOUI32_LED_RED ) digitalWrite(AOUI32_LED_RED_PIN, LOW);
}


/*!
    @brief  This function toggles the LEDs in mask `leds`.
    @param  leds
            A mask, formed by OR-ing AOUI32_LED_... macros.
*/
void aoui32_led_toggle(int leds) {
  if( leds & AOUI32_LED_GRN ) digitalWrite(AOUI32_LED_GRN_PIN, ! digitalRead(AOUI32_LED_GRN_PIN) );
  if( leds & AOUI32_LED_RED ) digitalWrite(AOUI32_LED_RED_PIN, ! digitalRead(AOUI32_LED_RED_PIN) );
}
