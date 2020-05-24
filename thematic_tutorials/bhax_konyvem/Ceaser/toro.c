#define MAX_TITKOS 4096
#define OLVASAS_BUFFER 256
#define KULCS_MERET 7

#include <stdio.h>
#include <unistd.h>
#include <string.h>

double atlagos_szohossz (const char *titkos, int titkos_meret) {
  int sz = 0;
  for (int i = 0; i < titkos_meret; ++i)
    if (titkos[i] == ' ')
      ++sz;
  return (double) titkos_meret / sz;
}

int tiszta_lehet (const char *titkos, int titkos_meret) {

  double szohossz = atlagos_szohossz (titkos, titkos_meret);
  return szohossz > 6.0 && szohossz < 9.0
    && strcasestr (titkos, "hogy") && strcasestr (titkos, "nem")
    && strcasestr (titkos, "az") && strcasestr (titkos, "ha");
}

void exor (const char kulcs[], int kulcs_meret, char titkos[], int titkos_meret) {
  int kulcs_index = 0;
  for (int i = 0; i < titkos_meret; ++i){
      titkos[i] = titkos[i] ^ kulcs[kulcs_index];
      kulcs_index = (kulcs_index + 1) % kulcs_meret;
    }
}

int exor_tores (const char kulcs[], int kulcs_meret, char titkos[], int titkos_meret) {
  exor (kulcs, kulcs_meret, titkos, titkos_meret);
  return tiszta_lehet (titkos, titkos_meret);
}

int main (void) {
  char kulcs[KULCS_MERET];
  char titkos[MAX_TITKOS];
  char *p = titkos;
  int olvasott_bajtok;

  while ((olvasott_bajtok =
	  read (0, (void *) p,
		(p - titkos + OLVASAS_BUFFER <
		 MAX_TITKOS) ? OLVASAS_BUFFER : titkos + MAX_TITKOS - p)))
    p += olvasott_bajtok;


  for (int i = 0; i < MAX_TITKOS - (p - titkos); ++i)
    titkos[p - titkos + i] = '\0';

  char letters[] = {'b','e','r','e','s','m'};
  int letterCount = sizeof(letters)/sizeof(letters[0]);

  for (int ii = 0; ii <= letterCount; ++ii)
    for (int ji = 0; ji <= letterCount; ++ji)
      for (int ki = 0; ki <= letterCount; ++ki)
	      for (int li = 0; li <= letterCount; ++li)
	        for (int mi = 0; mi <= letterCount; ++mi)
	          for (int ni = 0; ni <= letterCount; ++ni)
	            for (int oi = 0; oi <= letterCount; ++oi)
		          {
                kulcs[0] = letters[ii];
                kulcs[1] = letters[ji];
                kulcs[2] = letters[ki];
                kulcs[3] = letters[li];
                kulcs[4] = letters[mi];
                kulcs[5] = letters[ni];
                kulcs[6] = letters[oi];
                if (exor_tores (kulcs, KULCS_MERET, titkos, p - titkos))
                  printf("Kulcs: [%c%c%c%c%c%c%c]\nTiszta szoveg: [%s]\n",letters[ii], letters[ji], letters[ki], letters[li], letters[mi], letters[ni], letters[oi], titkos);


                exor (kulcs, KULCS_MERET, titkos, p - titkos);
              }
  return 0;
}

