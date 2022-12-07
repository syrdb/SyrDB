/*
    This file is part of SyrDB.

    SyrDB is free software: you can redistribute it and/or modify it under the terms
    of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version.

    SyrDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
    without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License along with SyrDB.
    If not, see <https://www.gnu.org/licenses/>.    
*/

#ifndef BINARY_H_
#define BINARY_H_

#include <iostream>
#include <vector>

typedef unsigned char byte;

namespace TheStngularity::SyrDB {
    /**
     * @brief Binary (Bytes) buffer class
     */
    class BinaryBuffer {
        private:
            std::vector<byte> buffer;  // Reader buffer
            int pos;  // Cursor position

        public:
            /**
             * @brief Construct a new Binary Buffer object
             */
            BinaryBuffer();

            /**
             * @brief Construct a new Binary Buffer object
             * @param binary Content of this buffer
             */
            BinaryBuffer(std::vector<byte> binary);

            /**
             * @brief Read the specified size of bytes
             * @param size Number of bytes to read
             * @return Readed bytes
             */
            std::vector<byte> read(unsigned int size);

            /**
             * @brief Write any bytes to buffer
             * @param binary Bytes to write
             */
            void write(std::vector<byte> binary);

            /**
             * @brief Insert any bytes to buffer by specified index
             * @param index Index of bytes insert
             * @param binary Bytes to insert
             */
            void insert(unsigned int index, std::vector<byte> binary);

            /**
             * @brief Get value from buffer
             * @return Buffer content
             */
            std::vector<byte> getValue();

            /**
             * @brief Get size of buffer
             * @return Buffer size
             */
            inline size_t size();

            /**
             * @brief Is a cursor on the buffer end or no
             * @return Whether cursor on the buffer end
             */
            bool isOnEnd();

            /**
             * @brief Reset cursor position
             */
            void reset();
    };
}

#endif