#include <iostream>
#include <string>
using namespace std;

class MediaItem 
{
protected:
    string location;
    double fileSize;
public:
    MediaItem(string loc, double size) : location(loc), fileSize(size) {}
    virtual void start() = 0;
    virtual void halt() = 0;
    virtual ~MediaItem() {}
};

class VideoMedia : virtual public MediaItem 
{
protected:
    string resolution;
public:
    VideoMedia(string loc, double size, string res) : MediaItem(loc, size), resolution(res) {}
};

class SoundMedia : virtual public MediaItem 
{
protected:
    int frequency;
public:
    SoundMedia(string loc, double size, int rate) : MediaItem(loc, size), frequency(rate) {}
};

class MovieFile : public VideoMedia, public SoundMedia 
{
public:
    MovieFile(string loc, double size, string res, int rate)
        : MediaItem(loc, size), VideoMedia(loc, size, res), SoundMedia(loc, size, rate) {}

    void start() override 
    {
        cout << "Playing movie: " << location << " (Size: " << fileSize << " MB, Resolution: " 
             << resolution << ", Frequency: " << frequency << " Hz)" << endl;
    }

    void halt() override 
    {
        cout << "Stopping movie: " << location << endl;
    }
};

class PictureFile : public VideoMedia 
{
public:
    PictureFile(string loc, double size, string res) : MediaItem(loc, size), VideoMedia(loc, size, res) {}

    void start() override 
    {
        cout << "Displaying picture: " << location << " (Resolution: " << resolution << ")" << endl;
    }

    void halt() override 
    {
        cout << "Closing picture: " << location << endl;
    }
};

class MusicFile : public SoundMedia 
{
public:
    MusicFile(string loc, double size, int rate) : MediaItem(loc, size), SoundMedia(loc, size, rate) {}

    void start() override 
    {
        cout << "Playing music: " << location << " (Frequency: " << frequency << " Hz)" << endl;
    }

    void halt() override 
    {
        cout << "Stopping music: " << location << endl;
    }
};

int main() 
{
    MediaItem* media[] = {
        new MovieFile("movie.mp4", 500, "1920x1080", 44100),
        new PictureFile("photo.jpg", 5, "1080x720"),
        new MusicFile("song.mp3", 10, 44100)
    };

    for (auto& m : media) 
    {
        m->start();
        m->halt();
        delete m;
    }

    return 0;
}
