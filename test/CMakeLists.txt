
FetchContent_Declare(
    Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.6)
FetchContent_MakeAvailable(Catch2)

set(TEST_CASES asset_loader_test)

foreach(TEST_CASE IN LISTS TEST_CASES)
  add_executable(${TEST_CASE} ${TEST_CASE}.cc)

  target_link_libraries(${TEST_CASE} PRIVATE asset_loader)

  target_compile_features(${TEST_CASE} PRIVATE cxx_std_17)
endforeach()