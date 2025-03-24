#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
  unsigned int u = UINT_MAX;
  float f = (float)u;
  double d = (double)u;

  printf("u=%u\n", u);  /* u=4294967295 */
  printf("f=%f\n", f);  /* f=4294967296.000000 */
  printf("d=%lf\n", d); /* d=4294967295.000000 */

  d = DBL_MAX;
  u = (unsigned int)d;
  printf("u=%u\n", u);  /* u=0 */
  printf("d=%lf\n", d); /* d=179769313486231570814527... */
}
