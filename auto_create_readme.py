#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: auto_create_readme.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/19
#########################################################################
import os, sys

if __name__ == '__main__':
    algFolders = []

    # 过滤非目标文件或文件夹
    for algFolder in os.listdir(os.getcwd()):
        if os.path.isdir(algFolder) and algFolder.split('_')[0].isdigit():
            algFolders.append(algFolder)   # 目标文件夹

    writeLines = {}
    # 循环外层文件夹
    for algFolder in algFolders:
        #print algFolder + ":------->\n"
        
        # 获取每题的id和name
        id, name = algFolder.strip().split('_')[0], algFolder.strip().split('_')[1:]
        # 格式化name
        name = ' '.join(name) 
        # print id + '\n' + name + '\n'
        absFolderPath = os.path.join(os.getcwd(), algFolder)
        
        # 初始化变量
        problem_title = 'https://www.leetcode.com//problemset/algorithms/'
        tags = 'Default'
        difficulty = 'Default'
        solutions = ''

        # 变脸每个题目目录下的所有文件，包括各个语言的实现文件和README.md文件
        for algFile in os.listdir(absFolderPath):
            curAlgFile = os.path.join(absFolderPath, algFile) 
            exe = algFile.strip().split('.')[-1]    # 扩展名
            if exe == 'md':
                # 读取每个题目的README.md文件，获取对应的link,tags等
                with open(curAlgFile, 'r') as f:
                    lines = f.readlines()
                    for i, line in enumerate(lines):
                        if i == 0:  # Title 
                            problem_title = '[' + line[line.find('.')+2:]
                            problem_title = problem_title[:-1].strip()    # 去除前后空格和换行符
                        elif line[0:7] == '###Tags' or line[0:7] == '###tags':
                            tags = lines[i + 1][:-1].strip()    # 去除前后空格和换行符
                        elif line[0:13] == '###Difficulty' or line[0:13] == '###difficulty':
                            difficulty = lines[i + 1][:-1].strip()    # 去除前后空格和换行符
            elif exe == 'c':
                cLink = './' + algFolder + '/' + algFolder + '.c'
                solutions += '[C](' + cLink + '), '
            elif exe == 'cpp':
                cplusplusLink = './' + algFolder + '/' + algFolder + '.cpp'
                solutions += '[C++](' + cplusplusLink + '), '
            elif exe == 'py':
                pyLink = './' + algFolder + '/' + algFolder + '.py'
                solutions += '[Python](' + pyLink + '), '
            elif exe == 'java':
                javaLink = './' + algFolder + '/' + algFolder + '.java'
                solutions += '[Java](' + javaLink + '), '
                    
            
        solutions = solutions[:-2]  # 去除最后的逗号
        writeLine = '|' + id + '|' +  problem_title + '|' + solutions + '|' + tags + '|' + difficulty + '|\n' 
        #print writeLine
        #writeLines.append(writeLine)
        writeLines[writeLine] = int(id)
    
    #print type(writeLines)
    writeLines = sorted(writeLines.iteritems(), key=lambda d:d[1], reverse = False)
    #print writeLines 
    # 写入README.md
    readme = 'README.md'
    title = ['##My Leetcode Algorithms\n\n', '| # | Title | Solution | Tags | Difficulty |\n', '|---| ----- | -------- | ---- | ---------- |\n']    
    aimF = open(readme, 'w')
    aimF.write(''.join(title))  # 写入标题

    for line in writeLines:
        #print line[0]
        aimF.write(line[0])

    aimF.close()
    print 'Done!'
