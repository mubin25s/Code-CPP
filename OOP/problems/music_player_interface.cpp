/*
Problem: Music Player Interface
Build an Interface using Pure Virtual Functions.
Implement it in MP3Player and WAVPlayer classes.
*/

#include <iostream>
#include <string>

// Interface completely abstracts functionality
class IMusicPlayer {
public:
    virtual void play(std::string track) = 0;
    virtual void stop() = 0;
    virtual void setVolume(int level) = 0;
    virtual ~IMusicPlayer() {}
};

class MP3Player : public IMusicPlayer {
private:
    int volume;
public:
    void play(std::string track) override {
        std::cout << "Decoding and Playing MP3: " << track << std::endl;
    }
    void stop() override {
        std::cout << "MP3 Player stopped." << std::endl;
    }
    void setVolume(int level) override {
        volume = level;
        std::cout << "MP3 Volume set to " << volume << std::endl;
    }
};

class WAVPlayer : public IMusicPlayer {
private:
    int volume;
public:
    void play(std::string track) override {
        std::cout << "Streaming lossless WAV: " << track << std::endl;
    }
    void stop() override {
        std::cout << "WAV Player stopped." << std::endl;
    }
    void setVolume(int level) override {
        volume = level;
        std::cout << "WAV Volume set to " << volume << std::endl;
    }
};

int main() {
    IMusicPlayer* myPlayer1 = new MP3Player();
    myPlayer1->setVolume(50);
    myPlayer1->play("song1.mp3");
    myPlayer1->stop();

    std::cout << "-----------------" << std::endl;

    IMusicPlayer* myPlayer2 = new WAVPlayer();
    myPlayer2->setVolume(80);
    myPlayer2->play("song2.wav");
    myPlayer2->stop();

    delete myPlayer1;
    delete myPlayer2;

    return 0;
}
