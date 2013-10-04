#include <digitalWriteFast.h>
//#include <avr/pgmspace.h>

#define DEBUG false

#define sL1 150
#define sS1 0

#define sL3 150
#define sS3 0

#define sL4 150
#define sS4 0

#define sL5 150
#define sS5 0

#define sL6 150
#define sS6 0

#define sL7 150
#define sS7 0

#define sL8 150
#define sS8 0

#define sL9 150
#define sS9 0

#define sL10 150
#define sS10 0

#define sL11 1500
#define sS11 0

#define sL12 150
#define sS12 0

#define sL13 150
#define sS13 0

//PROGMEM prog_int8_t a[]  = { 255, 250, 245, 239, 234};

//365
const byte s1[] PROGMEM  = {255, 250, 245, 239, 234, 229, 224, 218, 213, 208, 202, 197, 192, 187, 182, 177, 172, 167, 162, 157, 152, 147, 142, 137, 133, 128, 123, 119, 114, 110, 106, 101, 97, 93, 89, 85, 81, 77, 73, 70, 66, 62, 59, 56, 52, 49, 46, 43, 40, 37, 35, 32, 30, 27, 25, 23, 20, 18, 16, 15, 13, 11, 10, 9, 7, 6, 5, 4, 3, 3, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 9, 10, 11, 13, 15, 16, 18, 20, 23, 25, 27, 30, 32, 35, 37, 40, 43, 46, 49, 52, 56, 59, 62, 66, 70, 73, 77, 81, 85, 89, 93, 97, 101, 106, 110, 114, 119, 123, 128, 133, 137, 142, 147, 152, 157, 162, 167, 172, 177, 182, 187, 192, 197, 202, 208, 213, 218, 224, 229, 234, 239, 245, 250};

const byte s3[] PROGMEM = {255, 250, 245, 239, 234, 229, 224, 218, 213, 208, 202, 197, 192, 187, 182, 177, 172, 167, 162, 157, 152, 147, 142, 137, 133, 128, 123, 119, 114, 110, 106, 101, 97, 93, 89, 85, 81, 77, 73, 70, 66, 62, 59, 56, 52, 49, 46, 43, 40, 37, 35, 32, 30, 27, 25, 23, 20, 18, 16, 15, 13, 11, 10, 9, 7, 6, 5, 4, 3, 3, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 9, 10, 11, 13, 15, 16, 18, 20, 23, 25, 27, 30, 32, 35, 37, 40, 43, 46, 49, 52, 56, 59, 62, 66, 70, 73, 77, 81, 85, 89, 93, 97, 101, 106, 110, 114, 119, 123, 128, 133, 137, 142, 147, 152, 157, 162, 167, 172, 177, 182, 187, 192, 197, 202, 208, 213, 218, 224, 229, 234, 239, 245, 250};

const byte s4[] PROGMEM  = {255, 250, 245, 239, 234, 229, 224, 218, 213, 208, 202, 197, 192, 187, 182, 177, 172, 167, 162, 157, 152, 147, 142, 137, 133, 128, 123, 119, 114, 110, 106, 101, 97, 93, 89, 85, 81, 77, 73, 70, 66, 62, 59, 56, 52, 49, 46, 43, 40, 37, 35, 32, 30, 27, 25, 23, 20, 18, 16, 15, 13, 11, 10, 9, 7, 6, 5, 4, 3, 3, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 9, 10, 11, 13, 15, 16, 18, 20, 23, 25, 27, 30, 32, 35, 37, 40, 43, 46, 49, 52, 56, 59, 62, 66, 70, 73, 77, 81, 85, 89, 93, 97, 101, 106, 110, 114, 119, 123, 128, 133, 137, 142, 147, 152, 157, 162, 167, 172, 177, 182, 187, 192, 197, 202, 208, 213, 218, 224, 229, 234, 239, 245, 250};

