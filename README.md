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
and outputting a result using user input the main objective was solved. However, the program was not robust. For example, as I stored the initial user temperature as a float input, if the user inputted a character or string this could break the program. To fix this I created a loop where until the user has inputted a correct result it will keep asking the user for an initial temperature. To accomplish this, I first checked if cin(input) failed if it has I would reset the flag and skip to the next line in the stream and ask the user for input again. If I did not skip to the next line the program would not be able to escape the invalid character and the program would endlessly loop as every input would contain the previous error. I implemented a similar system for the input of C or F. For this one I used a do while loop as I intent for it to be ran at least once. I implemented a switch case statement where both the capital and lower-case letters are taken into account. For this input an ignore was not needed as a non-number input would not break the cin as we expect a char not a integer or float.

### Primer 2 - Self-service Checkout
In this problem I had to create a program that would keep on asking the user for an item quantity and its price until the quantity was 0 and give them a subtotal, tax and a total including tax.

Steps needed:
  * Create loop
  * Ask user for quantity
  * Break loop if quantity = 0
  * Ask user for price
  * Calculate subtotal
  * Calculate tax
  * Calculate total

#### Methods
Once I created my variables including the constant tax value I created my loop. For the exit condition I decided to set the quantity to be less than 0. This meant when I initialised and defined quantity I set it to 1. To calculate my subtotal I used the addition assignment operator (+=). I believed making another function would just add needless complexity when this tool already exists and accomplishes the same task in less lines of code. The calculations for tax and total were also calculated inline. Creating a function that would only be used once and does not reduce lines of code, reduce complexity, or make the code look prettier was something I found not worth pursuing.

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

Initially I had the main function call another function which would inspect the password for numbers/letters/special characters and then calculate a score and return it. The main function would then use a switch case to print out an output depending on the score. I later decided to change this by separating the inspection and score calculation. I did this as I believed they were two distinct jobs and separating them broke down the long function making it more easily readable and maintainable.

Some problems encountered was the definition of moderate and weak caused some confusion. If it was only numeric or alphabetic character, it would be considered weak and if it has the less than 4 characters it would not be considered moderate. I took this to mean as long as the string had more than or equal to 4 characters and 2 different types of characters which I included special characters. This meant $123 and abc% would be valid.

### Primer 4 Employee List Removal

For this task you had to ask for user input and delete a user from a list if they were in that list.

Steps Needed:
  * Get user delete choice
  * Search array for choice
  * If found move to end of array and erase
  * Print new array


#### Reflection
A difficulty in this task was that the primitive type arrays does not have any delete functionality. To circumvent this, I moved the chosen element to the end and replaced it with an empty string thereby erasing its data and making sure not to print it.

An initial weakness of the program was it would only delete the first name in the list and the program would then suspend. To alleviate this problem, I moved the return statement and created a flag to track if the name was ever found and if found print the new list.

### Primer 5 Phone Directory

The goal was to search a phone directory either by name or telephone number and give a report on the outcome.

Steps Needed:
  * Get user input of name or phone for search
  * Find person by name or phone number in directory
  * Print person name and phone number if found


#### Reflection
Some problems I had to first solve was checking if the user had inputted a phone number or name. To solve this, I created a pure function that checked every character and see if it was number or not.

The next step was to create a function that read every line of the file, parsed the file and check if that line in the records is what we are searching for. I decided to separate this function into two, one which read each line in the file and then checked if it was the line we were looking for and another that would parse the file. For example, Michael,00001112222 would give an array of {???Michael???,???00001112222???} once parsed allowing for easier matching. In my initial design I used an array for parsing, with the size of array being two. This worked very well however when going onto primer 6 which also needed a parser it would not work as each line had three variables. The variables being initial, last name and salary. In this case the parser would need an array of size 3 to output a result, not size 2. To combat this, I used vectors which are more flexible and allowed my parser function to be used in both primers.

An error I later found in testing was the user could input the phone number as 0000 111 2222, with spaces. This meant my is number would fail as it would count the spaces as non-numbers. To solve this issue, I created a pure function which removed spaces. In the function I used the erase remove idiom. This meant I would remove the unwanted elements in this case the spaces to the end or the array and then erase them. 

### Primer 6 Data File Parser
The task was to draw out a table based on the data in the file in a formatted way.

