**Name:** Derek Sifford \
**Access ID:** fw1575 \
**Project:** 1 \
**Date:** 2018/10/06 \
**Group Number:** 4

# EasyPaint - Predefined Canvas Sizes

## 1. Concepts

Add at least three frequently used canvas sizes under `Menu->Tools`, e.g. `800*600`, `1024*768`, `1280*720`.

## 2. Concept Location

### Table 1. Dependency Search (Canvas Resizing Concept)

| Class (file)                              | Tool used | Mark        | Comments                                              |
| ----------------------------------------- | --------- | ----------- | ----------------------------------------------------- |
| `AdditionalTools` (`additionaltools.cpp`) | ripgrep   | Located     | This is the physical implementation of `resizeCanvas` |
| `ImageArea` (`imagearea.cpp`)             | ripgrep   | Propagating | This class aggregates `AdditionalTools`               |
| `MainWindow` (`mainwindow.cpp`)           | ripgrep   | Propagating | This class aggregates `ImageArea`                     |

#### Dependency Search UML

![related_uml]

### Table 2. Grep Search

| Concept  | Query                                | # Results | Target class (file)                       | Tool used | Comments                                                                                                                         |
| -------- | ------------------------------------ | --------: | ----------------------------------------- | --------- | -------------------------------------------------------------------------------------------------------------------------------- |
| `Menu`   | `rg --ignore-case --type cpp menu`   |        97 | `MainWindow` (`mainwindow.cpp`)           | ripgrep   | This class is where items may be added to menus. `mToolsMenu` is the instance where the new action should be added.              |
| `Canvas` | `rg --ignore-case --type cpp canvas` |        12 | `AdditionalTools` (`additionaltools.cpp`) | ripgrep   | The `resizeCanvas` operation is implemented in `AdditionalTools`, but it is called and used elsewhere. Dependency Search needed. |

## 3. Impact Analysis

### Table 3. The list of all the classes visited during impact analysis

| Class name        | Tool used | Mark        | Comments                                                                          |
| ----------------- | --------- | ----------- | --------------------------------------------------------------------------------- |
| `AdditionalTools` | ripgrep   | Propagating | This is the physical implementation of `resizeCanvas`. No changes needed however. |
| `ImageArea`       | ripgrep   | Impacted    | Must be changed to add overload for calling `resizeCanvas`                        |
| `MainWindow`      | ripgrep   | Impacted    | Must be changed to add functionality.                                             |

#### Impact Analysis UML

![impact_uml]

## 4. Prefactoring

### Table 4. Prefactoring Code Files

| File Name                        | Task                                                                                               | Lines Added | Lines Deleted | Lines Total |
| -------------------------------- | -------------------------------------------------------------------------------------------------- | ----------: | ------------: | ----------: |
| `imagearea.cpp`, `imagearea.h`   | Add method overload to `resizeCanvas` that allows for an explicit resize without opening a dialog. |          15 |             3 |          18 |
| `mainwindow.cpp`, `mainwindow.h` | Add method overload to `resizeCanvasAct` that allows for passing explicit dimensions.              |          12 |             0 |          12 |

## 5. Actualization

### Table 5. Actualization Summary

| # Visited | # Changed | # Added | # Propagating | # Unchanged | # Added to Changed Set |
| --------: | --------: | ------: | ------------: | ----------: | ---------------------: |
|         2 |         2 |       0 |             1 |           0 |                      2 |

### Table 6. Actualization Code Files

| File Name        | Task                                                                                 | Lines Added | Lines Deleted | Lines Total |
| ---------------- | ------------------------------------------------------------------------------------ | ----------: | ------------: | ----------: |
| `mainwindow.cpp` | Move current canvas resize action into submenu to facilitate explicit sizes.         |           4 |             4 |           8 |
| `mainwindow.cpp` | `connect` the newly overloaded `resizeCanvasAct` to explicit actions in the submenu. |          16 |             0 |          16 |

## 6. Postfactoring

None

## 7. Verification

After making my small changes, I verified that they worked as intended by compiling and running the program and exercising all of the new buttons manually. I also verified that the existing canvas functionality remained functional. I found no issues.

### Table 7. Statement Verification

| File Name        | Total Statements | Covered Statements |   % |
| ---------------- | ---------------: | -----------------: | --: |
| `imagearea.cpp`  |                2 |                  2 | 100 |
| `mainwindow.cpp` |               15 |                 15 | 100 |

#### Tests Failed

None

#### Bugs Found

None

## 8. Sources

None

## 9. Highlighted Source Code

