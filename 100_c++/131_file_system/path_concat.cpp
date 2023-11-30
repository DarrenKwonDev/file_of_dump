#include <filesystem>
#include <iostream>

using namespace std;

// in case of msvc
// namespace fs = std::experimental::filesystem::v1;

namespace fs = std::filesystem;

int main() {
    fs::path path = "D://직박구리";
    fs::path path2 = "data";
    fs::path path21 = "/data";

    path /= path2; // 파일 경로로 합치기
    cout << path << endl;

    path /= path21;
    cout << path << endl; // /data만 출력됨

    fs::path path3 = "C://code";
    fs::path path4 = "openai";
    path3 += path4; // string concat임.
    cout << path3 << endl;

    return 0;
}