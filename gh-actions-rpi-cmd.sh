# note that this is running on a virtual rpi
export VIRTUAL_PI=1

apt-get update -y && apt-get full-upgrade -y
./install-deps.sh

g++ -Wall tests/test.cpp src/MCP3008.cpp -I include -o test -llgpio
