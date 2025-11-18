/*
 * Course: Arduino Based Real Time Oscilloscope
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Arduino Based Real Time Oscilloscope" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (Arduino)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/arduino-based-real-time-oscilloscope/
 * Repository: https://github.com/engasm89/arduino-based-real-time-oscilloscope
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

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

int main(void) { // Program entry point
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
} // End of main function
