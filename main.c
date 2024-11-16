#include <stdio.h>
#include "config/grayScaleImage.h"
#include "config/coloredBitmap.h"
#include "config/video.h"

int main() {
    // Exemple d'images
    int width = 1920;
    int height = 1080;

    // Test de la fonction grayScaleImage
    float graySize = grayScaleImage(width, height);
    printf("Taille de l'image en niveaux de gris (en bytes) : %.2f\n", graySize);

    // Test de la fonction coloredBitmap
    char* unit = "mo";  // Unité: mégaoctets
    float coloredSize = coloredBitmap(width, height, unit);
    printf("Taille de l'image colorée (%s) : %.2f\n", unit, coloredSize);

    // Exemple de vidéo
    int durationMovie = 120;  // Durée du film (en secondes)
    int durationCredits = 30;  // Durée des crédits (en secondes)
    int fps = 30;  // Frames per second

    // Test de la fonction video
    float videoSize = video(width, height, durationMovie, durationCredits, fps, unit);
    printf("Taille de la vidéo (%s) : %.2f\n", unit, videoSize);

    return 0;
}
