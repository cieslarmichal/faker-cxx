#ifndef ULID_STRUCT_HH
#define ULID_STRUCT_HH

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <random>
#include <vector>

#if _MSC_VER > 0
typedef uint32_t rand_t;
# else
typedef uint8_t rand_t;
#endif

namespace faker::helpers::ulid {

/**
 * ULID is a 16 byte Universally Unique Lexicographically Sortable Identifier
 * */
struct ULID {
	uint8_t data[16];

	ULID() {
		// unrolled loop
		data[0] = 0;
		data[1] = 0;
		data[2] = 0;
		data[3] = 0;
		data[4] = 0;
		data[5] = 0;
		data[6] = 0;
		data[7] = 0;
		data[8] = 0;
		data[9] = 0;
		data[10] = 0;
		data[11] = 0;
		data[12] = 0;
		data[13] = 0;
		data[14] = 0;
		data[15] = 0;
	}

	ULID(uint64_t val) {
		// unrolled loop
		data[15] = static_cast<uint8_t>(val);

		val >>= 8;
		data[14] = static_cast<uint8_t>(val);

		val >>= 8;
		data[13] = static_cast<uint8_t>(val);

		val >>= 8;
		data[12] = static_cast<uint8_t>(val);

		val >>= 8;
		data[11] = static_cast<uint8_t>(val);

		val >>= 8;
		data[10] = static_cast<uint8_t>(val);

		val >>= 8;
		data[9] = static_cast<uint8_t>(val);

		val >>= 8;
		data[8] = static_cast<uint8_t>(val);

		data[7] = 0;
		data[6] = 0;
		data[5] = 0;
		data[4] = 0;
		data[3] = 0;
		data[2] = 0;
		data[1] = 0;
		data[0] = 0;
	}

	ULID(const ULID& other) {
		// for (int i = 0 ; i < 16 ; i++) {
		// 	data[i] = other.data[i];
		// }

		// unrolled loop
		data[0] = other.data[0];
		data[1] = other.data[1];
		data[2] = other.data[2];
		data[3] = other.data[3];
		data[4] = other.data[4];
		data[5] = other.data[5];
		data[6] = other.data[6];
		data[7] = other.data[7];
		data[8] = other.data[8];
		data[9] = other.data[9];
		data[10] = other.data[10];
		data[11] = other.data[11];
		data[12] = other.data[12];
		data[13] = other.data[13];
		data[14] = other.data[14];
		data[15] = other.data[15];
	}

	ULID& operator=(const ULID& other) {
		// for (int i = 0 ; i < 16 ; i++) {
		// 	data[i] = other.data[i];
		// }

		// unrolled loop
		data[0] = other.data[0];
		data[1] = other.data[1];
		data[2] = other.data[2];
		data[3] = other.data[3];
		data[4] = other.data[4];
		data[5] = other.data[5];
		data[6] = other.data[6];
		data[7] = other.data[7];
		data[8] = other.data[8];
		data[9] = other.data[9];
		data[10] = other.data[10];
		data[11] = other.data[11];
		data[12] = other.data[12];
		data[13] = other.data[13];
		data[14] = other.data[14];
		data[15] = other.data[15];

		return *this;
	}

	ULID(ULID&& other) {
		// for (int i = 0 ; i < 16 ; i++) {
		// 	data[i] = other.data[i];
		// 	other.data[i] = 0;
		// }

		// unrolled loop
		data[0] = other.data[0];
		other.data[0] = 0;

		data[1] = other.data[1];
		other.data[1] = 0;

		data[2] = other.data[2];
		other.data[2] = 0;

		data[3] = other.data[3];
		other.data[3] = 0;

		data[4] = other.data[4];
		other.data[4] = 0;

		data[5] = other.data[5];
		other.data[5] = 0;

		data[6] = other.data[6];
		other.data[6] = 0;

		data[7] = other.data[7];
		other.data[7] = 0;

		data[8] = other.data[8];
		other.data[8] = 0;

		data[9] = other.data[9];
		other.data[9] = 0;

		data[10] = other.data[10];
		other.data[10] = 0;

		data[11] = other.data[11];
		other.data[11] = 0;

		data[12] = other.data[12];
		other.data[12] = 0;

		data[13] = other.data[13];
		other.data[13] = 0;

		data[14] = other.data[14];
		other.data[14] = 0;

		data[15] = other.data[15];
		other.data[15] = 0;
	}

