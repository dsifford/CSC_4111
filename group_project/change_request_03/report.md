**Name:** Derek Sifford \
**Access ID:** fw1575 \
**Project:** Change Request 3 \
**Date:** November 27, 2018 \
**Group Number:** 4

# Change Request 3: Histogram

## 1. Concepts

Add a new capability that can calculate the current image's [histogram](https://en.wikipedia.org/wiki/Image_histogram) and show it on a new canvas. For simplicity, you could just do the calculation on a grey-scale image.

### Core Concepts

-   Histogram
-   Tab
-   Gray

## 2. Concept Location

### Table 1. Grep Search

| Concept     | Query                                                   | # Results | Target Class (file)                       | Tool used | Comments                                                                                  |
| ----------- | ------------------------------------------------------- | --------: | ----------------------------------------- | --------- | ----------------------------------------------------------------------------------------- |
| `Histogram` | `rg --type cpp --ignore-case histogram`                 |         0 | N/A                                       | ripgrep   | Nothing found                                                                             |
| `Tab`       | `rg --type cpp Tab`                                     |         3 | `mainwindow.cpp`                          | ripgrep   | New tabs will need to be created in `mainwindow.cpp`                                      |
| `Gray`      | `rg --type cpp --ignore-case gray --files-with-matches` |         8 | `effects/grayeffect.cpp`, `imagearea.cpp` | ripgrep   | Gray effect is implemented in `effects/grayeffect.cpp`, and it is used in `imagearea.cpp` |

## 3. Impact Analysis

**Note:** This change request fundamentally is an addition of a _completely new_ functionality that does not exist anywhere yet in the application. Because of this, there are really no "concepts" or "impact sets" made because an entirely new feature is being added only. There will be no modifications to existing functionality anywhere.

![impact.png]

### Table 2. The list of all the classes visited during impact analysis

| Class name   | Tool used | Mark     | Comments                                                                                                                                   |
| ------------ | --------- | -------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
| `MainWindow` | None      | Impacted | This isn't really "impacted" in the sense that it will affect any existing functionality, but I will be adding a button into the menu bar. |

<!--
## 4. Prefactoring

    Please provide a detailed journal entry describing how you went about
    performing prefactoring for this change request. Write down the type of your
    refactoring in the 2nd column (e.g. "Extract a superclass" or use the terms on
    https://sourcemaking.com/refactoring).

### Table 4. Prefactoring Code Files

| File Name | Refactoring Issue | Lines Added | Lines Deleted | Lines Total |
| --------- | ----------------- | ----------: | ------------: | ----------: |
|           |                   |             |               |             |
|           |                   |             |               |             |
|           |                   |             |               |             |

## 5. Actualization

    Complete Table 5 & Table 6.

        Table 5
        -------
        Self-explanatory: describe the number of files you change.

        Table 6
        -------
        Column 1: Record where changes were made.
        Column 2: Record why changes were made.

### Table 5. Actualization Summary

| # Visited | # Changed | # Added | # Propagating | # Unchanged | # Added to Changed Set |
| --------: | --------: | ------: | ------------: | ----------: | ---------------------: |
|           |           |         |               |             |                        |

### Table 6. Actualization Code Files

| File Name | Task | Lines Added | Lines Deleted | Lines Total |
| --------- | ---- | ----------: | ------------: | ----------: |
|           |      |             |               |             |
|           |      |             |               |             |
|           |      |             |               |             |

## 6. Postfactoring

    Please provide a detailed journal entry describing how you went about
    performing postfactoring for this change request. Write down the type of your
    refactoring in the 2nd column (e.g. "Extract a superclass" or use the terms on
    https://sourcemaking.com/refactoring).

### Table 6. Postfactoring Code Files

| File Name | Refactoring Issue | Lines Added | Lines Deleted | Lines Total |
| --------- | ----------------- | ----------: | ------------: | ----------: |
|           |                   |             |               |             |
|           |                   |             |               |             |
|           |                   |             |               |             |

## 7. Verification

    Please provide a detailed journal entry describing how you went about
    performing verification for this change request.

### Table 7. Statement Verification

| File Name | Total Statements | Covered Statements |   % |
| --------- | ---------------: | -----------------: | --: |
|           |                  |                    |     |

#### Tests Failed

#### Bugs Found

## 8. Sources

    Include any sources that you cited or used information from

## 9. Highlighted Source Code

    Attach or cut and paste the code of the classes that you changed. Highlight
    the code that was changed or added. Use YELLOW for modified code RED for
    deleted code, and GREEN for added code.

    If you only changed one method in a large file, only include that method and
    the file name it’s from. Likewise, if you only changed a line or two in an
    event map or resource file, only include a few of the surrounding lines and
    the file name. Do not include thousands of lines of code that you did not
    change!

-->

[impact.png]: bin/impact.png
