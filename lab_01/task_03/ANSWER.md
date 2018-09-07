## Task 3 Solution

The reason for the failed build was due to the fact that somebody commented out
the `CDlgGuide::OnNext` method defined in `DlgGuide.cpp`.

Simply uncommenting this method (lines 51-70 of the afforementioned file) and
re-building was all that was required to make the project build and run
successfully.
