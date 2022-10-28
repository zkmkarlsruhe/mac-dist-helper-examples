// shamelessly adapted from the pd-lib-builder helloworld example:
// https://github.com/pure-data/helloworld
#include "m_pd.h"

// this version define is also read in Makefile...
#define VERSION "1.2.3"

static t_class *hellopd_class;

typedef struct _hellopd {
  t_object x_obj;
} t_hellopd;

void hellopd_bang(t_hellopd *x) {
  (void)x; // silence unused variable warning
  post("hello world");
}  

void *hellopd_new(void) {  
  t_hellopd *x = (t_hellopd *)pd_new(hellopd_class);
  return (void *)x;
}

void hellopd_setup(void) {
  hellopd_class = class_new(gensym("hellopd"),
    (t_newmethod)hellopd_new, NULL,
    sizeof(t_hellopd), CLASS_DEFAULT, 0);
  class_addbang(hellopd_class, hellopd_bang);
}
