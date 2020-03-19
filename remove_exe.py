#!/usr/bin/python

import os

def is_exe(fpath):
    return os.path.isfile(fpath) and os.access(fpath, os.X_OK) and not fpath.endswith('.cpp')
    
for root, dirs, files in os.walk('./codeforces'):
    for file in files:
        fpath = os.path.join(root, file)
        if(is_exe(fpath)):
            print(fpath)