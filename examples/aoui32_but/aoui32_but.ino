// aoui32_but.ino - demo of the buttons (UI) on the OSP32 board
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
This demonstrates how to detect button presses and button releases of the
buttons on the OSP32 board. The library can report the transitions (events
like going down or going up), not just the button being down or being up.

HARDWARE
The demo runs on the OSP32 board (uses the A, X, and Y buttons).
In Arduino select board "ESP32S3 Dev Module".

OUTPUT
Welcome to aoui32-but.ino
version: ui32 0.1.2
ui32: init

0 [A
0 A]
0 [X
0 X]
0 [Y
0 Y]
0 [A
   1 [X
   1 X]
   1 [Y
       2 [X
       2 X]
   1 Y]
0 A]
*/


void setup() {
  Serial.begin(115200);
  Serial.printf("\n\nWelcome to aoui32_but.ino\n");
  Serial.printf("version: ui32 %s\n", AOUI32_VERSION );

  aoui32_init();
  Serial.printf("\n");
}


int count;
void loop() {
  aoui32_but_scan();

  if( aoui32_but_wentdown(AOUI32_BUT_A) ) Serial.printf("%*d %s",4*count,count,"[A\n"), count++;
  if( aoui32_but_wentdown(AOUI32_BUT_X) ) Serial.printf("%*d %s",4*count,count,"[X\n"), count++;
  if( aoui32_but_wentdown(AOUI32_BUT_Y) ) Serial.printf("%*d %s",4*count,count,"[Y\n"), count++;

  if( aoui32_but_wentup  (AOUI32_BUT_A) ) count--, Serial.printf("%*d %s",4*count,count,"A]\n");
  if( aoui32_but_wentup  (AOUI32_BUT_X) ) count--, Serial.printf("%*d %s",4*count,count,"X]\n");
  if( aoui32_but_wentup  (AOUI32_BUT_Y) ) count--, Serial.printf("%*d %s",4*count,count,"Y]\n");

  delay(1);
}

