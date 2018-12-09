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

## 4. Prefactoring

None.

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
|         6 |         6 |       0 |             0 |           0 |                      6 |

### Table 6. Actualization Code Files

| File Name             | Task                                                      | Lines Added | Lines Deleted | Lines Total |
| --------------------- | --------------------------------------------------------- | ----------: | ------------: | ----------: |
| `CMakeLists.txt`      | Add `QtCharts` library                                    |           4 |             1 |           4 |
| `additionaltools.cpp` | Add `showHistogram()` method and core functionality of CR |          45 |             0 |          45 |
| `additionaltools.h`   | Add definitions for `showHistogram()`                     |           5 |             0 |           5 |
| `imagearea.cpp`       | Add `showHistogram()` passthrough method                  |           5 |             0 |           5 |
| `imagearea.h`         | Add definitions for `showHistogram()`                     |           5 |             0 |           5 |
| `mainwindow.cpp`      | Add `Show Image Histogram` action to tools menu           |           6 |             0 |           6 |

## 6. Postfactoring

None.

## 7. Verification

Code was tested with various colors and images. Undo still works. No other existing tools or functionality was impacted.

### Table 7. Statement Verification

| File Name             | Total Statements | Covered Statements |   % |
| --------------------- | ---------------: | -----------------: | --: |
| `additionaltools.cpp` |               24 |                 24 | 100 |
| `imagearea.cpp`       |                2 |                  2 | 100 |
| `mainwindow.cpp`      |                4 |                  4 | 100 |

#### Tests Failed

None.

#### Bugs Found

None.

## 8. Sources

None.

## 9. Highlighted Source Code

