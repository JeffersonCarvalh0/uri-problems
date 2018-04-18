#! /usr/bin/python
# encoding: utf8


while(True):
    line = input().split()

    if line[0] == '0' and line[1] == '0':
        break

    line[1] = line[1].replace(line[0], '')

    if (line[1] == ''):
        line[1] = 0
    else:
        line[1] = int(line[1])

    print(line[1])
