#include <stdio.h>
#include <string.h>

#define MAX_SENSOR_INFO 100

struct SensorData {
    char sensorID[10];
    float temperature;
    int humidity;
    int lightIntensity;
};

void parseData(const char* data, struct SensorData* sensorArray, int* sensorCount) {
    // Temporary variables to store parsed values
    char sensorID[10];
    float temperature;
    int humidity;
    int lightIntensity;

    // Copy the input data to a temporary string for parsing
    char tempData[MAX_SENSOR_INFO];
    strncpy(tempData, data, MAX_SENSOR_INFO);

    // Tokenize the data using '-' delimiter
    char* token = strtok(tempData, "-");
    
    while (token != NULL) {
        // Parse the sensor ID
        if (strncmp(token, "S", 1) == 0) {
            strncpy(sensorID, token, sizeof(sensorID));
        }
        // Parse the temperature
        else if (strncmp(token, "T", 1) == 0) {
            sscanf(token, "T:%f", &temperature);
        }
        // Parse the humidity
        else if (strncmp(token, "H", 1) == 0) {
            sscanf(token, "H:%d", &humidity);
        }
        // Parse the light intensity
        else if (strncmp(token, "L", 1) == 0) {
            sscanf(token, "L:%d", &lightIntensity);
        }
        
        token = strtok(NULL, "-");
    }

    // Populate the sensor data in the array
    struct SensorData sensor;
    strncpy(sensor.sensorID, sensorID, sizeof(sensor.sensorID));
    sensor.temperature = temperature;
    sensor.humidity = humidity;
    sensor.lightIntensity = lightIntensity;

    // Add the sensor data to the array
    sensorArray[*sensorCount] = sensor;
    (*sensorCount)++;
}

void printSensorInfo(const struct SensorData* sensorArray, int sensorCount) {
    printf("Sensor Info:\n");
    printf("---------------------\n");

    for (int i = 0; i < sensorCount; i++) {
        printf("Sensor ID: %s\n", sensorArray[i].sensorID);
        printf("Temperature: %.1f C\n", sensorArray[i].temperature);
        printf("Humidity: %d\n", sensorArray[i].humidity);
        printf("Light Intensity: %d%%\n", sensorArray[i].lightIntensity);
        printf("---------------------\n");
    }
}

int main() {
    const char* data = "S1-T:36.5-H:100-L:50";
    struct SensorData sensorArray[MAX_SENSOR_INFO];
    int sensorCount = 0;

    parseData(data, sensorArray, &sensorCount);
    printSensorInfo(sensorArray, sensorCount);

    return 0;
}
