#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: auto_add_difficulty.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/20
#########################################################################

import os
import codecs

if __name__ == '__main__':
    algFolders = [] 

    for algFolder in os.listdir(os.getcwd()):
       if os.path.isdir(algFolder) and algFolder.split('_')[0].isdigit():
           algFolders.append(algFolder)
        
    for algFolder in algFolders:
        absFolderPath = os.path.join(os.getcwd(), algFolder)

        for algFile in os.listdir(absFolderPath):
            curAlgFile = os.path.join(absFolderPath, algFile)
            exe = algFile.strip().split('.')[-1]

            if exe == 'txt':
                with codecs.open(curAlgFile, 'a', 'utf-8') as f:
                    f.write('\n##Difficulty\nEasy\n') 
        
