## Example Rebase
A quick example of rebasing a forked repo to include changes in the upstream repo.

Add the upstream repo:
```
git remote add upstream https://github.com/buidl-bitcoin/buidl-python.git
```

Fetch all info/branches from upstream:
```
git fetch upstream
```

Ensure we're on the main branch of our forked repo:
```
git checkout main
```

Rewrite our forked repo's main branch so that our commits are replayed on top of main's head
```
git rebase upstream/main
```
