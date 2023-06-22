/*
Task 1
Sort the above "data.csv" based on the "Temperature" field in descending order
a. Use only file handling concepts
b. Use array of structures and file handling

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_RECORDS 101

// Structure
typedef struct
{
   int No;
   char Sensor[3];
   char Date[11];
   char Time[9];
   int Light;
   int Temperature;
   int Humidity;
} Record;

// Function to compare records based on temperature
int compare_records(const void *a, const void *b)
{
   return ((Record *)b)->Temperature - ((Record *)a)->Temperature;
}

// Function to read records from file
int read_records(Record *records, const char *filename)
{
   FILE *file = fopen(filename, "r");
   if (!file)
   {
      printf("Failed to open the file for reading.\n");
      return 0;
   }

   char line[MAX_LINE_LENGTH];
   int recordCount = 0;

   fgets(line, MAX_LINE_LENGTH, file); // Skip the header line
   while (fgets(line, MAX_LINE_LENGTH, file) && recordCount < MAX_RECORDS)
   {
      if (sscanf(line, "%d,%[^,],%[^,],%[^,],%d,%d,%d", &records[recordCount].No, records[recordCount].Sensor, records[recordCount].Date, records[recordCount].Time, &records[recordCount].Light, &records[recordCount].Temperature, &records[recordCount].Humidity) == 7)
      {
         recordCount++;
      }
   }

   fclose(file);
   return recordCount;
}

// Function to write records back to the file
void write_records(const Record *records, int recordCount, const char *filename)
{
   FILE *file = fopen(filename, "w");
   if (!file)
   {
      printf("Failed to open the file for writing.\n");
      return;
   }

   fprintf(file, "No,Sensor,Date,Time,Light,Temperature,Humidity\n");
   for (int i = 0; i < recordCount; i++)
      fprintf(file, "%d,%s,%s,%s,%d,%d,%d\n", records[i].No, records[i].Sensor, records[i].Date, records[i].Time, records[i].Light, records[i].Temperature, records[i].Humidity);

   fclose(file);
}

int main()
{
   // Create an array to hold records
   Record records[MAX_RECORDS];

   // Function call
   int recordCount = read_records(records, "data.csv");

   if (!recordCount)
   {
      printf("Failed to read records from the file.\n");
      return 1;
   }

   // Function call
   qsort(records, recordCount, sizeof(Record), compare_records);

   // Function call
   write_records(records, recordCount, "data.csv");

   // Print a success message
   printf("Sorting completed successfully.\n");
   printf("Check 'data.csv' file.\n");

   return 0;
}


/*

Output

Sorting completed successfully.
Check 'data.csv' file.

*/