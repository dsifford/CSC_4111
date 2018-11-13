**Name:** Derek Sifford \
**Access ID:** fw1575 \
**Project:** 2 \
**Date:** 2018/11/05 \
**Group Number:** 4

# Flip Horizontally and Vertically

## 1. Concepts

Add a new feature that can flip the image horizontally and vertically.

## 2. Concept Location

|               |                 |
| ------------- | --------------- |
| **Name**      | Image Flip      |
| **Intention** | Image Rotate    |
| **Extension** | Image Transform |

### Table 1. Grep Search

| Concept        | Query                                | # Results | Target Class (file)                          | Tool used | Comments                                                                                                                                                              |
| -------------- | ------------------------------------ | --------: | -------------------------------------------- | --------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Image Rotation | `rg --type cpp --ignore-case rotate` |         3 | `AdditionalTools`, `ImageArea`, `MainWindow` | ripgrep   | It appears that the actual functionality will need to be done in `additionaltools` and this functionality will propagate upwards through `imagearea` and `mainwindow` |

## 3. Impact Analysis

![impact.png]

### Table 2. The list of all the classes visited during impact analysis

| Class name        | Tool used | Mark     | Comments                                                         |
| ----------------- | --------- | -------- | ---------------------------------------------------------------- |
| `AdditionalTools` | ripgrep   | Impacted | Need to add a new method to flip the image.                      |
| `ImageArea`       | ripgrep   | Impacted | Need to add a new method to ImageArea for image flipping.        |
| `MainWindow`      | ripgrep   | Impacted | Need to add a new item to the menu UI to trigger image flipping. |

## 4. Prefactoring

None needed.

## 5. Actualization

### Table 3. Actualization Summary

| # Visited | # Changed | # Added | # Propagating | # Unchanged | # Added to Changed Set |
| --------: | --------: | ------: | ------------: | ----------: | ---------------------: |
|         3 |         2 |       1 |             2 |           0 |                      3 |

### Table 4. Actualization Code Files

| File Name                                  | Task                                             | Lines Added | Lines Deleted | Lines Total |
| ------------------------------------------ | ------------------------------------------------ | ----------: | ------------: | ----------: |
| `additionaltools.cpp`, `additionaltools.h` | Implement `flipImage` functionality              |          14 |             0 |          14 |
| `imagearea.cpp`, `imagearea.h`             | Implement `flipImage` method                     |          12 |             0 |          12 |
| `mainwindow.cpp`, `mainwindow.cpp`         | Implement transform menu and flip image actions. |          13 |             0 |          13 |

## 6. Postfactoring

None needed.

## 7. Verification

I created a new image and drew a diagonal line. Next, I exercised both the flip horizontal and flip vertical actions in the `Tools->Transform` menu several times and made sure that the image applied the proper mirror transform in all cases.

### Table 5. Statement Verification

| File Name             | Total Statements | Covered Statements |   % |
| --------------------- | ---------------: | -----------------: | --: |
| `mainwindow.cpp`      |                8 |                  8 | 100 |
| `imagearea.cpp`       |                2 |                  2 | 100 |
| `additionaltools.cpp` |                4 |                  4 | 100 |

#### Tests Failed

None

#### Bugs Found

None

## 8. Sources

None

## 9. Highlighted Source Code

