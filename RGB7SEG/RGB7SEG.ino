
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN  2

// How many NeoPixels are attached to the Arduino?

#define DISPLAYS  4
#define NUMPIXELS   7
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(28, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 700; // delay for half a second



void clear_display () {
  //Display nothing
  for (int i = 0; i < NUMPIXELS * DISPLAYS; ++i) {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

  }
}



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

//  Serial.println(ones);
//  Serial.println(tens);
//  Serial.println(hundreds);
//  Serial.println(thousands);
//  Serial.println();
  int arr[DISPLAYS] = {ones, tens, hundreds, thousands};


  for (int p = 0; p < shift_display; ++p) {

    if (arr[p] == 0) {
      //Display 0
      for (int i = 0 + p * 7; i <= 5 + p * 7; ++i) {
        pixels.setPixelColor(i, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      }
      pixels.setPixelColor(1 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
    }

    else if (arr[p] == 1) {
      //Display 1
      for (int i = 1 + p * 7; i <= 2 + p * 7; ++i) {
        pixels.setPixelColor(i, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      }
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    
    else if (arr[p] == 2) {
      //Display 2
      pixels.setPixelColor(0 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.setPixelColor(1 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.setPixelColor(3 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.setPixelColor(4 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.setPixelColor(6 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    else if (arr[p] == 3) {
      //Display 3
      for (int i = 0 + p * 7; i <= 3 + p * 7; ++i) {
        pixels.setPixelColor(i, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      }
      pixels.setPixelColor(6 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    else if (arr[p] == 4) {
      //Display 4
      pixels.setPixelColor(1 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.setPixelColor(2 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.setPixelColor(5 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.setPixelColor(6 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    else if (arr[p] == 5) {
      //Display 5
      pixels.setPixelColor(0 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.setPixelColor(2 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.setPixelColor(3 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.setPixelColor(5 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.setPixelColor(6 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    else if (arr[p] == 6) {
      //Display 6
      pixels.setPixelColor(0 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      for (int i = 2 + p * 7; i < 7 + p * 7; ++i) {
        pixels.setPixelColor(i, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      }
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    else if (arr[p] == 7) {
      //Display 7
      for (int i = 0 + p * 7; i <= 2 + p * 7; ++i) {
        pixels.setPixelColor(i, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      }
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    else if (arr[p] == 8) {
      //Display 8
      for (int i = 0 + p * 7; i < 7 + p * 7; ++i) {
        pixels.setPixelColor(i, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
        pixels.show(); // This sends the updated pixel color to the hardware.
      }
    }
    else if (arr[p] == 9) {

      //Display 9
      for (int i = 0 + p * 7; i <= 3 + p * 7; ++i) {
        pixels.setPixelColor(i, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      }

      pixels.setPixelColor(5 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.setPixelColor(6 + p * 7, pixels.Color(red_, green_, blue_)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
  }

}


void setup() {
  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
  clear_display ();
}

void loop() {
  display_num(10, 4, 20/5, 50/5);

}