const byte s5[] PROGMEM  = {255, 250, 245, 239, 234, 229, 224, 218, 213, 208, 202, 197, 192, 187, 182, 177, 172, 167, 162, 157, 152, 147, 142, 137, 133, 128, 123, 119, 114, 110, 106, 101, 97, 93, 89, 85, 81, 77, 73, 70, 66, 62, 59, 56, 52, 49, 46, 43, 40, 37, 35, 32, 30, 27, 25, 23, 20, 18, 16, 15, 13, 11, 10, 9, 7, 6, 5, 4, 3, 3, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 9, 10, 11, 13, 15, 16, 18, 20, 23, 25, 27, 30, 32, 35, 37, 40, 43, 46, 49, 52, 56, 59, 62, 66, 70, 73, 77, 81, 85, 89, 93, 97, 101, 106, 110, 114, 119, 123, 128, 133, 137, 142, 147, 152, 157, 162, 167, 172, 177, 182, 187, 192, 197, 202, 208, 213, 218, 224, 229, 234, 239, 245, 250};

const byte s6[] PROGMEM  = {255, 250, 245, 239, 234, 229, 224, 218, 213, 208, 202, 197, 192, 187, 182, 177, 172, 167, 162, 157, 152, 147, 142, 137, 133, 128, 123, 119, 114, 110, 106, 101, 97, 93, 89, 85, 81, 77, 73, 70, 66, 62, 59, 56, 52, 49, 46, 43, 40, 37, 35, 32, 30, 27, 25, 23, 20, 18, 16, 15, 13, 11, 10, 9, 7, 6, 5, 4, 3, 3, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 9, 10, 11, 13, 15, 16, 18, 20, 23, 25, 27, 30, 32, 35, 37, 40, 43, 46, 49, 52, 56, 59, 62, 66, 70, 73, 77, 81, 85, 89, 93, 97, 101, 106, 110, 114, 119, 123, 128, 133, 137, 142, 147, 152, 157, 162, 167, 172, 177, 182, 187, 192, 197, 202, 208, 213, 218, 224, 229, 234, 239, 245, 250};

const byte s7[] PROGMEM  = {255, 250, 245, 239, 234, 229, 224, 218, 213, 208, 202, 197, 192, 187, 182, 177, 172, 167, 162, 157, 152, 147, 142, 137, 133, 128, 123, 119, 114, 110, 106, 101, 97, 93, 89, 85, 81, 77, 73, 70, 66, 62, 59, 56, 52, 49, 46, 43, 40, 37, 35, 32, 30, 27, 25, 23, 20, 18, 16, 15, 13, 11, 10, 9, 7, 6, 5, 4, 3, 3, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 9, 10, 11, 13, 15, 16, 18, 20, 23, 25, 27, 30, 32, 35, 37, 40, 43, 46, 49, 52, 56, 59, 62, 66, 70, 73, 77, 81, 85, 89, 93, 97, 101, 106, 110, 114, 119, 123, 128, 133, 137, 142, 147, 152, 157, 162, 167, 172, 177, 182, 187, 192, 197, 202, 208, 213, 218, 224, 229, 234, 239, 245, 250};

const byte s8[] PROGMEM  = {255, 250, 245, 239, 234, 229, 224, 218, 213, 208, 202, 197, 192, 187, 182, 177, 172, 167, 162, 157, 152, 147, 142, 137, 133, 128, 123, 119, 114, 110, 106, 101, 97, 93, 89, 85, 81, 77, 73, 70, 66, 62, 59, 56, 52, 49, 46, 43, 40, 37, 35, 32, 30, 27, 25, 23, 20, 18, 16, 15, 13, 11, 10, 9, 7, 6, 5, 4, 3, 3, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 9, 10, 11, 13, 15, 16, 18, 20, 23, 25, 27, 30, 32, 35, 37, 40, 43, 46, 49, 52, 56, 59, 62, 66, 70, 73, 77, 81, 85, 89, 93, 97, 101, 106, 110, 114, 119, 123, 128, 133, 137, 142, 147, 152, 157, 162, 167, 172, 177, 182, 187, 192, 197, 202, 208, 213, 218, 224, 229, 234, 239, 245, 250};

