#include <asset_loader/asset_loader.h>

#include <memory>
#include <iostream>
#include <sstream>

int main() {
  try {
    auto assetLoader = std::make_unique<kplutl::AssetLoader>("asset/text");

    std::stringstream stream;
    stream << assetLoader->GetInputStream("test.txt")->rdbuf();

    std::cout << stream.str();
  } catch (const std::runtime_error& ex) {
    std::cerr << "Error! - ";
    std::cerr << ex.what() << std::endl;

    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}