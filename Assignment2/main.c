#include <stdio.h>
#include <math.h>

union single_data
{
  unsigned int u;
  int i;
  float f;
  unsigned char c[4]; // 4 * 8 = 32 bits
};

union double_data
{
  double d;
  unsigned char c[8]; // 8 * 8 = 64 bits
};

void initializeBinaryArray(unsigned char *binary_arr, int length)
{
  for (int i = 0; i < length; i++)
  {
    binary_arr[i] = 0;
  }
}

int getMaxBinaryPOW(unsigned char max)
{
  static int i_gmbp = 0;
  double v_binary_pow = pow(2, ++i_gmbp);

  // 2^i_gmbp > max => return i_gmbp - 1
  if (v_binary_pow > (double)max)
  {
    // printf("v_binary_pow: %d = 2^%d, max: %d, \n", v_binary_pow, i_gmbp, max);
    int result = i_gmbp - 1;
    // printf("return: %d\n", result);
    i_gmbp = 0;
    return result;
  }
  else
  {
    return getMaxBinaryPOW(max);
  }
}

void setBinaryArray(unsigned char *binary_arr, unsigned char x)
{
  // static int i_b = -1;
  int n_max = getMaxBinaryPOW(x);
  // printf("set_binary x: %d, nmax:%d, test=%lu\n", x, n_max, pow(2, n_max));

  if (x > 0)
  {
    binary_arr[n_max] = 1;
    x -= (unsigned char)pow(2, n_max);
    // printf("\n\n\nagain\n");
    setBinaryArray(binary_arr, x);
    return;
  }

  return;
};

void printActualBitPatterns(int data_size, unsigned char *data)
{
  int bits_length = 8 * data_size;
  unsigned char result_binary_arr[bits_length];
  initializeBinaryArray(result_binary_arr, bits_length);

  int separation_num = bits_length / 8;
  unsigned char tmp_binary_arr[8]; // unsigned char[]1要素分 = 8bit分のbinaryArray

  for (int i = 0; i < separation_num; i++) // 8bitずつbinaryArrayを求める
  {
    initializeBinaryArray(tmp_binary_arr, 8);
    // printf("\nmain_for x = %d\n", data[i]);
    setBinaryArray(tmp_binary_arr, data[i]);

    for (int j = 0; j < 8; j++)
    {
      // printf("tmp[%d] = %d = result[%d](now: %d)\n", j, tmp_binary_arr[j], j + i * 8, result_binary_arr[j + i * 8]);
      result_binary_arr[i * 8 + j] = tmp_binary_arr[j];
    }
  }

  // printf("\n result[4]=%d , result[2]=%d\n", result_binary_arr[4], result_binary_arr[2]);

  // resultBinaryArrayを逆順に表示
  for (int i = bits_length - 1; i >= 0; i--)
  {
    printf("%d", result_binary_arr[i]);
    i % 8 == 0 && printf(" ");
  }

  printf("\n\n");
}

int main()
{

  int n = 0;
  union single_data sx;
  union double_data dx;

  dx.d = 0;
  sx.i = 0;

  /** unsigned int */
  // printf("\nunsigned integer: \n");

  // printf("0:\n");
  // sx.f = 0;
  // printActualBitPatterns(sizeof(sx.u), &(sx.c));

  // printf("1:\n");
  // sx.f = 1;
  // printActualBitPatterns(sizeof(sx.u), &(sx.c));

  // printf("2:\n");
  // sx.f = 2;
  // printActualBitPatterns(sizeof(sx.u), &(sx.c));

  // printf("-1:\n");
  // sx.f = -1;
  // printActualBitPatterns(sizeof(sx.u), &(sx.c));

  // printf("3.402823e+38:\n");
  // sx.f = 3.402823e+38;
  // printActualBitPatterns(sizeof(sx.u), &(sx.c));

  // printf("-3.402823e+38:\n");
  // sx.i = -3.402823e+38;
  // printActualBitPatterns(sizeof(sx.u), &(sx.c));

  /** int */
  // sx.i = 20;
  // printf("integer: \n");
  // printActualBitPatterns(sizeof(sx.i), &(sx.c));

  /** float */
  // sx.f = 20;
  // sx.f = -1.0 / 0.0;
  // printf("float: \n");
  // printActualBitPatterns(sizeof(sx.f), &(sx.c));

  // /** double */
  // printf("double: \n");

  printf("0:\n");
  dx.d = 0;
  printActualBitPatterns(sizeof(dx.d), &(dx.c));

  printf("1:\n");
  dx.d = 1;
  printActualBitPatterns(sizeof(dx.d), &(dx.c));

  printf("2:\n");
  dx.d = 2;
  printActualBitPatterns(sizeof(dx.d), &(dx.c));

  printf("-1:\n");
  dx.d = -1;
  printActualBitPatterns(sizeof(dx.d), &(dx.c));

  printf("1.797693e+308:\n");
  dx.d = 1.797693e+308;
  printActualBitPatterns(sizeof(dx.d), &(dx.c));

  printf("-1.797693e+308:\n");
  dx.d = -1.797693e+308;
  printActualBitPatterns(sizeof(dx.d), &(dx.c));

  // // dx.d = 20.000;
  // printf("1.0/0.0: \n");
  // dx.d = 1.0 / 0.0;
  // printActualBitPatterns(sizeof(dx.d), &(dx.c));

  // printf("-1.0/0.0: \n");
  // dx.d = -1.0 / 0.0;
  // printActualBitPatterns(sizeof(dx.d), &(dx.c));

  // printf("0.0/0.0: \n");
  // dx.d = 0.0 / 0.0;
  // printActualBitPatterns(sizeof(dx.d), &(dx.c));

  // printf("2^1000 \n");
  // dx.d = pow(2, 1000);
  // printActualBitPatterns(sizeof(dx.d), &(dx.c));

  return 0;
}