#include <stdio.h>

int main() {
    int h1, m1, s1; // First time
    int h2, m2, s2; // Second time
    int dh, dm, ds; // Difference

    printf("Enter first time (HH MM SS): ");
    scanf("%d %d %d", &h1, &m1, &s1);

    printf("Enter second time (HH MM SS): ");
    scanf("%d %d %d", &h2, &m2, &s2);

    // Convert both times to total seconds
    int total1 = h1*3600 + m1*60 + s1;
    int total2 = h2*3600 + m2*60 + s2;

    // Find absolute difference in seconds
    int diff = total1 - total2;
    if(diff < 0) diff = -diff;

    // Convert back to HH:MM:SS
    dh = diff / 3600;
    diff %= 3600;
    dm = diff / 60;
    ds = diff % 60;

    // Display result
    printf("Difference: %02d:%02d:%02d\n", dh, dm, ds);

    return 0;
}

