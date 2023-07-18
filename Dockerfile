FROM ubuntu:23.10

RUN apt update -y
RUN apt install -y cmake ninja-build g++-13 libstdc++-13-dev

COPY include/ faker-cxx/include/
COPY src/ faker-cxx/src/
COPY externals/ faker-cxx/externals/
COPY cmake/ faker-cxx/cmake/
COPY CMakeLists.txt faker-cxx/CMakeLists.txt
COPY run_linux_gxx_tests.sh faker-cxx/run_linux_gxx_tests.sh

RUN chmod 777 ./faker-cxx/run_linux_gxx_tests.sh

ENTRYPOINT cd faker-cxx && ./run_linux_gxx_tests.sh
