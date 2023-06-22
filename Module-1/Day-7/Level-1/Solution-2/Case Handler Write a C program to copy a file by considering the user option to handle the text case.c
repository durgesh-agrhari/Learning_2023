/*
Task 2
Case Handler:
Write a C program to copy a file by considering the user option to handle the text case
-u, to change file content to Upper Case
-l, to change file content to Lower Case
-s, to change file content to Sentence Case
if no options are passed then it should be a normal copy

Example, say we have a file f1 with the following content
f1:
-----------------------
This is the file data
testing Case copy
application
-----------------------

./cp -s f1 f2
f2:
-----------------------
This Is The Tile Data
Testing Case Copy
Application
-----------------------

./cp -l f1 f3
f3:
-----------------------
this is the tile data
testing case copy
application
-----------------------

./cp -u f1 f4
f4:
-----------------------
THIS IS THE FILE DATA
TESTING CASE COPY
APPLICATION
-----------------------

./cp f1 f5
Should perform a normal copy


*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to convert characters to uppercase
void convertToUpper(FILE *source, FILE *destination)
{
   int c;
   while ((c = fgetc(source)) != EOF)
   {
      fputc(toupper(c), destination);
   }
}

// Function to convert characters to lowercase
void convertToLower(FILE *source, FILE *destination)
{
   int c;
   while ((c = fgetc(source)) != EOF)
   {
      fputc(tolower(c), destination);
   }
}

// Function to convert characters to sentence case
void convertToSentenceCase(FILE *source, FILE *destination)
{
   int c;
   int sentenceStart = 1; // Indicates if the current character is at the beginning of a sentence

   while ((c = fgetc(source)) != EOF)
   {
      if (sentenceStart && isalpha(c))
      {
         fputc(toupper(c), destination); // Convert the first character of each sentence to uppercase
         sentenceStart = 0;
      }
      else
      {
         fputc(tolower(c), destination); // Convert the rest of the characters to lowercase
         if (c == '.' || c == '!' || c == '?')
            sentenceStart = 1; // Set the flag if a sentence-ending punctuation is encountered
      }
   }
}

int main(int argc, char *argv[])
{
   FILE *sourceFile, *destinationFile;
   int option = 0; // Default option is 0 for normal copy

   if (argc < 3)
   {
      printf("Insufficient arguments!\n");
      printf("Usage: ./cp [option] source_file destination_file\n");
      return 1;
   }

   if (argc > 3)
   {
      option = argv[1][1];                   // Option character
      sourceFile = fopen(argv[2], "r");      // Read mode
      destinationFile = fopen(argv[3], "w"); // Write mode
   }
   else
   {
      sourceFile = fopen(argv[1], "r");
      destinationFile = fopen(argv[2], "w");
   }

   if (sourceFile == NULL || destinationFile == NULL)
   {
      printf("Failed to open files.\n");
      return 1;
   }

   switch (option)
   {
   case 'u':
      convertToUpper(sourceFile, destinationFile); // Convert source to uppercase
      break;
   case 'l':
      convertToLower(sourceFile, destinationFile); // Convert source to lowercase
      break;
   case 's':
      convertToSentenceCase(sourceFile, destinationFile); // Convert source to sentence case
      break;
   default:
      // Normal copy
      int c;
      while ((c = fgetc(sourceFile)) != EOF)
      {
         fputc(c, destinationFile);
      }
   }

   fclose(sourceFile);
   fclose(destinationFile);
   printf("File copied successfully.\n");

   return 0;
}


/*

Sample output

PS D:\Coding\C\3.2 learning_2023\learning_2023\Module1\Day7\L1\Solution_2> ./cp -s f1 f2
File copied successfully.

PS D:\Coding\C\3.2 learning_2023\learning_2023\Module1\Day7\L1\Solution_2> ./cp -l f1 f3 
File copied successfully.

PS D:\Coding\C\3.2 learning_2023\learning_2023\Module1\Day7\L1\Solution_2> ./cp -u f1 f4
File copied successfully.

PS D:\Coding\C\3.2 learning_2023\learning_2023\Module1\Day7\L1\Solution_2> ./cp f1 f5   
File copied successfully.

PS D:\Coding\C\3.2 learning_2023\learning_2023\Module1\Day7\L1\Solution_2> ./cp -u  f5 f1
File copied successfully.

PS D:\Coding\C\3.2 learning_2023\learning_2023\Module1\Day7\L1\Solution_2> ./cp -l  f4 f2
File copied successfully.

------Failed conditoions------

PS D:\Coding\C\3.2 learning_2023\learning_2023\Module1\Day7\L1\Solution_2> ./cp f6 f2    
Failed to open files.

PS D:\Coding\C\3.2 learning_2023\learning_2023\Module1\Day7\L1\Solution_2> ./cp f6   
Insufficient arguments!
Usage: ./cp [option] source_file destination_file


*/