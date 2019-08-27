#include <stdio.h>
#include <math.h>

#define INDEX(r, c, w) (r * w + c) 


void conv(float *mat, float *matres, float *filter, int mh, int mw, int ksize, int stride)
{
  // 我们都按VALID方式padding,即no-zero padding
  // https://www.corvil.com/kb/what-is-the-difference-between-same-and-valid-padding-in-tf-nn-max-pool-of-tensorflow
  int out_height = ceil((float)(mh - ksize + 1) / stride);
  int out_width = ceil((float)(mw - ksize + 1) / stride);
  for (int i = 0; i < out_height; i++)
  {
    for (int j = 0; j < out_width; j++)
    {
      float tmp = 0.0;
      int start_x = i * stride;
      int start_y = j * stride;
      for (int k = 0; k < ksize; k++)
      {
        for (int l = 0; l < ksize; l++)
        {
          tmp += mat[INDEX(start_x + k, start_y + l, mw)] * filter[INDEX(k, l, ksize)];
        }
      }
      matres[i * out_width + j] = tmp;
    }
  }
}

void test_conv()
{
  float mat[] = {
    1,1,1,1,1,1,
    1,1,1,1,1,1,
    1,1,1,1,1,1,
    1,1,1,1,1,1,
    1,1,1,1,1,1,
    1,1,1,1,1,1
  };

  float filter[] = {
    2,2,2,
    2,2,2,
    2,2,2
  };
  // 我们都按VALID方式padding,即no-zero padding
  float result[] = { 0,0,0,0};
  conv(mat, result, filter, 6, 6, 3, 2);
  printf("%f, %f, %f, %f", result[0], result[1], result[2], result[3]);
}

int main()
{
  test_conv();
}
