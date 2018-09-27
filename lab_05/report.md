Name: Derek Sifford
Student access ID: fw1575
Project: 1
Date: September 26, 2018
Group Number: 4

# Concept Location and Impact Analysis

## 1. Change Request and concepts

_Extract/list significant concepts here._

## 2. Concept Location

| **Class/file name** | **Tool used** | **Mark** | **Comments** |
| ------------------- | ------------- | -------- | ------------ |
|                     |               |          |              |
|                     |               |          |              |
|                     |               |          |              |
|                     |               |          |              |
|                     |               |          |              |

_Using Table Y for grep search, list all the queries (2nd column) you
have tried for each concept (1st column). The number of matching files
by each query should be recorded in the 3rd column. List the “located”
classes/files in the fourth column and the tool used for this query in
the fifth column._

### Table 2. Grep Search

| Concept | Query                                                                                | \#Results | Target class/file                                                                                                                                                                                                                 | Tool used | Comments                                                                                                                                      |
| ------- | ------------------------------------------------------------------------------------ | --------: | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------- | --------------------------------------------------------------------------------------------------------------------------------------------- |
| Icons   | `rg --type cpp --ignore-case icon`, `rg --count --type cpp --ignore-case icon`       |        59 | `sources/mainwindow.cpp:50`<br>`sources/imagearea.cpp:4`<br>`sources/widgets/palettebutton.cpp:1`<br>`sources/widgets/shortcutedit.cpp:3`<br>`sources/widgets/toolbar.h:1`                                                        | ripgrep   | A majority of the icons are set in `sources/mainwindow.cpp`, however a few select edge cases exist elsewhere                                  |
| Toolbox | `rg --type cpp --ignore-case toolbox`                                                |         0 | N/A                                                                                                                                                                                                                               | ripgrep   | Nothing exists in the source called `Toolbox`, however, there does exist plenty of matches referencing `Toolbar`.                             |
| Toolbar | `rg --type cpp --ignore-caes toolbar`, `rg --count --type cpp --ignore-case toolbar` |        48 | `sources/mainwindow.h:3`<br>`sources/imagearea.h:4`<br>`sources/mainwindow.cpp:12`<br>`sources/widgets/palettebar.h:6`<br>`sources/widgets/toolbar.h:7`<br>`sources/widgets/palettebar.cpp:5`<br>`sources/widgets/toolbar.cpp:11` | ripgrep   | `Toolbar` class is defined in `sources/widgets/toolbar.h`. There is a subclass `PaletteBar` that is defined in `sources/widgets/palettebar.h` |
