.PHONY: all clean run

all : BasicDemo01.h libBasicDemo01.so

clean : 
	rm -rf BasicDemo01.h BasicDemo01.class libBasicDemo01.so

run :
	java -Djava.library.path=. BasicDemo01

BasicDemo01.h : BasicDemo01.java
	javac -h . BasicDemo01.java

libBasicDemo01.so : BasicDemo01.c
	g++ -fPIC -I"${JAVA_HOME}/include" -I"$(JAVA_HOME)/include/linux" -shared -o libBasicDemo01.so BasicDemo01.c

