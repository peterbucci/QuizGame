export module bitutils;

import <cstddef>;
import <string>;
import <iostream>;

export namespace BitUtils {
    /**
	 * @brief Display the binary representation of a byte.
	 * @param number The byte to display.
	 * @return The binary representation of the byte.
     */
    std::string displayBinary(std::byte number);
	/**
	 * @brief Get the value of a bit at a specific position.
	 * @param number The byte to get the bit from.
	 * @param position The position of the bit to get.
	 * @return The value of the bit at the specified position.
	 */
    bool getBit(std::byte number, int position);
	/**
	 * @brief Set the value of a bit at a specific position.
	 * @param number The byte to set the bit in.
	 * @param position The position of the bit to set.
	 */
    void setBit(std::byte& number, int position);
}
