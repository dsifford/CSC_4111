**Name:** Derek Sifford \
**Access ID:** fw1575 \
**Project:** \
**Date:** \
**Group Number:** 4

    ADD TITLE HERE

## 1. Concepts

    In this section, describe the change that you were requested to do. Give any
    relevant background information or any essential details.

## 2. Concept Location

    Explain the methodology used to locate each significant concept that was part of
    your change request (use dependency search or grep search).

    If doing a dependency search...

        Table 1
        -------
        Column 1: list all the files in the order that you have visited them.
        Column 2: Explain how you have found each file
        Column 3: Mention if class is related to the concept using one of the following terms...
            - Unchanged   => class has no relation to the concept but you have visited it.
            - Propagating => class guided you to the location of the concept, but you will not change it.
            - Located     => class will be changed.
        Column 4: write what you have learned about the class/file.

        Draw a UML class diagram of related classes
        -------------------------------------------
        "Located" classes     => RED text
        "Propagating" classes => ORANGE text
        "Unchanged" classes   => BLACK text

    If doing a grep search...

        Table 2
        -------
        Column 1: List the concept.
        Column 2: List all the queries you have tried.
        Column 3: List number files that have matches.
        Column 4: List the "Located" classes/files.
        Column 5: List the tool used for query.
        Column 6: Write what you have learned about the "Located" classes/files.

### Table 1. Dependency Search

| Class (file) | Tool used | Mark | Comments |
| ------------ | --------- | ---- | -------- |
|              |           |      |          |
|              |           |      |          |
|              |           |      |          |
|              |           |      |          |
|              |           |      |          |

### Table 2. Grep Search

| Concept | Query | # Results | Target Class (file) | Tool used | Comments |
| ------- | ----- | --------: | ------------------- | --------- | -------- |
|         |       |           |                     |           |          |
|         |       |           |                     |           |          |
|         |       |           |                     |           |          |
|         |       |           |                     |           |          |
|         |       |           |                     |           |          |

## 3. Impact Analysis

    Do a complete impact analysis based on the result of section 2.

        Table 3
        -------
        Column 1: List the potentially impacted class name.
        Column 2: List tool used to find class.
        Column 3: Classify the class using one of the following terms...
            - Impacted    => class will be changed.
            - Propagating => class guided you to the location of the concept, but you will not change it.
            - Unchanged   => class has no relation to the concept but you have visited it.
        Column 4: Write short comments explaining what you have learned about each class.

        Draw a UML class diagram of related classes
        -------------------------------------------
        "Impacted" classes    => RED text
        "Propagating" classes => ORANGE text
        "Unchanged" classes   => BLACK text

### Table 3. The list of all the classes visited during impact analysis

| Class name | Tool used | Mark | Comments |
| ---------- | --------- | ---- | -------- |
|            |           |      |          |
|            |           |      |          |
|            |           |      |          |
|            |           |      |          |
|            |           |      |          |
|            |           |      |          |

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
