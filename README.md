# Pima CC CIS265 Week #9

Write a program that sort a series of words entered by the user:
```text
  Enter word: foo
  Enter word: bar
  Enter word: baz
  Enter word: quux
  Enter word:
  In sorted order: bar baz foo quux
```
Assume that each word is no more than 20 characters long. Stop reading when the user enters an empty word (i.e., presses Enter without entering 
a word). Store each word in a dynamically allocated string, using an array of pointers to keep track of the strings, as in the remind2.c program 
(Section 17.2). After all words have been read, sort the array (using any sorting techniques) and then use a loop to print the words in sorted 
order. Hint: Use the read_line function to read each word, as in remind2.c
