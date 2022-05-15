# SimpleBBQ-Language
This is the interpreter for my esolang, called SimpleBBQ. SimpleBBQ is an esoteric programming language made by me. There is no stack nor queue, just 2 variables used for I/O, arithmetic and if-statements. Commands are composed of mainly q's and b's. If-statements are made using uppercase Q's and B's. The commands "place", "grill" and "serve" are additional commands to make the code feel more BBQ-like.
# Coding in SimpleBBQ
Here's a list of the functions in SimpleBBQ:
q (Get number from input and store in variable "hamburger")

qq (Get char  "                                          ")

qqq (Print number from "hamburger" and reset "hamburger" to 1)

qqqq ("   " char "                         ")

qqqqq (Print number from "hamburger")

qqqqqq ("  " char   "              ")

b (Increments "hamburger" by 1)

bb (Decrements "             ")

bbb (Multiplies "hamburger" with 2)

bbbb (Divides   "                ")

bbbbb (Squares "hamburger")

bbbbbb (resets "hamburger" to 1)

Uppercase B's do the same for the variable "nugget". This variable is used for if-statements.

Uppercase Q ends an if-statement.

'C' prints "nugget" as a number.

"place" gets input from user as a number and stores it in "hamburger",

"grill" squares it and

"serve" prints it as a number. See the "words" file for an example.

Parentheses serve as holders for comment.

If-statements work like this: first, give "nugget" a value. Example: B BBB BB. If "hamburger" and "nugget" have the same value, the code until the 'Q' will be run. Otherwise, it will be skipped. Example: B BBB BB qbq qbqbbqqqbbqqbbqqqq Q

Yes, I know, this description may look poopy, but hey! It is my first esolang, and one of my first GitHub commits. If you want to add something, please tell me first. Happy SimpleBBQ coding, and don't forget to extinguish the BBQ after use.
