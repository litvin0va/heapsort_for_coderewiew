#include "array_io.h"

void
heap (double*, int);
void
hp (double*, int, int);

void
check (double*,int);

void
check(double*a,int n)
{
  for (int i = 0; i < n - 1; i++)
    if (a[i] > a[i+1])
      {
        printf ("ERR\n");
        return;
      }
    printf ("GOOD\n");
}


int
main (int argc, char **argv)
{
  const char *name = 0;
  int n;
  double *a, t;
  if (argc != 3)
    {
      printf ("Usage: %s <file> <n> \n", argv[0]);
      return 1;
    }
  name = argv[1];
  n = atoi (argv[2]);
  if (!(a = new double[n]))
    {
      printf ("Not enougth memory!\n");
      return 2;
    }
  int ret = read_array (a, n, name);
  if (ret < 0)
    {
      switch (ret)
        {
          case -1:
            printf ("Cannot open %s\n", name);
            break;
          case -2:
            printf ("Cannot read %s\n", name);
            break;
          case -3:
            printf ("Not enougth data in %s\n", name);
            break;
          default:
            printf ("Error %d in %s\n", ret, name);
        }
      delete []a;
      return 3;
    }
  print_array (a, n);
  printf ("\n");
  t = clock ();
  heap (a, n);
  print_array (a, n);
  t = (clock ()-t) / CLOCKS_PER_SEC;
  printf("Elapsed = %.2f\n",t);
  check(a,n);
  delete []a;
  return 0;
}

void
heap (double *a, int n)
{
  int i;
  double tmp;
  for (i = n - 1; i >= 0; i--)
    hp (a, n, i);
  for (i = n - 1; i > 0; i--)
    {
      tmp = a[i];
      a[i] = a[0];
      a[0] = tmp;
      hp (a, i, 0);
    }
}

void
hp (double *a, int n, int curr)
{
  int t;
  double tmp;
  while (2 * curr + 1 < n)
  {
    t = 2 * curr + 1;
    if (2 * curr + 2 < n && !(a[2 * curr + 2] < a[t]) )
      t = 2 * curr + 2;
    if (a[curr] < a[t])
      {
        tmp = a[t];
        a[t] = a[curr];
        a[curr] = tmp;
        curr = t;
      }
    else
      break;
  }
}
