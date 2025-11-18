// Emit sampled waveform frames and ASCII visualization
#include <stdio.h> // Logs and plots
#include <math.h> // Sine wave

static void ascii_plot(const int *s, int n) { // Plot samples
  for (int i = 0; i < n; ++i) { // Iterate samples
    int bars = s[i] / 10; // Scale
    for (int b = 0; b < bars; ++b) printf("#"); // Bars
    printf("\n"); // New line
  } // End plot loop
}

int main(void) { // Entry
  printf("Arduino Based Real-Time Oscilloscope\n"); // Title
  int samples[64]; // Buffer
  for (int i = 0; i < 64; ++i) { // Generate sine samples
    double rad = (double)i * (2.0 * 3.14159 / 64.0); // Angle
    samples[i] = (int)( (sin(rad) * 0.5 + 0.5) * 100.0 ); // 0..100
  } // End generation
  for (int i = 0; i < 64; ++i) { // Print numeric frame
    printf("%d%s", samples[i], (i==63)?"\n":" "); // Emit
  } // End numeric
  ascii_plot(samples, 64); // Visualize
  return 0; // Exit
} // End main
