// aoui32_led.ino - demo of the signaling LEDs on the OSP32 board
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
#include <aoui32.h>

/*
DESCRIPTION
This demo shows the various ways the signaling LEDs on the OSP32 board 
can be controlled: on/off/toggle, changing a single or both LEDs.

HARDWARE
The demo runs on the OSP32 board (uses the red/error, green/ok LEDs).
In Arduino select board "ESP32S3 Dev Module".

OUTPUT
(nothing relevant, look at the red and green led on OSP32 board)
Welcome to aoui32_led.ino
version: ui32 0.3.4
ui32: init
*/


void setup() {
  Serial.begin(115200);
  Serial.printf("\n\nWelcome to aoui32_led.ino\n");
  Serial.printf("version: ui32 %s\n", AOUI32_VERSION );

  aoui32_init();
  Serial.printf("\n");
}


void loop() {
  // green blinks (red off)
  for( int i=0; i<10; i++ ) {
    aoui32_led_on ( AOUI32_LED_GRN ); delay(250);
    aoui32_led_off( AOUI32_LED_GRN ); delay(250);
  }

  // green blinks (red on)
  aoui32_led_on( AOUI32_LED_RED );
  for( int i=0; i<10; i++ ) {
    aoui32_led_on ( AOUI32_LED_GRN ); delay(250);
    aoui32_led_off( AOUI32_LED_GRN ); delay(250);
  }

  // green and red blink
  for( int i=0; i<10; i++ ) {
    aoui32_led_on ( AOUI32_LED_GRN | AOUI32_LED_RED ); delay(250);
    aoui32_led_off( AOUI32_LED_GRN | AOUI32_LED_RED ); delay(250);
  }

  // green and red blink - using toggle - alternate
  aoui32_led_on( AOUI32_LED_RED );
  for( int i=0; i<10; i++ ) {
    aoui32_led_toggle ( AOUI32_LED_GRN | AOUI32_LED_RED ); delay(250);
  }
}

