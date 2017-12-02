#ifndef BTT2_OP_H
#define BTT2_OP_H

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
  } option;

  option * unselected_option (char * text, void (*action) ());

  option * selected_option (char * text, void (*action) ());

#endif
