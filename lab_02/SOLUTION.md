# Lab 2 Solutions

## Task 1

Below are the sequence of steps performed in git that were required to complete
this exercise.

### Notes:

-   I used command line `git`, not TortoiseGit.
-   Assume all commands were entered at the project root directory.

| Command                     | Explanation                                                                                                                                                                                                                                                                                                          |
| --------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `git fetch`                 | Fetch the latest objects and refs from the remote repository to ensure my local repository is tracking the HEAD of the remote root.                                                                                                                                                                                  |
| `git pull`                  | Pulls the newer commits and files into my local repository (my local repository is now identical to the remote).                                                                                                                                                                                                     |
| `git add -A`                | After finishing my updates to the repo, I add the contents of the working tree to the git index.                                                                                                                                                                                                                     |
| `git commit -m '<message>'` | Stores the content of the index in a new commit along with a log message describing the changes I made.                                                                                                                                                                                                              |
| `git push -u origin master` | Pushes my changes back to the `master` branch of the remote repository (which I'm tracking as `origin`). The `-u` flag was provided to explicitly set `origin master` as my default tracking branch so that, for all future pushes, I only need to run `git push` without providing the remote or branch explicitly. |

## Task 2

