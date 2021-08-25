#include <stdio.h>

struct STUDENT
{
  char name[50];
  int rollNo, m1, m2, m3;
  float percentage;
}s[10];

void high_per ()
{
  int i, max = s[0].percentage, key = 0;
  for (i = 0; i < 10; i++)
    {
      if (s[i].percentage > max)
	{
	  max = s[i].percentage;
	  key = i;
	}
    }
  printf
    ("Name of s: %sRoll Number: %d\nMarks in:\n\tm1: %d\n\tm2: %d\n\tm3: %d\nPercentage: %.2f\n",
     s[key].name, s[key].rollNo, s[key].m1, s[key].m2, s[key].m3,
     s[key].percentage);
}


int main ()
{
  printf ("Program written by enrollment number 200420107012\n");

  int n, i;
  char name[50];
  printf ("Enter Number of students: ");
  scanf ("%d", &n);

  for (i = 0; i < n; i++)
    {
      printf ("Enter name of student: ");
      getchar ();
      fgets (s[i].name, 50, stdin);
      printf ("Enter s rollNo: ");
      scanf ("%d", &s[i].rollNo);
      printf ("Enter marks m1 m2 m3 of s(out of 70): ");
      scanf ("%d %d %d", &s[i].m1, &s[i].m2, &s[i].m3);
      s[i].percentage =
	((s[i].m1 + s[i].m2 + s[i].m3) * 100) / 210;
    }

  high_per ();

  return 0;
}
