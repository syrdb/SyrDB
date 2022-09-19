#include <iostream>
#include "libs/binary.h"

int main() {
    TheStngularity::SyrDB::BinaryBuffer buffer = TheStngularity::SyrDB::BinaryBuffer({0x00, 0x01, 0xff, 0x1f});
    std::cout << "Buffer size: " << buffer.size() << std::endl;
    std::cout << "Value: ";
    for(short i = 0; !buffer.isOnEnd(); i++)
        std::cout << (short)buffer.read(1)[0] << " ";
    std::cout << std::endl;
    return 0;
}