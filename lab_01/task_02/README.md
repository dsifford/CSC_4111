# Assignment Task 2 - 3- points

Write a program to help Wayne State football team to keep track of its players'
performance. The file that prints out the player's stats is already coded. You
are given a class for a player; however, a football team is composed of
offensive and defensive players. So you need to build on the player class. It is
rare that a player is both, so assume the team has exclusively offensive and
defensive players. All players have a name, number and they all play for some
number of minutes. However, a defensive player is measured by the number of
tackles they get, while an offensive player is measured by the number of yards
they get.

For this assignment you need to create 2 classes that inherit from a class
player that has already been coded. The player class makes no calculations; it
just holds data of each player. Your class will be used by the main function in
main.cpp to print the team's stats, so it must follow the guidelines below. You
may not change the files given in any way.

It does not compile because it misses some classes. The project needs 4 files
added (10 points):

-   `defense.h`
-   `defense.cpp`
-   `offense.h`
-   `offense.cpp`

There are also a few questions that must be answered (20 points).

Note the `main.cpp`, `player.h`, and `player.cpp` files must not be changed in
any way. 10 points will be deducted if any of them has been modified.

ahe added files should be formatted similarly to the Player class files. The
classes need to have the following, and you must decide the return types,
visibility and any additional modifiers for these methods:

### defense class fields

            int tackles;

### defense class methods

            Defense(string name);
            setMinutesPlayed(int minutes);
            setTackles(int tackles);
            printStats() const;

### offense class fields

            int yards;

### offense class methods

           Offense(string name);
           setMinutesPlayed(int minutes);
           setYards(int yards);
           printStats() const;

## Rules

1. Classes must inherit from the base class Player. You should not recode
   anything. If the base class already does something, do NOT put it in your
   derived class. Use what has been already there.
2. You should follow the coding conventions of the program given. All files
   should have a brief description at the beginning that includes the title of
   the file and your name. The code should have comments describing each method
   and large section. See the provided code for examples.
3. All 4 of the methods listed for each new class above must be implemented. You
   can add extra methods, but it is not necessary and there is no bonus. This is
   just a suggestion: the solution averages exactly one line of code (LOC)
   inside each method, so if a method has 2 LOC, another should have 0 LOC.
   There is no trick here either with crazy lines that call multiple methods or
   anything else. Basically, if you are writing many lines of code per method,
   you need to review inheritance or polymorphism. All classes should include
   all needed libraries.

Remove the debug folder from the project. Answer the 10 questions in a text
file, then put it with the cleaned project in a folder named Task2.
