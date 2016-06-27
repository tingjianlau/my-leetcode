#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: capture_html_content.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/25
#   > Detail: 自动创建目录，文件和README文件
#########################################################################

from bs4 import BeautifulSoup
import urllib2
import re
import os, sys
from os import system

#-----使用方法-------#
#param 1: string 传入slug url, 即题目网址的最后一段
#param 2: string 传入中文说明

if __name__ == '__main__':
    slug_url = sys.argv[1]
    chinese_contents = sys.argv[2]
    #chinese_contents = '合并两个数组'
    #slug_url = 'intersection-of-two-arrays'

    problem_dict ={}
    write_order = ['Title', 'Contents', 'Difficulty', 'Tags', 'Similar Problems']

    url = 'https://leetcode.com/problems/'+ slug_url
    content = urllib2.urlopen(url).read()
    
    soup = BeautifulSoup(content, 'html.parser')

    # link, Original Title, Id, Difficulty
    problem_dict['Link'] = url
    h3_string = list(soup.find('div', class_='question-title').stripped_strings)[0].strip().split('.')
    problem_dict['Id'], problem_dict['Original Title']= h3_string[0].strip(), h3_string[1].strip()
    problem_dict['Chinese Contents'] = chinese_contents
    problem_dict[write_order[2]] = list(soup.find_all('span', 'total-submit text-info'))[-1].strong.string.strip()
    
    # get problem's contents        
    contents = list(soup.find('div', class_='question-content'))
    for i in range(len(contents)-1, -1, -1):
        if str(contents[i]).find('/problems') != -1:
            similarInx = i
        elif str(contents[i]).find('/tag') != -1:
            tagInx = i
        elif str(contents[i]).find('subscribe') != -1:
            contentEndIdx = i
            break
    # contents
    problem_content = ''
    for i in range(contentEndIdx):
        problem_content += str(contents[i])
    problem_dict[write_order[1]] = problem_content.strip()
    # tags
    problem_tags_dict = {}
    for tag in contents[tagInx].find_all(href=re.compile(r'/tag/')):
        problem_tags_dict[tag.string.strip()] = tag['href'].strip()
    problem_tags = ''
    for key, val in problem_tags_dict.items():
        problem_tags += '[' + key + '](https://leetcode.com' + val + '), '
    problem_tags = problem_tags[:-2]
    problem_dict[write_order[3]] = problem_tags
    # similar
    problem_similar_dict = {}
    for similar in contents[similarInx].find_all(href=re.compile(r'/problems/')):
        problem_similar_dict[similar.string.strip()] = similar['href'].strip()
    problem_similar = ''
    for key, val in problem_similar_dict.items():
        problem_similar += '[' + key + '](https://leetcode.com' + val + '), '
    problem_similar = problem_similar[:-2]
    problem_dict[write_order[4]] = problem_similar

    #print problem_dict
    

    # 新建文件夹、代码文件和README.md
    # new folder's name
    if slug_url[-1] == '/':
        slug_url = slug_url[:-1]

    name_title = slug_url.replace('-', '_')
    name = problem_dict['Id'] + '_' + name_title 

    if not os.path.exists(name):
        # 建立文件夹
        command = "mkdir " + name 
        system(command)

        # 新建readme文件
        with open(name + '/README.md', 'w') as f:
            for i in range(len(write_order)):
                if i == 0:
                    line = '###[' + problem_dict['Id'] + '. ' + problem_dict['Original Title'] + '](' + problem_dict['Link'] + ')\n'
                    f.write(line)
                    line = problem_dict['Chinese Contents'] + '\n\n'
                    f.write(line)
                else:
                    line = '###' + write_order[i] + '\n'
                    f.write(line)
                    line = problem_dict[write_order[i]]+ '\n\n'
                    f.write(line)
    
    
        # 新建cpp文件
        command = "vim " + name + '/' + name + '.cpp'
        system(command)

        # 新建c文件
        command = "vim " + name + '/' + name + '.c'
        system(command)
     
        # 新建python文件
        command = "vim " + name + '/' + name + '.py'
        system(command)
        print 'Done for %s' % name
    else:
        print name + ' has been created!'

