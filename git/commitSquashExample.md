## Commit Squashing
A quick example of squashing commits (to make changes more clean/concise), then force pushing.

### Without Rebasing 
```
git reset --soft <commit hash to keep and build on top of>
```

The changes from the commits since the chosen hash are staged for use in a new commit.

Force push
```
git push --force origin <optional branch name, in this case none>
```

### With Rebase
```
git rebase -i <commit hash to keep and build on top of>
```
For example, replacing `pick` with `squash` for a commit would squash it into the previous commit (see [git-rebase](https://git-scm.com/docs/git-rebase#_interactive_mode) for details)

Force push
```
git push --force origin <optional branch name, in this case none>
```

