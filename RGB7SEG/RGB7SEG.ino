#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN  6

#define DISPLAYS  1 // number of RGB7SEG boards being used in series
#define NUMPIXELS  7 // number of RGB LEDs per board
#define BRIGHT 125 // brightness of LEDs out of 255

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(DISPLAYS*NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int red = 0;
int green = 0;
int blue = 0;

void clear_displays () {

  //Turn off all displays
  for (int i = 0; i < NUMPIXELS * DISPLAYS; ++i) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.setBrightness(BRIGHT);
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}


//display a number in the given RGB color code
void display_num(int v, int red_, int green_, int blue_) {

  int ones;
  int tens;
  int hundreds;
  int thousands;

  float shift_display = 0;

  if (v < 0 || v > 9999) {
    return;
  }

  ones = v % 10; v = v / 10;
  if (ones >= 0 || ones <= 9) {
    ++shift_display;
  }
  tens = v % 10; v = v / 10;
  if (tens >= 0 || tens <= 9) {
    ++shift_display;
  }
  hundreds = v % 10; v = v / 10;
  if (hundreds >= 0 || hundreds <= 9) {
    ++shift_display;
  }
  thousands = v;
  if (thousands >= 0 || thousands <= 9) {
    ++shift_display;
  }

  int arr[DISPLAYS] = {ones, tens, hundreds, thousands};


  for (int displayNum = 0;  displayNum < shift_display; ++displayNum) {

    if (arr[displayNum] == 0) {
      //Display 0
      for (int i = 0 +  displayNum * 7; i <= 5 +  displayNum * 7; ++i) {
        pixels.setPixelColor(i, pixels.Color(red_, green_, blue_));
      }
      pixels.setPixelColor(6 +  displayNum * 7, pixels.Color(0, 0, 0));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }

    else if (arr[displayNum] == 1) {
      //Display 1
      pixels.setPixelColor(0 +  displayNum * 7, pixels.Color(0, 0, 0));
      for (int i = 1 +  displayNum * 7; i <= 2 +  displayNum * 7; ++i) {
        pixels.setPixelColor(i, pixels.Color(red_, green_, blue_));
      }
      for (int i = 3 +  displayNum * 7; i <= 5 +  displayNum * 7; ++i) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
      pixels.setPixelColor(6 +  displayNum * 7, pixels.Color(0, 0, 0));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }

    else if (arr[displayNum] == 2) {
      //Display 2
      pixels.setPixelColor(0 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.setPixelColor(1 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.setPixelColor(2 +  displayNum * 7, pixels.Color(0, 0, 0));
      pixels.setPixelColor(3 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.setPixelColor(4 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.setPixelColor(5 +  displayNum * 7, pixels.Color(0, 0, 0));
      pixels.setPixelColor(6 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    else if (arr[displayNum] == 3) {
      //Display 3
      for (int i = 0 +  displayNum * 7; i <= 3 +  displayNum * 7; ++i) {
        pixels.setPixelColor(i, pixels.Color(red_, green_, blue_));
      }
      pixels.setPixelColor(4 +  displayNum * 7, pixels.Color(0, 0, 0));
      pixels.setPixelColor(5 +  displayNum * 7, pixels.Color(0, 0, 0));
      pixels.setPixelColor(6 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    else if (arr[displayNum] == 4) {
      //Display 4
      pixels.setPixelColor(0 +  displayNum * 7, pixels.Color(0, 0, 0));
      pixels.setPixelColor(1 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.setPixelColor(2 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.setPixelColor(3 +  displayNum * 7, pixels.Color(0, 0, 0));
      pixels.setPixelColor(4 +  displayNum * 7, pixels.Color(0, 0, 0));
      pixels.setPixelColor(5 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.setPixelColor(6 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    else if (arr[displayNum] == 5) {
      //Display 5
      pixels.setPixelColor(0 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.setPixelColor(1 +  displayNum * 7, pixels.Color(0, 0, 0));
      pixels.setPixelColor(2 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.setPixelColor(3 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.setPixelColor(4 +  displayNum * 7, pixels.Color(0, 0, 0));
      pixels.setPixelColor(5 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.setPixelColor(6 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    else if (arr[displayNum] == 6) {
      //Display 6
      pixels.setPixelColor(0 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.setPixelColor(1 +  displayNum * 7, pixels.Color(0, 0, 0));
      for (int i = 2 +  displayNum * 7; i <= 6 +  displayNum * 7; ++i) {
        pixels.setPixelColor(i, pixels.Color(red_, green_, blue_));
      }
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    else if (arr[displayNum] == 7) {
      //Display 7
      for (int i = 0 +  displayNum * 7; i <= 2 +  displayNum * 7; ++i) {
        pixels.setPixelColor(i, pixels.Color(red_, green_, blue_));
      }
      for (int i = 3 +  displayNum * 7; i <= 6 +  displayNum * 7; ++i) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }

      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    else if (arr[displayNum] == 8) {
      //Display 8
      for (int i = 0 +  displayNum * 7; i < 7 +  displayNum * 7; ++i) {
        pixels.setPixelColor(i, pixels.Color(red_, green_, blue_));
        pixels.show(); // This sends the updated pixel color to the hardware.
      }
    }
    else if (arr[displayNum] == 9) {

      //Display 9
      for (int i = 0 +  displayNum * 7; i <= 3 +  displayNum * 7; ++i) {
        pixels.setPixelColor(i, pixels.Color(red_, green_, blue_));
      }
      pixels.setPixelColor(4 +  displayNum * 7, pixels.Color(0, 0, 0));
      pixels.setPixelColor(5 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.setPixelColor(6 +  displayNum * 7, pixels.Color(red_, green_, blue_));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
  }

}


void setup() {
  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
  clear_displays (); //clears all the LED boards
}

void loop() {


  /*  Counts from 0 to 99 on two or more displays 
  or from 0 to 9 on one display from red, green, and then blue */
  
  for (int a = 0; a <= 99; ++a) {
    display_num(a, red, green, blue);
    if (red <= 255) {
      red += 10;
    }
    else if (green <= 255) {
      green += 10;
    }
    else if (blue <= 255) {
      blue += 10;
    }
    
    delay(250);

  }



}
