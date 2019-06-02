#!make -f

all: test
	./$<

demo: MemberDemo.o Member.o
	clang++-5.0 -std=c++17 $^ -o demo

test: MemberTest.o Member.o
	clang++-5.0 -std=c++17 $^ -o test

%.o: %.cpp
	clang++-5.0 -std=c++17 --compile $< -o $@

Member.o: Member.h

MemberDemo.o: Member.h

MemberTest.o: Member.h badkan.hpp

clean:
	rm -f *.o demo test