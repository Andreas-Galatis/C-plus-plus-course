# C-plus-plus-course
CS-210-T2578 Programming Languages 21EW2

**Summarize the project and what problem it was solving.**

The main focus for this project was on investing and the power of compound interest. We developed an object-oriented programming (OOP) application using secure and efficient C++ code that allows the users to see how their investments will grow over time. The application takes four inputs from the user: An initial investment amount, a monthly deposit amount, an annual interest rate, and the number of years the investment has to grow. The console then displays two static reports: One that shows the year-end balances and year-end earned interest, if no additional monthly deposits are made. And a second one that shows the year-end balances and year-end earned interest, based on the monthly deposit value that was input by the user.

**What did you do particularly well?**

One of the successes of this project was in readability and reusability, as described below in the last question. Another was having the user experience in mind when taking input by utilizing input validation methods that keeps prompting to user to enter the correct type of values for each prompt to ensure that the results would display the desired outputs. 

**Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?**

When writing a new application, new ideas present themselves, and this project was no different. Some improvements we can make to our existing program is to reduce the amount of code written in main. This will allow for even better readability and efficient mantainability in the future. Also, giving the user more options on how and when to enter or change the input values could enhance the user experience.

**Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?**

The most challenging part of writing this program was performing the calculations. Although the formula was straightforward, how to pass the right arguments to the proper functions, as well as determining the needed parameters took some trial an error. Additionally, since the calculations had to be placed in a for loop to iterate through each year the investment had to grow, this required a proper loop logic solution of how to calculate the rates for each iteration without overloading the values. This was resolved by creating a nested for loop that would reset certain values to accrue the right calculation for the next iteration.

**What skills from this project will be particularly transferable to other projects or course work?**

Some of the skills that will transfer to other projects are writing OOP code with separate files using inheritance; writing classes, functions, while using various parameters and arguments; properly initiating user input validation and nested loop logic for sophisticated calculations; and lastly, using creative display designs with user experience in mind.

**How did you make this program maintainable, readable, and adaptable?**

This was achieved by using separate header and implementation files thanks to the principle of inheritance which comes from using OOP. The header file, with the extension of .h contains an Investment class with definitions and functions, and the implementation of that class went into a .cpp file.  One more file called main.cpp was also created to host the main application driver that would call the Investment class and functions.
