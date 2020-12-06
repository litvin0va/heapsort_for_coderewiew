#define NMAX 20
#include "array_io.h"

int
read_array (double *a, int n, const char *name)
{
  FILE *fp;
  int i;
  if (!(fp = fopen (name,"r")))
    return -1;
  for (i = 0; i < n; i++)
  {
    if (fscanf (fp, "%lf", a + i) != 1)
    {
      if (!feof (fp))
      {
    fclose (fp);
    return -2;
      }
      fclose (fp);
      return -3;
    }
  }
  fclose (fp);
  return 0;
}

void
init_array(double *a, int n, int key)
{
  int i;
  srand (key);
  for (i = 0; i < n; i++)
    a[i] = rand() / 100000;
}

void
print_array(double *a,int n)
{
  int nmax = (n > NMAX ? NMAX : n);
  int i;
  for (i = 0; i < nmax; i++)
    printf(" %f", a[i]);
  printf ("\n");
}
