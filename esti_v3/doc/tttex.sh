#!/bin/sh
platex $1
dvipdfmx ${1:0:-3}"dvi"
rm *.log *.aux *.dvi
