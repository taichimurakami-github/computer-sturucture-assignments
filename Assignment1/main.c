#include <stdio.h>

/**
 * Computer Structure Assignment1 Source Code
 *
 * Author: C2IM2045 Taichi Murakami
 *
 * machine spec:
 *  - PC type    : M1 Macbook Air (late 2020)
 *  - CPU Arch   : ARM64 (customized ARMv8 by apple)
 *  - OS Version : macOS 11.6.1
 *  - Compiler   : gcc (Apple clang version 13.0.0 (clang-1300.0.29.30))
 */

void main()
{
  union cupack
  {
    char c[4];
    unsigned int u;
  } data;

  data.u = 0x01;

  printf("\n\n");
  printf("0x01の格納順は以下の通りです: %d %d %d %d \n", data.c[0], data.c[1], data.c[2], data.c[3]);

  if (data.c[0])
    printf("このコンピュータは リトルエンディアン です");
  if (data.c[3])
    printf("このコンピュータは ビッグエンディアン です");

  printf("\n\n");
}
