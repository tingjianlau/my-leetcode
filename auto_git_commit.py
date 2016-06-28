#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: git_auto_commit.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/15
#       > Detail: 自动创建README和自动提交github
#########################################################################

import os, sys, getopt
from os import system

def usage():
    print sys.argv[0], 'usage:'
    print '\t', '-m, --msg: the msg for commit' 
    print '\t', '-h, --help: print help msg' 

if __name__ == '__main__':
    try:
        opts, args = getopt.getopt(sys.argv[1:], 'hm:', ['help', 'msg='])
    except getopt.GetoptError as err:
        # print help infomation and exit:
        print(err)
        usage()
        sys.exit(2)
    msg = ''
    if len(opts) == 0:
        usage()
        sys.exit()
    for opt, arg in opts:
        if opt in ('-h', '--help'):
            usage()
            sys.exit()
        elif opt in ('-m', '--msg'):
            msg = arg
        else:
            assert False, 'unhandled option'
    
    commands = ['python auto_create_readme.py'
                'git add .',
                'git commit -m "' + msg + '"',
                'git push origin master']

    for cmd in commands:
        system(cmd)
