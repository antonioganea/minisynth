g++ -std=c++17

main.o: main.cpp
	g++ -std=c++17 main.cpp -o main.o -c -Iinclude/

VirtualController.o: ./src/VirtualController.cpp
	g++ -std=c++17 ./src/VirtualController.cpp -o VirtualController.o -c -Iinclude/

SoundSynth.o: ./src/SoundSynth.cpp
	g++ -std=c++17 ./src/SoundSynth.cpp -o SoundSynth.o -c -Iinclude/

AssetsRegistry.o: ./src/AssetsRegistry.cpp
	g++ -std=c++17 ./src/AssetsRegistry.cpp -o AssetsRegistry.o -c -Iinclude/

BayanButton.o: ./src/ui/BayanButton.cpp
	g++ -std=c++17 ./src/ui/BayanButton.cpp -o BayanButton.o -c -Iinclude/

BayanKeyboard.o: ./src/ui/BayanKeyboard.cpp
	g++ -std=c++17 ./src/ui/BayanKeyboard.cpp -o BayanKeyboard.o -c -Iinclude/

ElementManager.o: ./src/ui/ElementManager.cpp
	g++ -std=c++17 ./src/ui/ElementManager.cpp -o ElementManager.o -c -Iinclude/

Knob.o: ./src/ui/Knob.cpp
	g++ -std=c++17 ./src/ui/Knob.cpp -o Knob.o -c -Iinclude/

Label.o: ./src/ui/Label.cpp
	g++ -std=c++17 ./src/ui/Label.cpp -o Label.o -c -Iinclude/

Button.o: ./src/ui/Button.cpp
	g++ -std=c++17 ./src/ui/Button.cpp -o Button.o -c -Iinclude/

UIFactory.o: ./src/ui/UIFactory.cpp
	g++ -std=c++17 ./src/ui/UIFactory.cpp -o UIFactory.o -c -Iinclude/

main: main.o VirtualController.o SoundSynth.o AssetsRegistry.o BayanButton.o BayanKeyboard.o ElementManager.o Knob.o Label.o Button.o UIFactory.o
	g++ -std=c++17 main.o VirtualController.o SoundSynth.o AssetsRegistry.o BayanButton.o BayanKeyboard.o ElementManager.o Knob.o Label.o Button.o UIFactory.o -o main -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

run: main
	./main

clean:
	rm ./main.o
	rm ./main