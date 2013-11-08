#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;
modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," ca.mod");
    fprintf(stderr," cad.mod");
    fprintf(stderr," childa.mod");
    fprintf(stderr," iqq.mod");
    fprintf(stderr," kca.mod");
    fprintf(stderr," km.mod");
    fprintf(stderr," kvz_nature.mod");
    fprintf(stderr," naz_nature.mod");
    fprintf(stderr," peak.mod");
    fprintf(stderr," syn2.mod");
    fprintf(stderr, "\n");
  }
  _ca_reg();
  _cad_reg();
  _childa_reg();
  _iqq_reg();
  _kca_reg();
  _km_reg();
  _kvz_nature_reg();
  _naz_nature_reg();
  _peak_reg();
  _syn2_reg();
}
