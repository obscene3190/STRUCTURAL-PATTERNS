#include <iostream>
// Класс пультов имеет ссылку на устройство, которым управляет.
// Методы этого класса делегируют работу методам
// связанного устройства.

// Все устройства имеют общий интерфейс. Поэтому с ними может
// работать любой пульт.
class Device {
public:
    virtual void setVolume(int value) {
        int volume = value;
        std::cout<<"Volume: " << volume << std::endl;
    }
};
       
class Remote {
public:
    Device * device;
    Remote(Device * other) {
        device = other;
    }
    virtual void mute() {}
};


// Можно модернизировать АБСТРАКЦИЮ, не трогая код РЕАЛИЗАЦИИ.
class AdvancedRemote : public Remote {
public:
    AdvancedRemote(Device * other) : Remote(other) {}
    void mute() {
        device->setVolume(0);
    }
};

// Но каждое устройство имеет особую реализацию.
class Tv : public Device {
public:
    void setVolume(int value) override {
        int volume = value;
        std::cout<<"TV volume: " << volume << std::endl;
    }
};

class Radio : public Device {
public:
    void setVolume(int value) override {
        int volume = value;
        std::cout<<"Radio volume: " << volume << std::endl;
    }
};

int main() {
    Tv * tv = new Tv();
    Remote * remoteTv = new AdvancedRemote(tv);
    remoteTv->mute();
    Radio * radio = new Radio();
    Remote * remoteR = new AdvancedRemote(radio);
    remoteR->mute();
}
