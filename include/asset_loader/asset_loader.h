#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>

#include <cstdint>

namespace kplutl {
class AssetLoader {
 public:
  AssetLoader(std::filesystem::path basePath) {
    searchPaths_.emplace_back(std::move(basePath));
  }
  virtual ~AssetLoader() = default;

  std::shared_ptr<std::istream> GetInputStream(
      const std::string& filename) const {
    std::ifstream stream;
    if (SearchFile(filename, stream)) {
      return std::make_shared<std::ifstream>(std::move(stream));
    } else {
      throw std::runtime_error(
          "Unable to create a valid input stream for uri: " + filename);
    }
  }

 protected:
  virtual bool SearchFile(
      const std::string& filename, std::ifstream& stream,
      std::uint8_t level = 8) const {
    std::filesystem::path fullPath{};
    std::filesystem::path upPath{};
    for (int h = 0; h < level; ++h) {
      for (auto& path : searchPaths_) {
        fullPath = upPath;
        fullPath /= path;
        fullPath /= std::filesystem::u8path(filename);
        if (std::filesystem::exists(fullPath)) {
          stream = std::ifstream{fullPath, std::ios_base::binary};
          return true;
        }
      }
      upPath /= "../";
    }
    return false;
  }

 private:
  std::vector<std::filesystem::path> searchPaths_;
};

}  // namespace kplutl