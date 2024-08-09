#include <iostream>


class Singleton {
public:
    
    static Singleton& getInstance() {
        static Singleton instance; 
        return instance;
    }

   
    void showMessage() const {
        std::cout << "Hello, Singleton Pattern!" << std::endl;
    }

    
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
   
    Singleton() {
        std::cout << "Singleton instance created." << std::endl;
    }

    ~Singleton() {
        std::cout << "Singleton instance destroyed." << std::endl;
    }
};

int main() {
   
    Singleton& singleton = Singleton::getInstance();
    
    singleton.showMessage();
    
    Singleton& anotherSingleton = Singleton::getInstance();
    
    if (&singleton == &anotherSingleton) {
        std::cout << "Both instances are the same." << std::endl;
    } else {
        std::cout << "Instances are different." << std::endl;
    }
    
    return 0;
}
