# 二十四节气计算
国科大天文与空间科学学院研究生课程《天体测量学及其应用》课程大作业
### 注意
与另一个二十四节气计算程序不同，本程序读取DE/LE历表采用的程序为:ephcom version 1.0(
http://ephemeris.com/software.html 
)。
但是这个版本的代码有问题，所以我阅读并修改了了部分源代码（修改后的完整代码及使用的注意事项详见我的另一个库：
https://github.com/xunhou0222/ephcom_1.0_beta
）。
当我修改完了之后，才发现这个包更新到了第二版，只不过换了官网：
http://timeephem.sourceforge.net/ephcom2.php
但是我也懒得再折腾了，学弟学妹感兴趣可以研究一下2.0版本的，那个代码肯定比我修改得好。
### 本程序在 gcc 11.2.0下编译通过！
### 程序说明
    
         (1) bin
                可执行文件目录

         (2) input
                输入文件目录，内部包含二进制的DE星历文件“JPLEPH421”

         (3) lib
                静态库目录，包含两个静态库，一个是sofa包的静态库"libsofa_c_20210512.a"和利用包“ephcom 1.0”中的代码生成的静态库“libephcom.a"

         (4) src
                源码文件目录，其中main.c是主函数文件，其余是自定义函数。

         (5) 程序运行结果截图.png
                可执行文件运行结果截图。


### 编译方法
        打开终端，将路径切换至src下，执行：
                make    或    make -f makefile


### 程序运行方法
        打开终端，将路径切换至bin下，执行：
                ./SolarTerms