	ULID& operator=(ULID&& other) {
		// for (int i = 0 ; i < 16 ; i++) {
		// 	data[i] = other.data[i];
		// 	other.data[i] = 0;
		// }

		// unrolled loop
		data[0] = other.data[0];
		other.data[0] = 0;

		data[1] = other.data[1];
		other.data[1] = 0;

		data[2] = other.data[2];
		other.data[2] = 0;

		data[3] = other.data[3];
		other.data[3] = 0;

		data[4] = other.data[4];
		other.data[4] = 0;

		data[5] = other.data[5];
		other.data[5] = 0;

		data[6] = other.data[6];
		other.data[6] = 0;

		data[7] = other.data[7];
		other.data[7] = 0;

		data[8] = other.data[8];
		other.data[8] = 0;

		data[9] = other.data[9];
		other.data[9] = 0;

		data[10] = other.data[10];
		other.data[10] = 0;

		data[11] = other.data[11];
		other.data[11] = 0;

		data[12] = other.data[12];
		other.data[12] = 0;

		data[13] = other.data[13];
		other.data[13] = 0;

		data[14] = other.data[14];
		other.data[14] = 0;

		data[15] = other.data[15];
		other.data[15] = 0;

		return *this;
	}
};

/**
 * EncodeTime will encode the first 6 bytes of a uint8_t array to the passed
 * timestamp
 * */
inline void EncodeTime(time_t timestamp, ULID& ulid) {
	ulid.data[0] = static_cast<uint8_t>(timestamp >> 40);
	ulid.data[1] = static_cast<uint8_t>(timestamp >> 32);
	ulid.data[2] = static_cast<uint8_t>(timestamp >> 24);
	ulid.data[3] = static_cast<uint8_t>(timestamp >> 16);
	ulid.data[4] = static_cast<uint8_t>(timestamp >> 8);
	ulid.data[5] = static_cast<uint8_t>(timestamp);
}

/**
 * EncodeEntropy will encode the last 10 bytes of the passed uint8_t array with
 * the values generated using the passed random number generator.
 * */
inline void EncodeEntropy(const std::function<uint8_t()>& rng, ULID& ulid) {
	ulid.data[6] = rng();
	ulid.data[7] = rng();
	ulid.data[8] = rng();
	ulid.data[9] = rng();
	ulid.data[10] = rng();
	ulid.data[11] = rng();
	ulid.data[12] = rng();
	ulid.data[13] = rng();
	ulid.data[14] = rng();
	ulid.data[15] = rng();
}

/**
 * Encode will create an encoded ULID with a timestamp and a generator.
 * */
inline void Encode(time_t timestamp, const std::function<uint8_t()>& rng, ULID& ulid) {
	EncodeTime(timestamp, ulid);
	EncodeEntropy(rng, ulid);
}

/**
 * Create will create a ULID with a timestamp and a generator.
 * */
inline ULID Create(time_t timestamp, const std::function<uint8_t()>& rng) {
	ULID ulid;
	Encode(timestamp, rng, ulid);
	return ulid;
}

/**
 * Crockford's Base32
 * */
static const char Encoding[33] = "0123456789ABCDEFGHJKMNPQRSTVWXYZ";

/**
 * MarshalTo will marshal a ULID to the passed character array.
 *
 * Implementation taken directly from oklog/ulid
 * (https://sourcegraph.com/github.com/oklog/ulid@0774f81f6e44af5ce5e91c8d7d76cf710e889ebb/-/blob/ulid.go#L162-190)
 *
 * timestamp:<br>
 * dst[0]: first 3 bits of data[0]<br>
 * dst[1]: last 5 bits of data[0]<br>
 * dst[2]: first 5 bits of data[1]<br>
 * dst[3]: last 3 bits of data[1] + first 2 bits of data[2]<br>
 * dst[4]: bits 3-7 of data[2]<br>
 * dst[5]: last bit of data[2] + first 4 bits of data[3]<br>
 * dst[6]: last 4 bits of data[3] + first bit of data[4]<br>
 * dst[7]: bits 2-6 of data[4]<br>
 * dst[8]: last 2 bits of data[4] + first 3 bits of data[5]<br>
 * dst[9]: last 5 bits of data[5]<br>
 *
 * entropy:
 * follows similarly, except now all components are set to 5 bits.
 * */
inline void MarshalTo(const ULID& ulid, char dst[26]) {
	// 10 byte timestamp
	dst[0] = Encoding[(ulid.data[0] & 224) >> 5];
	dst[1] = Encoding[ulid.data[0] & 31];
	dst[2] = Encoding[(ulid.data[1] & 248) >> 3];
	dst[3] = Encoding[((ulid.data[1] & 7) << 2) | ((ulid.data[2] & 192) >> 6)];
	dst[4] = Encoding[(ulid.data[2] & 62) >> 1];
	dst[5] = Encoding[((ulid.data[2] & 1) << 4) | ((ulid.data[3] & 240) >> 4)];
	dst[6] = Encoding[((ulid.data[3] & 15) << 1) | ((ulid.data[4] & 128) >> 7)];
	dst[7] = Encoding[(ulid.data[4] & 124) >> 2];
	dst[8] = Encoding[((ulid.data[4] & 3) << 3) | ((ulid.data[5] & 224) >> 5)];
	dst[9] = Encoding[ulid.data[5] & 31];

	// 16 bytes of entropy
	dst[10] = Encoding[(ulid.data[6] & 248) >> 3];
	dst[11] = Encoding[((ulid.data[6] & 7) << 2) | ((ulid.data[7] & 192) >> 6)];
	dst[12] = Encoding[(ulid.data[7] & 62) >> 1];
	dst[13] = Encoding[((ulid.data[7] & 1) << 4) | ((ulid.data[8] & 240) >> 4)];
	dst[14] = Encoding[((ulid.data[8] & 15) << 1) | ((ulid.data[9] & 128) >> 7)];
	dst[15] = Encoding[(ulid.data[9] & 124) >> 2];
	dst[16] = Encoding[((ulid.data[9] & 3) << 3) | ((ulid.data[10] & 224) >> 5)];
	dst[17] = Encoding[ulid.data[10] & 31];
	dst[18] = Encoding[(ulid.data[11] & 248) >> 3];
	dst[19] = Encoding[((ulid.data[11] & 7) << 2) | ((ulid.data[12] & 192) >> 6)];
	dst[20] = Encoding[(ulid.data[12] & 62) >> 1];
	dst[21] = Encoding[((ulid.data[12] & 1) << 4) | ((ulid.data[13] & 240) >> 4)];
	dst[22] = Encoding[((ulid.data[13] & 15) << 1) | ((ulid.data[14] & 128) >> 7)];
	dst[23] = Encoding[(ulid.data[14] & 124) >> 2];
	dst[24] = Encoding[((ulid.data[14] & 3) << 3) | ((ulid.data[15] & 224) >> 5)];
	dst[25] = Encoding[ulid.data[15] & 31];
}

/**
 * Marshal will marshal a ULID to a std::string.
 * */
inline std::string Marshal(const ULID& ulid) {
	char data[27];
	data[26] = '\0';
	MarshalTo(ulid, data);
	return std::string(data);
}

};  // namespace ulid

#endif // ULID_STRUCT_HH