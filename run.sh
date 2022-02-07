rm -rf build
mkdir build
cd build
cmake .. -DWITH_GOOGLE_TEST=OFF
cmake --build . -j8
./helloworld_cli