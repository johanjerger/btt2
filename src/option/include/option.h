#ifndef BTT2_OPT_H
#define BTT2_OPT_H

/*
 *  Struct that contains the attributes of an option
 *  it contains the option's text, the way that
 *  it show and the tipe of action performed when you click it.
 */

  typedef struct _option
  {
    char * text;
    void (*show) (struct _option *);
    void (*action) ();
    void (*select) (struct _option *);
    void (*unselect) (struct _option *);
  } option_t;

  option_t * unselected_option (char * text, void (*action) ());

  option_t * selected_option (char * text, void (*action) ());

#endif
