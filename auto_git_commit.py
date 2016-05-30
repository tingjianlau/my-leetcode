#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: git_auto_commit.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/15
#########################################################################

import os, sys
from os import system

if __name__ == '__main__':
    msg = sys.argv[1]

    command = 'python auto_create_readme.py'
    system(command)
    
    command = 'git add .'
    system(command)

    command = 'git commit -m \"' + msg + '\"'
    system(command)

    command = 'git push origin master'
    system(command)
