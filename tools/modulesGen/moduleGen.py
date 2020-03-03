#!/usr/bin/python3

import os
import re

ftpl = open("modules.template.h","r")
#fgen = open("../gen/modules.gen.h","w")
code = ftpl.read()
loops = re.match(r'^(//loop)(*)(//end)$',code,re.I|re.M)
print(loops)
