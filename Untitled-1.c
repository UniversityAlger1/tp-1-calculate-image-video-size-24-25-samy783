#include <stdio.h>
#include <string.h>

float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Calculate total size
    long totalSize = (long)(durationMovie * fps * w * h * 3) + (durationCredits * fps * w * h);

    // Convert size
    if (strcmp(unit, "bt") == 0) return totalSize;                  
    if (strcmp(unit, "ko") == 0) return totalSize / 1024.0;             
    if (strcmp(unit, "mo") == 0) return totalSize / (1024.0 * 1024);    
    if (strcmp(unit, "go") == 0) return totalSize / (1024.0 * 1024 * 1024);

    return 0;
}

int main() {
    // Paramètres de la vidéo
    int w = 1920, h = 1080, durationMovie = 120, durationCredits = 30, fps = 30;
    char unit[] = "mo";

    // Appel de la fonction
    float size = video(w, h, durationMovie, durationCredits, fps, unit);

    // Affichage du résultat
    printf("La taille de la vidéo est : %.2f %s\n", size, unit);

    return 0;
}
