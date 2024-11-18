#include <string.h>
#include "config/coloredBitmap.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   unit: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parameter)
float coloredBitmap(int w, int h, char* unit) {
    // Vérifier que les dimensions sont valides
    if (w <= 0 || h <= 0) {
        return -1; // Retourne une valeur négative pour signaler une erreur
    }

    // Taille brute en bits
    float sizeBits = (float)(w * h * 24);

    // Conversion selon l'unité demandée
    if (strcmp(unit, "bt") == 0) {
        return sizeBits;
    } else if (strcmp(unit, "ko") == 0) {
        return sizeBits / (8 * 1024);
    } else if (strcmp(unit, "mo") == 0) {
        return sizeBits / (8 * 1024 * 1024);
    } else if (strcmp(unit, "go") == 0) {
        return sizeBits / (8 * 1024 * 1024 * 1024);
    } else {
        return -1; // Retourne une valeur négative pour signaler une unité invalide
    }
}
