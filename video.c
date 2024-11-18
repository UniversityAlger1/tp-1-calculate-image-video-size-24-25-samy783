#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration (in seconds) of the color section of the video
//   durationCredits: duration (in seconds) of the black-and-white section of the video
//   fps: Frames Per Second of the video
//   unit: Unit of the output value ('bt', 'ko', 'mo', 'go')
// Return value:
//   Size of the video in the specified unit
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Validation des paramètres d'entrée
    if (w <= 0 || h <= 0 || durationMovie < 0 || durationCredits < 0 || fps <= 0) {
        return -1; // Retourne une valeur négative pour signaler une erreur
    }

    // Taille d'une image colorée et N&B (en bits)
    float sizeColorFrame = (float)(w * h * 24); // 24 bits par pixel pour les sections colorées
    float sizeGrayFrame = (float)(w * h * 8);  // 8 bits par pixel pour les sections N&B

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
    } else {
        return -1; // Retourne une valeur négative pour une unité invalide
    }
}
