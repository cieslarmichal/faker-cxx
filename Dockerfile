FROM ubuntu:23.10

RUN apt update -y
RUN apt install -y cmake ninja-build g++-13 libstdc++-13-dev

COPY include/ faker-cxx/include/
COPY src/ faker-cxx/src/
COPY tests/ faker-cxx/tests/
COPY externals/ faker-cxx/externals/
COPY cmake/ faker-cxx/cmake/
COPY CMakeLists.txt faker-cxx/CMakeLists.txt
COPY scripts/ faker-cxx/scripts/

RUN chmod 777 ./faker-cxx/scripts/run_tests_linux_gxx.sh

ENTRYPOINT cd faker-cxx && ./scripts/run_tests_linux_gxx.sh
