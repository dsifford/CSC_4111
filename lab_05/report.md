Name: Derek Sifford<br />
Student access ID: fw1575<br />
Project: 1<br />
Date: September 26, 2018<br />
Group Number: 4

# Concept Location and Impact Analysis

## 1. Change Request and concepts

The overall goal of this report is to just gain familiarity with the `EasyPaint` code structure. Hence, there are no changes to be documented here.

The broad concepts being explored in this report are **grep searching** and **depenedency analyses** using standard developer tools.

## 2. Concept Location

### Table 1. Dependency Analysis

| Class/file name                                  | Tool used | Mark        | Comments                                     |
| ------------------------------------------------ | --------- | ----------- | -------------------------------------------- |
| `sources/mainwindow.cpp`, `MainWindow`           | ripgrep   | Propagating | Aggregation -- not deeply dependent          |
| `sources/imagearea.cpp`, `ImageArea`             | ripgrep   | Propagating | Composition -- deeply dependent              |
| `sources/additionaltools.cpp`, `AdditionalTools` | ripgrep   | Located     | This is the implementation of `resizeCanvas` |

#### UML of Dependency Chain

![canvasuml]

### Table 2. Grep Search

| Concept | Query                                                                                | \#Results | Target class/file                                                                                                                                                                                                                 | Tool used | Comments                                                                                                                                      |
| ------- | ------------------------------------------------------------------------------------ | --------: | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------- | --------------------------------------------------------------------------------------------------------------------------------------------- |
| Icons   | `rg --type cpp --ignore-case icon`, `rg --count --type cpp --ignore-case icon`       |        59 | `sources/mainwindow.cpp:50`<br />`sources/imagearea.cpp:4`<br />`sources/widgets/palettebutton.cpp:1`<br />`sources/widgets/shortcutedit.cpp:3`<br />`sources/widgets/toolbar.h:1`                                                        | ripgrep   | A majority of the icons are set in `sources/mainwindow.cpp`, however a few select edge cases exist elsewhere                                  |
| Toolbox | `rg --type cpp --ignore-case toolbox`                                                |         0 | N/A                                                                                                                                                                                                                               | ripgrep   | Nothing exists in the source called `Toolbox`, however, there does exist plenty of matches referencing `Toolbar`.                             |
| Toolbar | `rg --type cpp --ignore-caes toolbar`, `rg --count --type cpp --ignore-case toolbar` |        48 | `sources/mainwindow.h:3`<br />`sources/imagearea.h:4`<br />`sources/mainwindow.cpp:12`<br />`sources/widgets/palettebar.h:6`<br />`sources/widgets/toolbar.h:7`<br />`sources/widgets/palettebar.cpp:5`<br />`sources/widgets/toolbar.cpp:11` | ripgrep   | `Toolbar` class is defined in `sources/widgets/toolbar.h`. There is a subclass `PaletteBar` that is defined in `sources/widgets/palettebar.h` |

[canvasuml]: ./uml/bin/canvas.png
