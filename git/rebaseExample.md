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

### Interactive Rebase
As another example, let's suppose we have 3 commits (A, B, and C), and would like to edit one of these commits (B), for example, to address a comment in a PR review.

We interactive rebase on op of A:
```
git rebase -i HEAD~2
```

Within the text editor, update `pick` to `edit` for commit B.  At this point the rebase stops with commit B.  Make the appropriate changes, stage the change, then continue.
```
git add <changed file(s)>
git rebase --continue
```

In the presented text editor, update the existing commit message for B (or keep it the same as appropriate).
The changes for commit C are then also added on top.
It's then a good idea to check with `git log` and `git diff <A>`
