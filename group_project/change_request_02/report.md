**Name:** Derek Sifford \
**Access ID:** fw1575 \
**Project:** 2 \
**Date:** 2018/11/05 \
**Group Number:** 4

# Flip Horizontally and Vertically

## 1. Concepts

Add a new feature that can flip the image horizontally and vertically.

## 2. Concept Location

### Table 1. Grep Search

| Concept        | Query                                | # Results | Target Class (file)                          | Tool used | Comments                                                                                                                                                              |
| -------------- | ------------------------------------ | --------: | -------------------------------------------- | --------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Image Rotation | `rg --type cpp --ignore-case rotate` |         3 | `AdditionalTools`, `ImageArea`, `MainWindow` | ripgrep   | It appears that the actual functionality will need to be done in `additionaltools` and this functionality will propagate upwards through `imagearea` and `mainwindow` |

## 3. Impact Analysis

![impact.png]

### Table 3. The list of all the classes visited during impact analysis

| Class name        | Tool used | Mark     | Comments                                                         |
| ----------------- | --------- | -------- | ---------------------------------------------------------------- |
| `AdditionalTools` | ripgrep   | Impacted | Need to add a new method to flip the image.                      |
| `ImageArea`       | ripgrep   | Impacted | Need to add a new method to ImageArea for image flipping.        |
| `MainWindow`      | ripgrep   | Impacted | Need to add a new item to the menu UI to trigger image flipping. |

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

[impact.png]: bin/impact.png
