##!/bin/bash

 javac -h . BasicDemo01.java
 g++ -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -shared -o libBasicDemo01.so BasicDemo01.c
 java -Djava.library.path=. BasicDemo01