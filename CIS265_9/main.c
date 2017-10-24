/*************************************************************************
* Title: (CIS265_9) Word Sorting.
* File: main.c
* Author: James Eli
* Date: 9/9/2017
*
* Write a program that sort a series of words entered by the user:
*   Enter word: foo
*   Enter word: bar
*   Enter word: baz
*   Enter word: quux
*   Enter word:
*   In sorted order: bar baz foo quux
*
* Assume that each word is no more than 20 characters long. Stop reading 
* when the user enters an empty word (i.e., presses Enter without entering 
* a word). Store each word in a dynamically allocated string, using an array 
* of pointers to keep track of the strings, as in the remind2.c program 
* (Section 17.2). After all words have been read, sort the array (using 
* any sorting techniques) and then use a loop to print the words in sorted 
* order. Hint: Use the read_line function to read each word, as in remind2.c
*
* Notes:
*  (1) Compiled with MS Visual Studio 2017 Community (v141), using C
*      language options.
*
* Submitted in partial fulfillment of the requirements of PCC CIS-265.
*************************************************************************
* Change Log:
*   09/09/2017: Initial release. JME
*   10/19/2017: Added validate function. JME
*   10/20/2017: Added free to release mmeory acquired by malloc. JME
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// C/C++ Preprocessor Definitions: _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996) 

// Definitions.
#define MAX_WORD_LENGTH    20                    // Max word length.
#define WORD_LENGTH        (MAX_WORD_LENGTH + 1) // String length.
#define MAX_WORDS          50                    // Maximum words permitted.
#define MAX_INPUT_ATTEMPTS 3                     // Maximum invalid input attempts.
#define INSTRUCTIONS 	   "This program sorts a series of words entered by the user. Maximum\n"     \
                           "word length is 20 characters. The program stops reading when an empty\n" \
                           "word is entered (Enter pressed without entering a word).\n\n"

// Compare 2 strings. 
static int compare(const void *a, const void *b) {
	return strcmp(*(const char **)a, *(const char **)b);
}

// Validate string characters as alphabetic.
static bool validate(const char* s) {
	// Empty?
	if (s == NULL || *s == '\0')
		return false;
	// Check alphabetic.
	while (*s)
		if (!isalpha(*s++))
			return false;
	// Arriving here means only valid chars found.
	return true;
}

// Function from remind2.c used per assignment directions (see above).
static int read_line(char str[], const int n) {
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}

// Program starts here.
int main(void) {
	char *words[MAX_WORDS]; // Array holding inputed words.
	int count = 0;          // Word counter.

	fputs(INSTRUCTIONS, stdout); // Display program instructions.

	while (1) {
		char s[WORD_LENGTH];    // Temporary holds user input.

		if (count == MAX_WORDS) {
			fputs("Maximum word count reached.\n", stderr);
			break;
		}

		// Word entry occurs here.
		fputs("Enter word: ", stdout);
		read_line(s, MAX_WORD_LENGTH);

		// Enter pressed without text, exit while loop.
		if (strlen(s) == 0)
			break;

		if (validate(s)) {
			// Request storage for new word.
			words[count] = malloc(strlen(s) + 1);
			if (words[count] == NULL) {
				fputs("Insufficient memory available, aborting.\n", stdout);
				exit(EXIT_FAILURE);
			}
			strcpy(words[count], s);
			count++;
		}
		else
			fputs("Entry does not appear to be a valid word! It has been rejected.\n", stdout);
	}

	// Use library qsort function to sort word array.
	qsort(words, count, sizeof(char *), compare);

	// Display results.
	fputs("In sorted order:", stdout);
	for (int i = 0; i < count; i++) {
		fprintf(stdout, " %s", words[i]);
		free(words[i]);
	}
	fputs("\n", stdout);
}
