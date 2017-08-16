#!/bin/sh
#
#本脚本为Mac下的自动make
#需要自己下载
#autoscan
#aclocal
#autoconf
#autoheader
#automake
#等

#前三个参数不可为空：
#一：程序名
#二：程序版本
#三：bug report邮箱

#第四个参数起，为所有.c .cpp ch文件
#如：mymain.c mytest.c mytest.h

#本版本只试用较简单的情况

Autoscan
mv configure.scan configure.in
sed -i -e 's|FULL-PACKAGE-NAME|'$1'|' configure.in
sed -i -e 's|VERSION|'$2'|' configure.in
sed -i -e 's|BUG-REPORT-ADDRESS|'$3'|' configure.in
sed -i -e 's|AC_OUTPUT|AC_OUTPUT(Makefile)|' configure.in
#sed -i -e 's|AC_CONFIG_HEADERS([config.h])|AC_CONFIG_HEADERS([config.h]) AM_INIT_AUTOMAKE('$1','$2');|' configure.in
#sed '10 a|AM_INIT_AUTOMAKE('$1','$2');|' configure.in
sed -e '8 a\'$'\n''AM_INIT_AUTOMAKE('$1','$2')' configure.in >> configure2.in
cp configure2.in configure.in
rm configure2.in
aclocal
autoconf
echo "AUTOMAKE_OPTIONS=foreign
bin_PROGRAMS=$1
$1_SOURCES=$4 $5 $6 $7 $8 $9
" > Makefile.am

autoheader
automake --add-missing
./configure
make
