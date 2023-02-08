#pragma once

#include<Neko/Core.h>
#include<Neko/Application.h>
#include<iostream>
#include<Neko/Log.h>

extern Neko::Application* Neko::CreateApplication();

int main(int argc,char** argv){
    Neko::Log::Init();

    std::cout<<"application created"<<std::endl;
    auto app =Neko::CreateApplication();
    app->Run();
    delete app;

}