Steps Needed:
  * Get line parsed into vector
  * Get every line into a vector ??? meaning would have a vector containing vectors { {???I???,???Jim???,???203500???}, {???J???,???Kelly???,???10300???}
  * Print formatted table each line containing data about a person

#### Reflection

From the previous primer I could use the file parser to parse each line. I also created a function to get the 2d vector. In this function I also tracked the maximum length of the last name and salary.  As c++ cannot return two or more different variables both the 2d vector and the maximum lengths, I fixed this by reserving the last element in the array for the maximum lengths of the last name and salary. Once the data was captured in the main function, I printed the data with printf. Printf has a feature that allows you to insert text left aligned in a given space, ???%-*s???, the * is how many spaces you want to take and the s the string that will be replaced. I replaced the star by max salary for width of the salary column and max last name for length of the last name column.

#### Primer 7 Sleep Timer

This function operated by calling another function which halted the current thread by 10 seconds. This meant any further action in the main function could no be operated until the sleeper function was completed. One thing I learnt in this task is how to use of default values in c++.

#### Primer 8 Joining Threads

In this task the main thread is started in the function, and we then call two functions each with a different thread in the main function. As we did a join in the main function, it could not end until the two new threaded functions ended and returned. After the two functions were finished we printed a statement saying the main thread has also ended.

#### Primer 9 Car Class

The task was to create a car class which the user could operate on.

The tasks I completed to make the program work:	
  *  Make variables, made make and colour string, engine and locked as Boolean (All Private Variables)
  *  Create constructor
  *  Make setters, getters for colour and make
  *  Make function to change state of engine and locked status that also printed out a message depending if it was already locked or turned on

A way to improve some functionality of the methods would be to turn the engine and locked methods pure. The check to see if you are already turning a car that is already turned on or locking a car that is already locked can be done in another. The main function could the get the output and print the results. I didn???t think turning the functions purer would be worth the added complexity in making and implementing the added methods as in the current iteration each time we change state we expect the outcome to be printed anyway so having it in the method simplifies things.

#### Primer 10 Area Of

The way this function worked is by having a class with three methods. The method names would be the same except the arguments. With this we could have three functions with the same name but doing different things. In the first method I calculated the area of a rectangle. In the second I calculated the area of a triangle. In the third I calculated the area of a trapezium/trapezoid.

---
## Section 2 - Programming Paradigms
### Programming Paradigms

Simply put, a programming paradigm, for example, procedural, object-oriented, functional, structured, declarative, imperative and event driven can be described as a specific approach used when trying to solve a problem.  Although many programming languages can (and do) support multiple paradigms this discussion will focus more specifically on the possible benefits with examples of the potential differences and similarities of five from the above list.

#### Imperative Programming

Is when the code is explicit and the instructions are stated clearly. This gives us better understanding and more control on how and what the program does.

#### Declarative Programming

Declarative code asks more on what you want than how you would get it. This leaves more control on the system and less on you. Unlike imperative programming it also means you can only use tools provided to you.

An example of declarative programming is sql. For sql you can only use the tools provided for example, where and orderby operators. You cannot alter how sql would do these tasks only use them. This however brings an advantage to a user as it reduces the complexity of working with the system and gives powerful tools to access the database that does not require a lot of initial set up and learning that may otherwise be needed for imperative programming.

#### Event Driven Programming

Event driven use imperative code with one or more functions that manage the code. The code or program respond to events such as mouse clicks with listeners and handlers. In modern systems such that have a graphical user interface this is very important. For example, pressing a button which fires an event to make a character in a game jump.

#### Object Oriented Programming

Object oriented programming is where data and code are objects. Objects can have attributes and functions which are called methods. It is useful in representing real world constructs, with them having properties and methods that can do tasks. For example, a person has a height being a property and can walk which would be a method. OOP programming has features such as encapsulation, inheritance and polymorphism which allows for more flexible code that can be reused and is modular in nature making it more maintainable. This can be especially useful in large scale projects.

#### Functional Programming

Functional programming is coding using functions. Some main focuses are pure functions and reusable code. Reusable code is important especially for large projects, where codebases can go past thousands of lines of code. Making code reusable means less testing, and more maintainability due to less lines of code. As for pure functions, it is when a function meets two requirements. One being having the same input you would receive the same response. Another point is they have no side effects e.g. printing out a statement. An advantage or feature or pure functions is they can be replace by their value. E.g. Max(10,13,2) will returns 13 so in this case it can be replaced by 13.

#### Programming Languages

Many programming languages will often combine and use multiple programming paradigms. This allows the programmer to code in a way they would like and give them more freedom. For example in c++ you can code in an imperative, oop or functional way. You could also 
mix some of the paradigms giving even further choices and flexibility.

---
## Section 3 - Continued Professional Development
### Benefits of becoming a Polyglot Programmer

A polyglot programmer is one who can write code in multiple languages.
This usually means they have a deeper understanding of code than just a specific language and its syntax.
In a modern world this is very useful, not only can it help you get jobs by giving you a more variety of working options it also has other benefits. It allows a programmer to look at a problem and choose which tool would be the best for the job rather than which language they prefer. It also is very advantageous when working on certain sdk's that are only available on certain language.
For example, Google???s firebase support C++, Java, JavaScript, JavaScript/Node.js, Objective-C, and Swift. Amazon's Lambda service is a powerful tool which I have used personally and at work however it only supports Java, Go, PowerShell, Node. js, C#, Python, and Ruby. This would force the programmer to use one of these languages and learn them if they have not already. There are various tools to create infrastructure with code with one new one being amazon's cdk. This allows you to create resources with code, but it is limited to the following languages: TypeScript, JavaScript, Python, Java, C#/.Net. This shows being limited to one or a few languages can prohibit you from doing interesting and creative projects. Also it is very common for codebases to have multiple languages in them. One common combination is sql alongside a more imperative and functional language such as C++ or PHP.

In conclusion being a versatile programmer not only allows for more creative projects such as C++ for making games and java for making android applications it allows for more career opportunities.
