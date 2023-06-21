#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time getTimeDifference(struct Time start, struct Time end) {
    struct Time difference;
    int totalSecondsStart = start.hours * 3600 + start.minutes * 60 + start.seconds;
    int totalSecondsEnd = end.hours * 3600 + end.minutes * 60 + end.seconds;
    int differenceSeconds = totalSecondsEnd - totalSecondsStart;
    
    difference.hours = differenceSeconds / 3600;
    differenceSeconds = differenceSeconds % 3600;
    difference.minutes = differenceSeconds / 60;
    difference.seconds = differenceSeconds % 60;
    
    return difference;
}

int main() {
    struct Time startTime, endTime, timeDiff;
    
    printf("Enter the start time (hh:mm:ss): ");
    scanf("%d:%d:%d", &startTime.hours, &startTime.minutes, &startTime.seconds);
    
    printf("Enter the end time (hh:mm:ss): ");
    scanf("%d:%d:%d", &endTime.hours, &endTime.minutes, &endTime.seconds);
    
    timeDiff = getTimeDifference(startTime, endTime);
    
    printf("\nTime difference: %02d:%02d:%02d\n", timeDiff.hours, timeDiff.minutes, timeDiff.seconds);
    
    return 0;
}
