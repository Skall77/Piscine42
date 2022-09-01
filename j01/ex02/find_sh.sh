#!/bin/bash
find . -type f -name "*.sh" | cut -f 2 -d "." | rev | cut -d "/" -f 1 | rev
