
add_library(asset_loader asset_loader.cc)

target_include_directories(asset_loader PUBLIC ../include)

target_compile_features(asset_loader PUBLIC cxx_std_17)