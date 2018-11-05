**Name:** Derek Sifford \
**Access ID:** fw1575 \
**Project:** Change Request Extra Credit \
**Date:** 2018/10/31 \
**Group Number:** 4

# Change Request Extra Credit

## 1. Concepts

Tabs of the image region have default titles "Untitled Image", add a new functionality that can change the titles by double clicking on the tab.

## 2. Concept Location

### Table 1. Dependency Search

Not needed.

### Table 2. Grep Search

| Concept | Query                                   | # Results | Target Class (file)                                            | Tool used | Comments                                                                           |
| ------- | --------------------------------------- | --------: | -------------------------------------------------------------- | --------- | ---------------------------------------------------------------------------------- |
| Tabs    | `rg --type cpp --ignore-case tabwidget` |         3 | `mainwindow.cpp`, `mainwindow.h`, `dialogs/settingsdialog.cpp` | ripgrep   | `mTabWidget` in `mainwindow.cpp` looks like the only place I need to make changes. |

## 3. Impact Analysis

![impact]

### Table 3. The list of all the classes visited during impact analysis

| Class name   | Tool used | Mark     | Comments                                                |
| ------------ | --------- | -------- | ------------------------------------------------------- |
| `MainWindow` | ripgrep   | impacted | Just need to add a double click handler to `mTabWidget` |

## 4. Prefactoring

Not needed.

## 5. Actualization

### Table 5. Actualization Summary

| # Visited | # Changed | # Added | # Propagating | # Unchanged | # Added to Changed Set |
| --------: | --------: | ------: | ------------: | ----------: | ---------------------: |
|         1 |         0 |      12 |             0 |           0 |                     12 |

### Table 6. Actualization Code Files

| File Name        | Task                                                           | Lines Added | Lines Deleted | Lines Total |
| ---------------- | -------------------------------------------------------------- | ----------: | ------------: | ----------: |
| `mainwindow.h`   | Add `renameTab` method definition                              |           1 |             0 |           1 |
| `mainwindow.cpp` | Implement `renameTab`                                          |          11 |             0 |          11 |
| `mainwindow.cpp` | Connect `renameTab` to double `mTabWidget` doubleclick handler |           1 |             0 |           1 |

## 6. Postfactoring

Not needed.

## 7. Verification

After implementing, I built and ran the application and tested renaming the tab with one tab, and several tabs. All manual tests worked as expected.

### Table 7. Statement Verification

| File Name        | Total Statements | Covered Statements |   % |
| ---------------- | ---------------: | -----------------: | --: |
| `mainwindow.cpp` |                5 |                  5 | 100 |

#### Tests Failed

None

#### Bugs Found

None

## 8. Sources

None

## 9. Highlighted Source Code

```diff
commit 2f19d173c2c14af7c0a3c87d3a4c7308a54d02d6
Author: Derek P Sifford <dereksifford@gmail.com>
Date:   Tue Oct 16 16:46:22 2018 -0400

    finish rename tab functionality

diff --git a/Extracredit/dsifford/EasyPaint/sources/mainwindow.cpp b/Extracredit/dsifford/EasyPaint/sources/mainwindow.cpp
index 135945e..7f62153 100644
--- a/Extracredit/dsifford/EasyPaint/sources/mainwindow.cpp
+++ b/Extracredit/dsifford/EasyPaint/sources/mainwindow.cpp
@@ -91,6 +91,7 @@ void MainWindow::initializeTabWidget()
     connect(mTabWidget, SIGNAL(currentChanged(int)), this, SLOT(activateTab(int)));
     connect(mTabWidget, SIGNAL(currentChanged(int)), this, SLOT(enableActions(int)));
     connect(mTabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
+	connect(mTabWidget, &QTabWidget::tabBarDoubleClicked, this, &MainWindow::renameTab);
     setCentralWidget(mTabWidget);
 }
 
@@ -841,6 +842,17 @@ void MainWindow::setInstrument(InstrumentsEnum instrument)
     mPrevInstrumentSetted = false;
 }
 
+void MainWindow::renameTab(int index)
+{
+    bool ok;
+    QString text = QInputDialog::getText(this, tr("Rename tab"),
+                                         tr("New tab name"), QLineEdit::Normal,
+                                         NULL, &ok);
+    if (ok && !text.isEmpty()) {
+        mTabWidget->setTabText(index, text);
+    }
+}
+
 void MainWindow::helpAct()
 {
     QMessageBox::about(this, tr("About EasyPaint"),
```

[impact]: ./bin/impact.png
