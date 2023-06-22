/*
Task 2
Update an entry in the data.csv based on the "EntryNo" field
a. Use only file handling concepts
b. Use array of structures and file handling

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_ENTRIES 100
#define FILENAME "data.csv"

// Structure
typedef struct
{
   int entryNo;
   char sensor[MAX_LENGTH];
   char date[MAX_LENGTH];
   char time[MAX_LENGTH];
   int light;
   int temperature;
   int humidity;
} Entry;

// Function to update the entry in the data.csv
void updateEntry(Entry entries[], int index, int entryNo, const char *sensor, const char *date, const char *time, int light, int temperature, int humidity)
{
   entries[index].entryNo = entryNo;
   strcpy(entries[index].sensor, sensor);
   strcpy(entries[index].date, date);
   strcpy(entries[index].time, time);
   entries[index].light = light;
   entries[index].temperature = temperature;
   entries[index].humidity = humidity;
}

// Function to find the entry
int findEntry(const Entry entries[], int numEntries, int entryNo)
{
   for (int i = 0; i < numEntries; i++)
   {
      if (entries[i].entryNo == entryNo)
      {
         return i;
      }
   }
   return -1;
}

int main()
{
   Entry entries[MAX_ENTRIES];
   int numEntries = 0;

   FILE *file = fopen(FILENAME, "r");
   if (file == NULL)
   {
      printf("Failed to open file.\n");
      return 1;
   }

   char line[MAX_LENGTH];

   fgets(line, MAX_LENGTH, file);

   while (fgets(line, MAX_LENGTH, file) != NULL && numEntries < MAX_ENTRIES)
   {
      Entry entry;
      sscanf(line, "%d,%[^,],%[^,],%[^,],%d,%d,%d",
             &entry.entryNo,
             entry.sensor,
             entry.date,
             entry.time,
             &entry.light,
             &entry.temperature,
             &entry.humidity);

      entries[numEntries++] = entry;
   }

   fclose(file);

   int entryNo;

   // Read user data
   printf("Enter the EntryNo to update: ");
   scanf("%d", &entryNo);

   // Function call to find the entry
   int index = findEntry(entries, numEntries, entryNo);
   if (index == -1)
   {
      printf("EntryNo %d not found. No updates made.\n", entryNo);
      return 1;
   }

   char sensor[MAX_LENGTH];
   char date[MAX_LENGTH];
   char time[MAX_LENGTH];
   int light, temperature, humidity;

   // Read user data
   printf("Sensor: ");
   scanf("%s", sensor);
   printf("Date: ");
   scanf("%s", date);
   printf("Time: ");
   scanf("%s", time);
   printf("Light: ");
   scanf("%d", &light);
   printf("Temperature: ");
   scanf("%d", &temperature);
   printf("Humidity: ");
   scanf("%d", &humidity);

   // Function call
   // Update the entry with the new information
   updateEntry(entries, index, entryNo, sensor, date, time, light, temperature, humidity);

   file = fopen(FILENAME, "w");
   if (file == NULL)
   {
      printf("Failed to open file for writing.\n");
      return 1;
   }

   fprintf(file, "No,Sensor,Date,Time,Light,Temperature,Humidity\n");

   // Write each entry to the file
   for (int i = 0; i < numEntries; i++)
   {
      fprintf(file, "%d,%s,%s,%s,%d,%d,%d\n",
              entries[i].entryNo,
              entries[i].sensor,
              entries[i].date,
              entries[i].time,
              entries[i].light,
              entries[i].temperature,
              entries[i].humidity);
   }

   fclose(file);

   // Print the result
   printf("EntryNo %d updated successfully.\n", entryNo);

   return 0;
}


/*

Sample output

Enter the EntryNo to update: 25
Sensor: S4
Date: 02-06-2023
Time: 12:15:00
Light: 48
Temperature: 51
Humidity: 99

EntryNo 25 updated successfully.

data.csv
Before update
25,S2,01-06-2023,00:02:00,95,31,67

After update
25,S4,02-06-2023,12:15:00,48,51,99

---------------------------------------------------------

Enter the EntryNo to update: 18
Sensor: S2
Date: 02-06-2023
Time: 18:12:55
Light: 40
Temperature: 46
Humidity: 99
EntryNo 18 updated successfully.

data.csv
Before update
18,S1,01-06-2023,00:01:25,39,20,41

After update
18,S2,02-06-2023,18:12:55,40,46,99

---------------------------------------------------------

Enter the EntryNo to update: 26
EntryNo 26 not found. No updates made.

*/