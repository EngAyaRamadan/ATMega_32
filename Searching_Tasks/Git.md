

# Git & GitHub

## Outlines

* ###### Version Control Systems

* ###### Git
* ###### GitHub
* ###### Difference between Git and GitHub
* ###### Why learn Git ?
* ###### Repository
* ###### Commands

-----------

### Version Control Systems (VCS)

* #####  Software package that allows users to track changes

* #####  Features 

  * ###### Allows you to track:
    
    *  ###### Software 
    *  ###### Documents
    *  ###### Build information

* #####  Many different types Such as Git

  ------------

  ###  Git

* #####  Is a distributed  control system 

  * ###### Designed to handel everything from small to very large projects 

    ###### with speed and efficiency 

* ##### Free and open source

* ##### Very fast

* ##### Has GUI

---------

### GitHub

* #####  Is an online software development platform

  * ###### It's used for storing, tracking, and collaborating on software projects

* ##### It easy for developers to share code files and collaborate with 

  ##### fellow developers on open-source projects

* ##### Integrate with git

* #####  Serves as a host for Git repository teams to store their code in a centralized location

![6422b6b5ec206_how_to_use_github](D:\azex\GitHup\AVR_Projects\6422b6b5ec206_how_to_use_github.png)

------

### Difference between Git and GitHub

* ##### Git

  > * ###### Used for version control
  >
  > * ###### Installed locally on computer
  >
  > * ###### Tracks changes made to a file

* ##### GitHub

  > * ######  used for hosting Git repositories
  >
  > * ###### cloud_based
  >
  > * ###### provides a web interface 
  >
  >   ###### to view file changes



##### You do not need GitHub to use git, but you cannot use GitHub without using git

----

### Why learn Git ?

* ##### Developers contribute to the same project

* ##### You can revert changes

* ##### You can calloborate to fix issues

* ##### You can calloborate to create new features

* ##### You can solve confilicts

* ##### You can organize features

![why-git](D:\azex\GitHup\AVR_Projects\why-git.png)

-----

### Repository

* ##### A repository contains all of your code, your files, and each file's revision history

#####                    You can discuss and manage your work within the repository

* #####  You can have many repositories  contribute to a single software  product

* #####  Can be either public or private

  * ###### A private repository is visible to those with whom the repo owner shares access

    ######  However, if a person sets their repo to public, it will be visible to everyone online

    ######  Anyone can contribute to a publicly available repo by creating a pull request to 

    ###### this repository

* ##### Track Changes for Multiple Versions

  * ###### When multiple people collaborate on a project, it’s hard to keep track of revisions  

  ######        who changed what, when and where those files are stored. GitHub and repository 

  ######        managers take care of this problem by keeping track of all the changes that your 

  ######         collaborators have pushed to the repository.

* ##### Local Repository 

  * ###### on p.c

* ##### remote Repository

  * ###### such as Repository on GitHub

-----

### Commands

```
    
    Definitions
clone : clone (copy) from local Repository or remote Repository
branch: allow you to work on different parts of a project 
add   :to add all untracked files
commit: snapshot or checkpoint in your local Repository
push  : upload local changes to remote
pull  : pull changes from remote to local
pull request : tell other about your changes to pull it from local to remote

```

###### any one can push and pull depend on permissions

```bash
   
   commands line
git clone <repo_url>
git remote -v
git branch
git status
git add <file_name>
git reset head <file_name>
git commit -m "any_message"
git push origin <your_branch_name> 
git config -l
git help config
git config --global <any_config> 
git config --global <any_config> <any_value>
git config --global --unset <any_config>
git config --global --edit  

```

​           ![Git Diagram](D:\azex\GitHup\AVR_Projects\Git Diagram.svg)
