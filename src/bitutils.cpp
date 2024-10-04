module bitutils;

namespace BitUtils {
    std::string displayBinary(std::byte number) {
        std::string binaryString;

		// Loop through each bit in the byte and add it to the binary string.
        for (int i = 7; i >= 0; i--) {
			binaryString += (((number >> i) & std::byte{ 1 }) == std::byte{ 1 } ? '1' : '0'); // Check if the bit is 1 or 0.
        }
        return binaryString;
    }

    bool getBit(std::byte number, int position) {
		return ((number >> position) & std::byte{ 1 }) == std::byte{ 1 }; // Check if the bit is 1 or 0.
    }

    void setBit(std::byte& number, int position) {
		number |= (std::byte{ 1 } << position); // Set the bit to 1.
    }
}
