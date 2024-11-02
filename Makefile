all: TechTarget

TechTarget: Driver.cpp LinkedList.h DataClass.h SmartPointer.h
	g++ Driver.cpp -o TechTarget

clean:
	rm -f TechTarget
