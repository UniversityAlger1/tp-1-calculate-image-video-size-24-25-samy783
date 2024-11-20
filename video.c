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

    // Size of the colored movie

    int totalFramesMovie = durationMovie * fps;
    int totalFramesCredits = durationCredits * fps;
    int totalPixels1 = w * h * 3;
    int totalPixels2 = w * h ;
    int movieSizeBytes = totalFramesMovie * totalPixels1  ; 
    int creditsSizeBytes = totalFramesCredits * totalPixels2 ; 
    int totalSize = movieSizeBytes + creditsSizeBytes ;

    // Convertion
    float size;
    if (strcmp(unit, "bt") == 0) {
        size = totalSize;
    } else if (strcmp(unit, "ko") == 0) {
        size = totalSize / 1024.0f; // 1 KB = 1024 bytes
    } else if (strcmp(unit, "mo") == 0) {
        size = totalSize / (1024.0f * 1024.0f); // 1 MB = 1024 KB
    } else if (strcmp(unit, "go") == 0) {
        size = totalSize / (1024.0f * 1024.0f * 1024.0f); // 1 GB = 1024 MB
    } else {
        return 0; 
    }

    return size;
}
