# Lab 01, Task 02 - Answers to questions asked in the code

## Question 1 - Why is there an '&' before the players on lines 29 to 33?

The ampersand preceeds the variables in this context because you are assigning
the array indices values of these variables **by reference**. So, instead of
`team` being an array of length 5 containing players by value, it is instead an
array of pointers to memory addresses holding the players.

## Question 2 - Why not use a loop for lines 45 to 49?

There are several reasons why you wouldn't use a loop in this case. But probably
the most important two reasons are as follows:

1. The players are not all of the same type. So, in this case, you'd run into
   trouble because `Defense` players don't have a `setYards` method and
   `Offense` players don't have a `setTackles` method.
2. You're assigning stats that are specific to each arbitrary player. Unless you
   had an additional array containing these values indexed the same as the array
   of players, there's no way to guarantee the correct values would be set to
   the correct player. In short, it's more trouble than it's worth for a set of
   5 players.

## Question 3 - What do the #ifndef, #define and #endif preprocessor commands do in this file?

These directives ensure that the headers are included only once in any given
build.

## Question 4 - The player's name, notice it's private, What does this mean you have to do?

This means that derived classes will not have access to the value. So, in our
case, we must define and maintain the value of `name` explicitly ourselves in
the `Defense` and `Offense` derived classes.

## Question 5 - Why does number have to be private.

I'm assuming there is a typo in this question and that instead it should read
"Why does number have to be **protected**".

This is because derived classes are expected to need access to these variables.
By making them protected, the variables still can't be changed outside of the
base class, but it opens up the option of allowing derived classes from
accessing and manipulating it.

## Question 6 - why does this method equal zero?

By having this virtual method set equal to zero, we're creating a **pure virtual
function**. This implicitly tells the compiler that the entire class (in this
case `Player`) should be treated as an **abstract base class** and should not be
allowed to be instantiated on its own. What's more, derived classes of this base
class will also be treated as abstract classes until the method is implemented.

## Question 7 - What does 'const' do here?

By providing the `const` attribute to member functions, we're telling the
compiler that the method itself should not be allowed to modify state of the
class whatsoever. If variable mutations are detected, the compiler will error.
It is beneficial to make methods `const` whenever possible to prevent accidental
state modifications.
