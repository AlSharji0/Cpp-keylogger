#include <iostream>
#include <cstdlib>
#include <string>
#include <filesystem>

void clearBrowserCache(){
    std::string appData = getenv("APPDATA");
    if (appData.empty()) return ;
    else{
        std::string cachePath = appData + "\\..\\Local\\Google\\Chrome\\User Data";
        try{
            std::filesystem::remove_all(cachePath);
            std::string createpath = "mkdir" + cachePath;
            system(createpath.c_str());
        }
        catch(const std::filesystem::filesystem_error& e){
            std::cerr << "Error removing cache directory: " << e.what() << '\n';
        }
        
    }
}

int main(){
    clearBrowserCache();
}