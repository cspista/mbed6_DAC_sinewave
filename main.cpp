#include "mbed.h"

const double pi = 3.141592653589793238462;
const double amplitude = 32767;               // 2^15-1

// The sinewave is created on this pin
// Adjust analog output pin name to your board spec.
AnalogOut aout(PA_4);

int main() {
    double rads = 0.0;
    uint16_t sample[36] = {0};
    for (int i = 0; i < 36; i++) {
        rads = (pi * i*10) / 180.0f;
        sample[i] = (uint16_t)(amplitude * (1.0 + sin(rads)));
    }

    while (1) {
        for (int i = 0; i < 36; i++) {       
            aout.write_u16(sample[i]);
            wait_us(63);                  // 1.0/(440Hz*36) = 63.13 us
        }
    }
}