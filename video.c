#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   // YOUR CODE HERE - BEGIN
// Taille d'une image colorée et N&B (en bits)
    float sizeColorFrame = (float)(w * h * 24); // 24 bits par pixel
    float sizeGrayFrame = (float)(w * h * 8);  // 8 bits par pixel

    // Taille totale des deux sections
    float totalBits = (sizeColorFrame * fps * durationMovie) + (sizeGrayFrame * fps * durationCredits);

    // Conversion selon l'unité demandée
    if (strcmp(unit, "bt") == 0) {
        return totalBits;
    } else if (strcmp(unit, "ko") == 0) {
        return totalBits / (8 * 1024);
    } else if (strcmp(unit, "mo") == 0) {
        return totalBits / (8 * 1024 * 1024);
    } else if (strcmp(unit, "go") == 0) {
        return totalBits / (8 * 1024 * 1024 * 1024);
    }

   // YOUR CODE HERE - END
   return 0;
}