/*
Task 3
Data Viewer:
Write an application to view the log stored in data.csv
Example, say you have the following data in data.csv

------------------------------------

EntryNo,sensorNo,Temperature,Humidity,Light,

1,S1,36.5,100,50,10:30:50
2,S3,30,100,50,10:30:55
3,S2,-6.6,100,10,10:31:00
------------------------------------

a. Write a function to extract each line in the .csv file and store it in an array of structures.

b. Also implement functions to display the contents of the array of structures.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// Structure
typedef struct
{
   int entryNo;
   char sensorNo[3];
   char date[11];
   char time[9];
   int light;
   int temperature;
   int humidity;
} LogEntry;

LogEntry logEntries[MAX_ENTRIES];
int numEntries = 0;

void extractDataFromFile(const char *filename)
{
   FILE *file = fopen(filename, "r");
   if (file == NULL)
   {
      printf("Failed to open the file.\n");
      return;
   }

   char line[256];
   fgets(line, sizeof(line), file);

   // Read each line and store it in the array of structures
   while (fgets(line, sizeof(line), file) != NULL)
   {
      LogEntry entry;
      sscanf(line, "%d,%[^,],%[^,],%[^,],%d,%d,%d",
             &entry.entryNo, entry.sensorNo, entry.date, entry.time,
             &entry.light, &entry.temperature, &entry.humidity);
      logEntries[numEntries++] = entry;
   }

   fclose(file);
}

// Function to search log entry with the specified entryNo
void displayLogEntry(int entryNo)
{
   int found = 0;
   for (int i = 0; i < numEntries; i++)
   {
      if (logEntries[i].entryNo == entryNo)
      {
         printf("EntryNo\tSensorNo\tDate\t\tTime\t\tLight\tTemperature\tHumidity\n");
         printf("--------------------------------------------------------------------\n");
         LogEntry entry = logEntries[i];
         printf("%d\t%s\t\t%s\t%s\t%d\t%d\t\t%d\n",
                entry.entryNo, entry.sensorNo, entry.date, entry.time,
                entry.light, entry.temperature, entry.humidity);
         found = 1;
         break;
      }
   }
   if (!found)
   {
      printf("No log entry with EntryNo %d found.\n", entryNo);
   }
}

// Function to all log entries
void displayAllLogEntries()
{
   if (numEntries == 0)
   {
      printf("No log entries available.\n");
      return;
   }

   printf("EntryNo\tSensorNo\tDate\t\tTime\t\tLight\tTemperature\tHumidity\n");
   printf("--------------------------------------------------------------------\n");

   for (int i = 0; i < numEntries; i++)
   {
      LogEntry entry = logEntries[i];
      printf("%d\t%s\t\t%s\t%s\t%d\t%d\t\t%d\n",
             entry.entryNo, entry.sensorNo, entry.date, entry.time,
             entry.light, entry.temperature, entry.humidity);
   }
}

int main()
{
   const char *filename = "data.csv";
   extractDataFromFile(filename);

   int choice;
   printf("Select an option:\n");
   printf("1. Display all log entries\n");
   printf("2. Display a specific log entry\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);

   // 1 to display all log entries
   if (choice == 1)
   {
      displayAllLogEntries();
   }
   // 2 to display specific log entry
   else if (choice == 2)
   {
      int entryNo;
      printf("Enter the EntryNo: ");
      scanf("%d", &entryNo);
      displayLogEntry(entryNo);
   }
   // Invalid choice
   else
   {
      printf("Invalid choice. Exiting...\n");
   }

   return 0;
}


/*

Sample output

Select an option:
1. Display all log entries
2. Display a specific log entry

Enter your choice: 1

EntryNo SensorNo        Date            Time            Light   Temperature     Humidity
--------------------------------------------------------------------
1       S1              01-06-2023      00:00:00        81      30              45
2       S3              01-06-2023      00:00:05        36      26              95
3       S2              01-06-2023      00:00:10        54      21              70
4       S2              01-06-2023      00:00:15        42      39              50
5       S3              01-06-2023      00:00:20        49      42              85
6       S3              01-06-2023      00:00:25        70      38              73
7       S3              01-06-2023      00:00:30        32      44              68
8       S2              01-06-2023      00:00:35        90      43              89
9       S3              01-06-2023      00:00:40        33      22              88
10      S3              01-06-2023      00:00:45        33      26              50
11      S2              01-06-2023      00:00:50        50      42              88
12      S1              01-06-2023      00:00:55        89      40              76
13      S3              01-06-2023      00:01:00        61      32              82
14      S1              01-06-2023      00:01:05        77      38              59
15      S3              01-06-2023      00:01:10        93      44              52
16      S2              01-06-2023      00:01:15        74      30              45
17      S3              01-06-2023      00:01:20        97      30              42
18      S1              01-06-2023      00:01:25        39      20              41
19      S3              01-06-2023      00:01:30        41      29              98
20      S3              01-06-2023      00:01:35        92      38              65
21      S1              01-06-2023      00:01:40        61      33              64
22      S3              01-06-2023      00:01:45        71      20              84
23      S2              01-06-2023      00:01:50        35      21              74
24      S3              01-06-2023      00:01:55        89      22              56
25      S2              01-06-2023      00:02:00        95      31              67


--------------------------------------------------------------------------------------------


Select an option:
1. Display all log entries
2. Display a specific log entry

Enter your choice: 2
Enter the EntryNo: 19

EntryNo SensorNo        Date            Time            Light   Temperature     Humidity
--------------------------------------------------------------------
19      S3              01-06-2023      00:01:30        41      29              98


--------------------------------------------------------------------------------------------


Select an option:
1. Display all log entries
2. Display a specific log entry

Enter your choice: 2
Enter the EntryNo: 7

EntryNo SensorNo        Date            Time            Light   Temperature     Humidity
--------------------------------------------------------------------
7       S3              01-06-2023      00:00:30        32      44              68


--------------------------------------------------------------------------------------------


Select an option:
1. Display all log entries
2. Display a specific log entry

Enter your choice: 2
Enter the EntryNo: 50

No log entry with EntryNo 50 found.

*/