.PHONY: all clean run

all : BasicDemo02.h libBasicDemo02.so

clean : 
	rm -rf BasicDemo02.h BasicDemo02.class libBasicDemo02.so

run :
	java -Djava.library.path=. BasicDemo02

BasicDemo02.h : BasicDemo02.java
	javac -h . BasicDemo02.java

libBasicDemo02.so : BasicDemo02.c
	g++ -fPIC -I"${JAVA_HOME}/include" -I"$(JAVA_HOME)/include/linux" -shared -o libBasicDemo02.so BasicDemo02.c

