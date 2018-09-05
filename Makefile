GCC = g++

PA3: PA3.o CartPoint.o CartVector.o Cave.o CoralReef.o Fish.o GameCommand.o GameObject.o Model.o View.o
	$(GCC) PA3.o CartPoint.o CartVector.o Cave.o CoralReef.o Fish.o GameCommand.o GameObject.o Model.o View.o -o PA3

PA3.o: PA3.cpp
	$(GCC) -c PA3.cpp

CartPoint.o: CartPoint.cpp
	$(GCC) -c CartPoint.cpp

CartVector.o: CartVector.cpp
	$(GCC) -c CartVector.cpp

Cave.o: Cave.cpp
	$(GCC) -c Cave.cpp

CoralReef.o: CoralReef.cpp
	$(GCC) -c CoralReef.cpp

Fish.o: Fish.cpp
	$(GCC) -c Fish.cpp

GameCommand.o: GameCommand.cpp
	$(GCC) -c GameCommand.cpp

GameObject.o: GameObject.cpp
	$(GCC) -c GameObject.cpp

Model.o: Model.cpp
	$(GCC) -c Model.cpp

View.o: View.cpp
	$(GCC) -c View.cpp

clean:
	rm PA3.o CartPoint.o CartVector.o Cave.o CoralReef.o Fish.o GameCommand.o GameObject.o Model.o View.o PA3