```diff
diff --git a/Project/EasyPaintQt5/sources/imagearea.cpp b/Project/EasyPaintQt5/sources/imagearea.cpp
index 0e8568d..a4c59e6 100644
--- a/Project/EasyPaintQt5/sources/imagearea.cpp
+++ b/Project/EasyPaintQt5/sources/imagearea.cpp
@@ -271,6 +271,12 @@ void ImageArea::resizeImage()
     emit sendNewImageSize(mImage->size());
 }

+void ImageArea::resizeCanvas(int width, int height)
+{
+	mAdditionalTools->resizeCanvas(width, height, false);
+	emit sendNewImageSize(mImage->size());
+}
+
 void ImageArea::resizeCanvas()
 {
     mAdditionalTools->resizeCanvas(mImage->width(), mImage->height(), true);
diff --git a/Project/EasyPaintQt5/sources/imagearea.h b/Project/EasyPaintQt5/sources/imagearea.h
index e955dbd..c71d7d0 100644
--- a/Project/EasyPaintQt5/sources/imagearea.h
+++ b/Project/EasyPaintQt5/sources/imagearea.h
@@ -79,6 +79,12 @@ public:
      *
      */
     void resizeImage();
+    /**
+     * @brief Resize canvas using explicit dimensions.
+     *
+     * @param width,height The dimensions to resize the canvas to.
+     */
+    void resizeCanvas(int width, int height);
     /**
      * @brief Resize canvas using resize dialog.
      *
@@ -162,7 +168,7 @@ public:
      *
      */
     void pushUndoCommand(UndoCommand *command);
-
+
 private:
     /**
      * @brief Initialize image with base params.
@@ -241,7 +247,7 @@ signals:
      *
      */
     void sendEnableSelectionInstrument(bool enable);
-
+
 private slots:
     void autoSave();

@@ -250,7 +256,7 @@ protected:
     void mouseMoveEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);
     void paintEvent(QPaintEvent *event);
-
+
 };

 #endif // IMAGEAREA_H
diff --git a/Project/EasyPaintQt5/sources/mainwindow.cpp b/Project/EasyPaintQt5/sources/mainwindow.cpp
index 135945e..1bc3fa5 100644
--- a/Project/EasyPaintQt5/sources/mainwindow.cpp
+++ b/Project/EasyPaintQt5/sources/mainwindow.cpp
@@ -79,7 +79,7 @@ MainWindow::MainWindow(QStringList filePaths, QWidget *parent)

 MainWindow::~MainWindow()
 {
-
+
 }

 void MainWindow::initializeTabWidget()
@@ -367,9 +367,25 @@ void MainWindow::initializeMainMenu()
     connect(resizeImAction, SIGNAL(triggered()), this, SLOT(resizeImageAct()));
     mToolsMenu->addAction(resizeImAction);

-    QAction *resizeCanAction = new QAction(tr("Canvas size"), this);
-    connect(resizeCanAction, SIGNAL(triggered()), this, SLOT(resizeCanvasAct()));
-    mToolsMenu->addAction(resizeCanAction);
+    QMenu *canvasSizeMenu = new QMenu(tr("Canvas size"));
+
+    QAction *resizeCan800_600Action = new QAction(tr("800x600"), this);
+    connect(resizeCan800_600Action, &QAction::triggered, this, [=](){ this->resizeCanvasAct(800, 600); });
+    canvasSizeMenu->addAction(resizeCan800_600Action);
+
+    QAction *resizeCan1024_768Action = new QAction(tr("1024x768"), this);
+    connect(resizeCan1024_768Action, &QAction::triggered, this, [=](){ this->resizeCanvasAct(1024, 768); });
+    canvasSizeMenu->addAction(resizeCan1024_768Action);
+
+    QAction *resizeCan1280_720Action = new QAction(tr("1280x720"), this);
+    connect(resizeCan1280_720Action, &QAction::triggered, this, [=](){ this->resizeCanvasAct(1280, 720); });
+    canvasSizeMenu->addAction(resizeCan1280_720Action);
+
+    QAction *resizeCanCustomAction = new QAction(tr("Custom"), this);
+    connect(resizeCanCustomAction, SIGNAL(triggered()), this, SLOT(resizeCanvasAct()));
+    canvasSizeMenu->addAction(resizeCanCustomAction);
+
+    mToolsMenu->addMenu(canvasSizeMenu);

     QMenu *rotateMenu = new QMenu(tr("Rotate"));

@@ -622,6 +638,11 @@ void MainWindow::resizeImageAct()
     getCurrentImageArea()->resizeImage();
 }

+void MainWindow::resizeCanvasAct(int width, int height)
+{
+    getCurrentImageArea()->resizeCanvas(width, height);
+}
+
 void MainWindow::resizeCanvasAct()
 {
     getCurrentImageArea()->resizeCanvas();
diff --git a/Project/EasyPaintQt5/sources/mainwindow.h b/Project/EasyPaintQt5/sources/mainwindow.h
index 8e4cd9e..a40dfc7 100644
--- a/Project/EasyPaintQt5/sources/mainwindow.h
+++ b/Project/EasyPaintQt5/sources/mainwindow.h
@@ -49,7 +49,7 @@ QT_END_NAMESPACE
 class MainWindow : public QMainWindow
 {
     Q_OBJECT
-
+
 public:
     MainWindow(QStringList filePaths, QWidget *parent = 0);
     ~MainWindow();
@@ -124,6 +124,12 @@ private slots:
     void settingsAct();
     void effectsAct();
     void resizeImageAct();
+    /**
+     * @brief Resize canvas using explicit dimensions.
+     *
+     * @param width,height The dimensions to resize the canvas to.
+     */
+    void resizeCanvasAct(int width, int height);
     void resizeCanvasAct();
     void rotateLeftImageAct();
     void rotateRightImageAct();
```

[related_uml]: bin/related.png
[impact_uml]: bin/impact.png
