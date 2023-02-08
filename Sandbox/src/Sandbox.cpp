#include<neko.h>

class Sandbox:public Neko::Application{
    public:
    Sandbox(){    }
    ~Sandbox(){}    
    void Run(){}

};

Neko::Application* Neko::CreateApplication(){
    return new Sandbox();
}