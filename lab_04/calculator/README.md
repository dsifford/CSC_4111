# QT Calculator GUI Documentation

A simple GUI application built with QT that compiles to all desktop platforms.

## Usage

The application works with both the mouse and with the keyboard. Enter any
operation as you would a regular handheld calculator. To continue using the
result of the last calculation, simply press the operation key that you'd like
to perform on that result, similarly to a handlheld calculator.

## Keyboard Shortcuts

| Key              | Action        |
| ---------------- | ------------- |
| `1`              | insert `1`    |
| `2`              | insert `2`    |
| `3`              | insert `3`    |
| `4`              | insert `4`    |
| `5`              | insert `5`    |
| `6`              | insert `6`    |
| `7`              | insert `7`    |
| `8`              | insert `8`    |
| `9`              | insert `9`    |
| `0`              | insert `0`    |
| `.`              | insert `.`    |
| `+`              | press `+`     |
| `-`              | press `-`     |
| `*`              | press `×`     |
| `/`              | press `÷`     |
| `r`              | press `√`     |
| `Enter`          | press `=`     |
| `Backspace`      | press `Del`   |
| `Ctrl+Backspace` | press `Clear` |

## Lessons Learned

While developing this application, the salient lesson I learned was that
judicious use of QT Designer can save an enormous amount of time when hacking
together a user interface using QT. QT Designer generates a `.ui` file
automatically and all that needs to be done after that is simply running the
`setupUi` method to automatically wire it together to your program.