const byte s9[] PROGMEM  = {255, 250, 245, 239, 234, 229, 224, 218, 213, 208, 202, 197, 192, 187, 182, 177, 172, 167, 162, 157, 152, 147, 142, 137, 133, 128, 123, 119, 114, 110, 106, 101, 97, 93, 89, 85, 81, 77, 73, 70, 66, 62, 59, 56, 52, 49, 46, 43, 40, 37, 35, 32, 30, 27, 25, 23, 20, 18, 16, 15, 13, 11, 10, 9, 7, 6, 5, 4, 3, 3, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 9, 10, 11, 13, 15, 16, 18, 20, 23, 25, 27, 30, 32, 35, 37, 40, 43, 46, 49, 52, 56, 59, 62, 66, 70, 73, 77, 81, 85, 89, 93, 97, 101, 106, 110, 114, 119, 123, 128, 133, 137, 142, 147, 152, 157, 162, 167, 172, 177, 182, 187, 192, 197, 202, 208, 213, 218, 224, 229, 234, 239, 245, 250};

const byte s10[] PROGMEM  = {255, 250, 245, 239, 234, 229, 224, 218, 213, 208, 202, 197, 192, 187, 182, 177, 172, 167, 162, 157, 152, 147, 142, 137, 133, 128, 123, 119, 114, 110, 106, 101, 97, 93, 89, 85, 81, 77, 73, 70, 66, 62, 59, 56, 52, 49, 46, 43, 40, 37, 35, 32, 30, 27, 25, 23, 20, 18, 16, 15, 13, 11, 10, 9, 7, 6, 5, 4, 3, 3, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 9, 10, 11, 13, 15, 16, 18, 20, 23, 25, 27, 30, 32, 35, 37, 40, 43, 46, 49, 52, 56, 59, 62, 66, 70, 73, 77, 81, 85, 89, 93, 97, 101, 106, 110, 114, 119, 123, 128, 133, 137, 142, 147, 152, 157, 162, 167, 172, 177, 182, 187, 192, 197, 202, 208, 213, 218, 224, 229, 234, 239, 245, 250};

const byte s11[] PROGMEM = {155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 155, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55};

const byte s12[] PROGMEM = {255, 250, 245, 239, 234, 229, 224, 218, 213, 208, 202, 197, 192, 187, 182, 177, 172, 167, 162, 157, 152, 147, 142, 137, 133, 128, 123, 119, 114, 110, 106, 101, 97, 93, 89, 85, 81, 77, 73, 70, 66, 62, 59, 56, 52, 49, 46, 43, 40, 37, 35, 32, 30, 27, 25, 23, 20, 18, 16, 15, 13, 11, 10, 9, 7, 6, 5, 4, 3, 3, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 9, 10, 11, 13, 15, 16, 18, 20, 23, 25, 27, 30, 32, 35, 37, 40, 43, 46, 49, 52, 56, 59, 62, 66, 70, 73, 77, 81, 85, 89, 93, 97, 101, 106, 110, 114, 119, 123, 128, 133, 137, 142, 147, 152, 157, 162, 167, 172, 177, 182, 187, 192, 197, 202, 208, 213, 218, 224, 229, 234, 239, 245, 250};

const byte s13[] PROGMEM = {255, 250, 245, 239, 234, 229, 224, 218, 213, 208, 202, 197, 192, 187, 182, 177, 172, 167, 162, 157, 152, 147, 142, 137, 133, 128, 123, 119, 114, 110, 106, 101, 97, 93, 89, 85, 81, 77, 73, 70, 66, 62, 59, 56, 52, 49, 46, 43, 40, 37, 35, 32, 30, 27, 25, 23, 20, 18, 16, 15, 13, 11, 10, 9, 7, 6, 5, 4, 3, 3, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 9, 10, 11, 13, 15, 16, 18, 20, 23, 25, 27, 30, 32, 35, 37, 40, 43, 46, 49, 52, 56, 59, 62, 66, 70, 73, 77, 81, 85, 89, 93, 97, 101, 106, 110, 114, 119, 123, 128, 133, 137, 142, 147, 152, 157, 162, 167, 172, 177, 182, 187, 192, 197, 202, 208, 213, 218, 224, 229, 234, 239, 245, 250};


