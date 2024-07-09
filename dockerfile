FROM python:slim

RUN apt -y update && apt -y install git

# python
RUN pip install yapf pycodestyle pydocstyle
# only for cli (vscode extentions work for editor)
RUN pip install flake8 autopep8

# C/C++
# RUN apt -y install cppcheck clang clang-format
RUN apt-get update && \
    apt-get install -y --fix-missing cppcheck clang clang-format

# Java
RUN apt -y install openjdk-17-jre openjdk-17-jdk

WORKDIR /mnt
