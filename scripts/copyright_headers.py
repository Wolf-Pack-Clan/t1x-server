#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

header = """\
/**************************************************************************/
/*  $filename                                                             */
/**************************************************************************/
/*                         This file is part of:                          */
/*                               T1X-Server                               */
/*             https://github.com/Wolf-Pack-Clan/t1x-server               */
/**************************************************************************/
/* Copyright (c) 2025 Wolf Pack                                           */
/*                                                                        */
/* This program is free software: you can redistribute it and/or modify   */
/* it under the terms of the GNU General Public License as published by   */
/* the Free Software Foundation, either version 3 of the License, or      */
/* (at your option) any later version.                                    */
/*                                                                        */
/* This program is distributed in the hope that it will be useful,        */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of         */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          */
/* GNU General Public License for more details.                           */
/*                                                                        */
/* You should have received a copy of the GNU General Public License      */
/* along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/**************************************************************************/
"""

fname = sys.argv[1]

# Handle replacing $filename with actual filename and keep alignment
fsingle = fname.strip()
if fsingle.find("/") != -1:
    fsingle = fsingle[fsingle.rfind("/") + 1 :]
rep_fl = "$filename"
rep_fi = fsingle
len_fl = len(rep_fl)
len_fi = len(rep_fi)
# Pad with spaces to keep alignment
if len_fi < len_fl:
    for x in range(len_fl - len_fi):
        rep_fi += " "
elif len_fl < len_fi:
    for x in range(len_fi - len_fl):
        rep_fl += " "
if header.find(rep_fl) != -1:
    text = header.replace(rep_fl, rep_fi)
else:
    text = header.replace("$filename", fsingle)
text += "\n"

# We now have the proper header, so we want to ignore the one in the original file
# and potentially empty lines and badly formatted lines, while keeping comments that
# come after the header, and then keep everything non-header unchanged.
# To do so, we skip empty lines that may be at the top in a first pass.
# In a second pass, we skip all consecutive comment lines starting with "/*",
# then we can append the rest (step 2).

with open(fname.strip(), "r") as fileread:
    lines = fileread.readlines()
header_done = False

if "**************" in lines[0]:
    sys.exit(0)

new_content = text + "\n" + "".join(lines)

with open(fname, "w") as filewrite:
    filewrite.write(new_content)
