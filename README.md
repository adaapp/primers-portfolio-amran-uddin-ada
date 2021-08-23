# Primer Portfolio

## Section 1 - Primer Challenges
### Primer 1 - Fahrenheit / Centigrade Conversion
This challenge requires us to allow a user to enter a value before selecting whether to convert it from Fahrenheit to Centigrade or Centigrade to Fahrenheit.  As part of the initial design the conversion algorithms were needed for both calculations. 

To help complete this challenge I needed to break the overall problem down into the following main tasks: 
* Get data from the user
* Verify the data is in a suitable format
* Create a method to convert F->C
* Create a method to convert C->F
 
#### Reflection (as well as issues, challenges & resolutions)
After creating basic functionality of having two pure functions
and outputting a result using user input the main objective was solved. However, the program was not robust. For example as I stored the initial user temperatue as a float input, if the user inputted a character or string this could break the program. To fix this I created a loop where until the user has inputted a correct result it will keep asking the user for an initial temperature. To accomplish this I first checked if cin(input) failed if it has I would reset the flag and skip to the next line in the stream and ask the user for input again. If I did not skip to the next line the program would not be able to escape the invalid character and the program would endlessly loop as every input would contain the previous error. I implemented a similar system for the input of C or F. For this one I used a do while loop as I intent for it to be ran at least once. I implemented a switch case statement where both the capital and lower case letters are taken into account. For this input an ignore was not needed as a non number input would not break the cin as we expect a char not a integer or float.

### Primer 2 - Self-service Checkout
In this problem I had to create a program that would keep on asking the user for an item quantity and its price until the quantity was 0 and give them a subtotal,tax and a total including tax.

Steps needed:
  * Create loop
  * Ask user for quantity
  * break loop if quantity = 0
  * Ask user for price
  * Calculate subtotal
  * calculate tax
  * calculate total

#### Methods
Once I created my variables including the constant tax I created my loop. For the exit condition I decided to set the quantity to be less than 0. This meant when I initiliased and defined quantity I set it to 1. To calculate my subtotal I used the addition assignment operator(+=). I believed making another function would just add needless complexity when this tool already exists and accomplishes the same task in less lines of code. The calculations for tax and total were also calculated inline. Creating a function that would only be used once and does not reduce lines of code, reduce complexity, or make the code look prettier was something I found not worth pursuing.

Something that had to be considered was printing a value to 2dp. I initially struggled with this but once I found C/C++'s printf function which has many handy abilities including inserting floats into a string and formatting it to 2dp. Once I discovered printf I used it much more frequently in my further work.

### Primer 3 Password Complexity Checker
The aim of this task was to check a users password and return how strong the password was.

Steps Needed:
  * Calculate number of letters in password
  * Calculate number of integers
  * Calculate number of special characters
  * Calculate score of password
  * Return output of score

#### Reflection

Inititally I had the main function call another function which would inspect the password for numbers/letters/special charachters and then calculate a score and return it. The main function would then use a switch case to print out an output depending on the score. I later decided to change this by seperating the inspection and score calculation. I did this as I believed they were two distinct jobs and seperating them broke down the long function making it more easily readable and maintainable.

Some problems encountered was the definition of moderate and weak caused some confusion. If it was only numeric or alphabetic character it would be considered weak and if it has the less than 4 characters it would not be considered moderate. I took this to mean as long as the string had more than or equal to 4 characters and 2 different types of characters which I included special charachters. This meant $123 and abc% would be valid.

### Primer 4 Employee List Removal

For this task you had to ask for user input and delete a user from a list if they were in that list.

#### Reflection
A difficulty in this task was that the primitive type arrays does not have any delete functionality. To circumvent this I moved the chosen element to the end and replaced it with an empty string thereby erasing its data and making sure not to print it.

An ininital weakness of the program was it would only delete the first name in the list and the program would then suspend. To alleviate this problem I moved the return statement and created a flag to track if the name was ever found.

### Primer 6 Phone Directory

The goal was to to search a phone directory either by name or telephone number and give a report on the outcome

#### Reflection
A difficulty in this task was that the primitive type arrays does not have any delete functionality. To circumvent this I moved the chosen element to the end and replaced it with an empty string thereby erasing its data and making sure not to print it.

### Data File Parser
Print pretty table
  
..  

---
## Section 2 - Programming Paradigms
### Programming Paradigms
Simply put, a programming paradigm, for example, procedural, object-oriented, functional, structured, declarative, imperative and event driven can be described as a specific approach used when trying to solve a problem.  Although many programming languages can (and do) support multiple paradigms this discussion will focus more specifically on the possible benefits with examples of the potential differences and similarities of five from the above list. These are ...

---
## Section 3 - Continued Professional Development
### Benefits of becoming a Polyglot Programmer
Vestibulum vitae semper sem. Duis leo leo, suscipit at felis non, pellentesque varius massa. Sed sit amet orci nibh. Morbi scelerisque faucibus elit, vitae mollis turpis finibus eget. In convallis euismod nunc non imperdiet. Duis ultricies pulvinar lorem, sed molestie nunc porta at. Aenean arcu ante, efficitur nec felis sed, feugiat iaculis turpis. Vestibulum eu elementum diam. Quisque nec tortor auctor, scelerisque ante vitae, fringilla tellus.

Quisque ligula lectus, efficitur quis malesuada sit amet, malesuada sed nibh. In lorem erat, elementum quis tempus nec, rhoncus ac ante. Mauris suscipit massa tempor, pulvinar neque vel, gravida nulla. Donec massa diam, molestie in diam nec, vulputate faucibus ligula. Aliquam erat volutpat. Aliquam sit amet dui ligula. Nullam euismod eros ultrices magna convallis lobortis. Proin convallis placerat tincidunt. Quisque interdum, nisi id egestas luctus, augue libero lacinia urna, sit amet tempus nisl sem nec quam. Vestibulum interdum urna mauris, vel dignissim nisi dignissim egestas. Donec volutpat dictum dui, at egestas sem tristique nec.
