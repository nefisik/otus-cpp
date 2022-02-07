rm -rf build
mkdir build
cd build
cmake .. -DWITH_GOOGLE_TEST=ON
cmake --build . -j8
./test_version