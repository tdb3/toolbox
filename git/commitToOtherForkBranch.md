## Committing to a branch on another forked repo
There may be times when it's advantageous to suggest an addition to a branch on another user's fork of a repo (e.g. during PR review).  In this way, the commit created can conveniently be cherry-picked by the user.

Basic steps:
Fork the main repo if you haven't already, and clone it locally.
Add the user's forked repo as a remote:
```
git remote add <other_user> git://path/to/coworkers/repo.git
```
Fetch and checkout the user's branch on which you wish to add a commit.
```
git fetch <other_user>
git checkout --track /<other_users_branch>
```
Make the desired change and add it to the staging area:
```
git add src/init.cpp
```
Commit the change and push it to your origin.
```
git commit -m 'Commit measage that fits well with branch commit history'
git push origin
```

The commit on your fork can then be provided to the author in a PR comment, so they can cherry-pick the commit at their discretion.
