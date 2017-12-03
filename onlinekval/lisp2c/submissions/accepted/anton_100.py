#!/usr/bin/env python3
import re

re_noargs = re.compile(r'\(([a-z]+)\)')
re_withargs = re.compile(r'\(([a-z]+) ')

# Read Lisp function call
function_call = input()

# Transform to C function call
function_call = re.sub(re_noargs, r'\1()', function_call)
function_call = re.sub(re_withargs, r'\1(', function_call)
function_call = function_call.replace(' ', ', ')

# Print C function call
print(function_call)