int sP1 = sS1;
int sP3 = sS3;
int sP4 = sS4;
int sP5 = sS5;
int sP6 = sS6;
int sP7 = sS7;
int sP8 = sS8;
int sP9 = sS9;
int sP10 = sS10;
int sP11 = sS11;
int sP12 = sS12;
int sP13 = sS13;

int d=0;

int stepTime = 9;
int initDelay = 800;
int IP0_pin = 2; 

long crossTime;
boolean crossed=false;

void setup(){ 
  pinMode(IP0_pin, INPUT);   
  pinMode(1, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
} 

void loop(){ 
    if (!digitalRead(IP0_pin) || DEBUG){
	    if (!crossed || DEBUG){


   //digitalWriteFast2(13, HIGH);
		  // init delay
		  crossTime = micros();
		  while (micros() - crossTime < initDelay){   }
   //digitalWriteFast2(13, LOW);

          zeroCross();
          crossed = true;
        }
    } else {
       crossed = false; 
    }
}

void zeroCross(){

// ONE PULSE DIVIDED INTO 255
  for (int i=0;i<256;i++){ 
   
     if (i==pgm_read_byte(&s1[sP1])){
	     digitalWriteFast2(1, HIGH);
     }
     if (i==pgm_read_byte(&s3[sP3])){
	     digitalWriteFast2(3, HIGH);
     }
     if (i==pgm_read_byte(&s4[sP4])){
	     digitalWriteFast2(4, HIGH);
     }
     if (i==pgm_read_byte(&s5[sP5])){
	     digitalWriteFast2(5, HIGH);
     }
     if (i==pgm_read_byte(&s6[sP6])){
	     digitalWriteFast2(6, HIGH);
     }
     if (i==pgm_read_byte(&s7[sP7])){
	     digitalWriteFast2(7, HIGH);
     }
     if (i==pgm_read_byte(&s8[sP8])){
	     digitalWriteFast2(8, HIGH);
     }
     if (i==pgm_read_byte(&s9[sP9])){
	     digitalWriteFast2(9, HIGH);
     }
     if (i==pgm_read_byte(&s10[sP10])){
	     digitalWriteFast2(10, HIGH);
     }
     if (i==pgm_read_byte(&s11[sP11])){
	     digitalWriteFast2(11, HIGH);
     }
     if (i==pgm_read_byte(&s12[sP12])){
	     digitalWriteFast2(12, HIGH);
     }
     if (i==pgm_read_byte(&s13[sP13])){
	     digitalWriteFast2(13, HIGH);
     }
     crossTime = micros();
     while (micros() - crossTime < stepTime){   }
  } 
// END -ONE PULSE DIVIDED INTO 255
    
   // delay for on time
     crossTime = micros();
     while (micros() - crossTime < 100){   }

   // switch all off
   digitalWriteFast2(1, LOW);
   digitalWriteFast2(3, LOW);
   digitalWriteFast2(4, LOW);
   digitalWriteFast2(5, LOW);
   digitalWriteFast2(6, LOW);
   digitalWriteFast2(7, LOW);
   digitalWriteFast2(8, LOW);
   digitalWriteFast2(9, LOW);
   digitalWriteFast2(10, LOW);
   digitalWriteFast2(11, LOW);
   digitalWriteFast2(12, LOW);
   digitalWriteFast2(13, LOW);

	if (d==0){
		sP1++;
		sP3++;
		sP4++;
		sP5++;
		sP6++;
		sP7++;
	}
	if (d==1){
		sP8++;	
		sP9++;
		sP10++;
		sP11++;
		sP12++;
		sP13++;
	}

   
   if (sP1==sL1) sP1=0;
   if (sP3==sL3) sP3=0;
   if (sP4==sL4) sP4=0;
   if (sP5==sL5) sP5=0;
   if (sP6==sL6) sP6=0;
   if (sP7==sL7) sP7=0;
   if (sP8==sL8) sP8=0;
   if (sP9==sL9) sP9=0;
   if (sP10==sL10) sP10=0;
   if (sP11==sL11) sP11=0;
   if (sP12==sL12) sP12=0;
   if (sP13==sL13) sP13=0;

	d++;
	if (d==2) d=0;

}