```diff
diff --git a/Project/EasyPaintQt5/sources/additionaltools.cpp b/Project/EasyPaintQt5/sources/additionaltools.cpp
index d74201c..cc1a21c 100644
--- a/Project/EasyPaintQt5/sources/additionaltools.cpp
+++ b/Project/EasyPaintQt5/sources/additionaltools.cpp
@@ -47,6 +47,14 @@ AdditionalTools::~AdditionalTools()

 }

+void AdditionalTools::flipImage(bool vertical)
+{
+    mPImageArea->setImage(mPImageArea->getImage()->mirrored(!vertical, vertical));
+    mPImageArea->update();
+    mPImageArea->setEdited(true);
+    mPImageArea->clearSelection();
+}
+
 void AdditionalTools::resizeCanvas(int width, int height, bool flag)
 {
     if(flag)
diff --git a/Project/EasyPaintQt5/sources/additionaltools.h b/Project/EasyPaintQt5/sources/additionaltools.h
index d79db0d..0cf7457 100644
--- a/Project/EasyPaintQt5/sources/additionaltools.h
+++ b/Project/EasyPaintQt5/sources/additionaltools.h
@@ -52,6 +52,13 @@ public:
     explicit AdditionalTools(ImageArea *pImageArea, QObject *parent = 0);
     ~AdditionalTools();

+    /**
+     * @brief Apply mirror transform to image
+     *
+     * @param vertical Vertical mirror if true, otherwise horizontal.
+     */
+    void flipImage(bool vertical = false);
+
     /**
      * @brief Resize image area
      *
@@ -87,16 +94,16 @@ public:
      * @return returns true in case of success
      */
     bool zoomImage(qreal factor);
-
+
 private:
     ImageArea *mPImageArea; /**< A pointer to ImageArea */
     qreal mZoomedFactor; /**< Difference between original and current image */

 signals:
     void sendNewImageSize(const QSize&);
-
+
 public slots:
-
+
 };

 #endif // ADDITIONALTOOLS_H
diff --git a/Project/EasyPaintQt5/sources/imagearea.cpp b/Project/EasyPaintQt5/sources/imagearea.cpp
index e923d23..b1550eb 100644
--- a/Project/EasyPaintQt5/sources/imagearea.cpp
+++ b/Project/EasyPaintQt5/sources/imagearea.cpp
@@ -297,6 +297,11 @@ void ImageArea::rotateImage(int rotation)
     emit sendNewImageSize(mImage->size());
 }

+void ImageArea::flipImage(bool vertical)
+{
+    mAdditionalTools->flipImage(vertical);
+    emit sendNewImageSize(mImage->size());
+}

 void ImageArea::applyEffect(EffectsEnum effect)
 {
diff --git a/Project/EasyPaintQt5/sources/imagearea.h b/Project/EasyPaintQt5/sources/imagearea.h
index 02eadb4..83ff8dd 100644
--- a/Project/EasyPaintQt5/sources/imagearea.h
+++ b/Project/EasyPaintQt5/sources/imagearea.h
@@ -102,6 +102,12 @@ public:
      * @param rotation, Rotate the canvas.
      */
     void rotateImage(int rotation);
+    /**
+     * @brief Apply mirror transform to image
+     *
+     * @param vertical Vertical mirror if true, otherwise horizontal.
+     */
+    void flipImage(bool vertical);

     inline QString getFileName() { return mFilePath.split('/').last(); }
     inline QImage* getImage() { return mImage; }
diff --git a/Project/EasyPaintQt5/sources/mainwindow.cpp b/Project/EasyPaintQt5/sources/mainwindow.cpp
index 869408a..b1858c5 100644
--- a/Project/EasyPaintQt5/sources/mainwindow.cpp
+++ b/Project/EasyPaintQt5/sources/mainwindow.cpp
@@ -416,6 +416,18 @@ void MainWindow::initializeMainMenu()

     mToolsMenu->addMenu(rotateMenu);

+    QMenu *transformMenu = new QMenu(tr("Transform"));
+
+    mFlipHorizontalAction = new QAction(tr("Flip Horizontal"));
+    connect(mFlipHorizontalAction, &QAction::triggered, [=]() { getCurrentImageArea()->flipImage(false); });
+    transformMenu->addAction(mFlipHorizontalAction);
+
+    mFlipVerticalAction = new QAction(tr("Flip Vertical"));
+    connect(mFlipVerticalAction, &QAction::triggered, [=]() { getCurrentImageArea()->flipImage(true); });
+    transformMenu->addAction(mFlipVerticalAction);
+
+    mToolsMenu->addMenu(transformMenu);
+
     QMenu *zoomMenu = new QMenu(tr("Zoom"));

     mZoomInAction = new QAction(tr("Zoom In"), this);
diff --git a/Project/EasyPaintQt5/sources/mainwindow.h b/Project/EasyPaintQt5/sources/mainwindow.h
index 6cde159..53e1426 100644
--- a/Project/EasyPaintQt5/sources/mainwindow.h
+++ b/Project/EasyPaintQt5/sources/mainwindow.h
@@ -101,7 +101,8 @@ private:
     QMap<EffectsEnum, QAction*> mEffectsActMap;
     QAction *mSaveAction, *mSaveAsAction, *mCloseAction, *mPrintAction,
         *mUndoAction, *mRedoAction, *mCopyAction, *mCutAction,
-        *mNewAction, *mOpenAction, *mExitAction, *mPasteAction, *mZoomInAction, *mZoomOutAction;
+        *mNewAction, *mOpenAction, *mExitAction, *mPasteAction, *mZoomInAction, *mZoomOutAction,
+        *mFlipHorizontalAction, *mFlipVerticalAction;
     QAction *pZoom50, *pZoom100, *pZoom200;

     QMenu *mInstrumentsMenu, *mEffectsMenu, *mToolsMenu;
```

[impact.png]: bin/impact.png
