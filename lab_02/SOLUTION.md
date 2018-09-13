# Lab 2 Solutions

## Task 1

Below are the sequence of steps performed in git that were required to complete
this exercise.

### Notes:

-   I used command line `git`, not TortoiseGit.
-   Assume all commands were entered at the project root directory.

| Command                                          | Explanation                                                                                                                                                                                                                                                                                                          |
| ------------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `git`&nbsp;`fetch`                               | Fetch the latest objects and refs from the remote repository to ensure my local repository is tracking the HEAD of the remote root.                                                                                                                                                                                  |
| `git`&nbsp;`pull`                                | Pulls the newer commits and files into my local repository (my local repository is now identical to the remote).                                                                                                                                                                                                     |
| `git`&nbsp;`add`&nbsp;`-A`                       | After finishing my updates to the repo, I add the contents of the working tree to the git index.                                                                                                                                                                                                                     |
| `git`&nbsp;`commit -m`&nbsp;`'<message>'` | Stores the content of the index in a new commit along with a log message describing the changes I made.                                                                                                                                                                                                              |
| `git`&nbsp;`push`&nbsp;`-u origin`&nbsp;`master` | Pushes my changes back to the `master` branch of the remote repository (which I'm tracking as `origin`). The `-u` flag was provided to explicitly set `origin master` as my default tracking branch so that, for all future pushes, I only need to run `git push` without providing the remote or branch explicitly. |

## Task 2

In the remainder of this document, I'll be comparing the main similarities and
differences between git, subversion, and mercurial.

### High Level Differences

For the naive user, git and mercurial are the most similar to each other in
terms of use and functionality. Both operate using a decentralized approach
(each user has their own copy of the repository and the "source of truth" exists
instead using a robust metadata system).

Subversion, however, does not work this way. With subversion, there exists only
one centralized "main" repository that acts as a source of truth. Whenever a
user "checks in" their changes in svn, all users get the changes.

Additionally, git and mercurial track individual byte-level changes to
individual files explicitly, whereas subversion tracks entire file revisions. As
such, this makes the history much larger overall and tends to make new checkouts
take longer (sometimes extremely so).

### Layout Differences

Again, git and mercurial tend to be most similar here. Both tend to be out of
the developer's way and store all their business logic in hidden directories.

Subversion is an absolute disaster in this aspect. If one wanted to use
subversion, you'd need to adapt their directory structure where, at the svn
root, there are three folders: `trunk`, `branches`, and `tags`.

The trunk in svn is the main line of development and the absolute source of
truth. The tags and branches directories hold tagged code and branches
separately from the main repository. This is the single biggest reason why I
dislike and will never choose to use svn.

### Workflow Differences

Finally, below are a quick comparison of the common workflow commands between
git, mercurial, and subversion.

| Task                                    | Git                       | Mercurial                | Subversion                                    |
| --------------------------------------- | ------------------------- | ------------------------ | --------------------------------------------- |
| Create a new repository                 | `git init`                | `hg init`                | N/A (must import from server)                 |
| Copy remote repository to local machine | `git clone <url>`         | `hg clone <url>`         | `svn checkout <url>`                          |
| Add changes to staging                  | `git add <file>`          | `hg add <file>`          | `svn add <file>`                              |
| Commit changes                          | `git commit -m <message>` | `hg commit -m <message>` | `svn commit` (**Warning!** This also pushes!) |
| Push changes to remote                  | `git push`                | `hg push`                | N/A (commit does this)                        |