```diff
diff --git a/Project/EasyPaintQt5/CMakeLists.txt b/Project/EasyPaintQt5/CMakeLists.txt
index 044d1d2..2957d35 100644
--- a/Project/EasyPaintQt5/CMakeLists.txt
+++ b/Project/EasyPaintQt5/CMakeLists.txt
@@ -122,8 +122,10 @@ project (${PROJECT})
 include_directories (./)

 find_package (Qt5Widgets REQUIRED)
+find_package (Qt5Charts REQUIRED)
 find_package(Qt5PrintSupport REQUIRED)
 include_directories(${Qt5Widgets_INCLUDE_DIRS})
+include_directories (${Qt5Charts_INCLUDE_DIRS})
 qt5_add_resources (QRC_SOURCES ${RESOURCES})
 qt5_wrap_cpp (MOC_SOURCES ${HEADERS})

@@ -137,7 +139,7 @@ source_group ("Resource Files" FILES ${QRC_SOURCES})
 #-------  build executable from sources ----------
 add_executable (${PROJECT} ${HEADERS} ${SOURCES} ${MOC_SOURCES} ${QRC_SOURCES})

-target_link_libraries (${PROJECT} ${Qt5PrintSupport_LIBRARIES})
+target_link_libraries (${PROJECT} ${Qt5PrintSupport_LIBRARIES} ${Qt5Charts_LIBRARIES})

 #-------  installing ----------
 if(UNIX AND NOT APPLE)
diff --git a/Project/EasyPaintQt5/sources/additionaltools.cpp b/Project/EasyPaintQt5/sources/additionaltools.cpp
index cc1a21c..7c9652e 100644
--- a/Project/EasyPaintQt5/sources/additionaltools.cpp
+++ b/Project/EasyPaintQt5/sources/additionaltools.cpp
@@ -35,6 +35,14 @@
 #include <QClipboard>
 #include <QApplication>

+#include <QPixmap>
+#include <QtCharts/QChart>
+#include <QtCharts/QChartView>
+#include <QtCharts/QBarSeries>
+#include <QtCharts/QBarSet>
+
+QT_CHARTS_USE_NAMESPACE
+
 AdditionalTools::AdditionalTools(ImageArea *pImageArea, QObject *parent) :
     QObject(parent)
 {
@@ -155,3 +163,40 @@ bool AdditionalTools::zoomImage(qreal factor)
         return true;
     }
 }
+
+void AdditionalTools::showHistogram()
+{
+    QImage copied = mPImageArea->getImage()->copy().convertToFormat(QImage::Format_Grayscale8);
+    QVector<int> colorValues(256);
+
+    uchar *bits = copied.bits();
+    for (int i = 0; i < (copied.width() * copied.height()); i++) {
+        colorValues[(int) bits[i]] += 1;
+    }
+
+    QBarSeries *series = new QBarSeries();
+    for (int i = 0; i < 255; i++) {
+        if (colorValues[i] == 0) {
+            continue;
+        }
+        QBarSet *item = new QBarSet(QString::number(i));
+        item->setColor(QColor(i, i, i));
+        *item << colorValues[i];
+        series->append(item);
+    }
+    QChart *chart = new QChart();
+    chart->addSeries(series);
+    chart->setTitle(tr("Grayscale Color Histogram"));
+
+    QChartView *view = new QChartView(chart);
+    view->setRenderHint(QPainter::Antialiasing);
+
+    QPixmap p = view->grab();
+
+    QImage rendered = p.toImage();
+    resizeCanvas(rendered.width(), rendered.height());
+
+    mPImageArea->setImage(rendered);
+    mPImageArea->update();
+    mPImageArea->setEdited(true);
+}
diff --git a/Project/EasyPaintQt5/sources/additionaltools.h b/Project/EasyPaintQt5/sources/additionaltools.h
index 0cf7457..ecfcd63 100644
--- a/Project/EasyPaintQt5/sources/additionaltools.h
+++ b/Project/EasyPaintQt5/sources/additionaltools.h
@@ -95,6 +95,11 @@ public:
      */
     bool zoomImage(qreal factor);

+    /**
+     * @brief Generates and displays a grayscale color histogram of current image.
+     */
+    void showHistogram();
+
 private:
     ImageArea *mPImageArea; /**< A pointer to ImageArea */
     qreal mZoomedFactor; /**< Difference between original and current image */
diff --git a/Project/EasyPaintQt5/sources/imagearea.cpp b/Project/EasyPaintQt5/sources/imagearea.cpp
index d4dd61b..b2c4c9f 100644
--- a/Project/EasyPaintQt5/sources/imagearea.cpp
+++ b/Project/EasyPaintQt5/sources/imagearea.cpp
@@ -616,3 +616,8 @@ void ImageArea::pushUndoCommand(UndoCommand *command)
     if(command != 0)
         mUndoStack->push(command);
 }
+
+void ImageArea::showHistogram()
+{
+    mAdditionalTools->showHistogram();
+}
diff --git a/Project/EasyPaintQt5/sources/imagearea.h b/Project/EasyPaintQt5/sources/imagearea.h
index 912a829..7b31eab 100644
--- a/Project/EasyPaintQt5/sources/imagearea.h
+++ b/Project/EasyPaintQt5/sources/imagearea.h
@@ -186,6 +186,11 @@ public:
      */
     void pushUndoCommand(UndoCommand *command);

+    /**
+     * @brief Generates and displays a grayscale color histogram of current image.
+     */
+    void showHistogram();
+
 private:
     /**
      * @brief Initialize image with base params.
diff --git a/Project/EasyPaintQt5/sources/mainwindow.cpp b/Project/EasyPaintQt5/sources/mainwindow.cpp
index e0585fe..e7dc67d 100644
--- a/Project/EasyPaintQt5/sources/mainwindow.cpp
+++ b/Project/EasyPaintQt5/sources/mainwindow.cpp
@@ -473,6 +473,12 @@ void MainWindow::initializeMainMenu()

     mToolsMenu->addMenu(zoomMenu);

+    mToolsMenu->addSeparator();
+
+    QAction *imageHistogramAction = new QAction(tr("Show Image Histogram"), this);
+    connect(imageHistogramAction, &QAction::triggered, [=]() { getCurrentImageArea()->showHistogram(); });
+    mToolsMenu->addAction(imageHistogramAction);
+
     QMenu *aboutMenu = menuBar()->addMenu(tr("&About"));

     QAction *aboutAction = new QAction(tr("&About EasyPaint"), this);
```

[impact.png]: bin/impact.png
