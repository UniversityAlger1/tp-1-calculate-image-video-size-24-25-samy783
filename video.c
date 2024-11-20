#include <string.h>

float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   
   
    // Calculate totalsize 

    
    long totalSize = (long)(durationMovie * fps * w * h * 3) + (durationCredits * fps * w * h);

    // Convert size 
    
    if (strcmp(unit, "bt") == 0) return totalSize;                  
    if (strcmp(unit, "ko") == 0) return totalSize / 1024.0;             
    if (strcmp(unit, "mo") == 0) return totalSize / (1024.0 * 1024);    
    if (strcmp(unit, "go") == 0) return totalSize / (1024.0 * 1024 * 1024);

    return 0;
}
