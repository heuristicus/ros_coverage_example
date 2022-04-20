# ROS code coverage

An example of how to generate code coverage reports from ros tests

# Running Tests

To test this out, clone it into a workspace and then run

```commandline
catkin test ros_coverage_example
```

You will see the results of the trivial tests that are implemented.

# Generating coverage

## Manual python coverage

It's possible to generate coverage somewhat manually. Using the `coverage` package, we can add a launch prefix to the test launch files.

```xml
<launch>
  <test test-name="my_code" pkg="ros_coverage_example" type="test_my_code_ros.py"
        launch-prefix="coverage run -p"/>
</launch>
```

With this launch prefix, when the tests are run you will see some `.coverage` prefixed files generated in the `~/.ros` directory.

To generate the coverage, run the tests with

```commandline
catkin test ros_coverage_example
```

If there is only one test, it may generate a single coverage file. If there are more, it's likely that they have suffixes to distinguish them, e.g.

```
michal@vetinari ~ $ ls -la ~/.ros/.cover*
-rw-r--r-- 1 michal michal  53248 Apr 19 15:14 /home/michal/.ros/.coverage.vetinari.115839.438412
-rw-r--r-- 1 michal michal 110592 Apr 19 15:14 /home/michal/.ros/.coverage.vetinari.115899.092796
```

We want to have these files combined so that we can look at the combined coverage of all of the tests.

To do that, we can use the `coverage combine` command, which will combine everything and generate a single `.coverage` file.

```commandline
cd ~/.ros
coverage combine .coverage*
```

And the directory looks something like

```
michal@vetinari ~ $ ls -la ~/.ros/.cover*
-rw-r--r-- 1 michal michal 110592 Apr 19 15:16 /home/michal/.ros/.coverage
```

Once we have that coverage file, we can generate a report with

```commandline
coverage report
```

However, without any filtering, this will usually show a lot of things that you're not interested in, like ros modules, numpy, and any other packages you've imported. To reduce the output we can use a filter like

```commandline
coverage report --include="*src/ros_coverage_example*"
```

which will generate a much more readable report

```
Name                                                                                        Stmts   Miss  Cover
---------------------------------------------------------------------------------------------------------------
/home/michal/git/independent/ros_coverage_example/src/ros_coverage_example/my_code.py          29      8    72%
/home/michal/git/independent/ros_coverage_example/src/ros_coverage_example/my_code_ros.py      21      3    86%
---------------------------------------------------------------------------------------------------------------
TOTAL                                                                                          50     11    78%
```

You can also use that coverage file to generate some html files to view the coverage more conveniently.

```commandline
cd .ros
coverage html --include="*src/ros_coverage_example*"
xdg-open htmlcov/index.html
```


## Using the code_coverage package

The [code_coverage](https://github.com/mikeferguson/code_coverage) package is a useful tool which adds some cmake commands to generate coverage.

You can install it with

```commandline
sudo apt install ros-noetic-code-coverage
```

There are instructions in that repository on how to install it, but you can also see the changes made in cmakelists and package xml in the commit [`ce1922`](https://github.com/heuristicus/ros_coverage_example/commit/ce1922eae5c94d58ac16437ea88dd93e3024057c) in this repository.

Key points:
- If using test launch files for python, you must add `launch-prefix="python3-coverage run -p"` to the `<test>` tag.
- Make sure you are using `add_rostest` along with test launch files to make sure that coverage is actually generated. Using only `catkin_add_gtest` is not sufficient for code_coverage to generate the coverage reports.

### Issues with symlinks

If using symlinked repositories, make sure you have the commit from the PR at https://github.com/mikeferguson/code_coverage/pull/37. Without that, python coverage generation will not be fully automated.

### Issues with `python3-coverage`

When trying code_coverage initially, I was using `coverage` installed with `pip3 install coverage`. There seems to be some version mismatch or other issues even if `python3-coverage` is actually installed. I ended up making a symlink with

```commandline
sudo ln -s /home/michal/.local/bin/coverage /usr/bin/python3-coverage
```

which made everything work.
