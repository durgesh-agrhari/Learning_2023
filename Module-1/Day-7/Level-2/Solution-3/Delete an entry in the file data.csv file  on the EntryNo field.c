/*
Task 3
Delete an entry in the file data.csv file  on the "EntryNo" field
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

// Function to delete a entry
void deleteEntry(Entry entries[], int *numEntries, int index)
{
   // Shift the entries after the deleted entry to fill the gap
   for (int i = index; i < *numEntries - 1; i++)
   {
      entries[i] = entries[i + 1];
   }

   (*numEntries)--;
}

// Function to find a entry
int findEntryByNo(const Entry entries[], int numEntries, int entryNo)
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
      if (strstr(line, ",0,0,0") != NULL)
         continue;

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
   printf("Enter the EntryNo to delete: ");
   scanf("%d", &entryNo);

   // Function call
   int index = findEntryByNo(entries, numEntries, entryNo);
   if (index == -1)
   {
      printf("EntryNo %d not found. No deletions made.\n", entryNo);
      return 1;
   }

   // Function call
   deleteEntry(entries, &numEntries, index);

   file = fopen(FILENAME, "w");
   if (file == NULL)
   {
      printf("Failed to open file for writing.\n");
      return 1;
   }

   fprintf(file, "No,Sensor,Date,Time,Light,Temperature,Humidity\n");
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
   printf("EntryNo %d deleted successfully.\n", entryNo);

   return 0;
}


/*

Sample ouptut

Enter the EntryNo to delete: 26
EntryNo 26 not found. No deletions made.

-----------------------------------------------------------

******data.csv - before******
No,Sensor,Date,Time,Light,Temperature,Humidity
1,S1,01-06-2023,00:00:00,81,30,45
2,S3,01-06-2023,00:00:05,36,26,95
3,S2,01-06-2023,00:00:10,54,21,70
4,S2,01-06-2023,00:00:15,42,39,50
5,S3,01-06-2023,00:00:20,49,42,85
6,S3,01-06-2023,00:00:25,70,38,73
7,S3,01-06-2023,00:00:30,32,44,68
8,S2,01-06-2023,00:00:35,90,43,89
9,S3,01-06-2023,00:00:40,33,22,88
10,S3,01-06-2023,00:00:45,33,26,50
11,S2,01-06-2023,00:00:50,50,42,88
12,S1,01-06-2023,00:00:55,89,40,76
13,S3,01-06-2023,00:01:00,61,32,82
14,S1,01-06-2023,00:01:05,77,38,59
15,S3,01-06-2023,00:01:10,93,44,52
16,S2,01-06-2023,00:01:15,74,30,45
17,S3,01-06-2023,00:01:20,97,30,42
18,S1,01-06-2023,00:01:25,39,20,41
19,S3,01-06-2023,00:01:30,41,29,98
20,S3,01-06-2023,00:01:35,92,38,65
21,S1,01-06-2023,00:01:40,61,33,64
22,S3,01-06-2023,00:01:45,71,20,84
23,S2,01-06-2023,00:01:50,35,21,74
24,S3,01-06-2023,00:01:55,89,22,56
25,S2,01-06-2023,00:02:00,95,31,67

Enter the EntryNo to delete: 10
EntryNo 10 deleted successfully.

******data.csv - after deletion******

No,Sensor,Date,Time,Light,Temperature,Humidity
1,S1,01-06-2023,00:00:00,81,30,45
2,S3,01-06-2023,00:00:05,36,26,95
3,S2,01-06-2023,00:00:10,54,21,70
4,S2,01-06-2023,00:00:15,42,39,50
5,S3,01-06-2023,00:00:20,49,42,85
6,S3,01-06-2023,00:00:25,70,38,73
7,S3,01-06-2023,00:00:30,32,44,68
8,S2,01-06-2023,00:00:35,90,43,89
9,S3,01-06-2023,00:00:40,33,22,88
11,S2,01-06-2023,00:00:50,50,42,88
12,S1,01-06-2023,00:00:55,89,40,76
13,S3,01-06-2023,00:01:00,61,32,82
14,S1,01-06-2023,00:01:05,77,38,59
15,S3,01-06-2023,00:01:10,93,44,52
16,S2,01-06-2023,00:01:15,74,30,45
17,S3,01-06-2023,00:01:20,97,30,42
18,S1,01-06-2023,00:01:25,39,20,41
19,S3,01-06-2023,00:01:30,41,29,98
20,S3,01-06-2023,00:01:35,92,38,65
21,S1,01-06-2023,00:01:40,61,33,64
22,S3,01-06-2023,00:01:45,71,20,84
23,S2,01-06-2023,00:01:50,35,21,74
24,S3,01-06-2023,00:01:55,89,22,56
25,S2,01-06-2023,00:02:00,95,31,67

*/