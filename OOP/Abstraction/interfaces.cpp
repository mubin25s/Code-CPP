#include <iostream>

// An Interface in C++ is simply a class where ALL functions are pure virtual
// and there are NO member variables.
class IPlayable {
public:
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual ~IPlayable() {} // Good practice
};

class VideoPlayer : public IPlayable {
public:
    void play() override { std::cout << "Playing video." << std::endl; }
    void pause() override { std::cout << "Pausing video." << std::endl; }
    void stop() override { std::cout << "Stopping video." << std::endl; }
};

int main() {
    IPlayable* player = new VideoPlayer();
    
    player->play();
    player->pause();
    player->stop();

    delete player;
    return 0;
}
