# Minisynth
A minimalistic 8-bit 🎵 synthesizer 🎵 written in C++ with SFML.

## How?
Minisynth generates small audio buffers on the fly, taking some parameters as input. Traditional waveforms included.

## Why?
I ❤️ music.

### Homework Criteria part:

- [x] Interfața grafica (în SDL, SFML, Qt, etc) cu API pentru C++
- [x] Heap Memory Allocation [[LINK]](https://github.com/antonioganea/minisynth/blob/master/src/SoundSynth.cpp#L53)
- [x] Lambda expressions [[LINK]](https://github.com/antonioganea/minisynth/blob/master/main.cpp#L44)
- [x] Design patterns (1 om = 2, 2 oameni = 3, 3 oameni =4, 4 oameni = 5)
+ - [x] Singleton [[LINK]](https://github.com/antonioganea/minisynth/blob/master/include/VirtualController.hpp)
+ - [x] Factory [[LINK]](https://github.com/antonioganea/minisynth/blob/master/include/ui/UIFactory.hpp)
- [x] Abstract Classes [[LINK]](https://github.com/antonioganea/minisynth/blob/master/include/Interactable.hpp)
- [x] RTTI [[LINK]](https://github.com/antonioganea/minisynth/blob/master/include/ui/ElementManager.hpp#L22)
- [x] Templates [[LINK]](https://github.com/antonioganea/minisynth/blob/master/include/ui/ElementManager.hpp#L22)
- [x] Exceptions (de extins std::exception) [[LINK]](https://github.com/antonioganea/minisynth/blob/master/include/ui/BayanKeyboard.hpp#L9)
- [x] Operatori (minim 4 * numărul oamenilor din echipa) [[LINK1]](https://github.com/antonioganea/minisynth/commit/7bec8cfb2f150efc3749ddd6751af3064363c66a) [[LINK2]](https://github.com/antonioganea/minisynth/commit/fb91c0cd3fc4ac5639b5a9367f0aad4db7b83062)
- [x] Smart pointers (minim 1 tip / proiect) [[LINK1]](https://github.com/antonioganea/minisynth/blob/master/src/AssetsRegistry.cpp#L7) -> std::shared_ptr [[LINK2]](https://github.com/antonioganea/minisynth/blob/master/src/ui/UIFactory.cpp#L17) -> std::unique_ptr
- [x] STL [[LINK1]](https://github.com/antonioganea/minisynth/blob/master/include/AssetsRegistry.hpp#L11) -> std::map [[LINK2]](https://github.com/antonioganea/minisynth/blob/master/include/ui/ElementManager.hpp#L9) -> std::vector
- [x] Features of C++17/20 (constexpr, consteval, constinit, fold expressions, init statement for if/switch, etc) (minim 1 / proiect) [[macosBranchLink]](https://github.com/antonioganea/minisynth/blob/macos/src/ui/BayanKeyboard.cpp#L4) -> fold expression

## Demo
[Click here to download a video](https://github.com/antonioganea/quickdoc/blob/master/prezi.mp4?raw=true)
