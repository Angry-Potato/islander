# islander
A simple CLI tool to find an island in a set of 2d points, by Liam Humphreys.

## Installation
Clone the github repository using `git clone git@github.com:Angry-Potato/islander.git`, or download the source in a zip from [here](https://github.com/Angry-Potato/islander/archive/master.zip).

From the root directory, run `make` to list available targets to compile the executable.

## Usage
Typical usage steps are (from root dir)

```
make clean release # cleans and compiles islander to ./bin/islander with compiler flags to optimise for executable size + speed, runs unit tests, then runs a clean again
```

```
./bin/islander data/problem_med.txt # runs islander program against the problem_med.txt data source
```

Last run of Islander in release mode against the `big` dataset took 292.572 seconds.
![dying of old age](https://pbs.twimg.com/profile_images/559115611259678720/7w_NsZVI_400x400.jpeg)

At least it gets the right place!


Make targets available are:
```
Commands available are:
make debug          # Compiles islander to ./bin/islander, runs unit tests, then runs a clean
make release        # Compiles islander to ./bin/islander with compiler flags to optimise for executable size + speed, runs unit tests, then runs a clean
make islander       # Compiles islander to ./bin/islander, then runs unit tests
make clean          # Removes all *.o files in the project
make unit_test      # Compiles the test executable to ./bin/test_islander, then runs unit tests
make dockerislander # Runs compilation and unit tests in a container, then copies executables out to ./bin/
make dockerclean    # Removes the islander container
make dockercp       # Copies executables out from the islander container, and into ./bin
make dockerrun      # Runs given target in islander container (defaults to debug)
make dockerbuild    # Builds the islander container
```
