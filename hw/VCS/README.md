## Problem Part 2.A

```bash
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020 (master)
$ git branch
* master
  test1
  test2

```

## Problem Part 2.B

```bash
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (test1)
$ ls
README.md  test.txt


```

## Problem Part 2.C

```bash
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (test1)
$ notepad test.txt


```

## Problem Part 2.D

```bash
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (test1)
$ git add test.txt

Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (test1)
$ git commit -m 'test file committed' ./test.txt
[test1 c80f250] test file committed
 1 file changed, 1 insertion(+)
 create mode 100644 hw/VCS/test.txt

```

## Problem Part 2.E

```bash
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (test2)
$ ls
README.md

#### I do not see the file test.txt in the branch of test2 because the changes stages on test1 branches
#### It never affect the other branches unless we merge one branch to another.

```

## Problem Part 2.F

```bash
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (test2)
$ ls
README.md  test.txt

Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (test2)
$ notepad test.txt

```

## Problem Part 2.G

```bash
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (test2)
$ git checkout test1
error: The following untracked working tree files would be overwritten by checkout:
        hw/VCS/test.txt
Please move or remove them before you switch branches.
Aborting
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (test2)
$ git add test.txt

Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (test2)
$ git commit -m 'add test.txt on test2 branch' ./test.txt
[test2 4f7a7a2] add test.txt on test2 branch
 1 file changed, 2 insertions(+)
 create mode 100644 hw/VCS/test.txt
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (test2)
$ git checkout test1
Switched to branch 'test1'
D       hw/README.md


```

## Problem Part 2.H

```bash
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020 (master)
$ git merge test1
Updating 020905c..c80f250
Fast-forward
 hw/VCS/test.txt | 1 +
 1 file changed, 1 insertion(+)
 create mode 100644 hw/VCS/test.txt


```

## Problem Part 2.I

```bash
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (master)
$ ls
README.md  test.txt

```

## Problem Part 2.J

```bash
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (master)
$ git merge test2
CONFLICT (add/add): Merge conflict in hw/VCS/test.txt
Auto-merging hw/VCS/test.txt
Automatic merge failed; fix conflicts and then commit the result.

#### This conflict happnes because the file test.txt already exist in the master branch
#### To solve this problem we have to change the file in the test2 branch, then stage and commit can
#### solve the problem.


```

## Problem Part 2.K

```bash
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (master|MERGING)
$ git checkout test2
error: you need to resolve your current index first
hw/VCS/test.txt: needs merge


```

## Problem Part 2.L

```bash
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (master|MERGING)
$ git status
On branch master
Your branch is ahead of 'origin/master' by 1 commit.
  (use "git push" to publish your local commits)

You have unmerged paths.
  (fix conflicts and run "git commit")
  (use "git merge --abort" to abort the merge)

Unmerged paths:
  (use "git add <file>..." to mark resolution)
        both added:      test.txt

Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        deleted:    ../README.md

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        README.md

no changes added to commit (use "git add" and/or "git commit -a")

#### It seems there is some conflict needs to be fix and has to update them and commit them and some change has not been stages and committted

```

## Problem Part 2.M

```bash
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (master|MERGING)
$ vim test.txt



```

## Problem Part 2.N

```bash
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (master)
$ git checkout test2
Switched to branch 'test2'

```

## Problem Part 2.O

```bash
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (test2)
$ git branch -d test1
error: The branch 'test1' is not fully merged.
If you are sure you want to delete it, run 'git branch -D test1'.


```

## Problem Part 2.P

```bash
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (test2)
$ git checkout master
Switched to branch 'master'
Your branch is ahead of 'origin/master' by 3 commits.
  (use "git push" to publish your local commits)

Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (master)
$ git branch -d test1
Deleted branch test1 (was c80f250).

Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (master)
$ git branch
* master
  test2

```

## Problem Part 2.Q   

```bash   
#### The different message because when you try to delete test1 inside the test2 you can not be able to do it because   
#### test1 and test2 created from master branch so if you want to delete test1 and test2 you have to go to master branch first   


```   
## Problem Part 2.R   

```bash   
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (test2)     
$ git branch -d test2   
error: Cannot delete branch 'test2' checked out at 'C:/Users/Home/Desktop/Git/DSP2020F/IDSF2020'   



```  

## Problem Part 2.S   

```bash   
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (master)   
$ git branch -d test2   
Deleted branch test2 (was 4f7a7a2).   
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (master)   
$ git branch   
* master   
   
```  
## Problem Part 2.T   

```bash   
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (master)   
$ git branch -d test2   
Deleted branch test2 (was 4f7a7a2).   
Home@DESKTOP-FFMCP9F MINGW64 ~/Desktop/Git/DSP2020F/IDSF2020/hw/VCS (master)   
$ git branch   
* master   
   
```  
