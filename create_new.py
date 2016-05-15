#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: create_new.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/15
#########################################################################

import os, sys
from os import system 

if __name__ == '__main__':
    name = sys.argv[1]
    if not os.path.exists(name):
        # 建立文件夹
        command = "mkdir " + name
        system(command)
    
        # 新建cpp文件
        command = "vim " + name + '/' + name + '.cpp'
        system(command)

        # 新建c文件
        command = "vim " + name + '/' + name + '.c'
        system(command)
     
        # 新建python文件
        command = "vim " + name + '/' + name + '.py'
        system(command)

        # 新建readme文件
        command = "vim " + name + '/' + 'README.md'
        system(command)
    else:
        print name + 'has been created!'
