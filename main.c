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
    char* unit = "mo";  // Unité : mégaoctets
    float coloredSize = coloredBitmap(width, height, unit);
    if (coloredSize >= 0) {
        printf("Taille de l'image colorée (%s) : %.2f\n", unit, coloredSize);
    } else {
        printf("Erreur : paramètres invalides ou unité incorrecte pour l'image colorée\n");
    }
    // Exemple de vidéo
    int durationMovie = 120;  // Durée du film (en secondes)
    int durationCredits = 30;  // Durée des crédits (en secondes)
    int fps = 30;  // Frames per second

    // Test de la fonction video
    float videoSize = video(width, height, durationMovie, durationCredits, fps, unit);
    if (videoSize >= 0) {
        printf("Taille de la vidéo (%s) : %.2f\n", unit, videoSize);
    } else {
        printf("Erreur : paramètres invalides ou unité incorrecte pour la vidéo\n");
    }

    return 0;
}
