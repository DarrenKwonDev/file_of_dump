#include <filesystem>
#include <iostream>

using namespace std;

// in case of msvc
// namespace fs = std::experimental::filesystem::v1;

namespace fs = std::filesystem;

int main() {
    fs::path a = fs::current_path();
    fs::path b = "_test1";
    fs::path c = "_test2";

    fs::path from = a / b;
    fs::path to = a / c;

    for (auto& entry : fs::recursive_directory_iterator(from)) {
        cout << entry.path() << endl;
    }

    try {
        fs::copy(from, to);                              // 비재귀적
        fs::copy(from, to, fs::copy_options::recursive); // 재귀적으로 복사.
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    // 내용물 지우기
    fs::remove_all(from);
    fs::remove_all(to);

    return 0;
}