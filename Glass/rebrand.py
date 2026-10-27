#!/usr/bin/env python3
import os, sys
for root, dirs, files in os.walk('.'):
    for f in files:
        path = os.path.join(root, f)
        try:
            with open(path, 'r', encoding='utf-8', errors='ignore') as file:
                content = file.read()
            content = content.replace('Glass(OS)', 'Glass(OS)')
            with open(path, 'w', encoding='utf-8') as file:
                file.write(content)
        except:
            pass
